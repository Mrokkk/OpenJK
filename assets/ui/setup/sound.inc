layoutDef
{
    type                    vert
    pos                     $submenu_posx $submenu_posy

    itemDef : submenu_separator
    {
    }

    itemDef : submenu_slider
    {
        name                effects_volume
        group               sound
        text                @MENUS0_EFFECTS_VOLUME
        descText            @MENUS1_ADJUST_VOLUME_FOR_SOUND
        cvarfloat           "s_volume" 0 0 1
        textalignx          120
    }

    itemDef : submenu_slider
    {
        name                music_volume
        group               sound
        text                @MENUS0_MUSIC_VOLUME
        descText            @MENUS1_ADJUST_VOLUME_FOR_MUSIC
        cvarfloat           "s_musicvolume" 0 0 1
        textalignx          120
    }

    itemDef : submenu_slider
    {
        name                voice_volume
        group               sound
        text                @MENUS1_VOICE_VOLUME
        descText            @MENUS2_ADJUST_VOLUME_FOR_SPEECH
        cvarfloat           "s_volumevoice" 0 0 1
        textalignx          120
    }

    itemDef : submenu_separator
    {
    }

    itemDef : submenu_multi_button
    {
        name                sound_quality
        group               sound
        text                @MENUS0_SOUND_QUALITY
        descText            @MENUS2_TRADE_CLARITY_OF_SOUND
        cvar                "s_khz"
        cvarFloatList
        {
            @MENUS0_LOW         11
            @MENUS0_HIGH        22
            @MENUS0_VERY_HIGH   44
        }
        action
        {
            uiScript        update s_khz
        }
    }

    itemDef : submenu_separator
    {
    }

    itemDef : submenu_onoff_button
    {
        name                eax
        group               sound
        cvar                "s_UseOpenAL"
        text                @MENUS3_EAX
        descText            @MENUS3_EAX
        textalignx          120
        action
        {
            uiScript        update s_khz
        }
    }

    itemDef
    {
        name                eax_icon
        group               sound
        style               WINDOW_STYLE_SHADER
        rect                0 0 128 64
        background          "gfx/menus/eax"
        forecolor           1 1 1 1
        visible             1
        cvarTest            "s_UseOpenAL"
        hideCvar            { 0 }
        decoration
    }
}
