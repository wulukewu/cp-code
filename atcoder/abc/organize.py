import os
import re
import subprocess

def organize_abc_files(directory="."):
    """
    Organizes files in a directory by moving files matching "abc***" 
    into subdirectories named after the "abc***" prefix (e.g., abc072).
    Uses "git mv" to ensure Git tracks the file moves.

    Args:
        directory (str): The directory to organize (default: current directory).
    """

    files = os.listdir(directory)
    abc_files = {}

    for filename in files:
        match = re.match(r"^(\d{8})\s+(abc\d+)([a-z\d]*)\.(cpp|py|bin)$", filename)
        if match:
            date_str, prefix, suffix, extension = match.groups()
            if prefix not in abc_files:
                abc_files[prefix] = []
            abc_files[prefix].append(filename)

    for prefix, filenames in abc_files.items():
        folder_name = prefix
        folder_path = os.path.join(directory, folder_name)

        # Create the directory if it doesn't exist
        if not os.path.exists(folder_path):
            os.makedirs(folder_path)

        for filename in filenames:
            source_path = os.path.join(directory, filename)
            dest_path = os.path.join(folder_path, filename)

            # Use git mv to move the file and track the change
            try:
                subprocess.run(["git", "mv", source_path, dest_path], check=True, capture_output=True, text=True)
                print(f"Moved {filename} to {folder_name}/")
            except subprocess.CalledProcessError as e:
                print(f"Error moving {filename}: {e.stderr}")


if __name__ == "__main__":
    organize_abc_files()  # Organize files in the current directory