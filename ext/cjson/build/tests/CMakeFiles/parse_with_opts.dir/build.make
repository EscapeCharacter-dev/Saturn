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
include tests/CMakeFiles/parse_with_opts.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/parse_with_opts.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/parse_with_opts.dir/flags.make

tests/CMakeFiles/parse_with_opts.dir/parse_with_opts.c.o: tests/CMakeFiles/parse_with_opts.dir/flags.make
tests/CMakeFiles/parse_with_opts.dir/parse_with_opts.c.o: ../tests/parse_with_opts.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/escapechar/saturn/ext/cjson/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/parse_with_opts.dir/parse_with_opts.c.o"
	cd /home/escapechar/saturn/ext/cjson/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/parse_with_opts.dir/parse_with_opts.c.o   -c /home/escapechar/saturn/ext/cjson/tests/parse_with_opts.c

tests/CMakeFiles/parse_with_opts.dir/parse_with_opts.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/parse_with_opts.dir/parse_with_opts.c.i"
	cd /home/escapechar/saturn/ext/cjson/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/escapechar/saturn/ext/cjson/tests/parse_with_opts.c > CMakeFiles/parse_with_opts.dir/parse_with_opts.c.i

tests/CMakeFiles/parse_with_opts.dir/parse_with_opts.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/parse_with_opts.dir/parse_with_opts.c.s"
	cd /home/escapechar/saturn/ext/cjson/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/escapechar/saturn/ext/cjson/tests/parse_with_opts.c -o CMakeFiles/parse_with_opts.dir/parse_with_opts.c.s

# Object files for target parse_with_opts
parse_with_opts_OBJECTS = \
"CMakeFiles/parse_with_opts.dir/parse_with_opts.c.o"

# External object files for target parse_with_opts
parse_with_opts_EXTERNAL_OBJECTS =

tests/parse_with_opts: tests/CMakeFiles/parse_with_opts.dir/parse_with_opts.c.o
tests/parse_with_opts: tests/CMakeFiles/parse_with_opts.dir/build.make
tests/parse_with_opts: libcjson.so.1.7.14
tests/parse_with_opts: tests/libunity.a
tests/parse_with_opts: tests/CMakeFiles/parse_with_opts.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/escapechar/saturn/ext/cjson/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable parse_with_opts"
	cd /home/escapechar/saturn/ext/cjson/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/parse_with_opts.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/parse_with_opts.dir/build: tests/parse_with_opts

.PHONY : tests/CMakeFiles/parse_with_opts.dir/build

tests/CMakeFiles/parse_with_opts.dir/clean:
	cd /home/escapechar/saturn/ext/cjson/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/parse_with_opts.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/parse_with_opts.dir/clean

tests/CMakeFiles/parse_with_opts.dir/depend:
	cd /home/escapechar/saturn/ext/cjson/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/escapechar/saturn/ext/cjson /home/escapechar/saturn/ext/cjson/tests /home/escapechar/saturn/ext/cjson/build /home/escapechar/saturn/ext/cjson/build/tests /home/escapechar/saturn/ext/cjson/build/tests/CMakeFiles/parse_with_opts.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/parse_with_opts.dir/depend

