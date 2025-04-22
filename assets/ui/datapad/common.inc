itemDef
{
    name                datapad_background
    group               none
    style               WINDOW_STYLE_SHADER
    rect                0 0 640 480
    background          "*white"
    forecolor           0 0 0 1
    visible             1
    decoration
}

itemDef scheme
{
    name                datapad_button
    group               none
    style               WINDOW_STYLE_EMPTY
    type                ITEM_TYPE_BUTTON
    rect                0 0 95 25
    text                @MENUS1_RESUME
    descText            @MENUS1_RETURN_TO_GAME
    font                2
    textscale           1
    textalignx          48
    textalign           ITEM_ALIGN_CENTER
    forecolor           .509 .609 .847 1
    appearance_slot     0
    visible             1
}

itemDef scheme
{
    name                datapad_button_active
    group               none
    style               WINDOW_STYLE_EMPTY
    type                ITEM_TYPE_BUTTON
    rect                0 0 0 0
    font                2
    textscale           1
    textalignx          48
    textalign           ITEM_ALIGN_CENTER
    forecolor           1 1 1 1
    appearance_slot     1
    visible             1
}

itemDef
{
    name                prev_on
    group               none
    style               WINDOW_STYLE_SHADER
    rect                265 384 32 26
    background          "gfx/menus/dp_arrow_lon"
    forecolor           1 1 1 1
    visible             0
    decoration
}

itemDef
{
    name                prev_off
    group               none
    style               WINDOW_STYLE_SHADER
    rect                265 384 32 26
    background          "gfx/menus/dp_arrow_l"
    forecolor           1 1 1 1
    visible             0
    decoration
}

itemDef
{
    name                next_on
    group               none
    style               WINDOW_STYLE_SHADER
    rect                344 384 32 26
    background          "gfx/menus/dp_arrow_ron"
    forecolor           1 1 1 1
    visible             0
    decoration
}

itemDef
{
    name                next_off
    group               none
    style               WINDOW_STYLE_SHADER
    rect                344 384 32 26
    background          "gfx/menus/dp_arrow_r"
    forecolor           1 1 1 1
    visible             0
    decoration
}
