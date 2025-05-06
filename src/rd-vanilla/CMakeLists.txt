#============================================================================
# Copyright (C) 2013 - 2018, OpenJK contributors
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

# Make sure the user is not executing this script directly
if(NOT IN_OPENJO)
    message(FATAL_ERROR "Use the top-level cmake script!")
endif(NOT IN_OPENJO)

# Defines
set(RD_VANILLA_DEFINES ${SHARED_DEFINES} "RENDERER" "_JK2EXE")

# Files

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

set(RD_VANILLA_LIBRARIES
    ${JPEG_LIBRARIES}
    ${PNG_LIBRARIES}
    ${ZLIB_LIBRARIES}
    ${MINIZIP_LIBRARIES}
    ${OPENGL_LIBRARIES}
)

set(RD_VANILLA_INCLUDE_DIRS
    ${SRC_DIR}
    ${SRC_DIR}/rd-vanilla
    ${SRC_DIR}/rd-common
    ${GSL_DIR}
    ${LIB_DIR}

    ${JPEG_INCLUDE_DIR}
    ${PNG_INCLUDE_DIRS}
    ${ZLIB_INCLUDE_DIR}
    ${MINIZIP_INCLUDE_DIRS}
    ${OPENGL_INCLUDE_DIR}
)

add_library(${RENDERER_VANILLA_NAME} SHARED
    ../ghoul2/G2.h
    ../ghoul2/ghoul2_gore.h
    G2_API.cpp
    G2_bolts.cpp
    G2_bones.cpp
    G2_misc.cpp
    G2_surfaces.cpp

    glext.h
    qgl.h
    tr_arb.cpp
    tr_backend.cpp
    tr_bsp.cpp
    tr_cmds.cpp
    tr_curve.cpp
    tr_draw.cpp
    tr_ghoul2.cpp
    tr_image.cpp
    tr_init.cpp
    tr_light.cpp
    tr_local.h
    tr_main.cpp
    tr_marks.cpp
    tr_mesh.cpp
    tr_model.cpp
    tr_quicksprite.cpp
    tr_quicksprite.h
    tr_scene.cpp
    tr_shade.cpp
    tr_shade_calc.cpp
    tr_shader.cpp
    tr_shadows.cpp
    tr_skin.cpp
    tr_sky.cpp
    tr_stl.cpp
    tr_stl.h
    tr_subs.cpp
    tr_surface.cpp
    tr_surfacesprites.cpp
    tr_world.cpp
    tr_WorldEffects.cpp
    tr_WorldEffects.h

    ../qcommon/matcomp.cpp
    ../qcommon/q_shared.cpp
    ../qcommon/q_shared.h
    ../qcommon/ojk_i_saved_game.h
    ../qcommon/ojk_saved_game_class_archivers.h
    ../qcommon/ojk_saved_game_helper.h
    ../qcommon/ojk_saved_game_helper_fwd.h
    ../qcommon/ojk_scope_guard.h

    ../rd-common/mdx_format.h
    ../rd-common/tr_common.h
    ../rd-common/tr_font.cpp
    ../rd-common/tr_font.h
    ../rd-common/tr_image_load.cpp
    ../rd-common/tr_image_jpg.cpp
    ../rd-common/tr_image_tga.cpp
    ../rd-common/tr_image_png.cpp
    ../rd-common/tr_noise.cpp
    ../rd-common/tr_public.h
    ../rd-common/tr_types.h

    ${SHARED_COMMON_FILES}
)

if(NOT MSVC)
    # remove "lib" prefix for .so/.dylib files
    set_target_properties(${RENDERER_VANILLA_NAME} PROPERTIES PREFIX "")
endif()

if(WIN32)
    install(TARGETS ${RENDERER_VANILLA_NAME}
        RUNTIME
        DESTINATION ${CMAKE_INSTALL_PREFIX}
        COMPONENT ${JK2SP_CLIENT_COMPONENT})
elseif(APPLE)
    install(TARGETS ${RENDERER_VANILLA_NAME}
        LIBRARY
        DESTINATION "${CMAKE_INSTALL_PREFIX}/${ENGINE_NAME}.app/Contents/MacOS/"
        COMPONENT ${JK2SP_CLIENT_COMPONENT})
else()
    install(TARGETS ${RENDERER_VANILLA_NAME}
        LIBRARY
        DESTINATION ${CMAKE_INSTALL_PREFIX}
        COMPONENT ${JK2SP_CLIENT_COMPONENT})
endif()

set_target_properties(${RENDERER_VANILLA_NAME} PROPERTIES COMPILE_DEFINITIONS "${RD_VANILLA_DEFINES}")

# Hide symbols not explicitly marked public.
set_property(TARGET ${RENDERER_VANILLA_NAME} APPEND PROPERTY COMPILE_OPTIONS ${OPENJK_VISIBILITY_FLAGS})

set_target_properties(${RENDERER_VANILLA_NAME} PROPERTIES INCLUDE_DIRECTORIES "${RD_VANILLA_INCLUDE_DIRS}")
set_target_properties(${RENDERER_VANILLA_NAME} PROPERTIES PROJECT_LABEL "JK2 SP Vanilla Renderer")

target_link_libraries(${RENDERER_VANILLA_NAME} ${RD_VANILLA_LIBRARIES})
