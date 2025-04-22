include "ui/common/background.inc"
include "ui/common/commonitems.inc"

itemDef : submenu_background
{
    name                setup_background
}

itemDef : submenu_title
{
    name                setup_title
    text                @MENUS2_SETUP_OPTIONS
}

submenuGroupsDef
{
    video
    video2
    sound
    options
    lang
    other
    mods
    defaults
    vidrestart
    applyChanges
}

include "ui/setup/videorestart.inc"
include "ui/setup/defaults.inc"
include "ui/setup/video1.inc"
include "ui/setup/video2.inc"
include "ui/setup/sound.inc"
include "ui/setup/options.inc"
include "ui/setup/lang.inc"
include "ui/setup/other.inc"
include "ui/setup/mods.inc"
include "ui/setup/buttons.inc"
