# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /Users/amitcharran/CLionProjects/Project6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/amitcharran/CLionProjects/Project6/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Project6.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Project6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project6.dir/flags.make

CMakeFiles/Project6.dir/main.cpp.o: CMakeFiles/Project6.dir/flags.make
CMakeFiles/Project6.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/amitcharran/CLionProjects/Project6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project6.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project6.dir/main.cpp.o -c /Users/amitcharran/CLionProjects/Project6/main.cpp

CMakeFiles/Project6.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project6.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/amitcharran/CLionProjects/Project6/main.cpp > CMakeFiles/Project6.dir/main.cpp.i

CMakeFiles/Project6.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project6.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/amitcharran/CLionProjects/Project6/main.cpp -o CMakeFiles/Project6.dir/main.cpp.s

# Object files for target Project6
Project6_OBJECTS = \
"CMakeFiles/Project6.dir/main.cpp.o"

# External object files for target Project6
Project6_EXTERNAL_OBJECTS =

Project6: CMakeFiles/Project6.dir/main.cpp.o
Project6: CMakeFiles/Project6.dir/build.make
Project6: CMakeFiles/Project6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/amitcharran/CLionProjects/Project6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Project6"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Project6.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project6.dir/build: Project6

.PHONY : CMakeFiles/Project6.dir/build

CMakeFiles/Project6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Project6.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Project6.dir/clean

CMakeFiles/Project6.dir/depend:
	cd /Users/amitcharran/CLionProjects/Project6/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/amitcharran/CLionProjects/Project6 /Users/amitcharran/CLionProjects/Project6 /Users/amitcharran/CLionProjects/Project6/cmake-build-debug /Users/amitcharran/CLionProjects/Project6/cmake-build-debug /Users/amitcharran/CLionProjects/Project6/cmake-build-debug/CMakeFiles/Project6.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Project6.dir/depend

