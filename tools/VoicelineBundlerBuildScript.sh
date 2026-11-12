#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"

g++ "$SCRIPT_DIR/VoicelineBundler.cpp" -o "$SCRIPT_DIR/VoicelineBundler"

if [ $? -eq 0 ]; then
    echo "Compilation successful: $SCRIPT_DIR/VoicelineBundler"
else
    echo "Compilation failed."
    exit 1
fi
