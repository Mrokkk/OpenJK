layoutDef
{
    type                    vert
    pos                     $submenu_posx $submenu_posy

    itemDef : submenu_bind_button
    {
        name                movement1
        group               movecontrols
        text                @MENUS1_WALK_FORWARD
        descText            @MENUS1_MOVES_PLAYER_FORWARD
        cvar                "+forward"
    }

    itemDef : submenu_bind_button
    {
        name                movement2
        group               movecontrols
        type                ITEM_TYPE_BIND
        text                @MENUS1_BACKPEDAL
        descText            @MENUS1_MOVES_PLAYER_BACKWARD
        cvar                "+back"
    }

    itemDef : submenu_bind_button
    {
        name                movement3
        group               movecontrols
        type                ITEM_TYPE_BIND
        text                @MENUS1_TURN_LEFT
        descText            @MENUS1_ROTATES_PLAYER_LEFT
        cvar                "+left"
    }

    itemDef : submenu_bind_button
    {
        name                movement4
        group               movecontrols
        type                ITEM_TYPE_BIND
        text                @MENUS1_TURN_RIGHT
        descText            @MENUS1_ROTATES_PLAYER_RIGHT
        cvar                "+right"
    }

    itemDef : submenu_bind_button
    {
        name                movement
        group               movecontrols
        type                ITEM_TYPE_BIND
        text                @MENUS1_RUN_WALK
        descText            @MENUS1_IF_HELD_TOGGLES_BETWEEN
        cvar                "+speed"
    }

    itemDef : submenu_bind_button
    {
        name                movement
        group               movecontrols
        type                ITEM_TYPE_BIND
        text                @MENUS1_STEP_LEFT
        descText            @MENUS1_STEPS_PLAYER_TO_THE_LEFT
        cvar                "+moveleft"
    }

    itemDef : submenu_bind_button
    {
        name                movement
        group               movecontrols
        type                ITEM_TYPE_BIND
        text                @MENUS1_STEP_RIGHT
        descText            @MENUS1_STEPS_PLAYER_TO_THE_RIGHT
        cvar                "+moveright"
    }

    itemDef : submenu_bind_button
    {
        name                movement
        group               movecontrols
        type                ITEM_TYPE_BIND
        text                @MENUS1_SIDESTEP_TURN
        descText            @MENUS1_HELD_ALLOWS_PLAYER_TO
        cvar                "+strafe"
    }

    itemDef : submenu_bind_button
    {
        name                movement
        group               movecontrols
        type                ITEM_TYPE_BIND
        text                @MENUS1_UP_JUMP
        descText            @MENUS1_MAKES_PLAYER_JUMP_IF
        cvar                "+moveup"
    }

    itemDef : submenu_bind_button
    {
        name                movement
        group               movecontrols
        type                ITEM_TYPE_BIND
        text                @MENUS1_DOWN_CROUCH
        descText            @MENUS1_MAKES_PLAYER_CROUCH_TO
        cvar                "+movedown"
    }

    itemDef : submenu_separator
    {
    }

    itemDef
    {
        name                movement
        group               movecontrols
        text                @MENUS2_HOLD_USE_PLUS_STRAFE
        font                2
        textscale           0.8
        rect                0 0 300 20
        textalign           ITEM_ALIGN_CENTER
        textalignx          150
        textaligny          -2
        forecolor           0.7 0.7 0.7 1
        visible             0
        decoration
    }
}
