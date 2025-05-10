layoutDef
{
    type                    vert
    pos                     $submenu_posx $submenu_posy

    itemDef : submenu_multi_button
    {
        name                video_mode
        group               video
        text                @MENUS0_VIDEO_MODE
        descText            @MENUS1_CHANGE_THE_DISPLAY_RESOLUTION
        cvarFloatList
        {
            "640x480"       3
            "800x600"       4
            "960x720"       5
            "1024x768"      6
            "1152x864"      7
            "1280x720"      8
            "1280x800"      9
            "1280x1024"     10
            "1368x768"      11
            "1400x1050"     12
            "1440x900"      13
            "1600x900"      14
            "1600x1200"     15
            "1680x1050"     16
            "1920x1080"     17
            "1920x1200"     18
            "2048x1152"     19
            "2048x1536"     20
            "2560x1440"     21
            "3840x2160"     22
            @OPENJO_NATIVE  -2
        }
        cvar                "ui_r_mode"
        action
        {
            uiScript        glCustom
            setcvar         ui_r_modified 1
            show            applyChanges
        }
    }

    itemDef : submenu_multi_button
    {
        name                color_depth
        group               video
        text                @MENUS0_COLOR_DEPTH
        descText            @MENUS1_CHANGE_THE_NUMBER_OF
        cvarFloatList
        {
            @MENUS0_DEFAULT 0
            @MENUS0_16_BIT  16
            @MENUS0_32_BIT  32
        }
        cvar                "ui_r_colorbits"
        action
        {
            uiScript        glCustom
            uiScript update "ui_r_colorbits"
            setcvar         ui_r_modified   1
            show            applyChanges
        }
    }

    itemDef : submenu_onoff_button
    {
        name                fullscreen
        group               video
        text                @MENUS0_FULL_SCREEN
        descText            @MENUS1_TOGGLE_BETWEEN_FULL_SCREEN
        cvar                "ui_r_fullscreen"
        action
        {
            uiScript        glCustom
            setcvar         ui_r_modified 1
            show            applyChanges
        }
    }

    itemDef : submenu_multi_button
    {
        name                geometric_detail
        group               video
        text                @MENUS0_GEOMETRIC_DETAIL
        descText            @MENUS1_ADJUST_THE_NUMBER_OF
        cvarFloatList
        {
            @MENUS0_LOW     2
            @MENUS0_MEDIUM  1
            @MENUS0_HIGH    0
        }
        cvar                "ui_r_lodbias"
        action
        {
            uiScript        glCustom
            uiScript update "ui_r_lodbias"
            setcvar         ui_r_modified 1
            show            applyChanges
        }
    }

    itemDef : submenu_multi_button
    {
        name                texture_detail
        group               video
        text                @MENUS0_TEXTURE_DETAIL
        descText            @MENUS1_SELECT_THE_RESOLUTION
        cvarFloatList
        {
            @MENUS0_LOW         3
            @MENUS0_MEDIUM      2
            @MENUS0_HIGH        1
            @MENUS0_VERY_HIGH   0
        }
        cvar                "ui_r_picmip"
        action
        {
            uiScript        glCustom
            setcvar         ui_r_modified 1
            show            applyChanges
        }
    }

    itemDef : submenu_multi_button
    {
        name                texture_quality
        group               video
        text                @MENUS0_TEXTURE_QUALITY
        descText            @MENUS1_SELECT_THE_NUMBER_OF
        cvarFloatList
        {
            @MENUS0_DEFAULT 0
            @MENUS0_16_BIT  16
            @MENUS0_32_BIT  32
        }
        cvar                "ui_r_texturebits"
        action
        {
            uiScript        glCustom
            setcvar         ui_r_modified 1
            show            applyChanges
        }
    }

    itemDef : submenu_multi_button
    {
        name                texture_filter
        group               video
        text                @MENUS0_TEXTURE_FILTER
        descText            @MENUS1_ADJUST_HOW_WELL_THE_TEXTURES
        cvarStrList
        {
            @MENUS1_BILINEAR    , "GL_LINEAR_MIPMAP_NEAREST" ,
            @MENUS1_TRILINEAR   , "GL_LINEAR_MIPMAP_LINEAR"
        }
        cvar                "ui_r_texturemode"
        action
        {
            uiScript        glCustom
            setcvar         ui_r_modified 1
            show            applyChanges
        }
    }

    itemDef : submenu_onoff_button
    {
        name                simple_shaders
        group               video
        text                @MENUS0_DETAILED_SHADERS
        descText            @MENUS1_HIDE_OR_UNHIDE_TEXTURES
        cvar                "ui_r_detailtextures"
        action
        {
            uiScript        glCustom
            setcvar         ui_r_modified 1
            show            applyChanges
        }
    }

    itemDef : submenu_multi_button
    {
        name                msaa
        group               video
        text                @OPENJO_ANTIALIASING
        descText            @OPENJO_MULTISAMPLE_ANTIALIASING
        cvar                "r_ext_multisample"
        cvarFloatList
        {
            @MENUS0_OFF     0
            "2x"            2
            "4x"            4
            "8x"            8
            "16x"           16
        }
        action
        {
            uiScript        glCustom
            setcvar         ui_r_modified 1
            show            applyChanges
        }
    }

    itemDef : submenu_onoff_button
    {
        name                compress_textures
        group               video
        text                @MENUS0_COMPRESSED_TEXTURES
        descText            @MENUS1_TAKE_ADVANTAGE_OF_3D
        cvar                "ui_r_ext_compress_textures"
        action
        {
            uiScript        glCustom
            setcvar         ui_r_modified 1
            show            applyChanges
        }
    }
}
