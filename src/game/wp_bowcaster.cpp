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
#include "g_headers.h"

#include "b_local.h"
#include "g_local.h"
#include "wp_saber.h"
#include "w_local.h"
#include "g_functions.h"

//-------------------
//	Wookiee Bowcaster
//-------------------

//---------------------------------------------------------
static void WP_BowcasterMainFire( gentity_t *ent )
//---------------------------------------------------------
{
	int			count;
	float		vel, spread;
	vec3_t		angs, dir, start;
	gentity_t	*missile;

	int velocity	= weaponData[WP_BOWCASTER].velocity;
	int size		= weaponData[WP_BOWCASTER].missileSize;

	// Do the damages
	int damage = ent->NPC
		? NPC_Damage(weaponData[WP_BOWCASTER].npcDamages, g_spskill->integer)
		: weaponData[WP_BOWCASTER].damage;

	VectorCopy( wpMuzzle, start );
	WP_TraceSetStart( ent, start, vec3_origin, vec3_origin );//make sure our start point isn't on the other side of a wall

	count = ( level.time - ent->client->ps.weaponChargeTime ) / BOWCASTER_CHARGE_UNIT;

	if ( count < 1 )
	{
		count = 1;
	}
	else if ( count > 5 )
	{
		count = 5;
	}

	if ( !(count & 1 ))
	{
		// if we aren't odd, knock us down a level
		count--;
	}

//	if ( ent->client && ent->client->ps.powerups[PW_WEAPON_OVERCHARGE] > 0 && ent->client->ps.powerups[PW_WEAPON_OVERCHARGE] > cg.time )
//	{
//		// in overcharge mode, so doing double damage
//		damage *= 2;
//	}

	for ( int i = 0; i < count; i++ )
	{
		// create a range of different velocities
		vel = velocity * ( Q_flrand(-1.0f, 1.0f) * BOWCASTER_VEL_RANGE + 1.0f );

		vectoangles( wpFwd, angs );

		// add some slop to the fire direction
		spread = weaponData[WP_BOWCASTER].spread;
		angs[PITCH] += Q_flrand(-1.0f, 1.0f) * spread * 0.2f;
		angs[YAW]	+= ((i+0.5f) * spread - count * 0.5f * spread );
		if ( ent->NPC )
		{
			angs[PITCH] += ( Q_flrand(-1.0f, 1.0f) * (BLASTER_NPC_SPREAD+(6-ent->NPC->currentAim)*0.25f) );
			angs[YAW]	+= ( Q_flrand(-1.0f, 1.0f) * (BLASTER_NPC_SPREAD+(6-ent->NPC->currentAim)*0.25f) );
		}

		AngleVectors( angs, dir, NULL, NULL );

		missile = CreateMissile( start, dir, vel, 10000, ent );

		missile->classname = "bowcaster_proj";
		missile->s.weapon = WP_BOWCASTER;

		VectorSet( missile->maxs, size, size, size );
		VectorScale( missile->maxs, -1, missile->mins );

//		if ( ent->client && ent->client->ps.powerups[PW_WEAPON_OVERCHARGE] > 0 && ent->client->ps.powerups[PW_WEAPON_OVERCHARGE] > cg.time )
//		{
//			missile->flags |= FL_OVERCHARGED;
//		}

		missile->damage = damage;
		missile->dflags = DAMAGE_DEATH_KNOCKBACK;
		missile->methodOfDeath = MOD_BOWCASTER;
		missile->clipmask = MASK_SHOT | CONTENTS_LIGHTSABER;
		missile->splashDamage = weaponData[WP_BOWCASTER].splashDamage;
		missile->splashRadius = weaponData[WP_BOWCASTER].splashRadius;

		// we don't want it to bounce
		missile->bounceCount = 0;
		ent->client->sess.missionStats.shotsFired++;
	}
}

//---------------------------------------------------------
static void WP_BowcasterAltFire( gentity_t *ent )
//---------------------------------------------------------
{
	vec3_t	start;

	int velocity	= weaponData[WP_BOWCASTER].altVelocity;
	int size		= weaponData[WP_BOWCASTER].altMissileSize;

	// Do the damages
	int damage = ent->NPC
		? NPC_Damage(weaponData[WP_BOWCASTER].npcAltDamages, g_spskill->integer)
		: weaponData[WP_BOWCASTER].altDamage;

	VectorCopy( wpMuzzle, start );
	WP_TraceSetStart( ent, start, vec3_origin, vec3_origin );//make sure our start point isn't on the other side of a wall

	gentity_t *missile = CreateMissile( start, wpFwd, velocity, 10000, ent, qtrue );

	missile->classname = "bowcaster_alt_proj";
	missile->s.weapon = WP_BOWCASTER;

	VectorSet( missile->maxs, size, size, size );
	VectorScale( missile->maxs, -1, missile->mins );

//	if ( ent->client && ent->client->ps.powerups[PW_WEAPON_OVERCHARGE] > 0 && ent->client->ps.powerups[PW_WEAPON_OVERCHARGE] > cg.time )
//	{
//		// in overcharge mode, so doing double damage
//		missile->flags |= FL_OVERCHARGED;
//		damage *= 2;
//	}

	missile->s.eFlags |= EF_BOUNCE;
	missile->bounceCount = 3;

	missile->damage = damage;
	missile->dflags = DAMAGE_DEATH_KNOCKBACK;
	missile->methodOfDeath = MOD_BOWCASTER_ALT;
	missile->clipmask = MASK_SHOT | CONTENTS_LIGHTSABER;
	missile->splashDamage = weaponData[WP_BOWCASTER].splashDamage;
	missile->splashRadius = weaponData[WP_BOWCASTER].splashRadius;
}

//---------------------------------------------------------
void WP_FireBowcaster( gentity_t *ent, qboolean alt_fire )
//---------------------------------------------------------
{
	if ( alt_fire )
	{
		WP_BowcasterAltFire( ent );
	}
	else
	{
		WP_BowcasterMainFire( ent );
	}
}

// vim: set noexpandtab tabstop=4 shiftwidth=4 :
