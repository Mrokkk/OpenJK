layoutDef
{
    type                    vert
    pos                     $submenu_posx $submenu_posy

    itemDef : submenu_onoff_button
    {
        name                developer
        group               other
        text                "Developer mode:"
        descText            "Set developer mode"
        cvar                "developer"
    }

    itemDef : submenu_onoff_button
    {
        name                openinglogos
        group               other
        text                "Opening logos:"
        descText            "Show opening logos"
        cvar                "com_bootlogo"
    }

    itemDef : submenu_onoff_button
    {
        name                cheats
        group               other
        text                "Cheats:"
        descText            "Enable cheats"
        cvar                "helpUsObi"
    }

    itemDef : submenu_onoff_button
    {
        name                jediknockdown
        group               other
        text                "Jedi knock down:"
        descText            "Allow for knocking down Jedi by jumping on them"
        cvar                "g_jediKnockDown"
    }
}
