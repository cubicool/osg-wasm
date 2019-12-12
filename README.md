# Overview

A repository to help compile OpenSceneGraph using WebAssembly and Empscripten.

# Considerations

- This project currently only builds under Unix-like environments (or WSL on
  Windows). In the future, support for pure Windows 10+ compilation will also be
  provided.

- OSG and any library dependencies will need to all be compiled statically.
  Support for dynamic linkage is experimental.

- The path of least resistance will be to use the "embedded" osgViewer mode,
  along with SDL2 for creating the OpenGL context (which emcc supports well).
