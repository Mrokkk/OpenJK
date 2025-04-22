include "ui/common/background.inc"
include "ui/common/commonitems.inc"

itemDef : submenu_background
{
    name                setup_background
}

itemDef : submenu_title
{
    name                control_title
    text                @MENUS1_CONFIGURE_CONTROLS
}

submenuGroupsDef
{
    weaponcontrols
    forcecontrols
    attackcontrols
    movecontrols
    invcontrols
    quickcontrols
    joycontrols
    othercontrols
}

include "ui/controls/buttons.inc"
include "ui/controls/weapons.inc"
include "ui/controls/force.inc"
include "ui/controls/attack.inc"
include "ui/controls/movement.inc"
include "ui/controls/inventory.inc"
include "ui/controls/quickkeys.inc"
include "ui/controls/mousejoystick.inc"
include "ui/controls/other.inc"
include "ui/controls/text.inc"
