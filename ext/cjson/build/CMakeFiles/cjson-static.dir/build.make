# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/escapechar/saturn/ext/cjson

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/escapechar/saturn/ext/cjson/build

# Include any dependencies generated for this target.
include CMakeFiles/cjson-static.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cjson-static.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cjson-static.dir/flags.make

CMakeFiles/cjson-static.dir/cJSON.c.o: CMakeFiles/cjson-static.dir/flags.make
CMakeFiles/cjson-static.dir/cJSON.c.o: ../cJSON.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/escapechar/saturn/ext/cjson/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cjson-static.dir/cJSON.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cjson-static.dir/cJSON.c.o   -c /home/escapechar/saturn/ext/cjson/cJSON.c

CMakeFiles/cjson-static.dir/cJSON.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cjson-static.dir/cJSON.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/escapechar/saturn/ext/cjson/cJSON.c > CMakeFiles/cjson-static.dir/cJSON.c.i

CMakeFiles/cjson-static.dir/cJSON.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cjson-static.dir/cJSON.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/escapechar/saturn/ext/cjson/cJSON.c -o CMakeFiles/cjson-static.dir/cJSON.c.s

# Object files for target cjson-static
cjson__static_OBJECTS = \
"CMakeFiles/cjson-static.dir/cJSON.c.o"

# External object files for target cjson-static
cjson__static_EXTERNAL_OBJECTS =

libcjson.a: CMakeFiles/cjson-static.dir/cJSON.c.o
libcjson.a: CMakeFiles/cjson-static.dir/build.make
libcjson.a: CMakeFiles/cjson-static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/escapechar/saturn/ext/cjson/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libcjson.a"
	$(CMAKE_COMMAND) -P CMakeFiles/cjson-static.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cjson-static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cjson-static.dir/build: libcjson.a

.PHONY : CMakeFiles/cjson-static.dir/build

CMakeFiles/cjson-static.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cjson-static.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cjson-static.dir/clean

CMakeFiles/cjson-static.dir/depend:
	cd /home/escapechar/saturn/ext/cjson/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/escapechar/saturn/ext/cjson /home/escapechar/saturn/ext/cjson /home/escapechar/saturn/ext/cjson/build /home/escapechar/saturn/ext/cjson/build /home/escapechar/saturn/ext/cjson/build/CMakeFiles/cjson-static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cjson-static.dir/depend

