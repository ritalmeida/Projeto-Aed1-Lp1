# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Ritaa/Documents/FACULDADE/projeto_aed_lp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Ritaa/Documents/FACULDADE/projeto_aed_lp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/projeto_aed_lp.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/projeto_aed_lp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/projeto_aed_lp.dir/flags.make

CMakeFiles/projeto_aed_lp.dir/main.c.o: CMakeFiles/projeto_aed_lp.dir/flags.make
CMakeFiles/projeto_aed_lp.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Ritaa/Documents/FACULDADE/projeto_aed_lp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/projeto_aed_lp.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/projeto_aed_lp.dir/main.c.o -c /Users/Ritaa/Documents/FACULDADE/projeto_aed_lp/main.c

CMakeFiles/projeto_aed_lp.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projeto_aed_lp.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Ritaa/Documents/FACULDADE/projeto_aed_lp/main.c > CMakeFiles/projeto_aed_lp.dir/main.c.i

CMakeFiles/projeto_aed_lp.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projeto_aed_lp.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Ritaa/Documents/FACULDADE/projeto_aed_lp/main.c -o CMakeFiles/projeto_aed_lp.dir/main.c.s

CMakeFiles/projeto_aed_lp.dir/dados.c.o: CMakeFiles/projeto_aed_lp.dir/flags.make
CMakeFiles/projeto_aed_lp.dir/dados.c.o: ../dados.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Ritaa/Documents/FACULDADE/projeto_aed_lp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/projeto_aed_lp.dir/dados.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/projeto_aed_lp.dir/dados.c.o -c /Users/Ritaa/Documents/FACULDADE/projeto_aed_lp/dados.c

CMakeFiles/projeto_aed_lp.dir/dados.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projeto_aed_lp.dir/dados.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Ritaa/Documents/FACULDADE/projeto_aed_lp/dados.c > CMakeFiles/projeto_aed_lp.dir/dados.c.i

CMakeFiles/projeto_aed_lp.dir/dados.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projeto_aed_lp.dir/dados.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Ritaa/Documents/FACULDADE/projeto_aed_lp/dados.c -o CMakeFiles/projeto_aed_lp.dir/dados.c.s

CMakeFiles/projeto_aed_lp.dir/ficheiros.c.o: CMakeFiles/projeto_aed_lp.dir/flags.make
CMakeFiles/projeto_aed_lp.dir/ficheiros.c.o: ../ficheiros.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Ritaa/Documents/FACULDADE/projeto_aed_lp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/projeto_aed_lp.dir/ficheiros.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/projeto_aed_lp.dir/ficheiros.c.o -c /Users/Ritaa/Documents/FACULDADE/projeto_aed_lp/ficheiros.c

CMakeFiles/projeto_aed_lp.dir/ficheiros.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projeto_aed_lp.dir/ficheiros.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Ritaa/Documents/FACULDADE/projeto_aed_lp/ficheiros.c > CMakeFiles/projeto_aed_lp.dir/ficheiros.c.i

CMakeFiles/projeto_aed_lp.dir/ficheiros.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projeto_aed_lp.dir/ficheiros.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Ritaa/Documents/FACULDADE/projeto_aed_lp/ficheiros.c -o CMakeFiles/projeto_aed_lp.dir/ficheiros.c.s

CMakeFiles/projeto_aed_lp.dir/test/teste1.c.o: CMakeFiles/projeto_aed_lp.dir/flags.make
CMakeFiles/projeto_aed_lp.dir/test/teste1.c.o: ../test/teste1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Ritaa/Documents/FACULDADE/projeto_aed_lp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/projeto_aed_lp.dir/test/teste1.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/projeto_aed_lp.dir/test/teste1.c.o -c /Users/Ritaa/Documents/FACULDADE/projeto_aed_lp/test/teste1.c

CMakeFiles/projeto_aed_lp.dir/test/teste1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projeto_aed_lp.dir/test/teste1.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Ritaa/Documents/FACULDADE/projeto_aed_lp/test/teste1.c > CMakeFiles/projeto_aed_lp.dir/test/teste1.c.i

CMakeFiles/projeto_aed_lp.dir/test/teste1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projeto_aed_lp.dir/test/teste1.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Ritaa/Documents/FACULDADE/projeto_aed_lp/test/teste1.c -o CMakeFiles/projeto_aed_lp.dir/test/teste1.c.s

CMakeFiles/projeto_aed_lp.dir/algoritmoGenetico.c.o: CMakeFiles/projeto_aed_lp.dir/flags.make
CMakeFiles/projeto_aed_lp.dir/algoritmoGenetico.c.o: ../algoritmoGenetico.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Ritaa/Documents/FACULDADE/projeto_aed_lp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/projeto_aed_lp.dir/algoritmoGenetico.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/projeto_aed_lp.dir/algoritmoGenetico.c.o -c /Users/Ritaa/Documents/FACULDADE/projeto_aed_lp/algoritmoGenetico.c

CMakeFiles/projeto_aed_lp.dir/algoritmoGenetico.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projeto_aed_lp.dir/algoritmoGenetico.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Ritaa/Documents/FACULDADE/projeto_aed_lp/algoritmoGenetico.c > CMakeFiles/projeto_aed_lp.dir/algoritmoGenetico.c.i

CMakeFiles/projeto_aed_lp.dir/algoritmoGenetico.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projeto_aed_lp.dir/algoritmoGenetico.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Ritaa/Documents/FACULDADE/projeto_aed_lp/algoritmoGenetico.c -o CMakeFiles/projeto_aed_lp.dir/algoritmoGenetico.c.s

# Object files for target projeto_aed_lp
projeto_aed_lp_OBJECTS = \
"CMakeFiles/projeto_aed_lp.dir/main.c.o" \
"CMakeFiles/projeto_aed_lp.dir/dados.c.o" \
"CMakeFiles/projeto_aed_lp.dir/ficheiros.c.o" \
"CMakeFiles/projeto_aed_lp.dir/test/teste1.c.o" \
"CMakeFiles/projeto_aed_lp.dir/algoritmoGenetico.c.o"

# External object files for target projeto_aed_lp
projeto_aed_lp_EXTERNAL_OBJECTS =

projeto_aed_lp: CMakeFiles/projeto_aed_lp.dir/main.c.o
projeto_aed_lp: CMakeFiles/projeto_aed_lp.dir/dados.c.o
projeto_aed_lp: CMakeFiles/projeto_aed_lp.dir/ficheiros.c.o
projeto_aed_lp: CMakeFiles/projeto_aed_lp.dir/test/teste1.c.o
projeto_aed_lp: CMakeFiles/projeto_aed_lp.dir/algoritmoGenetico.c.o
projeto_aed_lp: CMakeFiles/projeto_aed_lp.dir/build.make
projeto_aed_lp: CMakeFiles/projeto_aed_lp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Ritaa/Documents/FACULDADE/projeto_aed_lp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable projeto_aed_lp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/projeto_aed_lp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/projeto_aed_lp.dir/build: projeto_aed_lp
.PHONY : CMakeFiles/projeto_aed_lp.dir/build

CMakeFiles/projeto_aed_lp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/projeto_aed_lp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/projeto_aed_lp.dir/clean

CMakeFiles/projeto_aed_lp.dir/depend:
	cd /Users/Ritaa/Documents/FACULDADE/projeto_aed_lp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Ritaa/Documents/FACULDADE/projeto_aed_lp /Users/Ritaa/Documents/FACULDADE/projeto_aed_lp /Users/Ritaa/Documents/FACULDADE/projeto_aed_lp/cmake-build-debug /Users/Ritaa/Documents/FACULDADE/projeto_aed_lp/cmake-build-debug /Users/Ritaa/Documents/FACULDADE/projeto_aed_lp/cmake-build-debug/CMakeFiles/projeto_aed_lp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/projeto_aed_lp.dir/depend

