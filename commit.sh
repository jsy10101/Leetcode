#!/bin/bash

# Function to check for unstaged changes and return their filenames
get_unstaged_files() {
  git status --short | grep '^[A(\ M)?]' | awk '{print $2}' | grep -E '\.(cc|py)$'
}

unstaged_files=$(get_unstaged_files)

if [ -z "$unstaged_files" ]; then
  echo "No unstaged files found."
  exit 0
fi

for filename in $unstaged_files; do
  read -p "Do you want to commit the file '${filename}' and then push it? (y/n): " choice
  case "$choice" in 
    y|Y )
      echo
      echo "Adding file to staging and committing it locally..."
      echo "------------------------------------------------"
      echo
      git add "$filename"
      git commit -m "add ${filename}"

      echo
      echo "File '${filename}' has been added and committed locally."
      echo "------------------------------------------------"
      echo "Pushing the file to GitHub now..."
      echo
      
      git push

      echo "------------------------------------------------"
      echo "Success!!!"
      ;;
    n|N )
      echo "File '${filename}' has not been committed."
      ;;
    * )
      echo "Invalid choice. Skipping the file '${filename}'."
      ;;
  esac
done
