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

if(MSVC)
    set(Boost_USE_STATIC_LIBS ON)
endif()

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

set(TEST_TARGET "UnitTests")
set(TEST_INCLUDE_DIRS
    "${Boost_INCLUDE_DIRS}"
    "${SRC_DIR}"
    "${GSL_DIR}"
)

add_executable(${TEST_TARGET}
    "main.cpp"
    "safe/string.cpp"
    "safe/limited_vector.cpp"
    "${SRC_DIR}/qcommon/safe/string.cpp"
)

set_target_properties(${TEST_TARGET} PROPERTIES COMPILE_DEFINITIONS "${SHARED_DEFINES}")
set_target_properties(${TEST_TARGET} PROPERTIES INCLUDE_DIRECTORIES "${TEST_INCLUDE_DIRS}")
set_target_properties(${TEST_TARGET} PROPERTIES PROJECT_LABEL "Unit Tests")
target_link_libraries(${TEST_TARGET} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

if(NOT MSVC)
    #Generate a main function
    target_compile_definitions(${TEST_TARGET} PRIVATE BOOST_TEST_DYN_LINK)
endif()

add_test(NAME unittests COMMAND ${TEST_TARGET})
