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

# Include any dependencies generated for this target.
include test/CMakeFiles/high-side-switch-test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/high-side-switch-test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/high-side-switch-test.dir/flags.make

test/CMakeFiles/high-side-switch-test.dir/test_high-side-switch.obj: test/CMakeFiles/high-side-switch-test.dir/flags.make
test/CMakeFiles/high-side-switch-test.dir/test_high-side-switch.obj: test/CMakeFiles/high-side-switch-test.dir/includes_CXX.rsp
test/CMakeFiles/high-side-switch-test.dir/test_high-side-switch.obj: ../test/test_high-side-switch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/high-side-switch-test.dir/test_high-side-switch.obj"
	cd /d C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch\build\test && C:\mingw-w64\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\high-side-switch-test.dir\test_high-side-switch.obj -c C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch\test\test_high-side-switch.cpp

test/CMakeFiles/high-side-switch-test.dir/test_high-side-switch.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/high-side-switch-test.dir/test_high-side-switch.i"
	cd /d C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch\build\test && C:\mingw-w64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch\test\test_high-side-switch.cpp > CMakeFiles\high-side-switch-test.dir\test_high-side-switch.i

test/CMakeFiles/high-side-switch-test.dir/test_high-side-switch.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/high-side-switch-test.dir/test_high-side-switch.s"
	cd /d C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch\build\test && C:\mingw-w64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch\test\test_high-side-switch.cpp -o CMakeFiles\high-side-switch-test.dir\test_high-side-switch.s

# Object files for target high-side-switch-test
high__side__switch__test_OBJECTS = \
"CMakeFiles/high-side-switch-test.dir/test_high-side-switch.obj"

# External object files for target high-side-switch-test
high__side__switch__test_EXTERNAL_OBJECTS =

test/high-side-switch-test.exe: test/CMakeFiles/high-side-switch-test.dir/test_high-side-switch.obj
test/high-side-switch-test.exe: test/CMakeFiles/high-side-switch-test.dir/build.make
test/high-side-switch-test.exe: lib/libgtest_maind.a
test/high-side-switch-test.exe: lib/libgmock_maind.a
test/high-side-switch-test.exe: libhigh-side-switch.a
test/high-side-switch-test.exe: lib/libgmockd.a
test/high-side-switch-test.exe: lib/libgtestd.a
test/high-side-switch-test.exe: test/CMakeFiles/high-side-switch-test.dir/linklibs.rsp
test/high-side-switch-test.exe: test/CMakeFiles/high-side-switch-test.dir/objects1.rsp
test/high-side-switch-test.exe: test/CMakeFiles/high-side-switch-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable high-side-switch-test.exe"
	cd /d C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch\build\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\high-side-switch-test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/high-side-switch-test.dir/build: test/high-side-switch-test.exe

.PHONY : test/CMakeFiles/high-side-switch-test.dir/build

test/CMakeFiles/high-side-switch-test.dir/clean:
	cd /d C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch\build\test && $(CMAKE_COMMAND) -P CMakeFiles\high-side-switch-test.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/high-side-switch-test.dir/clean

test/CMakeFiles/high-side-switch-test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch\test C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch\build C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch\build\test C:\Users\jaumann\Documents\Arduino\libraries\high-side-switch\build\test\CMakeFiles\high-side-switch-test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/high-side-switch-test.dir/depend
