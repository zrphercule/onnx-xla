# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /private/home/jainv/onnx-xla

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /private/home/jainv/onnx-xla

# Include any dependencies generated for this target.
include CMakeFiles/xla_client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/xla_client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/xla_client.dir/flags.make

CMakeFiles/xla_client.dir/test_client.cc.o: CMakeFiles/xla_client.dir/flags.make
CMakeFiles/xla_client.dir/test_client.cc.o: test_client.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/private/home/jainv/onnx-xla/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/xla_client.dir/test_client.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/xla_client.dir/test_client.cc.o -c /private/home/jainv/onnx-xla/test_client.cc

CMakeFiles/xla_client.dir/test_client.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xla_client.dir/test_client.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /private/home/jainv/onnx-xla/test_client.cc > CMakeFiles/xla_client.dir/test_client.cc.i

CMakeFiles/xla_client.dir/test_client.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xla_client.dir/test_client.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /private/home/jainv/onnx-xla/test_client.cc -o CMakeFiles/xla_client.dir/test_client.cc.s

CMakeFiles/xla_client.dir/test_client.cc.o.requires:

.PHONY : CMakeFiles/xla_client.dir/test_client.cc.o.requires

CMakeFiles/xla_client.dir/test_client.cc.o.provides: CMakeFiles/xla_client.dir/test_client.cc.o.requires
	$(MAKE) -f CMakeFiles/xla_client.dir/build.make CMakeFiles/xla_client.dir/test_client.cc.o.provides.build
.PHONY : CMakeFiles/xla_client.dir/test_client.cc.o.provides

CMakeFiles/xla_client.dir/test_client.cc.o.provides.build: CMakeFiles/xla_client.dir/test_client.cc.o


# Object files for target xla_client
xla_client_OBJECTS = \
"CMakeFiles/xla_client.dir/test_client.cc.o"

# External object files for target xla_client
xla_client_EXTERNAL_OBJECTS =

xla_client: CMakeFiles/xla_client.dir/test_client.cc.o
xla_client: CMakeFiles/xla_client.dir/build.make
xla_client: /usr/local/lib/libprotobuf.so
xla_client: libxla_pb.a
xla_client: CMakeFiles/xla_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/private/home/jainv/onnx-xla/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable xla_client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/xla_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/xla_client.dir/build: xla_client

.PHONY : CMakeFiles/xla_client.dir/build

CMakeFiles/xla_client.dir/requires: CMakeFiles/xla_client.dir/test_client.cc.o.requires

.PHONY : CMakeFiles/xla_client.dir/requires

CMakeFiles/xla_client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/xla_client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/xla_client.dir/clean

CMakeFiles/xla_client.dir/depend:
	cd /private/home/jainv/onnx-xla && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /private/home/jainv/onnx-xla /private/home/jainv/onnx-xla /private/home/jainv/onnx-xla /private/home/jainv/onnx-xla /private/home/jainv/onnx-xla/CMakeFiles/xla_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/xla_client.dir/depend

