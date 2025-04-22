itemDef
{
    name                loadgame_title
    group               none
    style               WINDOW_STYLE_SHADER
    background          "gfx/menus/menu_blendbox"
    text                @MENUS1_LOAD_GAME
    rect                150 145 450 16
    font                3
    textscale           0.7
    textalign           ITEM_ALIGN_CENTER
    textalignx          225
    textaligny          -2
    forecolor           1 1 1 1
    visible             1
    decoration
}

itemDef
{
    name                loadgamedesc
    group               loadgame
    type                ITEM_TYPE_EDITFIELD
    style               WINDOW_STYLE_EMPTY
    flag                WINDOW_INACTIVE
    text                @MENUS1_DESC
    cvar                ui_gameDesc
    maxChars            60
    rect                150 165 450 16
    textalign           ITEM_ALIGN_LEFT
    textalignx          0
    textaligny          -4
    font                2
    textscale           .8
    outlinecolor        1 .5 .5 .5
    backcolor           0 0 0 0
    forecolor           1 1 1 1
    border              0
    bordercolor         0 0 0 0
    visible             1
}

itemDef
{
    name                loadgamelist
    group               loadscreen
    rect                145 190 285 230
    type                ITEM_TYPE_LISTBOX
    style               WINDOW_STYLE_FILLED
    elementwidth        120
    elementheight       16
    font                2
    textaligny          2
    textscale           0.7
    border              1
    bordersize          1
    bordercolor         .5 .5 .5 .5
    forecolor           0.65 0.65 1 1
    backcolor           0 0 .5 .25
    outlinecolor        .5 .5 .5 .5
    elementtype         LISTBOX_TEXT
    feeder              FEEDER_SAVEGAMES
    notselectable
    visible             1
    columns             2   2 35 150   155 25 100
    mouseEnter
    {
        setitemcolor    loadgamelist bordercolor .265 .824 .886 1
    }
    mouseExit
    {
        setitemcolor    loadgamelist bordercolor .5 .5 .5 .5
    }
    doubleclick
    {
        play            sound/interface/button1.wav
        uiScript        loadgame
    }
}

itemDef
{
    name                loadgamepic
    group               loadscreen
    style               WINDOW_STYLE_EMPTY
    ownerdraw           236 // UI_ALLMAPS_SELECTION
    font                2
    textscale           .8
    forecolor           1 1 1 1
    rect                435 190 180 135
    border              1
    bordercolor         .265 .824 .886 .25
    visible             1
}

itemDef
{
    name                loadgameaction
    group               actionbutton
    text                @MENUS1_LOAD_GAME
    descText            @MENUS1_LOAD_CHOSEN_GAME
    type                ITEM_TYPE_BUTTON
    style               WINDOW_STYLE_EMPTY
    rect                440 350 175 25
    font                3
    textscale           0.8
    textalignx          175
    textaligny          1
    textalign           ITEM_ALIGN_RIGHT
    textstyle           3
    forecolor           0.65 0.65 1 1
    visible             1
    cvarTest            ui_SelectionOK
    enableCvar          { "1" }
    glow                "gfx/menus/menu_blendbox2"
    action
    {
        hide            glow
        uiScript        loadgame
    }
}

itemDef
{
    name                deletegamebutton
    group               actionbutton
    text                @MENUS1_DELETE_GAME
    descText            @MENUS1_DELETE_CHOSEN_GAME
    type                ITEM_TYPE_BUTTON
    style               WINDOW_STYLE_EMPTY
    rect                440 375 175 25
    font                3
    textscale           0.8
    textalignx          175
    textaligny          1
    textalign           ITEM_ALIGN_RIGHT
    textstyle           3
    forecolor           0.65 0.65 1 1
    visible             1
    cvarTest            ui_SelectionOK
    enableCvar          { "1" }
    glow                "gfx/menus/menu_blendbox2"
    action
    {
        hide            glow
        uiScript        deletegame
    }
}
