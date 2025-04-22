layoutDef
{
    type                    vert
    pos                     $submenu_posx $submenu_posy

    itemDef : submenu_bind_button
    {
        name                weapon1
        group               weaponcontrols
        text                @MENUS1_STUN_BATON_LIGHTSABER
        descText            @MENUS1_READIES_THE_STUN_BATON
        cvar                "weapon 1"
        textscale           0.75
        textaligny          0
    }

    itemDef : submenu_bind_button
    {
        name                weapon3
        group               weaponcontrols
        text                @MENUS1_PISTOL
        descText            @MENUS1_READIES_THE_BRYAR_BLASTER
        cvar                "weapon 2"
    }

    itemDef : submenu_bind_button
    {
        name                none
        group               weaponcontrols
        text                @MENUS1_RIFLE
        descText            @MENUS1_READIES_THE_E_11_BLASTER
        cvar                "weapon 3"
    }

    itemDef : submenu_bind_button
    {
        name                none
        group               weaponcontrols
        text                @MENUS1_DISRUPTOR_RIFLE
        descText            @MENUS1_READIES_THE_TENLOSS_DXR_6
        cvar                "weapon 4"
    }

    itemDef : submenu_bind_button
    {
        name                none
        group               weaponcontrols
        text                @MENUS0_BOWCASTER
        descText            @MENUS1_READIES_THE_WOOKIEE_BOWCASTER
        cvar                "weapon 5"
    }

    itemDef : submenu_bind_button
    {
        name                none
        group               weaponcontrols
        text                @MENUS1_HEAVY_REPEATER
        descText            @MENUS1_READIES_THE_IMPERIAL
        cvar                "weapon 6"
    }

    itemDef : submenu_bind_button
    {
        name                none
        group               weaponcontrols
        text                @MENUS1_DEMP_2
        descText            @MENUS1_READIES_THE_DEMP2_GUN
        cvar                "weapon 7"
    }

    itemDef : submenu_bind_button
    {
        name                none
        group               weaponcontrols
        text                @MENUS1_FLECHETTE
        descText            @MENUS1_READIES_THE_GOLAN_ARMS
        cvar                "weapon 8"
    }

    itemDef : submenu_bind_button
    {
        name                none
        group               weaponcontrols
        text                @MENUS1_MERR_SONN
        descText            @MENUS1_READIES_THE_MERR_SONN
        cvar                "weapon 9"
    }

    itemDef : submenu_bind_button
    {
        name                none
        group               weaponcontrols
        text                @MENUS1_THROWABLE_WEAPONS
        descText            @MENUS1_TOGGLES_BETWEEN_DETONATORS
        cvar                "weapon 10"
    }

    itemDef : submenu_bind_button
    {
        name                none
        group               weaponcontrols
        text                @MENUS1_NEXT_WEAPON
        descText            @MENUS1_SELECTS_THE_NEXT_WEAPON
        cvar                "weapnext"
    }

    itemDef : submenu_bind_button
    {
        name                none
        group               weaponcontrols
        text                @MENUS1_PREVIOUS_WEAPON
        descText            @MENUS1_SELECTS_THE_PREVIOUS
        cvar                "weapprev"
    }
}
