#!/bin/bash


# Name of the C source file
SOURCE="main/main.c"

# Output directory
OUTPUT_DIR="bin"
# Extract filename without extension
OUTPUT_NAME=$(basename "$SOURCE" .c)
OUTPUT="$OUTPUT_DIR/$OUTPUT_NAME"

# Compile the c program
clang "$SOURCE" -o "$OUTPUT"

# Check if compilaiton was successful
if [ $? -eq 0 ]; then
	echo "Compilation was Successfull. Running the program..."
	./"$OUTPUT"
else
	echo "Compilation Failed."
fi
