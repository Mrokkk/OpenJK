#!/bin/sh

set -e

INSTALL_DIR=$(readlink -f "${1}")
CMAKE=${CMAKE:-cmake}

if [[ ! -d build ]]
then
    mkdir build
    pushd build
    ${CMAKE} \
        -DCMAKE_TOOLCHAIN_FILE=cmake/Toolchains/linux-i686.cmake \
        -DCMAKE_INSTALL_PREFIX="${INSTALL_DIR}" \
        ..
    popd
else
    INSTALL_DIR=$(sed -n -e "s/^CMAKE_INSTALL_PREFIX:PATH=//p" build/CMakeCache.txt)
fi

pushd build
make install -j$(nproc)
popd

cd "${INSTALL_DIR}"
./openjo_sp.i386
