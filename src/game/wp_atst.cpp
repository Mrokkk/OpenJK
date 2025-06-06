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

// ATST Main
//---------------------------------------------------------
void WP_ATSTMainFire( gentity_t *ent )
//---------------------------------------------------------
{
	float vel = weaponData[WP_ATST_MAIN].velocity;

//	if ( ent->client && (ent->client->ps.eFlags & EF_IN_ATST ))
//	{
//		vel = 4500.0f;
//	}

	if ( !ent->s.number )
	{
		// player shoots faster
		vel *= 1.6f;
	}

	gentity_t	*missile = CreateMissile( wpMuzzle, wpFwd, vel, 10000, ent );

	missile->classname = "atst_main_proj";
	missile->s.weapon = WP_ATST_MAIN;

	missile->damage = weaponData[WP_ATST_MAIN].damage;
	missile->dflags = DAMAGE_DEATH_KNOCKBACK|DAMAGE_HEAVY_WEAP_CLASS;
	missile->methodOfDeath = MOD_ENERGY;
	missile->clipmask = MASK_SHOT | CONTENTS_LIGHTSABER;

	missile->owner = ent;

	VectorSet( missile->maxs, ATST_MAIN_SIZE, ATST_MAIN_SIZE, ATST_MAIN_SIZE );
	VectorScale( missile->maxs, -1, missile->mins );

}

// ATST Alt Side
//---------------------------------------------------------
void WP_ATSTSideAltFire( gentity_t *ent )
//---------------------------------------------------------
{
	float	vel = ATST_SIDE_ALT_NPC_VELOCITY;

	if ( ent->client && (ent->client->ps.eFlags & EF_IN_ATST ))
	{
		vel = weaponData[WP_ATST_SIDE].altVelocity;
	}

	gentity_t *missile = CreateMissile( wpMuzzle, wpFwd, vel, 10000, ent, qtrue );

	missile->classname = "atst_rocket";
	missile->s.weapon = WP_ATST_SIDE;

	missile->mass = 10;

	// Do the damages
	int damage = ent->NPC
		? NPC_Damage(weaponData[WP_ATST_SIDE].npcAltDamages, g_spskill->integer)
		: weaponData[WP_ATST_SIDE].altDamage;

	VectorCopy( wpFwd, missile->movedir );

	// Make it easier to hit things
	VectorSet( missile->maxs, ATST_SIDE_ALT_ROCKET_SIZE, ATST_SIDE_ALT_ROCKET_SIZE, ATST_SIDE_ALT_ROCKET_SIZE );
	VectorScale( missile->maxs, -1, missile->mins );

	missile->damage = damage;
	missile->dflags = DAMAGE_DEATH_KNOCKBACK | DAMAGE_HEAVY_WEAP_CLASS;
	missile->methodOfDeath = MOD_EXPLOSIVE;
	missile->splashMethodOfDeath = MOD_EXPLOSIVE_SPLASH;
	missile->clipmask = MASK_SHOT | CONTENTS_LIGHTSABER;

	// Scale damage down a bit if it is coming from an NPC
	missile->splashDamage = weaponData[WP_ATST_SIDE].altSplashDamage * ( ent->s.number == 0 ? 1.0f : ATST_SIDE_ALT_ROCKET_SPLASH_SCALE );
	missile->splashRadius = weaponData[WP_ATST_SIDE].altSplashRadius;

	// we don't want it to ever bounce
	missile->bounceCount = 0;
}

// ATST Side
//---------------------------------------------------------
void WP_ATSTSideFire( gentity_t *ent )
//---------------------------------------------------------
{
	gentity_t *missile = CreateMissile( wpMuzzle, wpFwd, weaponData[WP_ATST_SIDE].velocity, 10000, ent, qfalse );

	missile->classname = "atst_side_proj";
	missile->s.weapon = WP_ATST_SIDE;

	// Do the damages
	int damage = ent->NPC
		? NPC_Damage(weaponData[WP_ATST_SIDE].npcDamages, g_spskill->integer)
		: weaponData[WP_ATST_SIDE].damage;

	VectorSet( missile->maxs, ATST_SIDE_MAIN_SIZE, ATST_SIDE_MAIN_SIZE, ATST_SIDE_MAIN_SIZE );
	VectorScale( missile->maxs, -1, missile->mins );

	missile->damage = damage;
	missile->dflags = DAMAGE_DEATH_KNOCKBACK|DAMAGE_HEAVY_WEAP_CLASS;
	missile->methodOfDeath = MOD_ENERGY;
	missile->clipmask = MASK_SHOT | CONTENTS_LIGHTSABER;

	missile->splashDamage = weaponData[WP_ATST_SIDE].splashDamage * ( ent->s.number == 0 ? 1.0f : 0.6f );
	missile->splashRadius = weaponData[WP_ATST_SIDE].splashRadius;

	// we don't want it to bounce
	missile->bounceCount = 0;
}

// vim: set noexpandtab tabstop=4 shiftwidth=4 :
