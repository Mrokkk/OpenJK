itemDef
{
    name                vidrestart_background
    group               vidrestart
    style               WINDOW_STYLE_SHADER
    rect                300 165 310 256
    background          "gfx/menus/menu_boxred"
    forecolor           1 1 1 0.5
    visible             0
    decoration
}

itemDef
{
    name                vidrestart_text1
    group               vidrestart
    text                @MENUS3_INGAME_DEFAULT
    text2               @MENUS3_INGAME_DEFAULT2
    rect                305 230 290 20
    textalign           ITEM_ALIGN_CENTER
    text2aligny         18
    textalignx          145
    font                2
    textscale           1
    forecolor           1 1 0 1
    visible             0
    decoration
}

itemDef
{
    name                vidrestart_text2
    group               vidrestart
    text                @MENUS0_VID_RESTART3
    rect                305 300 290 20
    textalign           ITEM_ALIGN_CENTER
    textalignx          145
    font                2
    textscale           1
    forecolor           1 1 0 1
    visible             0
}

itemDef
{
    name                vidrestart_yes
    group               vidrestart
    text                @MENUS0_YES
    type                ITEM_TYPE_BUTTON
    style               WINDOW_STYLE_EMPTY
    rect                467 386 120 32
    font                2
    textscale           1
    textalign           ITEM_ALIGN_CENTER
    textalignx          60
    textaligny          0
    descText            @MENUS0_APPLY_CHANGES_AND_THEN
    forecolor           0.65 0.65 1 1
    visible             -1
    background          "gfx/menus/menu_buttonback"
    action
    {
        close           all
        uiScript        updatevideosetup
    }
}

itemDef
{
    name                vidrestart_no
    group               vidrestart
    text                @MENUS0_NO
    type                ITEM_TYPE_BUTTON
    style               WINDOW_STYLE_EMPTY
    rect                305 386 120 32
    font                2
    textscale           1
    textalign           ITEM_ALIGN_CENTER
    textalignx          60
    textaligny          -1
    descText            @MENUS0_DO_NOT_APPLY_CHANGES
    forecolor           0.65 0.65 1 1
    visible             0
    background          "gfx/menus/menu_buttonback"
    action
    {
        show            setup_background
        showsubmenu     video
        show            applyChanges
    }
}
