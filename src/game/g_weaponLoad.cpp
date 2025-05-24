/*
===========================================================================
Copyright (C) 2000 - 2013, Raven Software, Inc.
Copyright (C) 2001 - 2013, Activision, Inc.
Copyright (C) 2013 - 2015, OpenJK contributors

This file is part of the OpenJK source code.

OpenJK is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License version 2 as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see <http://www.gnu.org/licenses/>.
===========================================================================
*/

// g_weaponLoad.cpp
// fills in memory struct with ext_dat\weapons.dat

#include "g_local.h"
#include <functional>

typedef struct
{
	const char	*name;
	void	(*func)(centity_t *cent, const struct weaponInfo_s *weapon );
} func_t;

// Bryar
void FX_BryarProjectileThink(  centity_t *cent, const struct weaponInfo_s *weapon );
void FX_BryarAltProjectileThink(  centity_t *cent, const struct weaponInfo_s *weapon );

// Blaster
void FX_BlasterProjectileThink( centity_t *cent, const struct weaponInfo_s *weapon );
void FX_BlasterAltFireThink( centity_t *cent, const struct weaponInfo_s *weapon );

// Bowcaster
void FX_BowcasterProjectileThink( centity_t *cent, const struct weaponInfo_s *weapon );

// Heavy Repeater
void FX_RepeaterProjectileThink( centity_t *cent, const struct weaponInfo_s *weapon );
void FX_RepeaterAltProjectileThink( centity_t *cent, const struct weaponInfo_s *weapon );

// DEMP2
void FX_DEMP2_ProjectileThink( centity_t *cent, const struct weaponInfo_s *weapon );
void FX_DEMP2_AltProjectileThink( centity_t *cent, const struct weaponInfo_s *weapon );

// Golan Arms Flechette
void FX_FlechetteProjectileThink( centity_t *cent, const struct weaponInfo_s *weapon );
void FX_FlechetteAltProjectileThink( centity_t *cent, const struct weaponInfo_s *weapon );

// Personal Rocket Launcher
void FX_RocketProjectileThink( centity_t *cent, const struct weaponInfo_s *weapon );
void FX_RocketAltProjectileThink( centity_t *cent, const struct weaponInfo_s *weapon );

// Emplaced weapon
void FX_EmplacedProjectileThink( centity_t *cent, const struct weaponInfo_s *weapon );

// Turret weapon
void FX_TurretProjectileThink( centity_t *cent, const struct weaponInfo_s *weapon );

// ATST Main weapon
void FX_ATSTMainProjectileThink( centity_t *cent, const struct weaponInfo_s *weapon );

// ATST Side weapons
void FX_ATSTSideMainProjectileThink( centity_t *cent, const struct weaponInfo_s *weapon );
void FX_ATSTSideAltProjectileThink( centity_t *cent, const struct weaponInfo_s *weapon );

// Table used to attach an extern missile function string to the actual cgame function
func_t	funcs[] = {
	{"bryar_func",			FX_BryarProjectileThink},
	{"bryar_alt_func",		FX_BryarAltProjectileThink},
	{"blaster_func",		FX_BlasterProjectileThink},
	{"blaster_alt_func",	FX_BlasterAltFireThink},
	{"bowcaster_func",		FX_BowcasterProjectileThink},
	{"repeater_func",		FX_RepeaterProjectileThink},
	{"repeater_alt_func",	FX_RepeaterAltProjectileThink},
	{"demp2_func",			FX_DEMP2_ProjectileThink},
	{"demp2_alt_func",		FX_DEMP2_AltProjectileThink},
	{"flechette_func",		FX_FlechetteProjectileThink},
	{"flechette_alt_func",	FX_FlechetteAltProjectileThink},
	{"rocket_func",			FX_RocketProjectileThink},
	{"rocket_alt_func",		FX_RocketAltProjectileThink},
	{"emplaced_func",		FX_EmplacedProjectileThink},
	{"turret_func",			FX_TurretProjectileThink},
	{"atstmain_func",		FX_ATSTMainProjectileThink},
	{"atst_side_alt_func",	FX_ATSTSideAltProjectileThink},
	{"atst_side_main_func",	FX_ATSTSideMainProjectileThink},
	{NULL,					NULL}
};

static struct wpnParms_s
{
	int	weaponNum;	// Current weapon number
	int	ammoNum;
} wpnParms;

static void WPN_Ammo (const char **holdBuf);
static void WPN_AmmoIcon (const char **holdBuf);
static void WPN_AmmoMax (const char **holdBuf);
static void WPN_AmmoLowCnt (const char **holdBuf);
static void WPN_AmmoType (const char **holdBuf);
static void WPN_WeaponType (const char **holdBuf);

// Legacy weapons.dat force fields
static void WPN_FuncSkip(const char **holdBuf);

namespace
{

template <int N>
struct WPN_StringParseImpl
{
	WPN_StringParseImpl(char (weaponData_t::*ptr)[N])
		: ptr_(ptr)
	{
	}

	void operator()(const char **holdBuf) const
	{
		const char *tokenStr;

		if (COM_ParseString(holdBuf, &tokenStr))
		{
			return;
		}

		int len = strlen(tokenStr) + 1;

		if (len > N)
		{
			len = N;
			gi.Printf(S_COLOR_YELLOW "WARNING: string too long in external WEAPONS.DAT '%s'\n", tokenStr);
		}

		Q_strncpyz(weaponData[wpnParms.weaponNum].*ptr_, tokenStr, len);
	}

private:
	char (weaponData_t::*ptr_)[N];
};

template <int N>
WPN_StringParseImpl<N> WPN_StringParse(char (weaponData_t::*ptr)[N])
{
	return WPN_StringParseImpl<N>(ptr);
}

struct WPN_EffectParse
{
	WPN_EffectParse(char (weaponData_t::*ptr)[64])
		: ptr_(ptr)
	{
	}

	void operator()(const char **holdBuf) const
	{
		WPN_StringParse(ptr_)(holdBuf);
		G_EffectIndex(weaponData[wpnParms.weaponNum].*ptr_);
	}

private:
	char (weaponData_t::*ptr_)[64];
};

struct WPN_IntParse
{
	WPN_IntParse(int weaponData_t::* ptr, int min = INT_MIN, int max = INT_MAX)
		: ptr_(ptr)
		, min_(min)
		, max_(max)
	{
	}

	void operator()(const char **holdBuf) const
	{
		int tokenInt;

		if (COM_ParseInt(holdBuf, &tokenInt))
		{
			SkipRestOfLine(holdBuf);
			return;
		}

		if (tokenInt < min_ || tokenInt > max_ )
		{
			gi.Printf(S_COLOR_YELLOW "WARNING: value exceeded <%d, %d> in external weapon data: '%d'\n", min_, max_, tokenInt);
			return;
		}

		weaponData[wpnParms.weaponNum].*ptr_ = tokenInt;
	}

private:
	int weaponData_t::* ptr_;
	int min_;
	int max_;
};

struct WPN_FloatParse
{
	WPN_FloatParse(float weaponData_t::* ptr, float min = FLT_MIN, float max = FLT_MAX)
		: ptr_(ptr)
		, min_(min)
		, max_(max)
	{
	}

	void operator()(const char **holdBuf) const
	{
		float tokenFlt;

		if (COM_ParseFloat(holdBuf, &tokenFlt))
		{
			SkipRestOfLine(holdBuf);
			return;
		}

		if (tokenFlt < min_ || tokenFlt > max_)
		{
			gi.Printf(S_COLOR_YELLOW "WARNING: value exceeded <%f, %f> in external weapon data: '%f'\n", min_, max_, tokenFlt);
		}

		weaponData[wpnParms.weaponNum].*ptr_ = tokenFlt;
	}

private:
	float weaponData_t::* ptr_;
	float min_;
	float max_;
};

struct WPN_FuncNameParse
{
	WPN_FuncNameParse(void *weaponData_t::* ptr)
		: ptr_(ptr)
	{
	}

	void operator()(const char **holdBuf) const
	{
		const char *tokenStr;

		if (COM_ParseString(holdBuf, &tokenStr))
		{
			return;
		}

		int len = strlen(tokenStr) + 1;

		if (len > 64)
		{
			len = 64;
			gi.Printf(S_COLOR_YELLOW"WARNING: func name '%s' too long in external WEAPONS.DAT\n", tokenStr);
		}

		for (func_t* s=funcs; s->name; s++ )
		{
			if (!Q_stricmp(s->name, tokenStr))
			{
				weaponData[wpnParms.weaponNum].*ptr_ = (void*)s->func;
				return;
			}
		}
		gi.Printf(S_COLOR_YELLOW"WARNING: func name '%s' in external WEAPONS.DAT does not exist\n", tokenStr);
	}

private:
	void *weaponData_t::* ptr_;
};

struct WPN_ColorParse
{
	WPN_ColorParse(float (weaponData_t::* ptr)[3])
		: ptr_(ptr)
	{
	}

	void operator()(const char **holdBuf) const
	{
		float tokenFlt;

		for (int i = 0; i < 3; ++i)
		{
			if (COM_ParseFloat(holdBuf, &tokenFlt))
			{
				SkipRestOfLine(holdBuf);
				continue;
			}

			if (tokenFlt < 0 || tokenFlt > 1)
			{
				gi.Printf(S_COLOR_YELLOW"WARNING: bad color in external weapon data '%f'\n", tokenFlt);
				continue;
			}

			(weaponData[wpnParms.weaponNum].*ptr_)[i] = tokenFlt;
		}
	}

private:
	float (weaponData_t::* ptr_)[3];
};

} // namespace

typedef struct
{
	const char *parmName;
	std::function<void(const char **holdBuf)> func;
} wpnParms_t;

// This is used as a fallback for each new field, in case they're using base files --eez
constexpr int defaultDamage[] = {
	0,							// WP_NONE
	0,							// WP_SABER										// handled elsewhere
	BRYAR_PISTOL_DAMAGE,		// WP_BRYAR_PISTOL
	BLASTER_DAMAGE,				// WP_BLASTER
	DISRUPTOR_MAIN_DAMAGE,		// WP_DISRUPTOR
	BOWCASTER_DAMAGE,			// WP_BOWCASTER
	REPEATER_DAMAGE,			// WP_REPEATER
	DEMP2_DAMAGE,				// WP_DEMP2
	FLECHETTE_DAMAGE,			// WP_FLECHETTE
	ROCKET_DAMAGE,				// WP_ROCKET_LAUNCHER
	TD_DAMAGE,					// WP_THERMAL
	LT_DAMAGE,					// WP_TRIP_MINE
	FLECHETTE_MINE_DAMAGE,		// WP_DET_PACK									// HACK, this is what the code sez.
	STUN_BATON_DAMAGE,			// WP_STUN_BATON
	0,							// WP_MELEE										// handled by the melee attack function
	EMPLACED_DAMAGE,			// WP_EMPLACED
	BRYAR_PISTOL_DAMAGE,		// WP_BOT_LASER
	0,							// WP_TURRET									// handled elsewhere
	ATST_MAIN_DAMAGE,			// WP_ATST_MAIN
	ATST_SIDE_MAIN_DAMAGE,		// WP_ATST_SIDE
	EMPLACED_DAMAGE,			// WP_TIE_FIGHTER
	EMPLACED_DAMAGE,			// WP_RAPID_FIRE_CONC
	BRYAR_PISTOL_DAMAGE			// WP_BLASTER_PISTOL
};

constexpr int defaultAltDamage[] = {
	0,							// WP_NONE
	0,							// WP_SABER										// handled elsewhere
	BRYAR_PISTOL_DAMAGE,		// WP_BRYAR_PISTOL
	BLASTER_DAMAGE,				// WP_BLASTER
	DISRUPTOR_ALT_DAMAGE,		// WP_DISRUPTOR
	BOWCASTER_DAMAGE,			// WP_BOWCASTER
	REPEATER_ALT_DAMAGE,		// WP_REPEATER
	DEMP2_ALT_DAMAGE,			// WP_DEMP2
	FLECHETTE_ALT_DAMAGE,		// WP_FLECHETTE
	ROCKET_DAMAGE,				// WP_ROCKET_LAUNCHER
	TD_ALT_DAMAGE,				// WP_THERMAL
	LT_DAMAGE,					// WP_TRIP_MINE
	FLECHETTE_MINE_DAMAGE,		// WP_DET_PACK									// HACK, this is what the code sez.
	STUN_BATON_ALT_DAMAGE,		// WP_STUN_BATON
	0,							// WP_MELEE										// handled by the melee attack function
	EMPLACED_DAMAGE,			// WP_EMPLACED
	BRYAR_PISTOL_DAMAGE,		// WP_BOT_LASER
	0,							// WP_TURRET									// handled elsewhere
	ATST_MAIN_DAMAGE,			// WP_ATST_MAIN
	ATST_SIDE_ALT_DAMAGE,		// WP_ATST_SIDE
	EMPLACED_DAMAGE,			// WP_TIE_FIGHTER
	0,							// WP_RAPID_FIRE_CONC							// repeater alt damage is used instead
	BRYAR_PISTOL_DAMAGE			// WP_BLASTER_PISTOL
};

constexpr int defaultSplashDamage[] = {
	0,									// WP_NONE
	0,									// WP_SABER
	0,									// WP_BRYAR_PISTOL
	0,									// WP_BLASTER
	0,									// WP_DISRUPTOR
	BOWCASTER_SPLASH_DAMAGE,			// WP_BOWCASTER
	0,									// WP_REPEATER
	0,									// WP_DEMP2
	0,									// WP_FLECHETTE
	ROCKET_SPLASH_DAMAGE,				// WP_ROCKET_LAUNCHER
	TD_SPLASH_DAM,						// WP_THERMAL
	LT_SPLASH_DAM,						// WP_TRIP_MINE
	FLECHETTE_MINE_SPLASH_DAMAGE,		// WP_DET_PACK									// HACK, this is what the code sez.
	0,									// WP_STUN_BATON
	0,									// WP_MELEE
	0,									// WP_EMPLACED
	0,									// WP_BOT_LASER
	0,									// WP_TURRET
	0,									// WP_ATST_MAIN
	ATST_SIDE_MAIN_SPLASH_DAMAGE,		// WP_ATST_SIDE
	0,									// WP_TIE_FIGHTER
	0,									// WP_RAPID_FIRE_CONC
	0									// WP_BLASTER_PISTOL
};

constexpr float defaultSplashRadius[] = {
	0,									// WP_NONE
	0,									// WP_SABER
	0,									// WP_BRYAR_PISTOL
	0,									// WP_BLASTER
	0,									// WP_DISRUPTOR
	BOWCASTER_SPLASH_RADIUS,			// WP_BOWCASTER
	0,									// WP_REPEATER
	0,									// WP_DEMP2
	0,									// WP_FLECHETTE
	ROCKET_SPLASH_RADIUS,				// WP_ROCKET_LAUNCHER
	TD_SPLASH_RAD,						// WP_THERMAL
	LT_SPLASH_RAD,						// WP_TRIP_MINE
	FLECHETTE_MINE_SPLASH_RADIUS,		// WP_DET_PACK									// HACK, this is what the code sez.
	0,									// WP_STUN_BATON
	0,									// WP_MELEE
	0,									// WP_EMPLACED
	0,									// WP_BOT_LASER
	0,									// WP_TURRET
	0,									// WP_ATST_MAIN
	ATST_SIDE_MAIN_SPLASH_RADIUS,		// WP_ATST_SIDE
	0,									// WP_TIE_FIGHTER
	0,									// WP_RAPID_FIRE_CONC
	0									// WP_BLASTER_PISTOL
};

constexpr int defaultAltSplashDamage[] = {
	0,									// WP_NONE
	0,									// WP_SABER										// handled elsewhere
	0,									// WP_BRYAR_PISTOL
	0,									// WP_BLASTER
	0,									// WP_DISRUPTOR
	BOWCASTER_SPLASH_DAMAGE,			// WP_BOWCASTER
	REPEATER_ALT_SPLASH_DAMAGE,			// WP_REPEATER
	DEMP2_ALT_DAMAGE,					// WP_DEMP2
	FLECHETTE_ALT_SPLASH_DAM,			// WP_FLECHETTE
	ROCKET_SPLASH_DAMAGE,				// WP_ROCKET_LAUNCHER
	TD_ALT_SPLASH_DAM,					// WP_THERMAL
	TD_ALT_SPLASH_DAM,					// WP_TRIP_MINE
	FLECHETTE_MINE_SPLASH_DAMAGE,		// WP_DET_PACK									// HACK, this is what the code sez.
	0,									// WP_STUN_BATON
	0,									// WP_MELEE										// handled by the melee attack function
	0,									// WP_EMPLACED
	0,									// WP_BOT_LASER
	0,									// WP_TURRET									// handled elsewhere
	0,									// WP_ATST_MAIN
	ATST_SIDE_ALT_SPLASH_DAMAGE,		// WP_ATST_SIDE
	0,									// WP_TIE_FIGHTER
	0,									// WP_RAPID_FIRE_CONC
	0									// WP_BLASTER_PISTOL
};

constexpr float defaultAltSplashRadius[] = {
	0,							// WP_NONE
	0,							// WP_SABER										// handled elsewhere
	0,							// WP_BRYAR_PISTOL
	0,							// WP_BLASTER
	0,							// WP_DISRUPTOR
	BOWCASTER_SPLASH_RADIUS,	// WP_BOWCASTER
	REPEATER_ALT_SPLASH_RADIUS,	// WP_REPEATER
	DEMP2_ALT_SPLASHRADIUS,		// WP_DEMP2
	FLECHETTE_ALT_SPLASH_RAD,	// WP_FLECHETTE
	ROCKET_SPLASH_RADIUS,		// WP_ROCKET_LAUNCHER
	TD_ALT_SPLASH_RAD,			// WP_THERMAL
	LT_SPLASH_RAD,				// WP_TRIP_MINE
	FLECHETTE_ALT_SPLASH_RAD,	// WP_DET_PACK									// HACK, this is what the code sez.
	0,							// WP_STUN_BATON
	0,							// WP_MELEE										// handled by the melee attack function
	0,							// WP_EMPLACED
	0,							// WP_BOT_LASER
	0,							// WP_TURRET									// handled elsewhere
	0,							// WP_ATST_MAIN
	ATST_SIDE_ALT_SPLASH_RADIUS,// WP_ATST_SIDE
	0,							// WP_TIE_FIGHTER
	0,							// WP_RAPID_FIRE_CONC
	0							// WP_BLASTER_PISTOL
};

constexpr int defaultNpcDamages[][3] = {
	{0, },	// WP_NONE
	{0, },	// WP_SABER
	{0, },	// WP_BRYAR_PISTOL
	{BLASTER_NPC_DAMAGE_EASY, BLASTER_NPC_DAMAGE_NORMAL, BLASTER_NPC_DAMAGE_HARD},						// WP_BLASTER
	{DISRUPTOR_NPC_MAIN_DAMAGE_EASY, DISRUPTOR_NPC_MAIN_DAMAGE_MEDIUM, DISRUPTOR_NPC_MAIN_DAMAGE_HARD},	// WP_DISRUPTOR
	{BOWCASTER_NPC_DAMAGE_EASY, BOWCASTER_NPC_DAMAGE_NORMAL, BOWCASTER_NPC_DAMAGE_HARD},				// WP_BOWCASTER
	{REPEATER_NPC_DAMAGE_EASY, REPEATER_NPC_DAMAGE_NORMAL, REPEATER_NPC_DAMAGE_HARD},					// WP_REPEATER
	{DEMP2_NPC_DAMAGE_EASY, DEMP2_NPC_DAMAGE_NORMAL, DEMP2_NPC_DAMAGE_HARD},							// WP_DEMP2
	{0, },	// WP_FLECHETTE
	{ROCKET_NPC_DAMAGE_EASY, ROCKET_NPC_DAMAGE_NORMAL, ROCKET_NPC_DAMAGE_HARD},							// WP_ROCKET_LAUNCHER
	{0, },	// WP_THERMAL
	{0, },	// WP_TRIP_MINE
	{0, },	// WP_DET_PACK
	{0, },	// WP_STUN_BATON
	{0, },	// WP_MELEE
	{0, },	// WP_EMPLACED
	{0, },	// WP_BOT_LASER
	{0, },	// WP_TURRET
	{0, },	// WP_ATST_MAIN
	{ATST_SIDE_MAIN_NPC_DAMAGE_EASY, ATST_SIDE_MAIN_NPC_DAMAGE_NORMAL, ATST_SIDE_MAIN_NPC_DAMAGE_HARD},	// WP_ATST_SIDE
	{0, },	// WP_TIE_FIGHTER
	{0, },	// WP_RAPID_FIRE_CONC
	{0, },	// WP_BLASTER_PISTOL
};

constexpr int defaultNpcAltDamages[][3] = {
	{0, },	// WP_NONE
	{0, },	// WP_SABER
	{0, },	// WP_BRYAR_PISTOL
	{BLASTER_NPC_DAMAGE_EASY, BLASTER_NPC_DAMAGE_NORMAL, BLASTER_NPC_DAMAGE_HARD},						// WP_BLASTER
	{DISRUPTOR_NPC_ALT_DAMAGE_EASY, DISRUPTOR_NPC_ALT_DAMAGE_MEDIUM, DISRUPTOR_NPC_ALT_DAMAGE_HARD},	// WP_DISRUPTOR
	{BOWCASTER_NPC_DAMAGE_EASY, BOWCASTER_NPC_DAMAGE_NORMAL, BOWCASTER_NPC_DAMAGE_HARD},				// WP_BOWCASTER
	{REPEATER_ALT_NPC_DAMAGE_EASY, REPEATER_ALT_NPC_DAMAGE_NORMAL, REPEATER_ALT_NPC_DAMAGE_HARD},		// WP_REPEATER
	{0, },	// WP_DEMP2
	{0, },	// WP_FLECHETTE
	{0, },	// WP_ROCKET_LAUNCHER
	{0, },	// WP_THERMAL
	{0, },	// WP_TRIP_MINE
	{0, },	// WP_DET_PACK
	{0, },	// WP_STUN_BATON
	{0, },	// WP_MELEE
	{0, },	// WP_EMPLACED
	{0, },	// WP_BOT_LASER
	{0, },	// WP_TURRET
	{0, },	// WP_ATST_MAIN
	{ATST_SIDE_ROCKET_NPC_DAMAGE_EASY, ATST_SIDE_ROCKET_NPC_DAMAGE_NORMAL, ATST_SIDE_ROCKET_NPC_DAMAGE_HARD},	// WP_ATST_SIDE
	{0, },	// WP_TIE_FIGHTER
	{0, },	// WP_RAPID_FIRE_CONC
	{0, },	// WP_BLASTER_PISTOL
};

constexpr int defaultVelocity[] = {
	0,							// WP_NONE
	0,							// WP_SABER
	BRYAR_PISTOL_VEL,			// WP_BRYAR_PISTOL
	BLASTER_VELOCITY,			// WP_BLASTER
	0,							// WP_DISRUPTOR
	BOWCASTER_VELOCITY,			// WP_BOWCASTER
	REPEATER_VELOCITY,			// WP_REPEATER
	DEMP2_VELOCITY,				// WP_DEMP2
	FLECHETTE_VEL,				// WP_FLECHETTE
	ROCKET_VELOCITY,			// WP_ROCKET_LAUNCHER
	TD_VELOCITY,				// WP_THERMAL
	LT_VELOCITY,				// WP_TRIP_MINE
	0,							// WP_DET_PACK
	0,							// WP_STUN_BATON
	0,							// WP_MELEE
	EMPLACED_VEL,				// WP_EMPLACED
	0,							// WP_BOT_LASER
	0,							// WP_TURRET
	ATST_MAIN_VEL,				// WP_ATST_MAIN
	ATST_SIDE_MAIN_VELOCITY,	// WP_ATST_SIDE
	0,							// WP_TIE_FIGHTER
	0,							// WP_RAPID_FIRE_CONC
	0							// WP_BLASTER_PISTOL
};

constexpr int defaultAltVelocity[] = {
	0,							// WP_NONE
	0,							// WP_SABER
	BRYAR_PISTOL_VEL,			// WP_BRYAR_PISTOL
	BLASTER_VELOCITY,			// WP_BLASTER
	0,							// WP_DISRUPTOR
	BOWCASTER_VELOCITY,			// WP_BOWCASTER
	REPEATER_ALT_VELOCITY,		// WP_REPEATER
	DEMP2_ALT_RANGE,			// WP_DEMP2
	FLECHETTE_VEL,				// WP_FLECHETTE
	ROCKET_VELOCITY,			// WP_ROCKET_LAUNCHER
	TD_ALT_VELOCITY,			// WP_THERMAL
	LT_ALT_VELOCITY,			// WP_TRIP_MINE
	0,							// WP_DET_PACK
	0,							// WP_STUN_BATON
	0,							// WP_MELEE
	EMPLACED_VEL,				// WP_EMPLACED
	0,							// WP_BOT_LASER
	0,							// WP_TURRET
	ATST_MAIN_VEL,				// WP_ATST_MAIN
	ATST_SIDE_ALT_VELOCITY,		// WP_ATST_SIDE
	0,							// WP_TIE_FIGHTER
	0,							// WP_RAPID_FIRE_CONC
	0							// WP_BLASTER_PISTOL
};

constexpr float defaultSpread[] = {
	0,							// WP_NONE
	0,							// WP_SABER
	0,							// WP_BRYAR_PISTOL
	BLASTER_MAIN_SPREAD,		// WP_BLASTER
	0,							// WP_DISRUPTOR
	BOWCASTER_ALT_SPREAD,		// WP_BOWCASTER
	0,							// WP_REPEATER
	0,							// WP_DEMP2
	0,							// WP_FLECHETTE
	0,							// WP_ROCKET_LAUNCHER
	0,							// WP_THERMAL
	0,							// WP_TRIP_MINE
	0,							// WP_DET_PACK
	0,							// WP_STUN_BATON
	0,							// WP_MELEE
	0,							// WP_EMPLACED
	0,							// WP_BOT_LASER
	0,							// WP_TURRET
	0,							// WP_ATST_MAIN
	0,							// WP_ATST_SIDE
	0,							// WP_TIE_FIGHTER
	0,							// WP_RAPID_FIRE_CONC
	0,							// WP_BLASTER_PISTOL
};

constexpr float defaultAltSpread[] = {
	0,							// WP_NONE
	0,							// WP_SABER
	0,							// WP_BRYAR_PISTOL
	BLASTER_ALT_SPREAD,			// WP_BLASTER
	0,							// WP_DISRUPTOR
	0,							// WP_BOWCASTER
	0,							// WP_REPEATER
	0,							// WP_DEMP2
	0,							// WP_FLECHETTE
	0,							// WP_ROCKET_LAUNCHER
	0,							// WP_THERMAL
	0,							// WP_TRIP_MINE
	0,							// WP_DET_PACK
	0,							// WP_STUN_BATON
	0,							// WP_MELEE
	0,							// WP_EMPLACED
	0,							// WP_BOT_LASER
	0,							// WP_TURRET
	0,							// WP_ATST_MAIN
	0,							// WP_ATST_SIDE
	0,							// WP_TIE_FIGHTER
	0,							// WP_RAPID_FIRE_CONC
	0,							// WP_BLASTER_PISTOL
};

constexpr int defaultMissileSize[] = {
	0,							// WP_NONE
	0,							// WP_SABER
	0,							// WP_BRYAR_PISTOL
	0,							// WP_BLASTER
	0,							// WP_DISRUPTOR
	BOWCASTER_SIZE,				// WP_BOWCASTER
	0,							// WP_REPEATER
	DEMP2_SIZE,					// WP_DEMP2
	FLECHETTE_SIZE,				// WP_FLECHETTE
	ROCKET_SIZE,				// WP_ROCKET_LAUNCHER
	0,							// WP_THERMAL
	LT_SIZE,					// WP_TRIP_MINE
	0,							// WP_DET_PACK
	0,							// WP_STUN_BATON
	0,							// WP_MELEE
	EMPLACED_SIZE,				// WP_EMPLACED
	0,							// WP_BOT_LASER
	0,							// WP_TURRET
	ATST_MAIN_SIZE,				// WP_ATST_MAIN
	ATST_SIDE_MAIN_SIZE,		// WP_ATST_SIDE
	0,							// WP_TIE_FIGHTER
	0,							// WP_RAPID_FIRE_CONC
	0							// WP_BLASTER_PISTOL
};

constexpr int defaultAltMissileSize[] = {
	0,							// WP_NONE
	0,							// WP_SABER
	0,							// WP_BRYAR_PISTOL
	0,							// WP_BLASTER
	0,							// WP_DISRUPTOR
	BOWCASTER_SIZE,				// WP_BOWCASTER
	0,							// WP_REPEATER
	DEMP2_SIZE,					// WP_DEMP2
	FLECHETTE_SIZE,				// WP_FLECHETTE
	ROCKET_SIZE,				// WP_ROCKET_LAUNCHER
	0,							// WP_THERMAL
	LT_SIZE,					// WP_TRIP_MINE
	0,							// WP_DET_PACK
	0,							// WP_STUN_BATON
	0,							// WP_MELEE
	EMPLACED_SIZE,				// WP_EMPLACED
	0,							// WP_BOT_LASER
	0,							// WP_TURRET
	ATST_MAIN_SIZE,				// WP_ATST_MAIN
	ATST_SIDE_ALT_ROCKET_SIZE,	// WP_ATST_SIDE
	0,							// WP_TIE_FIGHTER
	0,							// WP_RAPID_FIRE_CONC
	0							// WP_BLASTER_PISTOL
};

static const wpnParms_t wpnParams[] = {
	{ "ammo",					WPN_Ammo },
	{ "ammoicon",				WPN_AmmoIcon },
	{ "ammomax",				WPN_AmmoMax },
	{ "ammolowcount",			WPN_AmmoLowCnt },
	{ "ammotype",				WPN_AmmoType },
	{ "energypershot",			WPN_IntParse(&weaponData_t::energyPerShot, 0, 1000) },
	{ "fireTime",				WPN_IntParse(&weaponData_t::fireTime, 0, 10000) },
	{ "firingsound",			WPN_StringParse(&weaponData_t::firingSnd) },
	{ "altfiringsound",			WPN_StringParse(&weaponData_t::altFiringSnd) },
	{ "stopsound",				WPN_StringParse(&weaponData_t::stopSnd) },
	{ "chargesound",			WPN_StringParse(&weaponData_t::chargeSnd) },
	{ "altchargesound",			WPN_StringParse(&weaponData_t::altChargeSnd) },
	{ "selectsound",			WPN_StringParse(&weaponData_t::selectSnd) },
	{ "range",					WPN_IntParse(&weaponData_t::range, 0, 10000) },
	{ "weaponclass",			WPN_StringParse(&weaponData_t::classname) },
	{ "weaponicon",				WPN_StringParse(&weaponData_t::weaponIcon) },
	{ "weaponmodel",			WPN_StringParse(&weaponData_t::weaponMdl) },
	{ "weapontype",				WPN_WeaponType },
	{ "altenergypershot",		WPN_IntParse(&weaponData_t::altEnergyPerShot, 0, 1000) },
	{ "altfireTime",			WPN_IntParse(&weaponData_t::altFireTime, 0, 10000) },
	{ "altrange",				WPN_IntParse(&weaponData_t::altRange, 0, 10000) },
	{ "barrelcount",			WPN_IntParse(&weaponData_t::numBarrels, 0, 4) },
	{ "missileModel",			WPN_StringParse(&weaponData_t::missileMdl) },
	{ "altmissileModel", 		WPN_StringParse(&weaponData_t::alt_missileMdl) },
	{ "missileSound",			WPN_StringParse(&weaponData_t::missileSound) },
	{ "altmissileSound", 		WPN_StringParse(&weaponData_t::alt_missileSound) },
	{ "missileLight",			WPN_FloatParse(&weaponData_t::missileDlight, 0, 255) },
	{ "altmissileLight", 		WPN_FloatParse(&weaponData_t::alt_missileDlight, 0, 255) },
	{ "missileLightColor",		WPN_ColorParse(&weaponData_t::missileDlightColor) },
	{ "altmissileLightColor",	WPN_ColorParse(&weaponData_t::alt_missileDlightColor) },
	{ "missileFuncName",		WPN_FuncNameParse(&weaponData_t::func) },
	{ "altmissileFuncName",		WPN_FuncNameParse(&weaponData_t::altfunc) },
	{ "missileHitSound",		WPN_StringParse(&weaponData_t::missileHitSound) },
	{ "altmissileHitSound",		WPN_StringParse(&weaponData_t::altmissileHitSound) },
	{ "muzzleEffect",			WPN_EffectParse(&weaponData_t::mMuzzleEffect) },
	{ "altmuzzleEffect",		WPN_EffectParse(&weaponData_t::mAltMuzzleEffect) },

	// OPENJK NEW FIELDS
	{ "damage",					WPN_IntParse(&weaponData_t::damage) },
	{ "altdamage",				WPN_IntParse(&weaponData_t::altDamage) },
	{ "splashDamage",			WPN_IntParse(&weaponData_t::splashDamage) },
	{ "altSplashDamage",		WPN_IntParse(&weaponData_t::altSplashDamage) },
	{ "splashRadius",			WPN_FloatParse(&weaponData_t::splashRadius) },
	{ "altSplashRadius",		WPN_FloatParse(&weaponData_t::altSplashRadius) },
	{ "velocity",				WPN_IntParse(&weaponData_t::velocity) },
	{ "altVelocity",			WPN_IntParse(&weaponData_t::altVelocity) },
	{ "missileSize",			WPN_IntParse(&weaponData_t::missileSize) },
	{ "altMissileSize",			WPN_IntParse(&weaponData_t::altMissileSize) },
	{ "spread",					WPN_FloatParse(&weaponData_t::spread) },
	{ "altSpread",				WPN_FloatParse(&weaponData_t::altSpread) },

	// Old legacy files contain these, so we skip them to shut up warnings
	{ "firingforce",			WPN_FuncSkip },
	{ "chargeforce",			WPN_FuncSkip },
	{ "altchargeforce",			WPN_FuncSkip },
	{ "selectforce",			WPN_FuncSkip },
};

constexpr size_t numWpnParms = ARRAY_LEN(wpnParams);

static void WPN_FuncSkip(const char **holdBuf)
{
	SkipRestOfLine(holdBuf);
}

static void WPN_WeaponType(const char **holdBuf)
{
	const char *tokenStr;

	if (COM_ParseString(holdBuf, &tokenStr))
	{
		return;
	}

#define WEAPON_TYPE(x) \
	if (!Q_stricmp(tokenStr, #x)) \
	{ \
		wpnParms.weaponNum = x; \
		return; \
	}

	WEAPON_TYPE(WP_NONE)
	WEAPON_TYPE(WP_SABER)
	WEAPON_TYPE(WP_BRYAR_PISTOL)
	WEAPON_TYPE(WP_BLASTER)
	WEAPON_TYPE(WP_DISRUPTOR)
	WEAPON_TYPE(WP_BOWCASTER)
	WEAPON_TYPE(WP_REPEATER)
	WEAPON_TYPE(WP_DEMP2)
	WEAPON_TYPE(WP_FLECHETTE)
	WEAPON_TYPE(WP_ROCKET_LAUNCHER)
	WEAPON_TYPE(WP_THERMAL)
	WEAPON_TYPE(WP_TRIP_MINE)
	WEAPON_TYPE(WP_DET_PACK)
	WEAPON_TYPE(WP_STUN_BATON)
	WEAPON_TYPE(WP_MELEE)
	WEAPON_TYPE(WP_EMPLACED_GUN)
	WEAPON_TYPE(WP_BOT_LASER)
	WEAPON_TYPE(WP_TURRET)
	WEAPON_TYPE(WP_ATST_MAIN)
	WEAPON_TYPE(WP_ATST_SIDE)
	WEAPON_TYPE(WP_TIE_FIGHTER)
	WEAPON_TYPE(WP_RAPID_FIRE_CONC)
	WEAPON_TYPE(WP_BLASTER_PISTOL)

	wpnParms.weaponNum = 0;
	gi.Printf(S_COLOR_YELLOW"WARNING: bad weapontype in external weapon data '%s'\n", tokenStr);
}

static void WPN_AmmoType(const char **holdBuf)
{
	int tokenInt;

	if (COM_ParseInt(holdBuf, &tokenInt))
	{
		SkipRestOfLine(holdBuf);
		return;
	}

	if (tokenInt < AMMO_NONE || tokenInt >= AMMO_MAX)
	{
		gi.Printf(S_COLOR_YELLOW"WARNING: bad Ammotype in external weapon data '%d'\n", tokenInt);
		return;
	}

	weaponData[wpnParms.weaponNum].ammoIndex = tokenInt;
}

static void WPN_AmmoLowCnt(const char **holdBuf)
{
	int tokenInt;

	if (COM_ParseInt(holdBuf, &tokenInt))
	{
		SkipRestOfLine(holdBuf);
		return;
	}

	if (tokenInt < 0 || tokenInt > 100)
	{
		gi.Printf(S_COLOR_YELLOW"WARNING: bad Ammolowcount in external weapon data '%d'\n", tokenInt);
		return;
	}

	weaponData[wpnParms.weaponNum].ammoLow = tokenInt;
}

static void WPN_Ammo(const char **holdBuf)
{
	const char *tokenStr;

	if (COM_ParseString(holdBuf, &tokenStr))
	{
		return;
	}

#define AMMO_TYPE(x) \
	if (!Q_stricmp(tokenStr, #x)) \
	{ \
		wpnParms.ammoNum = x; \
		return; \
	}

	AMMO_TYPE(AMMO_NONE)
	AMMO_TYPE(AMMO_FORCE)
	AMMO_TYPE(AMMO_BLASTER)
	AMMO_TYPE(AMMO_POWERCELL)
	AMMO_TYPE(AMMO_METAL_BOLTS)
	AMMO_TYPE(AMMO_ROCKETS)
	AMMO_TYPE(AMMO_EMPLACED)
	AMMO_TYPE(AMMO_THERMAL)
	AMMO_TYPE(AMMO_TRIPMINE)
	AMMO_TYPE(AMMO_DETPACK)

	gi.Printf(S_COLOR_YELLOW"WARNING: bad ammotype in external weapon data '%s'\n", tokenStr);
	wpnParms.ammoNum = 0;
}

static void WPN_AmmoIcon(const char **holdBuf)
{
	const char *tokenStr;

	if (COM_ParseString(holdBuf, &tokenStr))
	{
		return;
	}

	int len = strlen(tokenStr) + 1;

	if (len > 64)
	{
		len = 64;
		gi.Printf(S_COLOR_YELLOW"WARNING: ammoicon too long in external WEAPONS.DAT '%s'\n", tokenStr);
	}

	Q_strncpyz(ammoData[wpnParms.ammoNum].icon,tokenStr,len);
}

static void WPN_AmmoMax(const char **holdBuf)
{
	int tokenInt;

	if (COM_ParseInt(holdBuf,&tokenInt))
	{
		SkipRestOfLine(holdBuf);
		return;
	}

	if (tokenInt < 0 || tokenInt > 1000)
	{
		gi.Printf(S_COLOR_YELLOW"WARNING: bad Ammo Max in external weapon data '%d'\n", tokenInt);
		return;
	}
	ammoData[wpnParms.ammoNum].max = tokenInt;
}

static void WP_ParseWeaponParms(const char **holdBuf)
{
	const char *token;
	size_t i;

	while (holdBuf)
	{
		token = COM_ParseExt(holdBuf, qtrue);

		if (!Q_stricmp( token, "}"))	// End of data for this weapon
		{
			break;
		}

		// Loop through possible parameters
		for (i = 0; i< numWpnParms; ++i)
		{
			if (!Q_stricmp(token, wpnParams[i].parmName))
			{
				wpnParams[i].func(holdBuf);
				break;
			}
		}

		if (i < numWpnParms)	// Find parameter???
		{
			continue;
		}

		Com_Printf(S_COLOR_YELLOW "WARNING: bad parameter in external weapon data '%s'\n", token); // errors are far too serious for me
	}
}

static void WP_ParseParms(const char *buffer)
{
	const char	*holdBuf;
	const char	*token;

	holdBuf = buffer;
	COM_BeginParseSession();

	while (holdBuf)
	{
		token = COM_ParseExt(&holdBuf, qtrue);

		if (!Q_stricmp(token, "{"))
		{
			WP_ParseWeaponParms(&holdBuf);
		}
	}

	COM_EndParseSession();
}

void WP_LoadWeaponParms (void)
{
	char *buffer;

	const auto improvedWeapons = gi.cvar("cg_improvedWeapons", "1", CVAR_ARCHIVE);

	gi.FS_ReadFile(improvedWeapons->integer ? "ext_data/weapons_new.dat" : "ext_data/weapons.dat", (void **)&buffer);

	// initialise the data area
	memset(weaponData, 0, sizeof(weaponData));

	// put in the default values, because backwards compatibility is awesome!
	for (int i = 0; i < WP_NUM_WEAPONS; i++)
	{
		weaponData[i].damage = defaultDamage[i];
		weaponData[i].altDamage = defaultAltDamage[i];
		weaponData[i].splashDamage = defaultSplashDamage[i];
		weaponData[i].altSplashDamage = defaultAltSplashDamage[i];
		weaponData[i].splashRadius = defaultSplashRadius[i];
		weaponData[i].altSplashRadius = defaultAltSplashRadius[i];
		weaponData[i].velocity = defaultVelocity[i];
		weaponData[i].altVelocity = defaultAltVelocity[i];
		weaponData[i].missileSize = defaultMissileSize[i];
		weaponData[i].altMissileSize = defaultAltMissileSize[i];
		weaponData[i].spread = defaultSpread[i];
		weaponData[i].altSpread = defaultAltSpread[i];
		for (size_t j = 0; j < ARRAY_LEN(weaponData[i].npcDamages); ++j)
		{
			weaponData[i].npcDamages[j] = defaultNpcDamages[i][j];
		}
		for (size_t j = 0; j < ARRAY_LEN(weaponData[i].npcAltDamages); ++j)
		{
			weaponData[i].npcAltDamages[j] = defaultNpcAltDamages[i][j];
		}
	}

	WP_ParseParms(buffer);

	gi.FS_FreeFile(buffer);
}

// vim: set noexpandtab tabstop=4 shiftwidth=4 :
