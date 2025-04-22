itemDef
{
    name                frame_pic
    group               none
    style               WINDOW_STYLE_SHADER
    rect                0 0 $SCREEN_WIDTH $SCREEN_HEIGHT
    background          "gfx/menus/menu1"
    forecolor           1 1 1 1
    visible             1
    decoration
}

itemDef
{
    name                starwars
    group               none
    style               WINDOW_STYLE_SHADER
    rect                143 12 470 93
    background          "gfx/menus/menu4"
    forecolor           1 1 1 1
    visible             1
    decoration
}

itemDef
{
    name                saberglow
    group               saberblue
    style               WINDOW_STYLE_SHADER
    rect                30 0 90 480
    background          "gfx/menus/menu3"
    forecolor           0.8 0.8 0.8 1
    visible             1
    cvarTest            ui_saber_color
    hideCvar            { 1 }
    decoration
}

itemDef
{
    name                saberhalo
    group               saberblue
    style               WINDOW_STYLE_SHADER
    rect                -425 -185 1000 1000
    background          "gfx/menus/menu2"
    forecolor           0.5 0.5 0.5 1
    visible             1
    cvarTest            ui_saber_color
    hideCvar            { 1 }
    decoration
}

itemDef
{
    name                saberglow
    group               saberred
    style               WINDOW_STYLE_SHADER
    rect                30 0 90 480
    background          "gfx/menus/menu3r"
    forecolor           0.8 0.8 0.8 1
    cvarTest            ui_saber_color
    hideCvar            { 0 }
    visible             1
    decoration
}

itemDef
{
    name                saberhalo
    group               saberred
    style               WINDOW_STYLE_SHADER
    rect                -425 -185 1000 1000
    background          "gfx/menus/menu2r"
    forecolor           0.5 0.5 0.5 1
    cvarTest            ui_saber_color
    hideCvar            { 0 }
    visible             1
    decoration
}

itemDef
{
    name                logomodel
    group               none
    type                ITEM_TYPE_MODEL
    rect                -123 48 400 400
    model_angle         90
    model_rotation      3.5
    asset_model         "models/map_objects/bespin/jk2logo.md3"
    model_fovx          37
    model_fovy          34
    model_origin        100 100 100
    visible             1
    decoration
}

itemDef
{
    name                saberhalo2
    group               none
    style               WINDOW_STYLE_SHADER
    rect                -225 15 600 600
    background          "gfx/menus/menu2b"
    forecolor           0.25 0.25 0.25 1
    cvarTest            ui_saber_color
    hideCvar            { 1 }
    visible             1
    decoration
}

itemDef
{
    name                saberhalo2
    group               none
    style               WINDOW_STYLE_SHADER
    rect                -225 15 600 600
    background          "gfx/menus/menu2r"
    forecolor           0.25 0.25 0.25 1
    cvarTest            ui_saber_color
    hideCvar            { 0 }
    visible             1
    decoration
}
