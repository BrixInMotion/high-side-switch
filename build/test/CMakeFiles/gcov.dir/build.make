# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch\build

# Utility rule file for gcov.

# Include the progress variables for this target.
include test/CMakeFiles/gcov.dir/progress.make

test/CMakeFiles/gcov:
	"C:\Program Files\CMake\bin\cmake.exe" -E make_directory coverage
	C:\mingw-w64\mingw32\bin\mingw32-make.exe test

gcov: test/CMakeFiles/gcov
gcov: test/CMakeFiles/gcov.dir/build.make
	cd /d C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch\build\coverage && "C:\Program Files\CMake\bin\cmake.exe" -E echo "=================== GCOV ===================="
	cd /d C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch\build\coverage && gcov -b -a C:/Users/jaumann/Documents/Arduino/libraries/high-side-switch/src/*.cpp -o C:/Users/jaumann/Documents/Arduino/libraries/high-side-switch/build/CMakeFiles/high-side-switch.dir/src
	cd /d C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch\build\coverage && gcov -b -a C:/Users/jaumann/Documents/Arduino/libraries/high-side-switch/src/corelib/*.c -o C:/Users/jaumann/Documents/Arduino/libraries/high-side-switch/build/CMakeFiles/high-side-switch.dir/src/corelib
	cd /d C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch\build\coverage && "C:\Program Files\CMake\bin\cmake.exe" -E echo "-- Coverage files have been output to C:/Users/jaumann/Documents/Arduino/libraries/high-side-switch/build/coverage"
.PHONY : gcov

# Rule to build all files generated by this target.
test/CMakeFiles/gcov.dir/build: gcov

.PHONY : test/CMakeFiles/gcov.dir/build

test/CMakeFiles/gcov.dir/clean:
	cd /d C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch\build\test && $(CMAKE_COMMAND) -P CMakeFiles\gcov.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/gcov.dir/clean

test/CMakeFiles/gcov.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch\test C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch\build C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch\build\test C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch\build\test\CMakeFiles\gcov.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/gcov.dir/depend
