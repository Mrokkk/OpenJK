layoutDef
{
    type                    vert
    pos                     $submenu_posx $submenu_posy

    itemDef : submenu_bind_button
    {
        name                force2
        group               forcecontrols
        text                @MENUS0_FORCE_PUSH
        descText            @MENUS1_USES_FORCE_PUSH_ABILITY
        cvar                "force_throw"
    }

    itemDef : submenu_bind_button
    {
        name                force3
        group               forcecontrols
        text                @MENUS0_FORCE_PULL
        descText            @MENUS1_USES_FORCE_PULL_ABILITY
        cvar                "force_pull"
    }

    itemDef : submenu_bind_button
    {
        name                force4
        group               forcecontrols
        text                @MENUS0_FORCE_SPEED
        descText            @MENUS1_USES_FORCE_SPEED_ABILITY
        cvar                "force_speed"
    }

    itemDef : submenu_bind_button
    {
        name                force5
        group               forcecontrols
        text                @MENUS0_FORCE_HEAL
        descText            @MENUS1_USES_FORCE_HEAL_ABILITY
        cvar                "force_heal"
    }

    itemDef : submenu_bind_button
    {
        name                force6
        group               forcecontrols
        text                @MENUS0_FORCE_GRIP
        descText            @MENUS2_USES_FORCE_GRIP_ABILITY
        cvar                "+force_grip"
    }

    itemDef : submenu_bind_button
    {
        name                force7
        group               forcecontrols
        text                @MENUS0_FORCE_MINDTRICK
        descText            @MENUS2_USES_JEDI_MIND_TRICK
        cvar                "force_distract"
    }

    itemDef : submenu_bind_button
    {
        name                force8
        group               forcecontrols
        text                @MENUS0_FORCE_LIGHTNING
        descText            @MENUS2_USES_FORCE_LIGHTNING
        cvar                "+force_lightning"
    }

    itemDef : submenu_separator
    {
    }

    itemDef : submenu_bind_button
    {
        name                forcekeys
        group               forcecontrols
        text                @MENUS1_USE_FORCE_POWER
        descText            @MENUS1_USES_CURRENTLY_SELECTED
        cvar                "+useforce"
    }

    itemDef : submenu_bind_button
    {
        name                forcekeys
        group               forcecontrols
        text                @MENUS1_FORCE_NEXT
        descText            @MENUS1_SELECTS_NEXT_AVAILABLE
        cvar                "forcenext"
    }

    itemDef : submenu_bind_button
    {
        name                forcekeys
        group               forcecontrols
        text                @MENUS1_FORCE_PREVIOUS
        descText            @MENUS1_SELECTS_PREVIOUS_AVAILABLE
        cvar                "forceprev"
    }
}
