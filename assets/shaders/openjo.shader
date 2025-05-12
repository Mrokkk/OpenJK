gfx/effects/sabers/red_glow2
{
    cull    twosided
    {
        map gfx/effects/sabers/red_glow2
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen vertex
    }
}

gfx/effects/sabers/orange_glow2
{
    cull    twosided
    {
        map gfx/effects/sabers/orange_glow2
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen vertex
    }
}

gfx/effects/sabers/yellow_glow2
{
    cull    twosided
    {
        map gfx/effects/sabers/yellow_glow2
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen vertex
    }
}

gfx/effects/sabers/green_glow2
{
    cull    twosided
    {
        map gfx/effects/sabers/green_glow2
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen vertex
    }
}

gfx/effects/sabers/blue_glow2
{
    cull    twosided
    {
        map gfx/effects/sabers/blue_glow2
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen vertex
    }
}

gfx/effects/sabers/purple_glow2
{
    cull    twosided
    {
        map gfx/effects/sabers/purple_glow2
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen vertex
    }
}

gfx/menus/menu4a
{
    nopicmip
    nomipmaps
    {
        map gfx/menus/menu4
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
    {
        map gfx/menus/menu4
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        stencilAlphaMask range 0.35 0.99
    }
    {
        map gfx/menus/menu5
        blendFunc GL_ONE GL_ONE
        tcMod scale 0.5 1
        tcMod scroll -0.15 0
        stenciled
    }
}
