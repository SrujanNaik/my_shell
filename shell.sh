
#!/bin/bash

# Exit immediately if any command fails
set -e

# Name of the C source file
SOURCE="main/main.c"

# Output directory
OUTPUT_DIR="bin"
mkdir -p "$OUTPUT_DIR"  # Ensure output directory exists

# Extract filename without extension
OUTPUT_NAME=$(basename "$SOURCE" .c)
OUTPUT="$OUTPUT_DIR/$OUTPUT_NAME"

# Compile the C program
clang "$SOURCE" -o "$OUTPUT" || { echo "Compilation Failed."; exit 1; }

# Run the compiled program
echo "Compilation was successful. Running the program..."
"./$OUTPUT"

