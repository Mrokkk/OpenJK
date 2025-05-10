#!/bin/sh

set -e

BASE_DIR="$(readlink -f $(dirname ${0}))"

. "${BASE_DIR}/scripts/utils.sh"

CMAKE=${CMAKE:-cmake}
BUILD_DIR="$(readlink -f build)"
UNPACKED_ASSETS_DIR="${BUILD_DIR}/assets"

if [[ ! -d build ]] || [[ ! -f build/CMakeCache.txt ]]
then
    mkdir -p build
    pushd_silent build
    INSTALL_DIR="${1}"
    ${CMAKE} \
        -DCMAKE_TOOLCHAIN_FILE=cmake/Toolchains/linux-i686.cmake \
        -DCMAKE_INSTALL_PREFIX="${INSTALL_DIR}" \
        "${BASE_DIR}"
    popd_silent
else
    INSTALL_DIR=$(sed -n -e "s/^CMAKE_INSTALL_PREFIX:PATH=//p" build/CMakeCache.txt)
fi

function assets_update()
{
    declare -a assets_to_update

    pushd_silent assets

    for file in $(find . -type f)
    do
        if [[ "${file}" -nt "${INSTALL_DIR}/base/openjo.pk3" ]]
        then
            assets_to_update+=("${file#./}")
        fi
    done

    if [[ ${#assets_to_update[@]} -ne 0 ]]
    then
        zip -r "${INSTALL_DIR}/base/openjo.pk3" ${assets_to_update[@]}
    fi

    popd_silent
}

assets_update

pushd_silent build
make install -j$(nproc)
popd_silent

cd "${INSTALL_DIR}"
./openjo_sp.i386
