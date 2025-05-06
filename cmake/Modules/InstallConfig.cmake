#============================================================================
# Copyright (C) 2015, OpenJK contributors
#
# This file is part of the OpenJK source code.
#
# OpenJK is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License version 2 as
# published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, see <http://www.gnu.org/licenses/>.
#============================================================================

# Install components
set(JK2SP_CLIENT_COMPONENT "JK2SPClient")

# Component display names
include(CPackComponent)

set(CPACK_COMPONENT_JK2SPCLIENT_DISPLAY_NAME "Core")
set(CPACK_COMPONENT_JK2SPCLIENT_DESCRIPTION "Files required to play the Jedi Outcast single player game.")
set(CPACK_COMPONENTS_ALL ${JK2SP_CLIENT_COMPONENT})

set(CPACK_ARCHIVE_COMPONENT_INSTALL ON)

# Component groups
set(CPACK_COMPONENT_JK2SPCLIENT_GROUP "JK2SP")

cpack_add_component_group(JK2SP
    DISPLAY_NAME "Jedi Outcast Single Player"
    DESCRIPTION "Jedi Outcast single player game")

if(WIN32)
    set(CPACK_NSIS_DISPLAY_NAME "OpenJO")
    set(CPACK_NSIS_PACKAGE_NAME "OpenJO")
    set(CPACK_NSIS_MUI_ICON "${SRC_DIR}/icons/icon.ico")
    set(CPACK_NSIS_MUI_UNIICON "${SRC_DIR}/icons/icon.ico")
    set(CPACK_NSIS_URL_INFO_ABOUT "https://openjk.org")

    set(CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP TRUE)
    include(InstallRequiredSystemLibraries)

    # Don't run this for now until we have JK2 SP working
    string(REPLACE "/" "\\\\" ICON "${SRC_DIR}/win32/starwars.ico")
    set(CPACK_NSIS_CREATE_ICONS_EXTRA
        "${CPACK_NSIS_CREATE_ICONS_EXTRA}
        CreateShortCut '$SMPROGRAMS\\\\$STARTMENU_FOLDER\\\\Jedi Outcast SP.lnk' \\\\
            '$INSTDIR\\\\${ENGINE_NAME}.exe' \\\\
            '' \\\\
            '${ICON}'")

    set(CPACK_NSIS_DELETE_ICONS_EXTRA
        "${CPACK_NSIS_DELETE_ICONS_EXTRA}
        Delete '$SMPROGRAMS\\\\$MUI_TEMP\\\\Jedi Outcast SP.lnk'")

    install(FILES ${MPDir}/OpenAL32.dll ${MPDir}/EaxMan.dll
        DESTINATION ${CMAKE_INSTALL_PREFIX}
        COMPONENT ${JK2SP_CLIENT_COMPONENT})

    install(PROGRAMS ${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS}
        DESTINATION ${CMAKE_INSTALL_PREFIX}
        COMPONENT ${JK2SP_CLIENT_COMPONENT})
endif()

# CPack for installer creation
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_FILE_NAME "OpenJO-${CMAKE_SYSTEM_NAME}-${ARCHITECTURE}")

set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "An improved Jedi Outcast")
set(CPACK_PACKAGE_VENDOR "Mrokkk")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "OpenJO")
set(CPACK_RESOURCE_FILE_README "${CMAKE_SOURCE_DIR}/README.md")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE.txt")
set(CPACK_PACKAGE_DIRECTORY ${PACKAGE_DIR})
set(CPACK_BINARY_ZIP ON) # always create at least a zip file
set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY 0) # prevent additional directory in zip

include(CPack)
