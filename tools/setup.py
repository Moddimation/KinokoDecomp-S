#!/usr/bin/env python3

import argparse
import hashlib
from pathlib import Path
import subprocess
from typing import Optional
from common import setup_common as setup
from enum import Enum

TARGET_PATH = setup.get_target_path()
TARGET_ELF_PATH = setup.get_target_elf_path()

class Version(Enum):
    VER_100 = "1.0"
    VER_110 = "1.1"
    VER_120 = "1.2"
    VER_130 = "1.3"

def prepare_executable(original_nso: Optional[Path]):
    COMPRESSED_V10_HASH = "7a4289f6d8c0685c48cdc9219f49bfbed7a8662f84e812cb20773b65dec04e71"
    UNCOMPRESSED_V10_HASH = "c2112f5bcb28ba72a467fbc7b1976ef4c15beef3cf2ef948051d87abceed42e5"

    # The uncompressed v1.0 main NSO.
    TARGET_HASH = UNCOMPRESSED_V10_HASH

    if TARGET_PATH.is_file() and hashlib.sha256(TARGET_PATH.read_bytes()).hexdigest() == TARGET_HASH and TARGET_ELF_PATH.is_file():
        print(">>> NSO is already set up")
        return

    if not original_nso.is_file():
        setup.fail(f"{original_nso} is not a file")

    nso_data = original_nso.read_bytes()
    nso_hash = hashlib.sha256(nso_data).hexdigest()

    if nso_hash == UNCOMPRESSED_V10_HASH:
        print(">>> found uncompressed 1.0 NSO")
        TARGET_PATH.write_bytes(nso_data)

    elif nso_hash == COMPRESSED_V10_HASH:
        print(">>> found compressed 1.0 NSO")
        setup._decompress_nso(original_nso, TARGET_PATH)

    else:
        setup.fail(f"unknown executable: {nso_hash}")

    if not TARGET_PATH.is_file():
        setup.fail("internal error while preparing executable (missing NSO); please report")
    if hashlib.sha256(TARGET_PATH.read_bytes()).hexdigest() != TARGET_HASH:
        setup.fail("internal error while preparing executable (wrong NSO hash); please report")

    setup._convert_nso_to_elf(TARGET_PATH)

    if not TARGET_ELF_PATH.is_file():
        setup.fail("internal error while preparing executable (missing ELF); please report")

def get_build_dir():
    return setup.ROOT / "build"

def create_build_dir(ver, cmake_backend):
    if(ver != Version.VER_100): return # TODO remove this when multiple versions should be built
    build_dir = get_build_dir()
    if build_dir.is_dir():
        print(">>> build directory already exists: nothing to do")
        return

    subprocess.check_call(
        ['cmake', '-G', cmake_backend, f'-DCMAKE_CXX_FLAGS=-D{ver.name}', '-DCMAKE_BUILD_TYPE=RelWithDebInfo', '-DCMAKE_TOOLCHAIN_FILE=toolchain/ToolchainNX64.cmake', '-DCMAKE_CXX_COMPILER_LAUNCHER=ccache', '-B', str(build_dir)])
    print(">>> created build directory") 

def main():
    parser = argparse.ArgumentParser(
        "setup.py", description="Set up the Super Mario Odyssey decompilation project")
    parser.add_argument("original_nso", type=Path,
                        help="Path to the original NSO (1.0, compressed or not)", nargs="?")
    parser.add_argument("--cmake_backend", type=str,
                        help="CMake backend to use (Ninja, Unix Makefiles, etc.)", nargs="?", default="Ninja")
    parser.add_argument("--project-only", action="store_true",
                        help="Disable viking and original NSO setup")
    args = parser.parse_args()
    
    if not args.project_only:
        setup.install_viking()
        if not (setup.ROOT / 'data' / 'main.elf').is_file() and not args.original_nso:
            setup.fail("You have to pass the nso!")
            return
        prepare_executable(args.original_nso)
    setup.set_up_compiler("8.0.0")
    create_build_dir(Version.VER_100, args.cmake_backend)
    create_build_dir(Version.VER_110, args.cmake_backend)
    create_build_dir(Version.VER_120, args.cmake_backend)
    create_build_dir(Version.VER_130, args.cmake_backend)


if __name__ == "__main__":
    main()
