#!/bin/bash

libs="-luser32 -lopengl32";

warnings="-Wno-writable-strings -Wno-format-security"

includes="-Ithird_party -Ithird_party/Include"

clang++ $includes -g src/main.cpp -ovolt.exe $libs $warnings