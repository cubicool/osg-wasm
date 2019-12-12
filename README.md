# Overview

A repository to help compile OpenSceneGraph using WebAssembly and Emscripten.
I am slowly migrating the existing, gnarly, research code and bringing it into
this repo bit by bit. Documentation will keep pace.

# Considerations

- This project currently only builds under Unix-like environments (or WSL on
  Windows). In the future, support for pure Windows 10+ compilation will also be
  provided, if possible.

- OSG and any library dependencies will need to all be compiled statically.
  Support for dynamic linkage is experimental.

- The path of least resistance will be to use the "embedded" osgViewer mode,
  along with SDL2 for creating the OpenGL context (which emcc supports well).

# Setup

First you'll need to locally clone the EMSDK for this project.

```
# git clone https://github.com/emscripten-core/emsdk.git
# cd emsdk
# ./emsdk install latest
# ./emsdk activate latest
# source emsdk_env.sh --build=Release
```
Second, using the same environment/shell from above, checkout OSG and run the
special **emconfigure** command to invoke cmake.

```
# git clone https://github.com/AlphaPixel/OpenSceneGraph.git
# cd OpenSceneGraph
# emconfigure cmake . -DCMAKE_TOOLCHAIN_FILE=../emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake
# make
```

Notice how we define the toolchain file at the commandline, which is key to
properly building OSG using Emscripten.

# TODO

- Make the emsdk and OpenSceneGraph folders use git **submodules**.

- Investigate using a toplevel CMake configuration to automake the steps above.
