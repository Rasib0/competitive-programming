#!/bin/bash

# Iterate over each .cpp, .kt, and .py file in the current directory
for file in *.cpp *.kt *.py; do
	# Check if the file exists
	if [ -e "$file" ]; then
		# Get the filename without extension
		filename=$(basename -- "$file")
		filename_noext="${filename%.*}"

		# Create a folder with the same name if it doesn't exist
		mkdir -p "$filename_noext"

		# Move the file into the folder
		mv "$file" "$filename_noext/"
	fi
done
