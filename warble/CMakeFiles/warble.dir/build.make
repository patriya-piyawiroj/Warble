# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/vagrant/csci499_patriya-piyawiroj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vagrant/csci499_patriya-piyawiroj

# Include any dependencies generated for this target.
include warble/CMakeFiles/warble.dir/depend.make

# Include the progress variables for this target.
include warble/CMakeFiles/warble.dir/progress.make

# Include the compile flags for this target's objects.
include warble/CMakeFiles/warble.dir/flags.make

warble/dist/warble.pb.cc: protos/warble.proto
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/vagrant/csci499_patriya-piyawiroj/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating dist/warble.pb.cc, dist/warble.pb.h, dist/warble.grpc.pb.cc, dist/warble.grpc.pb.h"
	cd /home/vagrant/csci499_patriya-piyawiroj/warble && /usr/local/bin/protoc --grpc_out /home/vagrant/csci499_patriya-piyawiroj/warble/dist --cpp_out /home/vagrant/csci499_patriya-piyawiroj/warble/dist -I /home/vagrant/csci499_patriya-piyawiroj/protos --plugin=protoc-gen-grpc="/usr/local/bin/grpc_cpp_plugin" /home/vagrant/csci499_patriya-piyawiroj/protos/warble.proto

warble/dist/warble.pb.h: warble/dist/warble.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate warble/dist/warble.pb.h

warble/dist/warble.grpc.pb.cc: warble/dist/warble.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate warble/dist/warble.grpc.pb.cc

warble/dist/warble.grpc.pb.h: warble/dist/warble.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate warble/dist/warble.grpc.pb.h

warble/CMakeFiles/warble.dir/warble_cli.cc.o: warble/CMakeFiles/warble.dir/flags.make
warble/CMakeFiles/warble.dir/warble_cli.cc.o: warble/warble_cli.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vagrant/csci499_patriya-piyawiroj/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object warble/CMakeFiles/warble.dir/warble_cli.cc.o"
	cd /home/vagrant/csci499_patriya-piyawiroj/warble && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/warble.dir/warble_cli.cc.o -c /home/vagrant/csci499_patriya-piyawiroj/warble/warble_cli.cc

warble/CMakeFiles/warble.dir/warble_cli.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/warble.dir/warble_cli.cc.i"
	cd /home/vagrant/csci499_patriya-piyawiroj/warble && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vagrant/csci499_patriya-piyawiroj/warble/warble_cli.cc > CMakeFiles/warble.dir/warble_cli.cc.i

warble/CMakeFiles/warble.dir/warble_cli.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/warble.dir/warble_cli.cc.s"
	cd /home/vagrant/csci499_patriya-piyawiroj/warble && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vagrant/csci499_patriya-piyawiroj/warble/warble_cli.cc -o CMakeFiles/warble.dir/warble_cli.cc.s

warble/CMakeFiles/warble.dir/warble_cli.cc.o.requires:

.PHONY : warble/CMakeFiles/warble.dir/warble_cli.cc.o.requires

warble/CMakeFiles/warble.dir/warble_cli.cc.o.provides: warble/CMakeFiles/warble.dir/warble_cli.cc.o.requires
	$(MAKE) -f warble/CMakeFiles/warble.dir/build.make warble/CMakeFiles/warble.dir/warble_cli.cc.o.provides.build
.PHONY : warble/CMakeFiles/warble.dir/warble_cli.cc.o.provides

warble/CMakeFiles/warble.dir/warble_cli.cc.o.provides.build: warble/CMakeFiles/warble.dir/warble_cli.cc.o


warble/CMakeFiles/warble.dir/mock_service.cc.o: warble/CMakeFiles/warble.dir/flags.make
warble/CMakeFiles/warble.dir/mock_service.cc.o: warble/mock_service.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vagrant/csci499_patriya-piyawiroj/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object warble/CMakeFiles/warble.dir/mock_service.cc.o"
	cd /home/vagrant/csci499_patriya-piyawiroj/warble && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/warble.dir/mock_service.cc.o -c /home/vagrant/csci499_patriya-piyawiroj/warble/mock_service.cc

warble/CMakeFiles/warble.dir/mock_service.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/warble.dir/mock_service.cc.i"
	cd /home/vagrant/csci499_patriya-piyawiroj/warble && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vagrant/csci499_patriya-piyawiroj/warble/mock_service.cc > CMakeFiles/warble.dir/mock_service.cc.i

warble/CMakeFiles/warble.dir/mock_service.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/warble.dir/mock_service.cc.s"
	cd /home/vagrant/csci499_patriya-piyawiroj/warble && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vagrant/csci499_patriya-piyawiroj/warble/mock_service.cc -o CMakeFiles/warble.dir/mock_service.cc.s

warble/CMakeFiles/warble.dir/mock_service.cc.o.requires:

.PHONY : warble/CMakeFiles/warble.dir/mock_service.cc.o.requires

warble/CMakeFiles/warble.dir/mock_service.cc.o.provides: warble/CMakeFiles/warble.dir/mock_service.cc.o.requires
	$(MAKE) -f warble/CMakeFiles/warble.dir/build.make warble/CMakeFiles/warble.dir/mock_service.cc.o.provides.build
.PHONY : warble/CMakeFiles/warble.dir/mock_service.cc.o.provides

warble/CMakeFiles/warble.dir/mock_service.cc.o.provides.build: warble/CMakeFiles/warble.dir/mock_service.cc.o


warble/CMakeFiles/warble.dir/store.cc.o: warble/CMakeFiles/warble.dir/flags.make
warble/CMakeFiles/warble.dir/store.cc.o: warble/store.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vagrant/csci499_patriya-piyawiroj/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object warble/CMakeFiles/warble.dir/store.cc.o"
	cd /home/vagrant/csci499_patriya-piyawiroj/warble && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/warble.dir/store.cc.o -c /home/vagrant/csci499_patriya-piyawiroj/warble/store.cc

warble/CMakeFiles/warble.dir/store.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/warble.dir/store.cc.i"
	cd /home/vagrant/csci499_patriya-piyawiroj/warble && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vagrant/csci499_patriya-piyawiroj/warble/store.cc > CMakeFiles/warble.dir/store.cc.i

warble/CMakeFiles/warble.dir/store.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/warble.dir/store.cc.s"
	cd /home/vagrant/csci499_patriya-piyawiroj/warble && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vagrant/csci499_patriya-piyawiroj/warble/store.cc -o CMakeFiles/warble.dir/store.cc.s

warble/CMakeFiles/warble.dir/store.cc.o.requires:

.PHONY : warble/CMakeFiles/warble.dir/store.cc.o.requires

warble/CMakeFiles/warble.dir/store.cc.o.provides: warble/CMakeFiles/warble.dir/store.cc.o.requires
	$(MAKE) -f warble/CMakeFiles/warble.dir/build.make warble/CMakeFiles/warble.dir/store.cc.o.provides.build
.PHONY : warble/CMakeFiles/warble.dir/store.cc.o.provides

warble/CMakeFiles/warble.dir/store.cc.o.provides.build: warble/CMakeFiles/warble.dir/store.cc.o


warble/CMakeFiles/warble.dir/dist/warble.pb.cc.o: warble/CMakeFiles/warble.dir/flags.make
warble/CMakeFiles/warble.dir/dist/warble.pb.cc.o: warble/dist/warble.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vagrant/csci499_patriya-piyawiroj/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object warble/CMakeFiles/warble.dir/dist/warble.pb.cc.o"
	cd /home/vagrant/csci499_patriya-piyawiroj/warble && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/warble.dir/dist/warble.pb.cc.o -c /home/vagrant/csci499_patriya-piyawiroj/warble/dist/warble.pb.cc

warble/CMakeFiles/warble.dir/dist/warble.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/warble.dir/dist/warble.pb.cc.i"
	cd /home/vagrant/csci499_patriya-piyawiroj/warble && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vagrant/csci499_patriya-piyawiroj/warble/dist/warble.pb.cc > CMakeFiles/warble.dir/dist/warble.pb.cc.i

warble/CMakeFiles/warble.dir/dist/warble.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/warble.dir/dist/warble.pb.cc.s"
	cd /home/vagrant/csci499_patriya-piyawiroj/warble && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vagrant/csci499_patriya-piyawiroj/warble/dist/warble.pb.cc -o CMakeFiles/warble.dir/dist/warble.pb.cc.s

warble/CMakeFiles/warble.dir/dist/warble.pb.cc.o.requires:

.PHONY : warble/CMakeFiles/warble.dir/dist/warble.pb.cc.o.requires

warble/CMakeFiles/warble.dir/dist/warble.pb.cc.o.provides: warble/CMakeFiles/warble.dir/dist/warble.pb.cc.o.requires
	$(MAKE) -f warble/CMakeFiles/warble.dir/build.make warble/CMakeFiles/warble.dir/dist/warble.pb.cc.o.provides.build
.PHONY : warble/CMakeFiles/warble.dir/dist/warble.pb.cc.o.provides

warble/CMakeFiles/warble.dir/dist/warble.pb.cc.o.provides.build: warble/CMakeFiles/warble.dir/dist/warble.pb.cc.o


warble/CMakeFiles/warble.dir/dist/warble.grpc.pb.cc.o: warble/CMakeFiles/warble.dir/flags.make
warble/CMakeFiles/warble.dir/dist/warble.grpc.pb.cc.o: warble/dist/warble.grpc.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vagrant/csci499_patriya-piyawiroj/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object warble/CMakeFiles/warble.dir/dist/warble.grpc.pb.cc.o"
	cd /home/vagrant/csci499_patriya-piyawiroj/warble && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/warble.dir/dist/warble.grpc.pb.cc.o -c /home/vagrant/csci499_patriya-piyawiroj/warble/dist/warble.grpc.pb.cc

warble/CMakeFiles/warble.dir/dist/warble.grpc.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/warble.dir/dist/warble.grpc.pb.cc.i"
	cd /home/vagrant/csci499_patriya-piyawiroj/warble && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vagrant/csci499_patriya-piyawiroj/warble/dist/warble.grpc.pb.cc > CMakeFiles/warble.dir/dist/warble.grpc.pb.cc.i

warble/CMakeFiles/warble.dir/dist/warble.grpc.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/warble.dir/dist/warble.grpc.pb.cc.s"
	cd /home/vagrant/csci499_patriya-piyawiroj/warble && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vagrant/csci499_patriya-piyawiroj/warble/dist/warble.grpc.pb.cc -o CMakeFiles/warble.dir/dist/warble.grpc.pb.cc.s

warble/CMakeFiles/warble.dir/dist/warble.grpc.pb.cc.o.requires:

.PHONY : warble/CMakeFiles/warble.dir/dist/warble.grpc.pb.cc.o.requires

warble/CMakeFiles/warble.dir/dist/warble.grpc.pb.cc.o.provides: warble/CMakeFiles/warble.dir/dist/warble.grpc.pb.cc.o.requires
	$(MAKE) -f warble/CMakeFiles/warble.dir/build.make warble/CMakeFiles/warble.dir/dist/warble.grpc.pb.cc.o.provides.build
.PHONY : warble/CMakeFiles/warble.dir/dist/warble.grpc.pb.cc.o.provides

warble/CMakeFiles/warble.dir/dist/warble.grpc.pb.cc.o.provides.build: warble/CMakeFiles/warble.dir/dist/warble.grpc.pb.cc.o


# Object files for target warble
warble_OBJECTS = \
"CMakeFiles/warble.dir/warble_cli.cc.o" \
"CMakeFiles/warble.dir/mock_service.cc.o" \
"CMakeFiles/warble.dir/store.cc.o" \
"CMakeFiles/warble.dir/dist/warble.pb.cc.o" \
"CMakeFiles/warble.dir/dist/warble.grpc.pb.cc.o"

# External object files for target warble
warble_EXTERNAL_OBJECTS =

warble/warble: warble/CMakeFiles/warble.dir/warble_cli.cc.o
warble/warble: warble/CMakeFiles/warble.dir/mock_service.cc.o
warble/warble: warble/CMakeFiles/warble.dir/store.cc.o
warble/warble: warble/CMakeFiles/warble.dir/dist/warble.pb.cc.o
warble/warble: warble/CMakeFiles/warble.dir/dist/warble.grpc.pb.cc.o
warble/warble: warble/CMakeFiles/warble.dir/build.make
warble/warble: /usr/local/lib/libprotobuf.a
warble/warble: /usr/local/lib/libgflags.a
warble/warble: /usr/local/lib/libglog.a
warble/warble: /usr/local/lib/libgflags.a
warble/warble: warble/CMakeFiles/warble.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vagrant/csci499_patriya-piyawiroj/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable warble"
	cd /home/vagrant/csci499_patriya-piyawiroj/warble && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/warble.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
warble/CMakeFiles/warble.dir/build: warble/warble

.PHONY : warble/CMakeFiles/warble.dir/build

warble/CMakeFiles/warble.dir/requires: warble/CMakeFiles/warble.dir/warble_cli.cc.o.requires
warble/CMakeFiles/warble.dir/requires: warble/CMakeFiles/warble.dir/mock_service.cc.o.requires
warble/CMakeFiles/warble.dir/requires: warble/CMakeFiles/warble.dir/store.cc.o.requires
warble/CMakeFiles/warble.dir/requires: warble/CMakeFiles/warble.dir/dist/warble.pb.cc.o.requires
warble/CMakeFiles/warble.dir/requires: warble/CMakeFiles/warble.dir/dist/warble.grpc.pb.cc.o.requires

.PHONY : warble/CMakeFiles/warble.dir/requires

warble/CMakeFiles/warble.dir/clean:
	cd /home/vagrant/csci499_patriya-piyawiroj/warble && $(CMAKE_COMMAND) -P CMakeFiles/warble.dir/cmake_clean.cmake
.PHONY : warble/CMakeFiles/warble.dir/clean

warble/CMakeFiles/warble.dir/depend: warble/dist/warble.pb.cc
warble/CMakeFiles/warble.dir/depend: warble/dist/warble.pb.h
warble/CMakeFiles/warble.dir/depend: warble/dist/warble.grpc.pb.cc
warble/CMakeFiles/warble.dir/depend: warble/dist/warble.grpc.pb.h
	cd /home/vagrant/csci499_patriya-piyawiroj && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vagrant/csci499_patriya-piyawiroj /home/vagrant/csci499_patriya-piyawiroj/warble /home/vagrant/csci499_patriya-piyawiroj /home/vagrant/csci499_patriya-piyawiroj/warble /home/vagrant/csci499_patriya-piyawiroj/warble/CMakeFiles/warble.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : warble/CMakeFiles/warble.dir/depend
