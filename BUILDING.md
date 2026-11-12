## Requirements
**Operating system:** Windows or Linux.  
**C++ compiler:** C++23 compatible MSVC/GCC.  
**CMake:** Version 3.25 or newer.  
**Ninja:** Version 1.13.2 is currently used for development and testing.  
**Vulkan SDK:** Version 1.4.357 is currently used for development and testing.  

The project includes all other libraries and dependencies in the source under `/libs`.

## Commands

Run the following commands from the repository root.

### Debug Build

cmake --preset debug  
cmake --build .debug

### Release Build

cmake --preset release  
cmake --build .release