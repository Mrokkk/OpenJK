layoutDef
{
    type                        vert
    pos                         115 115

    layoutDef
    {
        type                    horiz

        itemDef : mainmenu_button
        {
            name                savegamebutton
            group               topbuttons
            text                @MENUS1_SAVE
            descText            @MENUS1_SAVE_CURRENT_GAME
            action
            {
                defer           VideoSetup  videowarningMenu
                close           all
                open            ingamesaveMenu
            }
        }

        itemDef : mainmenu_button
        {
            name                loadgamebutton
            group               topbuttons
            text                @MENUS1_LOAD
            descText            @MENUS1_LOAD_A_SAVED_GAME
            action
            {
                defer           VideoSetup  videowarningMenu
                close           all
                open            ingameloadMenu
            }
        }

        itemDef : mainmenu_button
        {
            name                controlsbutton
            group               topbuttons
            text                @MENUS0_CONTROLS2
            descText            @MENUS0_CONFIGURE_GAME_CONTROLS
            action
            {
                defer           VideoSetup  videowarningMenu
                close           all
                open            ingameControlsMenu
            }
        }

        itemDef : mainmenu_button
        {
            name                setupbutton
            group               topbuttons
            text                @MENUS0_SETUP
            descText            @MENUS0_CONFIGURE_GAME_SETTINGS
            action
            {
                close           all
                open            ingameSetupMenu
            }
        }
    }

    itemDef : header_line
    {
    }
}

itemDef
{
    name                exitgamebutton
    group               othermain
    text                @MENUS0_EXIT
    descText            @MENUS1_JEDI_KNIGHT_II
    type                ITEM_TYPE_BUTTON
    style               WINDOW_STYLE_EMPTY
    rect                115 444 130 24
    font                3
    textscale           1
    textalign           ITEM_ALIGN_CENTER
    textstyle           3
    textalignx          65
    textaligny          -1
    forecolor           0.65 0.65 1 1
    visible             1
    glow                "gfx/menus/menu_buttonback"
    action
    {
        defer           VideoSetup  videowarningMenu
        close           all
        open            ingamequitMenu
    }
}

itemDef
{
    name                resume
    group               none
    style               WINDOW_STYLE_EMPTY
    type                ITEM_TYPE_BUTTON
    rect                495 444 130 24
    text                @MENUS1_RESUME
    descText            @MENUS1_RESUME_CURRENT_GAME
    font                3
    textscale           1
    textalign           ITEM_ALIGN_CENTER
    textstyle           3
    textalignx          65
    textaligny          -1
    forecolor           0.65 0.65 1 1
    visible             1
    glow                "gfx/menus/menu_buttonback"
    action
    {
        defer           VideoSetup  videowarningMenu
        uiScript        closeingame
    }
}
