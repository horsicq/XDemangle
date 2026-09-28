# XDemangle

Qt symbol demangling library. Include `xdemangle.cmake` or `xdemangle.pri`
in an application to use the native demanglers in `xdemangle.cpp`.

`MODE_AUTO` detects common family prefixes. Use an explicit mode for ambiguous
symbols, Java, or an architecture-specific MSVC presentation. Unsupported or
malformed encodings are preserved unchanged, except GNAT's existing
angle-bracket presentation of invalid names. `getSupportedModes()` and
`getAllModes()` enumerate the available modes.

The separate [xxdemangle](../xxdemangle/README.md) project provides a standalone
C11 API without a Qt dependency.

## Regression tests

The regression project needs only Qt Core and a C++ compiler:

```sh
cmake -S tests/regression -B tests/regression/build -DCMAKE_PREFIX_PATH=path/to/Qt/kit
cmake --build tests/regression/build --config Release
ctest --test-dir tests/regression/build -C Release --output-on-failure
```

Tests cover family detection, complete symbol consumption, malformed input,
numeric bounds, recursive backreferences and representative valid symbols.
Windows builds copy the Qt Core runtime beside the test executables.
