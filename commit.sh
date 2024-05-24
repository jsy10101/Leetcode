#!/bin/bash

# Function to check for unstaged changes and return their filenames
get_unstaged_files() {
  git status --short | grep '^[AM?]' | awk '{print $2}' | grep '\.cc$'
}

unstaged_files=$(get_unstaged_files)

if [ -z "$unstaged_files" ]; then
  echo "No unstaged files found."
  exit 0
fi

for filename in $unstaged_files; do
  read -p "Do you want to commit the file '${filename}'? (y/n): " choice
  case "$choice" in 
    y|Y )
      git add "$filename"
      git commit -m "add ${filename}"

      echo "File '${filename}' has been added and committed."
      ;;
    n|N )
      echo "File '${filename}' has not been committed."
      ;;
    * )
      echo "Invalid choice. Skipping the file '${filename}'."
      ;;
  esac
done
