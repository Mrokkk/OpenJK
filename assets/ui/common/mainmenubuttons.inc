layoutDef
{
    type                        vert
    pos                         115 115

    layoutDef
    {
        type                    horiz

        itemDef : mainmenu_button
        {
            name                newgamebutton
            group               topbuttons
            text                @MENUS1_NEW
            descText            @MENUS1_START_A_NEW_GAME
            action
            {
                defer           VideoSetup  videowarningMenu
                close           all
                open            newgameMenu
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
                open            loadgameMenu
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
                open            controlsMenu
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
                defer           VideoSetup  videowarningMenu
                close           all
                open            setupMenu
            }
        }
    }

    itemDef : header_line
    {
    }
}

itemDef
{
    name                saberbutton
    group               othermain
    type                ITEM_TYPE_MULTI
    style               WINDOW_STYLE_EMPTY
    rect                51 284 52 60
    font                2
    textscale           1
    textaligny          0
    textalign           ITEM_ALIGN_CENTER
    textalignx          46
    backcolor           0 0 0 0
    forecolor           0.65 0.65 1 1
    visible             1
    cvar                "ui_saber_color"
    cvarFloatList
    {
        " "             0
        " "             1
    }
    clickSound          "sound/weapons/saber/saberon.mp3"
    mouseEnter
    {
        setitemcolor    saberhalo2  forecolor   0.7 0.7 0.7 1
    }
    mouseExit
    {
        setitemcolor    saberhalo2  forecolor   0.25 0.25 0.25 1
    }
    action
    {
        exec            "music music/mp/duel"
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
    clickSound          "sound/weapons/saber/saberoff.mp3"
    action
    {
        defer           VideoSetup  videowarningMenu
        close           all
        open            quitMenu
    }
}
