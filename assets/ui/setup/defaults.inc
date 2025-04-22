itemDef
{
    name                vidrestart_background
    group               defaults
    style               WINDOW_STYLE_SHADER
    rect                305 171 300 250
    background          "gfx/menus/menu_boxred"
    forecolor           1 1 1 0.5
    visible             0
    decoration
}

itemDef
{
    name                options
    group               defaults
    text                @MENUS0_WARNING
    rect                305 191 300 20
    textalign           ITEM_ALIGN_CENTER
    textalignx          150
    font                2
    textscale           1
    forecolor           1 1 0 1
    visible             0
    decoration
}

itemDef
{
    name                options
    group               defaults
    text                @MENUS3_INGAME_DEFAULT
    text2               @MENUS3_INGAME_DEFAULT2
    rect                305 231 300 20
    textalign           ITEM_ALIGN_CENTER
    textalignx          150
    text2aligny         20
    font                2
    textscale           1
    forecolor           1 1 0 1
    visible             0
    decoration
}

itemDef
{
    name                options
    group               defaults
    text                @MENUS0_VID_RESTART3
    rect                305 291 300 20
    textalign           ITEM_ALIGN_CENTER
    textalignx          150
    font                2
    textscale           1
    forecolor           1 1 0 1
    visible             0
    decoration
}

itemDef
{
    name                default_yes
    group               defaults
    text                @MENUS0_YES
    type                ITEM_TYPE_BUTTON
    style               WINDOW_STYLE_EMPTY
    rect                467 386 120 32
    font                2
    textscale           1
    textalign           ITEM_ALIGN_CENTER
    textstyle           3
    textalignx          60
    textaligny          0
    descText            @MENUS1_RESET_DEFAULT_VALUES
    forecolor           0.65 0.65 1 1
    visible             0
    glow                "gfx/menus/menu_buttonback"
    action
    {
        close           all
        uiscript        resetdefaults
    }
}

itemDef
{
    name                default_no
    group               defaults
    text                @MENUS0_NO
    type                ITEM_TYPE_BUTTON
    style               WINDOW_STYLE_EMPTY
    rect                305 386 120 32
    font                2
    textscale           1
    textalign           ITEM_ALIGN_CENTER
    textstyle           3
    textalignx          60
    textaligny          0
    descText            @MENUS1_NOT_RESET_DEFAULT_VALUES
    forecolor           0.65 0.65 1 1
    visible             0
    glow                "gfx/menus/menu_buttonback"
    action
    {
        show            video
        hide            applyChanges
        hide            video2
        hide            vidrestart
        hide            sound
        hide            options
        hide            lang
        hide            mods
        hide            defaults
        setfocus        graphics
        setactivebutton leftbuttons video1menubutton
    }
}
