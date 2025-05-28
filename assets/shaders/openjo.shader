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

gfx/misc/spark_new
{
    cull    disable
    {
        map gfx/misc/spark
        blendFunc GL_ONE GL_ONE
        rgbGen vertex
        glow
    }
}

gfx/misc/spark2_new
{
    cull    disable
    {
        map gfx/misc/spark2
        blendFunc GL_ONE GL_ONE
        rgbGen vertex
        glow
    }
}

gfx/misc/spark3_new
{
    cull    disable
    {
        map gfx/misc/spark3
        blendFunc GL_ONE GL_ONE
        rgbGen vertex
        glow
    }
}

gfx/hud/w_icon_atst
{
    nomipmaps
    {
        map gfx/hud/w_icon_atst
        blendFunc GL_ONE GL_ZERO
    }
}

gfx/hud/w_icon_atstside
{
    nomipmaps
    {
        map gfx/hud/w_icon_atstside
        blendFunc GL_ONE GL_ZERO
    }
}

icons/w_icon_turret
{
    nopicmip
    nomipmaps
    {
        map gfx/hud/w_icon_atst
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
}

icons/w_icon_turret_na
{
    nopicmip
    nomipmaps
    {
        map gfx/hud/w_icon_atst
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
}
