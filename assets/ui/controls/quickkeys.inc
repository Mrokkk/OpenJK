layoutDef
{
    type                    vert
    pos                     $submenu_posx $submenu_posy

    itemDef : submenu_separator
    {
    }

    itemDef : submenu_bind_button
    {
        name                quickkeys1
        group               quickcontrols
        text                @MENUS3_DATAPAD
        descText            @MENUS2_CHECK_DATAPAD_FOR_MISSION
        cvar                "datapad"
    }

    itemDef : submenu_separator
    {
    }

    itemDef : submenu_bind_button
    {
        name                quickkeys
        group               quickcontrols
        text                @MENUS1_SAVE_MENU
        descText            @MENUS2_BRINGS_UP_SAVE_GAME_MENU
        cvar                "uimenu ingamesavemenu"
    }

    itemDef : submenu_bind_button
    {
        name                quickkeys
        group               quickcontrols
        text                @MENUS1_LOAD_MENU
        descText            @MENUS2_BRINGS_UP_LOAD_GAME_MENU
        cvar                "uimenu ingameloadmenu"
    }

    itemDef : submenu_bind_button
    {
        name                quickkeys
        group               quickcontrols
        text                @MENUS1_INSTANT_SAVE
        descText            @MENUS2_AUTOMATICALLY_SAVES_GAME
        cvar                "save quik*"
    }

    itemDef : submenu_bind_button
    {
        name                quickkeys
        group               quickcontrols
        text                @MENUS1_INSTANT_LOAD
        descText            @MENUS2_AUTOMATICALLY_LOADS_GAME
        cvar                "load quik"
    }
}
