layoutDef
{
    type                    vert
    pos                     $submenu_posx $submenu_posy

    itemDef : submenu_separator
    {
    }

    itemDef : submenu_yesno_button
    {
        name                mousejoystick1
        group               joycontrols
        text                @MENUS1_FREE_LOOK
        descText            @MENUS1_TOGGLE_TO_ALLOW_PLAYER
        cvar                "cl_freelook"
    }

    itemDef : submenu_slider
    {
        name                mousejoystick
        group               joycontrols
        text                @MENUS1_SENSITIVITY
        descText            @MENUS1_ADJUSTS_CHARACTER_REACTION
        cvarfloat           "sensitivity" 5 2 30
    }

    itemDef : submenu_yesno_button
    {
        name                mousejoystick
        group               joycontrols
        text                @MENUS1_INVERT_MOUSE
        descText            @MENUS1_TOGGLE_TO_TILT_VIEW_IN
        cvar                "ui_mousePitch"
        action
        {
            uiScript update ui_mousePitch
        }
    }

    itemDef : submenu_yesno_button
    {
        name                mousejoystick
        group               joycontrols
        text                @MENUS1_SMOOTH_MOUSE
        descText            @MENUS1_WHEN_TURNED_ON_MOUSE
        cvar                "m_filter"
    }

    itemDef : submenu_separator
    {
    }

    itemDef : submenu_yesno_button
    {
        name                mousejoystick
        group               joycontrols
        text                @MENUS1_ENABLE_JOYSTICK
        descText            @MENUS1_TURNED_ON_GAME_SEARCHES
        cvar                "in_joystick"
        action
        {
            exec            in_restart
        }
    }

    itemDef : submenu_slider
    {
        name                mousejoystick
        group               joycontrols
        text                @MENUS1_JOYSTICK_THRESHOLD
        descText            @MENUS1_ADJUSTS_THE_SIZE_OF_THE
        cvarfloat           "joy_threshold" .15 .05 .75
        cvarTest            "in_joystick"
        hideCvar            { 0 }
    }

    itemDef : submenu_yesno_button
    {
        name                mousejoystick
        group               joycontrols
        text                @MENUS1_X_AXIS_AS_BUTTONS
        descText            @MENUS1_WHEN_OFF_HORIZONTAL
        cvar                "joy_xbutton"
        cvarTest            "in_joystick"
        hideCvar            { 0 }
    }

    itemDef : submenu_yesno_button
    {
        name                mousejoystick
        group               joycontrols
        text                @MENUS1_Y_AXIS_AS_BUTTONS
        descText            @MENUS1_WHEN_OFF_VERTICAL_STICK
        cvar                "joy_ybutton"
        cvarTest            "in_joystick"
        hideCvar            { 0 }
    }
}
