layoutDef
{
    type                    vert
    pos                     $submenu_posx $submenu_posy

    layoutDef
    {
        type                    horiz

        itemDef : submenu_multi_button
        {
            name                draw_crosshair
            group               options
            text                @MENUS2_DRAW_CROSSHAIR
            descText            @MENUS2_TOGGLE_TO_SHOW_OR_HIDE
            cvar                "cg_drawcrosshair"
            cvarFloatList
            {
                @MENUS0_OFF     0
                " "             1
                " "             2
                " "             3
                " "             4
                " "             5
                " "             6
                " "             7
                " "             8
                " "             9
            }
        }

        // FIXME: define image multi
        itemDef
        {
            name                crosshairpic
            group               options
            style               WINDOW_STYLE_EMPTY
            ownerdraw           242 // UI_CROSSHAIR
            font                2
            textscale           .8
            forecolor           1 1 1 1
            rect                -144 0 20 20
            border              0
            visible             1
        }
    }

    itemDef : submenu_onoff_button
    {
        name                healthbars
        group               options
        text                @OPENJO_DRAW_HEALTH_BARS
        descText            @OPENJO_DRAW_HEALTH_BARS_DESC
        cvar                "cg_drawHealthBars"
    }

    itemDef : submenu_onoff_button
    {
        name                show_fps
        group               options
        text                @OPENJO_SHOW_FPS
        descText            @MENUS2_TOGGLE_TO_SHOW_OR_HIDE
        cvar                "cg_drawfps"
    }

    itemDef : submenu_onoff_button
    {
        name                identifytarget
        group               options
        text                @MENUS0_IDENTIFY_TARGET
        descText            @MENUS2_TOGGLE_TO_HAVE_THE_CROSSHAIR
        cvar                "cg_crosshairIdentifyTarget"
    }

    itemDef : submenu_multi_button
    {
        name                slowmo
        group               options
        text                @MENUS2_SLOW_MOTION_DEATH
        cvar                "d_slowmodeath"
        cvarFloatList
        {
            @MENUS2_NEVER           0
            @MENUS2_ON_DEATH        1
            @MENUS2_RARELY          2
            @MENUS1_NORMAL          3
            @MENUS2_OFTEN           4
            @MENUS2_FREQUENTLY      5
            @MENUS2_EXCESSIVELY     6
        }
        descText            @MENUS2_SELECT_THE_FREQUENCY
    }

    itemDef : submenu_onoff_button
    {
        name                force3rd
        group               options
        text                @MENUS2_3RD_PERSON_LIGHTSABER
        descText            @MENUS2_WHEN_READYING_LIGHTSABER
        cvar                "cg_saberAutoThird"
    }

    itemDef : submenu_onoff_button
    {
        name                force1st
        group               options
        text                @MENUS2_1ST_PERSON_GUNS
        descText            @MENUS2_WHEN_PUTTING_AWAY_SABER
        cvar                "cg_gunAutoFirst"
    }

    itemDef : submenu_multi_button
    {
        name                dismemberment
        group               options
        text                @MENUS2_DISMEMBERMENT
        descText            @MENUS2_SELECT_WHAT_LIGHTSABER
        cvar                "g_dismemberment"
        cvarFloatList
        {
            @MENUS0_OFF     0
            @MENUS0_ON      3
        }
        cvarTest            ui_iscensored
        hideCvar            { 1 }
    }

    itemDef : submenu_onoff_button
    {
        name                weaponswayon
        group               options
        text                @MENUS3_VIEW_SWAYING
        descText            @MENUS3_VIEW_SWAYING_DESC
        cvar                "ui_disableWeaponSway"
        cvarTest            "ui_disableWeaponSway"
        showCvar            { "0" }
        action
        {
            exec            "exec noMotion.cfg"
            show            weaponswayoff
            setfocus        weaponswayoff
        }
    }

    itemDef : submenu_onoff_button
    {
        name                weaponswayoff
        group               options
        text                @MENUS3_VIEW_SWAYING
        descText            @MENUS3_VIEW_SWAYING_DESC
        cvar                "ui_disableWeaponSway"
        cvarTest            "ui_disableWeaponSway"
        hideCvar            { "0" }
        rect                0 -20 300 20
        action
        {
            exec            "exec restoreMotion.cfg"
            show            weaponswayon
            setfocus        weaponswayon
        }
    }
}
