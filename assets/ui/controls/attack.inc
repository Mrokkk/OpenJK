layoutDef
{
    type                    vert
    pos                     $submenu_posx $submenu_posy

    itemDef : submenu_bind_button
    {
        name                attacklook1
        group               attackcontrols
        text                @MENUS1_ATTACK
        descText            @MENUS1_ATTACKS_WITH_READIED
        cvar                "+attack"
    }

    itemDef : submenu_bind_button
    {
        name                attacklook2
        group               attackcontrols
        text                @MENUS1_ALT_ATTACK
        descText            @MENUS1_ATTACKS_WITH_ALTERNATE
        cvar                "+altattack"
    }

    itemDef : submenu_bind_button
    {
        name                attacksaber
        group               attackcontrols
        text                @MENUS1_LIGHTSABER_STYLE
        descText            @MENUS1_CYCLES_BETWEEN_AVAILABLE
        cvar                "saberAttackCycle"
    }

    itemDef : submenu_separator
    {
    }

    itemDef : submenu_bind_button
    {
        name                attacklook3
        group               attackcontrols
        text                @MENUS1_USE
        descText            @MENUS1_ACTIVATES_WORLD_DEVICES
        cvar                "+use"
    }

    itemDef : submenu_separator
    {
    }

    itemDef : submenu_bind_button
    {
        name                attacklook4
        group               attackcontrols
        text                @MENUS0_LOOK_UP
        descText            @MENUS1_TILTS_VIEW_UPWARDS
        cvar                "+lookup"
    }

    itemDef : submenu_bind_button
    {
        name                attacklook5
        group               attackcontrols
        text                @MENUS0_LOOK_DOWN
        descText            @MENUS1_TILTS_VIEW_DOWNWARDS
        cvar                "+lookdown"
    }

    itemDef : submenu_bind_button
    {
        name                attacklook
        group               attackcontrols
        text                @MENUS1_MOUSE_LOOK
        descText            @MENUS1_IF_HELD_ALLOWS_PLAYER
        cvar                "+mlook"
    }

    itemDef : submenu_bind_button
    {
        name                attacklook
        group               attackcontrols
        text                @MENUS1_CENTERVIEW
        descText            @MENUS1_RETURNS_VIEW_TO_HORIZONTAL
        cvar                "centerview"
    }

    itemDef : submenu_separator
    {
    }

    itemDef : submenu_bind_button
    {
        name                attacklook
        group               attackcontrols
        text                @MENUS0_3RD_PERSON
        descText            @MENUS1_CHANGES_VIEW_BETWEEN
        cvar                "cg_thirdperson !"
    }
}
