# Tutorial_game

A C++ project using [CMake](https://cmake.org/) and [CPM.cmake](https://github.com/cpm-cmake/CPM.cmake) for dependency management.

## Features
- Modern C++ (C++20)
- Dependencies fetched automatically via CPM.cmake:
  - [GLFW](https://github.com/glfw/glfw) – window & input
  - [GLAD](https://github.com/Dav1dde/glad) – OpenGL loader
  - [GLM](https://github.com/g-truc/glm) - graphics math library

## Build Instructions

### Prerequisites
- CMake ≥ 3.20
- A C++20 compiler (MSVC, GCC, or Clang)
- Git

### Clone repository
```bash
git clone https://github.com/Roland-More/Tutorial_game.git
cd Tutorial_game
```

### Configure & Build

#### Linux / macOS
```bash
cmake -B build -S .
cmake --build build
```

#### Windows (MSVC with CMake)
```bash
cmake -B build -S . -G "Visual Studio 17 2022"
cmake --build build --config Release
```

#### Windows (MinGW)
```bash
##### You can add one of theese options to the configuration
##### -DCMAKE_BUILD_TYPE=Release
##### -DCMAKE_BUILD_TYPE=Debug
cmake -B build -S . -G "MinGW Makefiles"
cmake --build build
```


### Run
After building, run the executable from the build folder:
```bash
./build/Tutorial_game                    (Linux / macOS)
.\build\Release\Tutorial_game.exe        (Windows - MSVC Release build)
.\build\src\Tutorial_game.exe            (Windows - MinGW)
```

### Clean Build (optional)
If you need to clean and rebuild:
```bash
cmake --build build --target clean
```
