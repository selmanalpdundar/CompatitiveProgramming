# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/selman/Google Drive/Master/First Year/First semester/Competitive programming and contests/Github/CompatitiveProgramming/MissingNumberInArray"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/selman/Google Drive/Master/First Year/First semester/Competitive programming and contests/Github/CompatitiveProgramming/MissingNumberInArray/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/MissingNumberInArray.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MissingNumberInArray.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MissingNumberInArray.dir/flags.make

CMakeFiles/MissingNumberInArray.dir/main.cpp.o: CMakeFiles/MissingNumberInArray.dir/flags.make
CMakeFiles/MissingNumberInArray.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/selman/Google Drive/Master/First Year/First semester/Competitive programming and contests/Github/CompatitiveProgramming/MissingNumberInArray/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MissingNumberInArray.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MissingNumberInArray.dir/main.cpp.o -c "/Users/selman/Google Drive/Master/First Year/First semester/Competitive programming and contests/Github/CompatitiveProgramming/MissingNumberInArray/main.cpp"

CMakeFiles/MissingNumberInArray.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MissingNumberInArray.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/selman/Google Drive/Master/First Year/First semester/Competitive programming and contests/Github/CompatitiveProgramming/MissingNumberInArray/main.cpp" > CMakeFiles/MissingNumberInArray.dir/main.cpp.i

CMakeFiles/MissingNumberInArray.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MissingNumberInArray.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/selman/Google Drive/Master/First Year/First semester/Competitive programming and contests/Github/CompatitiveProgramming/MissingNumberInArray/main.cpp" -o CMakeFiles/MissingNumberInArray.dir/main.cpp.s

# Object files for target MissingNumberInArray
MissingNumberInArray_OBJECTS = \
"CMakeFiles/MissingNumberInArray.dir/main.cpp.o"

# External object files for target MissingNumberInArray
MissingNumberInArray_EXTERNAL_OBJECTS =

MissingNumberInArray: CMakeFiles/MissingNumberInArray.dir/main.cpp.o
MissingNumberInArray: CMakeFiles/MissingNumberInArray.dir/build.make
MissingNumberInArray: CMakeFiles/MissingNumberInArray.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/selman/Google Drive/Master/First Year/First semester/Competitive programming and contests/Github/CompatitiveProgramming/MissingNumberInArray/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MissingNumberInArray"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MissingNumberInArray.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MissingNumberInArray.dir/build: MissingNumberInArray

.PHONY : CMakeFiles/MissingNumberInArray.dir/build

CMakeFiles/MissingNumberInArray.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MissingNumberInArray.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MissingNumberInArray.dir/clean

CMakeFiles/MissingNumberInArray.dir/depend:
	cd "/Users/selman/Google Drive/Master/First Year/First semester/Competitive programming and contests/Github/CompatitiveProgramming/MissingNumberInArray/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/selman/Google Drive/Master/First Year/First semester/Competitive programming and contests/Github/CompatitiveProgramming/MissingNumberInArray" "/Users/selman/Google Drive/Master/First Year/First semester/Competitive programming and contests/Github/CompatitiveProgramming/MissingNumberInArray" "/Users/selman/Google Drive/Master/First Year/First semester/Competitive programming and contests/Github/CompatitiveProgramming/MissingNumberInArray/cmake-build-debug" "/Users/selman/Google Drive/Master/First Year/First semester/Competitive programming and contests/Github/CompatitiveProgramming/MissingNumberInArray/cmake-build-debug" "/Users/selman/Google Drive/Master/First Year/First semester/Competitive programming and contests/Github/CompatitiveProgramming/MissingNumberInArray/cmake-build-debug/CMakeFiles/MissingNumberInArray.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/MissingNumberInArray.dir/depend
