layoutDef
{
    type                    vert
    pos                     120 171

    itemDef
    {
        name                weaponscontrolbutton
        group               leftbuttons
        text                @OPENJO_WEAPONS
        type                ITEM_TYPE_BUTTON
        style               WINDOW_STYLE_EMPTY
        rect                0 0 170 25
        font                3
        textscale           0.9
        textalignx          170
        textaligny          0
        textalign           ITEM_ALIGN_RIGHT
        textstyle           3
        forecolor           0.65 0.65 1 1
        visible             1
        descText            @MENUS0_CONFIGURE_WEAPON_CONTROLS
        glow                "gfx/menus/menu_blendbox2"
        action
        {
            show            setup_background
            showsubmenu     weaponcontrols
            setactivebutton leftbuttons weaponscontrolbutton
        }
    }

    itemDef
    {
        name                forcecontrolbutton
        group               leftbuttons
        text                @OPENJO_FORCE_POWERS
        type                ITEM_TYPE_BUTTON
        style               WINDOW_STYLE_EMPTY
        rect                0 0 170 25
        font                3
        textscale           0.9
        textalignx          170
        textaligny          0
        textalign           ITEM_ALIGN_RIGHT
        textstyle           3
        forecolor           0.65 0.65 1 1
        visible             1
        descText            @MENUS0_CONFIGURE_FORCE_POWER
        glow                "gfx/menus/menu_blendbox2"
        action
        {
            show            setup_background
            showsubmenu     forcecontrols
            setactivebutton leftbuttons forcecontrolbutton
        }
    }

    itemDef
    {
        name                attackcontrolbutton
        group               leftbuttons
        text                @OPENJO_ATTACK_LOOK
        type                ITEM_TYPE_BUTTON
        style               WINDOW_STYLE_EMPTY
        rect                0 0 170 25
        font                3
        textscale           0.9
        textalignx          170
        textaligny          0
        textalign           ITEM_ALIGN_RIGHT
        textstyle           3
        forecolor           0.65 0.65 1 1
        visible             1
        descText            @MENUS0_CONFIGURE_ATTACK_LOOK
        glow                "gfx/menus/menu_blendbox2"
        action
        {
            show            setup_background
            showsubmenu     attackcontrols
            setactivebutton leftbuttons attackcontrolbutton
        }
    }

    itemDef
    {
        name                movementcontrolbutton
        group               leftbuttons
        text                @OPENJO_MOVEMENT
        type                ITEM_TYPE_BUTTON
        style               WINDOW_STYLE_EMPTY
        rect                0 0 170 25
        font                3
        textscale           0.9
        textalignx          170
        textaligny          0
        textalign           ITEM_ALIGN_RIGHT
        textstyle           3
        forecolor           0.65 0.65 1 1
        visible             1
        descText            @MENUS0_CONFIGURE_MOVEMENT_KEYS
        glow                "gfx/menus/menu_blendbox2"
        action
        {
            show            setup_background
            showsubmenu     movecontrols
            setactivebutton leftbuttons movementcontrolbutton
        }
    }

    itemDef
    {
        name                inventorycontrolbutton
        group               leftbuttons
        text                @OPENJO_INVENTORY
        type                ITEM_TYPE_BUTTON
        style               WINDOW_STYLE_EMPTY
        rect                0 0 170 25
        font                3
        textscale           0.9
        textalignx          170
        textaligny          0
        textalign           ITEM_ALIGN_RIGHT
        textstyle           3
        forecolor           0.65 0.65 1 1
        visible             1
        descText            @MENUS0_CONFIGURE_INVENTORY_KEYS
        glow                "gfx/menus/menu_blendbox2"
        action
        {
            show            setup_background
            showsubmenu     invcontrols
            setactivebutton leftbuttons inventorycontrolbutton
        }
    }

    itemDef
    {
        name                quickcontrolbutton
        group               leftbuttons
        text                @OPENJO_QUICK_KEYS
        type                ITEM_TYPE_BUTTON
        style               WINDOW_STYLE_EMPTY
        rect                0 0 170 25
        font                3
        textscale           0.9
        textalignx          170
        textaligny          0
        textalign           ITEM_ALIGN_RIGHT
        textstyle           3
        forecolor           0.65 0.65 1 1
        visible             1
        descText            @MENUS1_CONFIGURE_QUICK_KEYS
        glow                "gfx/menus/menu_blendbox2"
        action
        {
            show            setup_background
            showsubmenu     quickcontrols
            setactivebutton leftbuttons quickcontrolbutton
        }
    }

    itemDef
    {
        name                mousejoystickcontrolbutton
        group               leftbuttons
        text                @OPENJO_MOUSE_JOYSTICK
        type                ITEM_TYPE_BUTTON
        style               WINDOW_STYLE_EMPTY
        rect                0 0 170 25
        font                3
        textscale           0.9
        textalignx          170
        textaligny          0
        textalign           ITEM_ALIGN_RIGHT
        textstyle           3
        forecolor           0.65 0.65 1 1
        visible             1
        descText            @MENUS0_CONFIGURE_MOUSE_AND_JOYSTICK
        glow                "gfx/menus/menu_blendbox2"
        action
        {
            show            setup_background
            showsubmenu     joycontrols
            setactivebutton leftbuttons mousejoystickcontrolbutton
        }
    }

    itemDef
    {
        name                othercontrolbutton
        group               leftbuttons
        text                @OPENJO_OTHER
        type                ITEM_TYPE_BUTTON
        style               WINDOW_STYLE_EMPTY
        rect                0 0 170 25
        font                3
        textscale           0.9
        textalignx          170
        textaligny          0
        textalign           ITEM_ALIGN_RIGHT
        textstyle           3
        forecolor           0.65 0.65 1 1
        visible             1
        descText            @MENUS0_CONFIGURE_ADDITIONAL
        glow                "gfx/menus/menu_blendbox2"
        action
        {
            show            setup_background
            showsubmenu     othercontrols
            setactivebutton leftbuttons othercontrolbutton
        }
    }
}
