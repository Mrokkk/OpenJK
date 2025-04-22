layoutDef
{
    type                    vert
    pos                     $submenu_posx $submenu_posy

    itemDef : submenu_separator
    {
    }

    itemDef : submenu_bind_button
    {
        name                inventory1
        group               invcontrols
        text                @MENUS1_ELECTROBINOCULARS
        descText            @MENUS1_ACTIVATES_NEURO_SAAV
        cvar                "zoom"
    }

    itemDef : submenu_bind_button
    {
        name                inventory2
        group               invcontrols
        text                @MENUS1_BACTA_CANISTER
        descText            @MENUS1_ACTIVATES_BIOTECH_BACTA
        cvar                "use_bacta"
    }

    itemDef : submenu_bind_button
    {
        name                inventory3
        group               invcontrols
        text                @MENUS0_SEEKER
        descText            @MENUS1_ACTIVATES_ARAKYD_MARK
        cvar                "use_seeker"
    }

    itemDef : submenu_bind_button
    {
        name                inventory4
        group               invcontrols
        text                @MENUS1_LIGHT_AMP_GOGGLES
        descText            @MENUS2_ACTIVATES_LIGHT_AMPLIFICATION
        cvar                "use_lightamp_goggles"
    }

    itemDef : submenu_bind_button
    {
        name                inventory5
        group               invcontrols
        text                @MENUS1_ASSAULT_SENTRY
        descText            @MENUS1_ACTIVATES_PORTABLE_ASSAULT
        cvar                "use_sentry"
    }

    itemDef : submenu_separator
    {
    }

    itemDef : submenu_bind_button
    {
        name                inventorykeys
        group               invcontrols
        text                @MENUS1_USE_HELD_ITEM
        descText            @MENUS1_ACTIVATES_CURRENTLY_SELECTED
        cvar                "invuse"
    }

    itemDef : submenu_bind_button
    {
        name                inventorykeys
        group               invcontrols
        text                @MENUS1_NEXT_INVENTORY
        descText            @MENUS1_SELECTS_NEXT_USABLE_ITEM
        cvar                "invnext"
    }

    itemDef : submenu_bind_button
    {
        name                inventorykeys
        group               invcontrols
        text                @MENUS1_PREV_INVENTORY
        descText            @MENUS1_SELECTS_PREVIOUS_USABLE
        cvar                "invprev"
    }
}
