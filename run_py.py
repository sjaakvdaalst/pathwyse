import os, sys, runpy

root = r"C:\Users\sjaak\dev\pathwyse"
os.add_dll_directory(root + r"\bin")
os.add_dll_directory(r"C:\Strawberry\c\bin")
sys.path.insert(0, root)
os.chdir(root)                      # pathwyse.set is read from the working directory
runpy.run_path(sys.argv[1], run_name="__main__")