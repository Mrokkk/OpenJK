layoutDef
{
    type                    vert
    pos                     $submenu_posx $submenu_posy

    itemDef
    {
        name                gamma_text
        group               video2
        style               WINDOW_STYLE_SHADER
        rect                10 5 280 36
        background          "gfx/menus/greyscale"
        forecolor           1 1 1 1
        visible             0
        decoration
    }

    itemDef
    {
        name                bright_text
        group               video2
        text                @MENUS0_ADJUST_BRIGHTNESS_SLIDER
        text2               @MENUS0_THE_NUMBER_6_CAN_BARELY
        text2aligny         14
        textalignx          128
        font                2
        textscale           0.8
        rect                13 4 256 40
        textalign           ITEM_ALIGN_CENTER
        forecolor           0.7 0.7 0.7 1
        visible             0
        decoration
    }

    itemDef : submenu_slider
    {
        name                brightness
        group               video2
        type                ITEM_TYPE_SLIDER
        text                @MENUS0_VIDEO_BRIGHTNESS
        descText            @MENUS1_ADJUST_THE_BRIGHTNESS
        cvarfloat           "r_gamma" 1 .5 3
        textalignx          120
    }

    itemDef : submenu_onoff_button
    {
        name                dynamic_light
        group               video2
        text                @MENUS0_DYNAMIC_LIGHTS
        descText            @MENUS1_TOGGLE_TO_TURN_ON_MOVING
        cvar                "r_dynamiclight"
    }

    itemDef : submenu_onoff_button
    {
        name                dynamic_glow
        group               video2
        text                @OPENJO_DYNAMIC_GLOW
        descText            @OPENJO_DYNAMIC_GLOW_DESC
        cvar                "r_dynamicGlow"
    }

    itemDef : submenu_multi_button
    {
        name                shadows
        group               video2
        text                @MENUS3_SHADOWS
        descText            @MENUS3_SHADOWS_DESC
        cvar                "cg_shadows"
        cvarFloatList
        {
            "None"          0
            "Simple"        1
            "Volumetric"    2
            //"Projected"   3
        }
    }

    itemDef : submenu_onoff_button
    {
        name                wall_marks
        group               video2
        text                @MENUS0_WALL_MARKS
        descText            @MENUS1_TOGGLE_TO_DISPLAY_SCORCH
        cvar                "cg_marks"
    }

    itemDef : submenu_onoff_button
    {
        name                video_mode
        group               video2
        text                @MENUS0_ANISOTROPIC_FILTERING
        descText            @MENUS1_TOGGLE_ADVANCED_TEXTURE
        cvarTest            r_ext_texture_filter_anisotropic_avail
        hideCvar            { 0 }
        cvar                r_ext_texture_filter_anisotropic
    }

    itemDef : submenu_onoff_button
    {
        name                light_flares
        group               video2
        text                @MENUS0_LIGHT_FLARES
        descText            @MENUS1_TOGGLE_TO_SHOW_HALOS
        cvar                "r_flares"
    }

    itemDef : submenu_base_button
    {
        name                advancedvideo
        group               video2
        type                ITEM_TYPE_BUTTON
        text                @MENUS2_SHOW_DRIVER_INFO
        descText            @MENUS2_SHOW_ADVANCED_INFORMATION
        rect                50 0 200 20
        textalign           ITEM_ALIGN_CENTER
        textstyle           3
        textalignx          100
        forecolor           0.65 0.65 1 1
        action
        {
            open            videodriverMenu
        }
    }
}
