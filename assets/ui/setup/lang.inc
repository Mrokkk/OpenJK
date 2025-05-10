layoutDef
{
    type                    vert
    pos                     $submenu_posx $submenu_posy

    itemDef : submenu_multi_button
    {
        name                text
        group               lang
        text                @MENUS0_TEXT
        descText            @MENUS2_CHOOSE_THE_LANGUAGE_FOR
        cvarTest            ui_hidelang
        hideCvar            { 1 }
        cvar                "sp_language"
        cvarFloatList
        {
            "English"       0
            "Francais"      1
            "Deutsch"       2
            "Español"       7
        }
    }

    itemDef : submenu_multi_button
    {
        name                voice
        group               lang
        text                @MENUS1_VOICE
        cvarTest            com_demo
        hideCvar            { 1 }
        cvar                "s_language"
        cvarStrList
        {
            "English",      "english"
            "Francais"      "francais"
            "Deutsch"       "deutsch"
            "Español"       "espanol"
        }
        descText            @MENUS3_CHOOSE_THE_LANGUAGE_TO
    }

    itemDef : submenu_multi_button
    {
        name                voice
        group               lang
        text                @MENUS1_SUBTITLES
        descText            @MENUS3_TOGGLE_WHETHER_SUBTITLES
        cvar                "g_subtitles"
        cvarFloatList
        {
            @MENUS3_NONE            0
            @MENUS3_ALL_VOICEOVERS  1
            @MENUS3_IN_CINEMATICS   2
        }
    }
}
