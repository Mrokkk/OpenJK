layoutDef
{
    type                    vert
    pos                     $submenu_posx $submenu_posy

    itemDef : submenu_separator
    {
    }

    itemDef : submenu_yesno_button
    {
        name                other1
        group               othercontrols
        text                @MENUS0_ALWAYS_RUN
        descText            @MENUS1_WHEN_ON_PLAYER_ALWAYS
        cvar                "cl_run"
    }

    itemDef : submenu_multi_button
    {
        name                other2
        group               othercontrols
        text                @MENUS0_AUTO_SWITCH
        descText            @MENUS1_CHOOSE_WHETHER_TO_SWITCH
        cvar                "cg_autoswitch"
        cvarFloatList
        {
            @MENUS1_DON_T_SWITCH        0
            @MENUS1_BEST_SAFE_WEAPON    1
            @MENUS1_ALWAYS_BEST_WEAPON  2
        }
    }
}
