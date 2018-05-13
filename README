# Toy x86 OS build example

This repository shows how clang can be used to cross-compile to x86 bare-metal. As a build system CMake is used. The necessary steps to compile are as follows:

```bash
mkdir build && cd build
cmake -DCMAKE_TOOLCHAIN_FILE=../Toolchain-x86-elf.cmake ..
cmake --build .
```

On macOS the standard linker ld can only create MachO files, therefore, lld is required on macOS.
