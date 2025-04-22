itemDef
{
    name                modlist
    group               mods
    rect                306 184 296 200
    type                ITEM_TYPE_LISTBOX
    style               WINDOW_STYLE_FILLED
    elementwidth        120
    elementheight       16
    font                2
    textscale           1
    border              1
    bordersize          1
    bordercolor         .5 .5 .5 .5
    forecolor           0.65 0.65 1 1
    backcolor           0 0 .5 .25
    outlinecolor        .5 .5 .5 .5
    elementtype         LISTBOX_TEXT
    feeder              9
    notselectable
    visible             0
    columns             2   2 40 20   200 80 30
}

itemDef
{
    name                loadmod
    group               mods
    text                @MENUS1_LOAD_MOD
    descText            @MENUS1_LOAD_CHOSEN_MOD
    type                ITEM_TYPE_BUTTON
    style               WINDOW_STYLE_EMPTY
    rect                305 391 300 20
    textalign           ITEM_ALIGN_CENTER
    textalignx          150
    font                2
    textscale           0.8
    forecolor           0.65 0.65 1 1
    visible             0
    glow                "gfx/menus/menu_buttonback"
}
