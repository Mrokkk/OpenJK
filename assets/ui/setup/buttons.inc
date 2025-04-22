layoutDef
{
    type                    vert
    pos                     120 171

    itemDef
    {
        name                video1menubutton
        group               leftbuttons
        text                @MENUS1_VIDEO
        type                ITEM_TYPE_BUTTON
        style               WINDOW_STYLE_EMPTY
        rect                0 0 170 25
        font                3
        textscale           0.9
        textalignx          170
        textaligny          0
        textstyle           3
        textalign           ITEM_ALIGN_RIGHT
        forecolor           0.65 0.65 1 1
        visible             1
        descText            @MENUS0_CONFIGURE_VIDEO_SETTINGS
        glow                "gfx/menus/menu_blendbox2"
        action
        {
            defer           VideoSetup  videowarningMenu
            uiScript        getvideosetup
            show            setup_background
            showsubmenu     video
            setactivebutton leftbuttons video1menubutton
        }
    }

    itemDef
    {
        name                video2menubutton
        group               leftbuttons
        text                @MENUS1_MORE_VIDEO
        type                ITEM_TYPE_BUTTON
        style               WINDOW_STYLE_EMPTY
        rect                0 0 170 25
        font                3
        textscale           0.9
        textalignx          170
        textaligny          0
        textalign           ITEM_ALIGN_RIGHT
        textstyle           3
        forecolor           0.65 0.65 1 1
        visible             1
        descText            @MENUS0_CONFIGUE_MORE_VIDEO_SETTINGS
        glow                "gfx/menus/menu_blendbox2"
        action
        {
            defer           VideoSetup  videowarningMenu
            show            setup_background
            showsubmenu     video2
            setactivebutton leftbuttons video2menubutton
        }
    }

    itemDef
    {
        name                soundmenubutton
        group               leftbuttons
        text                @MENUS1_SOUND
        type                ITEM_TYPE_BUTTON
        style               WINDOW_STYLE_EMPTY
        rect                0 0 170 25
        font                3
        textscale           0.9
        textalignx          170
        textaligny          0
        textalign           ITEM_ALIGN_RIGHT
        textstyle           3
        forecolor           0.65 0.65 1 1
        visible             1
        descText            @MENUS0_CONFIGURE_SOUND_SETTINGS
        glow                "gfx/menus/menu_blendbox2"
        action
        {
            defer           VideoSetup  videowarningMenu
            show            setup_background
            showsubmenu     sound
            setactivebutton leftbuttons soundmenubutton
        }
    }

    itemDef
    {
        name                gameoptionmenubutton
        group               leftbuttons
        text                @MENUS1_GAME_OPTIONS
        type                ITEM_TYPE_BUTTON
        style               WINDOW_STYLE_EMPTY
        rect                0 0 170 25
        font                3
        textscale           0.9
        textalignx          170
        textaligny          0
        textalign           ITEM_ALIGN_RIGHT
        textstyle           3
        forecolor           0.65 0.65 1 1
        visible             1
        descText            @MENUS0_CONFIGURE_GAME_OPTIONS
        glow                "gfx/menus/menu_blendbox2"
        action
        {
            defer           VideoSetup  videowarningMenu
            show            setup_background
            showsubmenu     options
            setactivebutton leftbuttons gameoptionmenubutton
        }
    }

    itemDef
    {
        name                langoptionmenubutton
        group               leftbuttons
        text                "Language"
        type                ITEM_TYPE_BUTTON
        style               WINDOW_STYLE_EMPTY
        rect                0 0 170 25
        font                3
        textscale           0.9
        textalignx          170
        textaligny          0
        textalign           ITEM_ALIGN_RIGHT
        textstyle           3
        forecolor           0.65 0.65 1 1
        visible             1
        descText            @MENUS0_CONFIGURE_GAME_OPTIONS
        glow                "gfx/menus/menu_blendbox2"
        action
        {
            defer           VideoSetup  videowarningMenu
            show            setup_background
            showsubmenu     lang
            setactivebutton leftbuttons langoptionmenubutton
        }
    }

    itemDef
    {
        name                otheroptions
        group               leftbuttons
        text                "Other"
        type                ITEM_TYPE_BUTTON
        style               WINDOW_STYLE_EMPTY
        rect                0 0 170 25
        font                3
        textscale           0.9
        textalignx          170
        textaligny          0
        textalign           ITEM_ALIGN_RIGHT
        textstyle           3
        forecolor           0.65 0.65 1 1
        visible             1
        descText            @MENUS0_CONFIGURE_GAME_OPTIONS
        glow                "gfx/menus/menu_blendbox2"
        action
        {
            defer           VideoSetup  videowarningMenu
            show            setup_background
            showsubmenu     other
            setactivebutton leftbuttons otheroptions
        }
    }

    itemDef
    {
        name                modsmenubutton
        group               leftbuttons
        text                @MENUS1_MODS
        type                ITEM_TYPE_BUTTON
        style               WINDOW_STYLE_EMPTY
        rect                0 0 170 25
        font                3
        textscale           0.9
        textalignx          170
        textaligny          0
        textalign           ITEM_ALIGN_RIGHT
        textstyle           3
        forecolor           0.65 0.65 1 1
        visible             1
        cvarTest            "cl_paused"
        hideCvar            { 1 }
        descText            @MENUS0_CONFIGURE_GAME_OPTIONS
        glow                "gfx/menus/menu_blendbox2"
        action
        {
            defer           VideoSetup  videowarningMenu
            show            setup_background
            showsubmenu     mods
            setactivebutton leftbuttons modsmenubutton
        }
    }

    itemDef
    {
        name                gamedefaultsmenubutton
        group               leftbuttons
        text                @MENUS1_DEFAULTS
        type                ITEM_TYPE_BUTTON
        style               WINDOW_STYLE_EMPTY
        rect                0 0 170 25
        font                3
        textscale           0.9
        textalignx          170
        textaligny          0
        textalign           ITEM_ALIGN_RIGHT
        textstyle           3
        forecolor           0.65 0.65 1 1
        visible             1
        descText            @MENUS0_RESTORE_DEFAULT_SETTINGS
        glow                "gfx/menus/menu_blendbox2"
        action
        {
            defer           VideoSetup  videowarningMenu
            show            setup_background
            showsubmenu     defaults
            setactivebutton leftbuttons gamedefaultsmenubutton
        }
    }

    itemDef
    {
        name                applyChanges
        group               none
        text                @MENUS0_APPLY_CHANGES
        type                ITEM_TYPE_BUTTON
        style               WINDOW_STYLE_EMPTY
        rect                0 0 170 25
        font                3
        textscale           0.9
        textalignx          170
        textaligny          0
        textalign           ITEM_ALIGN_RIGHT
        textstyle           3
        forecolor           1 0 0 1
        backcolor           0 0 1 0
        visible             0
        glow                "gfx/menus/menu_blendbox2"
        action
        {
            show            setup_background
            showsubmenu     vidrestart
            setfocus        vidrestart_no
        }
    }
}
