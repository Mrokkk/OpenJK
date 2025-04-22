itemDef scheme
{
    name                mainmenu_button
    style               WINDOW_STYLE_EMPTY
    type                ITEM_TYPE_BUTTON
    rect                0 0 130 24
    textaligny          0
    font                3
    textscale           0.9
    textalign           ITEM_ALIGN_CENTER
    textstyle           3
    textalignx          65
    forecolor           0.65 0.65 1 1
    visible             1
    glow                "gfx/menus/menu_buttonback"
}

itemDef scheme
{
    name                submenu_base_button
    rect                0 0 300 20
    textalign           ITEM_ALIGN_RIGHT
    textalignx          151
    textaligny          -2
    font                2
    textscale           0.8
    forecolor           1 1 1 1
    visible             0
    glow                "gfx/menus/menu_blendbox"
}

itemDef scheme : submenu_base_button
{
    name                submenu_multi_button
    type                ITEM_TYPE_MULTI
}

itemDef scheme : submenu_base_button
{
    name                submenu_onoff_button
    type                ITEM_TYPE_ONOFF
}

itemDef scheme : submenu_base_button
{
    name                submenu_yesno_button
    type                ITEM_TYPE_YESNO
}

itemDef scheme : submenu_base_button
{
    name                submenu_bind_button
    type                ITEM_TYPE_BIND
    mouseenter
    {
        show            keybindstatus
    }
    mouseexit
    {
        hide            keybindstatus
    }
}

itemDef scheme : submenu_base_button
{
    name                submenu_slider
    type                ITEM_TYPE_SLIDER
}

itemDef scheme
{
    name                submenu_separator
    rect                0 0 300 20
    visible             1
    decoration
}

itemDef scheme
{
    name                submenu_title
    style               WINDOW_STYLE_SHADER
    background          "gfx/menus/menu_blendbox"
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

itemDef scheme
{
    name                submenu_background
    style               WINDOW_STYLE_SHADER
    rect                300 165 310 256
    background          "gfx/menus/menu_box_mp"
    forecolor           1 1 1 1
    visible             0
    decoration
}

itemDef scheme
{
    name                header_line
    style               WINDOW_STYLE_SHADER
    rect                10 -3 500 4
    background          "gfx/menus/menu_line"
    forecolor           1 1 1 1
    visible             1
    decoration
}
