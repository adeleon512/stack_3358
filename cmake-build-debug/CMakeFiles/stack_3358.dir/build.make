# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = "C:\Program Files (x86)\JetBrains\CLion 2016.3.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\JetBrains\CLion 2016.3.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Adam\CLionProjects\stack_3358

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Adam\CLionProjects\stack_3358\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/stack_3358.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stack_3358.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stack_3358.dir/flags.make

CMakeFiles/stack_3358.dir/main.cpp.obj: CMakeFiles/stack_3358.dir/flags.make
CMakeFiles/stack_3358.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Adam\CLionProjects\stack_3358\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stack_3358.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\stack_3358.dir\main.cpp.obj -c C:\Users\Adam\CLionProjects\stack_3358\main.cpp

CMakeFiles/stack_3358.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stack_3358.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Adam\CLionProjects\stack_3358\main.cpp > CMakeFiles\stack_3358.dir\main.cpp.i

CMakeFiles/stack_3358.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stack_3358.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Adam\CLionProjects\stack_3358\main.cpp -o CMakeFiles\stack_3358.dir\main.cpp.s

CMakeFiles/stack_3358.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/stack_3358.dir/main.cpp.obj.requires

CMakeFiles/stack_3358.dir/main.cpp.obj.provides: CMakeFiles/stack_3358.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\stack_3358.dir\build.make CMakeFiles/stack_3358.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/stack_3358.dir/main.cpp.obj.provides

CMakeFiles/stack_3358.dir/main.cpp.obj.provides.build: CMakeFiles/stack_3358.dir/main.cpp.obj


# Object files for target stack_3358
stack_3358_OBJECTS = \
"CMakeFiles/stack_3358.dir/main.cpp.obj"

# External object files for target stack_3358
stack_3358_EXTERNAL_OBJECTS =

stack_3358.exe: CMakeFiles/stack_3358.dir/main.cpp.obj
stack_3358.exe: CMakeFiles/stack_3358.dir/build.make
stack_3358.exe: CMakeFiles/stack_3358.dir/linklibs.rsp
stack_3358.exe: CMakeFiles/stack_3358.dir/objects1.rsp
stack_3358.exe: CMakeFiles/stack_3358.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Adam\CLionProjects\stack_3358\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable stack_3358.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\stack_3358.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stack_3358.dir/build: stack_3358.exe

.PHONY : CMakeFiles/stack_3358.dir/build

CMakeFiles/stack_3358.dir/requires: CMakeFiles/stack_3358.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/stack_3358.dir/requires

CMakeFiles/stack_3358.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\stack_3358.dir\cmake_clean.cmake
.PHONY : CMakeFiles/stack_3358.dir/clean

CMakeFiles/stack_3358.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Adam\CLionProjects\stack_3358 C:\Users\Adam\CLionProjects\stack_3358 C:\Users\Adam\CLionProjects\stack_3358\cmake-build-debug C:\Users\Adam\CLionProjects\stack_3358\cmake-build-debug C:\Users\Adam\CLionProjects\stack_3358\cmake-build-debug\CMakeFiles\stack_3358.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stack_3358.dir/depend
