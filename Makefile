# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /private/home/jainv/onnx-xla/CMakeFiles /private/home/jainv/onnx-xla/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /private/home/jainv/onnx-xla/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named xla_o

# Build rule for target.
xla_o: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 xla_o
.PHONY : xla_o

# fast build rule for target.
xla_o/fast:
	$(MAKE) -f CMakeFiles/xla_o.dir/build.make CMakeFiles/xla_o.dir/build
.PHONY : xla_o/fast

test_client.o: test_client.cc.o

.PHONY : test_client.o

# target to build an object file
test_client.cc.o:
	$(MAKE) -f CMakeFiles/xla_o.dir/build.make CMakeFiles/xla_o.dir/test_client.cc.o
.PHONY : test_client.cc.o

test_client.i: test_client.cc.i

.PHONY : test_client.i

# target to preprocess a source file
test_client.cc.i:
	$(MAKE) -f CMakeFiles/xla_o.dir/build.make CMakeFiles/xla_o.dir/test_client.cc.i
.PHONY : test_client.cc.i

test_client.s: test_client.cc.s

.PHONY : test_client.s

# target to generate assembly for a file
test_client.cc.s:
	$(MAKE) -f CMakeFiles/xla_o.dir/build.make CMakeFiles/xla_o.dir/test_client.cc.s
.PHONY : test_client.cc.s

xla_pb/tensorflow/compiler/xla/rpc/xla_service.grpc.pb.o: xla_pb/tensorflow/compiler/xla/rpc/xla_service.grpc.pb.cc.o

.PHONY : xla_pb/tensorflow/compiler/xla/rpc/xla_service.grpc.pb.o

# target to build an object file
xla_pb/tensorflow/compiler/xla/rpc/xla_service.grpc.pb.cc.o:
	$(MAKE) -f CMakeFiles/xla_o.dir/build.make CMakeFiles/xla_o.dir/xla_pb/tensorflow/compiler/xla/rpc/xla_service.grpc.pb.cc.o
.PHONY : xla_pb/tensorflow/compiler/xla/rpc/xla_service.grpc.pb.cc.o

xla_pb/tensorflow/compiler/xla/rpc/xla_service.grpc.pb.i: xla_pb/tensorflow/compiler/xla/rpc/xla_service.grpc.pb.cc.i

.PHONY : xla_pb/tensorflow/compiler/xla/rpc/xla_service.grpc.pb.i

# target to preprocess a source file
xla_pb/tensorflow/compiler/xla/rpc/xla_service.grpc.pb.cc.i:
	$(MAKE) -f CMakeFiles/xla_o.dir/build.make CMakeFiles/xla_o.dir/xla_pb/tensorflow/compiler/xla/rpc/xla_service.grpc.pb.cc.i
.PHONY : xla_pb/tensorflow/compiler/xla/rpc/xla_service.grpc.pb.cc.i

xla_pb/tensorflow/compiler/xla/rpc/xla_service.grpc.pb.s: xla_pb/tensorflow/compiler/xla/rpc/xla_service.grpc.pb.cc.s

.PHONY : xla_pb/tensorflow/compiler/xla/rpc/xla_service.grpc.pb.s

# target to generate assembly for a file
xla_pb/tensorflow/compiler/xla/rpc/xla_service.grpc.pb.cc.s:
	$(MAKE) -f CMakeFiles/xla_o.dir/build.make CMakeFiles/xla_o.dir/xla_pb/tensorflow/compiler/xla/rpc/xla_service.grpc.pb.cc.s
.PHONY : xla_pb/tensorflow/compiler/xla/rpc/xla_service.grpc.pb.cc.s

xla_pb/tensorflow/compiler/xla/rpc/xla_service.pb.o: xla_pb/tensorflow/compiler/xla/rpc/xla_service.pb.cc.o

.PHONY : xla_pb/tensorflow/compiler/xla/rpc/xla_service.pb.o

# target to build an object file
xla_pb/tensorflow/compiler/xla/rpc/xla_service.pb.cc.o:
	$(MAKE) -f CMakeFiles/xla_o.dir/build.make CMakeFiles/xla_o.dir/xla_pb/tensorflow/compiler/xla/rpc/xla_service.pb.cc.o
.PHONY : xla_pb/tensorflow/compiler/xla/rpc/xla_service.pb.cc.o

xla_pb/tensorflow/compiler/xla/rpc/xla_service.pb.i: xla_pb/tensorflow/compiler/xla/rpc/xla_service.pb.cc.i

.PHONY : xla_pb/tensorflow/compiler/xla/rpc/xla_service.pb.i

# target to preprocess a source file
xla_pb/tensorflow/compiler/xla/rpc/xla_service.pb.cc.i:
	$(MAKE) -f CMakeFiles/xla_o.dir/build.make CMakeFiles/xla_o.dir/xla_pb/tensorflow/compiler/xla/rpc/xla_service.pb.cc.i
.PHONY : xla_pb/tensorflow/compiler/xla/rpc/xla_service.pb.cc.i

xla_pb/tensorflow/compiler/xla/rpc/xla_service.pb.s: xla_pb/tensorflow/compiler/xla/rpc/xla_service.pb.cc.s

.PHONY : xla_pb/tensorflow/compiler/xla/rpc/xla_service.pb.s

# target to generate assembly for a file
xla_pb/tensorflow/compiler/xla/rpc/xla_service.pb.cc.s:
	$(MAKE) -f CMakeFiles/xla_o.dir/build.make CMakeFiles/xla_o.dir/xla_pb/tensorflow/compiler/xla/rpc/xla_service.pb.cc.s
.PHONY : xla_pb/tensorflow/compiler/xla/rpc/xla_service.pb.cc.s

xla_pb/tensorflow/compiler/xla/service/hlo.pb.o: xla_pb/tensorflow/compiler/xla/service/hlo.pb.cc.o

.PHONY : xla_pb/tensorflow/compiler/xla/service/hlo.pb.o

# target to build an object file
xla_pb/tensorflow/compiler/xla/service/hlo.pb.cc.o:
	$(MAKE) -f CMakeFiles/xla_o.dir/build.make CMakeFiles/xla_o.dir/xla_pb/tensorflow/compiler/xla/service/hlo.pb.cc.o
.PHONY : xla_pb/tensorflow/compiler/xla/service/hlo.pb.cc.o

xla_pb/tensorflow/compiler/xla/service/hlo.pb.i: xla_pb/tensorflow/compiler/xla/service/hlo.pb.cc.i

.PHONY : xla_pb/tensorflow/compiler/xla/service/hlo.pb.i

# target to preprocess a source file
xla_pb/tensorflow/compiler/xla/service/hlo.pb.cc.i:
	$(MAKE) -f CMakeFiles/xla_o.dir/build.make CMakeFiles/xla_o.dir/xla_pb/tensorflow/compiler/xla/service/hlo.pb.cc.i
.PHONY : xla_pb/tensorflow/compiler/xla/service/hlo.pb.cc.i

xla_pb/tensorflow/compiler/xla/service/hlo.pb.s: xla_pb/tensorflow/compiler/xla/service/hlo.pb.cc.s

.PHONY : xla_pb/tensorflow/compiler/xla/service/hlo.pb.s

# target to generate assembly for a file
xla_pb/tensorflow/compiler/xla/service/hlo.pb.cc.s:
	$(MAKE) -f CMakeFiles/xla_o.dir/build.make CMakeFiles/xla_o.dir/xla_pb/tensorflow/compiler/xla/service/hlo.pb.cc.s
.PHONY : xla_pb/tensorflow/compiler/xla/service/hlo.pb.cc.s

xla_pb/tensorflow/compiler/xla/service/hlo_profile_printer_data.pb.o: xla_pb/tensorflow/compiler/xla/service/hlo_profile_printer_data.pb.cc.o

.PHONY : xla_pb/tensorflow/compiler/xla/service/hlo_profile_printer_data.pb.o

# target to build an object file
xla_pb/tensorflow/compiler/xla/service/hlo_profile_printer_data.pb.cc.o:
	$(MAKE) -f CMakeFiles/xla_o.dir/build.make CMakeFiles/xla_o.dir/xla_pb/tensorflow/compiler/xla/service/hlo_profile_printer_data.pb.cc.o
.PHONY : xla_pb/tensorflow/compiler/xla/service/hlo_profile_printer_data.pb.cc.o

xla_pb/tensorflow/compiler/xla/service/hlo_profile_printer_data.pb.i: xla_pb/tensorflow/compiler/xla/service/hlo_profile_printer_data.pb.cc.i

.PHONY : xla_pb/tensorflow/compiler/xla/service/hlo_profile_printer_data.pb.i

# target to preprocess a source file
xla_pb/tensorflow/compiler/xla/service/hlo_profile_printer_data.pb.cc.i:
	$(MAKE) -f CMakeFiles/xla_o.dir/build.make CMakeFiles/xla_o.dir/xla_pb/tensorflow/compiler/xla/service/hlo_profile_printer_data.pb.cc.i
.PHONY : xla_pb/tensorflow/compiler/xla/service/hlo_profile_printer_data.pb.cc.i

xla_pb/tensorflow/compiler/xla/service/hlo_profile_printer_data.pb.s: xla_pb/tensorflow/compiler/xla/service/hlo_profile_printer_data.pb.cc.s

.PHONY : xla_pb/tensorflow/compiler/xla/service/hlo_profile_printer_data.pb.s

# target to generate assembly for a file
xla_pb/tensorflow/compiler/xla/service/hlo_profile_printer_data.pb.cc.s:
	$(MAKE) -f CMakeFiles/xla_o.dir/build.make CMakeFiles/xla_o.dir/xla_pb/tensorflow/compiler/xla/service/hlo_profile_printer_data.pb.cc.s
.PHONY : xla_pb/tensorflow/compiler/xla/service/hlo_profile_printer_data.pb.cc.s

xla_pb/tensorflow/compiler/xla/xla.pb.o: xla_pb/tensorflow/compiler/xla/xla.pb.cc.o

.PHONY : xla_pb/tensorflow/compiler/xla/xla.pb.o

# target to build an object file
xla_pb/tensorflow/compiler/xla/xla.pb.cc.o:
	$(MAKE) -f CMakeFiles/xla_o.dir/build.make CMakeFiles/xla_o.dir/xla_pb/tensorflow/compiler/xla/xla.pb.cc.o
.PHONY : xla_pb/tensorflow/compiler/xla/xla.pb.cc.o

xla_pb/tensorflow/compiler/xla/xla.pb.i: xla_pb/tensorflow/compiler/xla/xla.pb.cc.i

.PHONY : xla_pb/tensorflow/compiler/xla/xla.pb.i

# target to preprocess a source file
xla_pb/tensorflow/compiler/xla/xla.pb.cc.i:
	$(MAKE) -f CMakeFiles/xla_o.dir/build.make CMakeFiles/xla_o.dir/xla_pb/tensorflow/compiler/xla/xla.pb.cc.i
.PHONY : xla_pb/tensorflow/compiler/xla/xla.pb.cc.i

xla_pb/tensorflow/compiler/xla/xla.pb.s: xla_pb/tensorflow/compiler/xla/xla.pb.cc.s

.PHONY : xla_pb/tensorflow/compiler/xla/xla.pb.s

# target to generate assembly for a file
xla_pb/tensorflow/compiler/xla/xla.pb.cc.s:
	$(MAKE) -f CMakeFiles/xla_o.dir/build.make CMakeFiles/xla_o.dir/xla_pb/tensorflow/compiler/xla/xla.pb.cc.s
.PHONY : xla_pb/tensorflow/compiler/xla/xla.pb.cc.s

xla_pb/tensorflow/compiler/xla/xla_data.pb.o: xla_pb/tensorflow/compiler/xla/xla_data.pb.cc.o

.PHONY : xla_pb/tensorflow/compiler/xla/xla_data.pb.o

# target to build an object file
xla_pb/tensorflow/compiler/xla/xla_data.pb.cc.o:
	$(MAKE) -f CMakeFiles/xla_o.dir/build.make CMakeFiles/xla_o.dir/xla_pb/tensorflow/compiler/xla/xla_data.pb.cc.o
.PHONY : xla_pb/tensorflow/compiler/xla/xla_data.pb.cc.o

xla_pb/tensorflow/compiler/xla/xla_data.pb.i: xla_pb/tensorflow/compiler/xla/xla_data.pb.cc.i

.PHONY : xla_pb/tensorflow/compiler/xla/xla_data.pb.i

# target to preprocess a source file
xla_pb/tensorflow/compiler/xla/xla_data.pb.cc.i:
	$(MAKE) -f CMakeFiles/xla_o.dir/build.make CMakeFiles/xla_o.dir/xla_pb/tensorflow/compiler/xla/xla_data.pb.cc.i
.PHONY : xla_pb/tensorflow/compiler/xla/xla_data.pb.cc.i

xla_pb/tensorflow/compiler/xla/xla_data.pb.s: xla_pb/tensorflow/compiler/xla/xla_data.pb.cc.s

.PHONY : xla_pb/tensorflow/compiler/xla/xla_data.pb.s

# target to generate assembly for a file
xla_pb/tensorflow/compiler/xla/xla_data.pb.cc.s:
	$(MAKE) -f CMakeFiles/xla_o.dir/build.make CMakeFiles/xla_o.dir/xla_pb/tensorflow/compiler/xla/xla_data.pb.cc.s
.PHONY : xla_pb/tensorflow/compiler/xla/xla_data.pb.cc.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... xla_o"
	@echo "... test_client.o"
	@echo "... test_client.i"
	@echo "... test_client.s"
	@echo "... xla_pb/tensorflow/compiler/xla/rpc/xla_service.grpc.pb.o"
	@echo "... xla_pb/tensorflow/compiler/xla/rpc/xla_service.grpc.pb.i"
	@echo "... xla_pb/tensorflow/compiler/xla/rpc/xla_service.grpc.pb.s"
	@echo "... xla_pb/tensorflow/compiler/xla/rpc/xla_service.pb.o"
	@echo "... xla_pb/tensorflow/compiler/xla/rpc/xla_service.pb.i"
	@echo "... xla_pb/tensorflow/compiler/xla/rpc/xla_service.pb.s"
	@echo "... xla_pb/tensorflow/compiler/xla/service/hlo.pb.o"
	@echo "... xla_pb/tensorflow/compiler/xla/service/hlo.pb.i"
	@echo "... xla_pb/tensorflow/compiler/xla/service/hlo.pb.s"
	@echo "... xla_pb/tensorflow/compiler/xla/service/hlo_profile_printer_data.pb.o"
	@echo "... xla_pb/tensorflow/compiler/xla/service/hlo_profile_printer_data.pb.i"
	@echo "... xla_pb/tensorflow/compiler/xla/service/hlo_profile_printer_data.pb.s"
	@echo "... xla_pb/tensorflow/compiler/xla/xla.pb.o"
	@echo "... xla_pb/tensorflow/compiler/xla/xla.pb.i"
	@echo "... xla_pb/tensorflow/compiler/xla/xla.pb.s"
	@echo "... xla_pb/tensorflow/compiler/xla/xla_data.pb.o"
	@echo "... xla_pb/tensorflow/compiler/xla/xla_data.pb.i"
	@echo "... xla_pb/tensorflow/compiler/xla/xla_data.pb.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

