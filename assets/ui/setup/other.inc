layoutDef
{
    type                    vert
    pos                     $submenu_posx $submenu_posy

    itemDef : submenu_onoff_button
    {
        name                developer
        group               other
        text                "Developer Mode:"
        descText            "Set developer mode"
        cvar                "developer"
    }

    itemDef : submenu_onoff_button
    {
        name                openinglogos
        group               other
        text                "Opening Logos:"
        descText            "Show opening logos"
        cvar                "com_bootlogo"
    }

    itemDef : submenu_onoff_button
    {
        name                improvedweapons
        group               other
        text                "Improved Weapons:"
        descText            "Enable better shooting experience (changing this will drop you to main menu)"
        cvar                "cg_improvedWeapons"

        action
        {
            uiScript        update cg_improvedWeapons
        }
    }

    itemDef : submenu_onoff_button
    {
        name                cheats
        group               other
        text                "Cheats:"
        descText            "Enable Cheats"
        cvar                "helpUsObi"
    }

    itemDef : submenu_onoff_button
    {
        name                jediknockdown
        group               other
        text                "Jedi Knockdown:"
        descText            "Allow for knocking down Jedi by jumping on them"
        cvar                "g_jediKnockDown"
    }
}
