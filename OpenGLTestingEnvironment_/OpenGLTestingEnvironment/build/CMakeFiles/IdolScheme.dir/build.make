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
CMAKE_SOURCE_DIR = /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/build

# Include any dependencies generated for this target.
include CMakeFiles/IdolScheme.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/IdolScheme.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/IdolScheme.dir/flags.make

CMakeFiles/IdolScheme.dir/assets/glad.c.o: CMakeFiles/IdolScheme.dir/flags.make
CMakeFiles/IdolScheme.dir/assets/glad.c.o: ../assets/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/IdolScheme.dir/assets/glad.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/IdolScheme.dir/assets/glad.c.o   -c /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/assets/glad.c

CMakeFiles/IdolScheme.dir/assets/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IdolScheme.dir/assets/glad.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/assets/glad.c > CMakeFiles/IdolScheme.dir/assets/glad.c.i

CMakeFiles/IdolScheme.dir/assets/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IdolScheme.dir/assets/glad.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/assets/glad.c -o CMakeFiles/IdolScheme.dir/assets/glad.c.s

CMakeFiles/IdolScheme.dir/assets/glad.c.o.requires:

.PHONY : CMakeFiles/IdolScheme.dir/assets/glad.c.o.requires

CMakeFiles/IdolScheme.dir/assets/glad.c.o.provides: CMakeFiles/IdolScheme.dir/assets/glad.c.o.requires
	$(MAKE) -f CMakeFiles/IdolScheme.dir/build.make CMakeFiles/IdolScheme.dir/assets/glad.c.o.provides.build
.PHONY : CMakeFiles/IdolScheme.dir/assets/glad.c.o.provides

CMakeFiles/IdolScheme.dir/assets/glad.c.o.provides.build: CMakeFiles/IdolScheme.dir/assets/glad.c.o


CMakeFiles/IdolScheme.dir/src/Vector3.cpp.o: CMakeFiles/IdolScheme.dir/flags.make
CMakeFiles/IdolScheme.dir/src/Vector3.cpp.o: ../src/Vector3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/IdolScheme.dir/src/Vector3.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/IdolScheme.dir/src/Vector3.cpp.o -c /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/Vector3.cpp

CMakeFiles/IdolScheme.dir/src/Vector3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IdolScheme.dir/src/Vector3.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/Vector3.cpp > CMakeFiles/IdolScheme.dir/src/Vector3.cpp.i

CMakeFiles/IdolScheme.dir/src/Vector3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IdolScheme.dir/src/Vector3.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/Vector3.cpp -o CMakeFiles/IdolScheme.dir/src/Vector3.cpp.s

CMakeFiles/IdolScheme.dir/src/Vector3.cpp.o.requires:

.PHONY : CMakeFiles/IdolScheme.dir/src/Vector3.cpp.o.requires

CMakeFiles/IdolScheme.dir/src/Vector3.cpp.o.provides: CMakeFiles/IdolScheme.dir/src/Vector3.cpp.o.requires
	$(MAKE) -f CMakeFiles/IdolScheme.dir/build.make CMakeFiles/IdolScheme.dir/src/Vector3.cpp.o.provides.build
.PHONY : CMakeFiles/IdolScheme.dir/src/Vector3.cpp.o.provides

CMakeFiles/IdolScheme.dir/src/Vector3.cpp.o.provides.build: CMakeFiles/IdolScheme.dir/src/Vector3.cpp.o


CMakeFiles/IdolScheme.dir/src/Triangle.cpp.o: CMakeFiles/IdolScheme.dir/flags.make
CMakeFiles/IdolScheme.dir/src/Triangle.cpp.o: ../src/Triangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/IdolScheme.dir/src/Triangle.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/IdolScheme.dir/src/Triangle.cpp.o -c /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/Triangle.cpp

CMakeFiles/IdolScheme.dir/src/Triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IdolScheme.dir/src/Triangle.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/Triangle.cpp > CMakeFiles/IdolScheme.dir/src/Triangle.cpp.i

CMakeFiles/IdolScheme.dir/src/Triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IdolScheme.dir/src/Triangle.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/Triangle.cpp -o CMakeFiles/IdolScheme.dir/src/Triangle.cpp.s

CMakeFiles/IdolScheme.dir/src/Triangle.cpp.o.requires:

.PHONY : CMakeFiles/IdolScheme.dir/src/Triangle.cpp.o.requires

CMakeFiles/IdolScheme.dir/src/Triangle.cpp.o.provides: CMakeFiles/IdolScheme.dir/src/Triangle.cpp.o.requires
	$(MAKE) -f CMakeFiles/IdolScheme.dir/build.make CMakeFiles/IdolScheme.dir/src/Triangle.cpp.o.provides.build
.PHONY : CMakeFiles/IdolScheme.dir/src/Triangle.cpp.o.provides

CMakeFiles/IdolScheme.dir/src/Triangle.cpp.o.provides.build: CMakeFiles/IdolScheme.dir/src/Triangle.cpp.o


CMakeFiles/IdolScheme.dir/src/TextureLoading.cpp.o: CMakeFiles/IdolScheme.dir/flags.make
CMakeFiles/IdolScheme.dir/src/TextureLoading.cpp.o: ../src/TextureLoading.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/IdolScheme.dir/src/TextureLoading.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/IdolScheme.dir/src/TextureLoading.cpp.o -c /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/TextureLoading.cpp

CMakeFiles/IdolScheme.dir/src/TextureLoading.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IdolScheme.dir/src/TextureLoading.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/TextureLoading.cpp > CMakeFiles/IdolScheme.dir/src/TextureLoading.cpp.i

CMakeFiles/IdolScheme.dir/src/TextureLoading.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IdolScheme.dir/src/TextureLoading.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/TextureLoading.cpp -o CMakeFiles/IdolScheme.dir/src/TextureLoading.cpp.s

CMakeFiles/IdolScheme.dir/src/TextureLoading.cpp.o.requires:

.PHONY : CMakeFiles/IdolScheme.dir/src/TextureLoading.cpp.o.requires

CMakeFiles/IdolScheme.dir/src/TextureLoading.cpp.o.provides: CMakeFiles/IdolScheme.dir/src/TextureLoading.cpp.o.requires
	$(MAKE) -f CMakeFiles/IdolScheme.dir/build.make CMakeFiles/IdolScheme.dir/src/TextureLoading.cpp.o.provides.build
.PHONY : CMakeFiles/IdolScheme.dir/src/TextureLoading.cpp.o.provides

CMakeFiles/IdolScheme.dir/src/TextureLoading.cpp.o.provides.build: CMakeFiles/IdolScheme.dir/src/TextureLoading.cpp.o


CMakeFiles/IdolScheme.dir/src/RegularPolygon.cpp.o: CMakeFiles/IdolScheme.dir/flags.make
CMakeFiles/IdolScheme.dir/src/RegularPolygon.cpp.o: ../src/RegularPolygon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/IdolScheme.dir/src/RegularPolygon.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/IdolScheme.dir/src/RegularPolygon.cpp.o -c /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/RegularPolygon.cpp

CMakeFiles/IdolScheme.dir/src/RegularPolygon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IdolScheme.dir/src/RegularPolygon.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/RegularPolygon.cpp > CMakeFiles/IdolScheme.dir/src/RegularPolygon.cpp.i

CMakeFiles/IdolScheme.dir/src/RegularPolygon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IdolScheme.dir/src/RegularPolygon.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/RegularPolygon.cpp -o CMakeFiles/IdolScheme.dir/src/RegularPolygon.cpp.s

CMakeFiles/IdolScheme.dir/src/RegularPolygon.cpp.o.requires:

.PHONY : CMakeFiles/IdolScheme.dir/src/RegularPolygon.cpp.o.requires

CMakeFiles/IdolScheme.dir/src/RegularPolygon.cpp.o.provides: CMakeFiles/IdolScheme.dir/src/RegularPolygon.cpp.o.requires
	$(MAKE) -f CMakeFiles/IdolScheme.dir/build.make CMakeFiles/IdolScheme.dir/src/RegularPolygon.cpp.o.provides.build
.PHONY : CMakeFiles/IdolScheme.dir/src/RegularPolygon.cpp.o.provides

CMakeFiles/IdolScheme.dir/src/RegularPolygon.cpp.o.provides.build: CMakeFiles/IdolScheme.dir/src/RegularPolygon.cpp.o


CMakeFiles/IdolScheme.dir/src/Source.cpp.o: CMakeFiles/IdolScheme.dir/flags.make
CMakeFiles/IdolScheme.dir/src/Source.cpp.o: ../src/Source.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/IdolScheme.dir/src/Source.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/IdolScheme.dir/src/Source.cpp.o -c /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/Source.cpp

CMakeFiles/IdolScheme.dir/src/Source.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IdolScheme.dir/src/Source.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/Source.cpp > CMakeFiles/IdolScheme.dir/src/Source.cpp.i

CMakeFiles/IdolScheme.dir/src/Source.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IdolScheme.dir/src/Source.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/Source.cpp -o CMakeFiles/IdolScheme.dir/src/Source.cpp.s

CMakeFiles/IdolScheme.dir/src/Source.cpp.o.requires:

.PHONY : CMakeFiles/IdolScheme.dir/src/Source.cpp.o.requires

CMakeFiles/IdolScheme.dir/src/Source.cpp.o.provides: CMakeFiles/IdolScheme.dir/src/Source.cpp.o.requires
	$(MAKE) -f CMakeFiles/IdolScheme.dir/build.make CMakeFiles/IdolScheme.dir/src/Source.cpp.o.provides.build
.PHONY : CMakeFiles/IdolScheme.dir/src/Source.cpp.o.provides

CMakeFiles/IdolScheme.dir/src/Source.cpp.o.provides.build: CMakeFiles/IdolScheme.dir/src/Source.cpp.o


CMakeFiles/IdolScheme.dir/src/Note.cpp.o: CMakeFiles/IdolScheme.dir/flags.make
CMakeFiles/IdolScheme.dir/src/Note.cpp.o: ../src/Note.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/IdolScheme.dir/src/Note.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/IdolScheme.dir/src/Note.cpp.o -c /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/Note.cpp

CMakeFiles/IdolScheme.dir/src/Note.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IdolScheme.dir/src/Note.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/Note.cpp > CMakeFiles/IdolScheme.dir/src/Note.cpp.i

CMakeFiles/IdolScheme.dir/src/Note.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IdolScheme.dir/src/Note.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/Note.cpp -o CMakeFiles/IdolScheme.dir/src/Note.cpp.s

CMakeFiles/IdolScheme.dir/src/Note.cpp.o.requires:

.PHONY : CMakeFiles/IdolScheme.dir/src/Note.cpp.o.requires

CMakeFiles/IdolScheme.dir/src/Note.cpp.o.provides: CMakeFiles/IdolScheme.dir/src/Note.cpp.o.requires
	$(MAKE) -f CMakeFiles/IdolScheme.dir/build.make CMakeFiles/IdolScheme.dir/src/Note.cpp.o.provides.build
.PHONY : CMakeFiles/IdolScheme.dir/src/Note.cpp.o.provides

CMakeFiles/IdolScheme.dir/src/Note.cpp.o.provides.build: CMakeFiles/IdolScheme.dir/src/Note.cpp.o


CMakeFiles/IdolScheme.dir/src/DebugVertexController.cpp.o: CMakeFiles/IdolScheme.dir/flags.make
CMakeFiles/IdolScheme.dir/src/DebugVertexController.cpp.o: ../src/DebugVertexController.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/IdolScheme.dir/src/DebugVertexController.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/IdolScheme.dir/src/DebugVertexController.cpp.o -c /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/DebugVertexController.cpp

CMakeFiles/IdolScheme.dir/src/DebugVertexController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IdolScheme.dir/src/DebugVertexController.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/DebugVertexController.cpp > CMakeFiles/IdolScheme.dir/src/DebugVertexController.cpp.i

CMakeFiles/IdolScheme.dir/src/DebugVertexController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IdolScheme.dir/src/DebugVertexController.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/DebugVertexController.cpp -o CMakeFiles/IdolScheme.dir/src/DebugVertexController.cpp.s

CMakeFiles/IdolScheme.dir/src/DebugVertexController.cpp.o.requires:

.PHONY : CMakeFiles/IdolScheme.dir/src/DebugVertexController.cpp.o.requires

CMakeFiles/IdolScheme.dir/src/DebugVertexController.cpp.o.provides: CMakeFiles/IdolScheme.dir/src/DebugVertexController.cpp.o.requires
	$(MAKE) -f CMakeFiles/IdolScheme.dir/build.make CMakeFiles/IdolScheme.dir/src/DebugVertexController.cpp.o.provides.build
.PHONY : CMakeFiles/IdolScheme.dir/src/DebugVertexController.cpp.o.provides

CMakeFiles/IdolScheme.dir/src/DebugVertexController.cpp.o.provides.build: CMakeFiles/IdolScheme.dir/src/DebugVertexController.cpp.o


CMakeFiles/IdolScheme.dir/src/stb_image.cpp.o: CMakeFiles/IdolScheme.dir/flags.make
CMakeFiles/IdolScheme.dir/src/stb_image.cpp.o: ../src/stb_image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/IdolScheme.dir/src/stb_image.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/IdolScheme.dir/src/stb_image.cpp.o -c /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/stb_image.cpp

CMakeFiles/IdolScheme.dir/src/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IdolScheme.dir/src/stb_image.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/stb_image.cpp > CMakeFiles/IdolScheme.dir/src/stb_image.cpp.i

CMakeFiles/IdolScheme.dir/src/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IdolScheme.dir/src/stb_image.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/stb_image.cpp -o CMakeFiles/IdolScheme.dir/src/stb_image.cpp.s

CMakeFiles/IdolScheme.dir/src/stb_image.cpp.o.requires:

.PHONY : CMakeFiles/IdolScheme.dir/src/stb_image.cpp.o.requires

CMakeFiles/IdolScheme.dir/src/stb_image.cpp.o.provides: CMakeFiles/IdolScheme.dir/src/stb_image.cpp.o.requires
	$(MAKE) -f CMakeFiles/IdolScheme.dir/build.make CMakeFiles/IdolScheme.dir/src/stb_image.cpp.o.provides.build
.PHONY : CMakeFiles/IdolScheme.dir/src/stb_image.cpp.o.provides

CMakeFiles/IdolScheme.dir/src/stb_image.cpp.o.provides.build: CMakeFiles/IdolScheme.dir/src/stb_image.cpp.o


CMakeFiles/IdolScheme.dir/src/Color.cpp.o: CMakeFiles/IdolScheme.dir/flags.make
CMakeFiles/IdolScheme.dir/src/Color.cpp.o: ../src/Color.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/IdolScheme.dir/src/Color.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/IdolScheme.dir/src/Color.cpp.o -c /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/Color.cpp

CMakeFiles/IdolScheme.dir/src/Color.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IdolScheme.dir/src/Color.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/Color.cpp > CMakeFiles/IdolScheme.dir/src/Color.cpp.i

CMakeFiles/IdolScheme.dir/src/Color.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IdolScheme.dir/src/Color.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/src/Color.cpp -o CMakeFiles/IdolScheme.dir/src/Color.cpp.s

CMakeFiles/IdolScheme.dir/src/Color.cpp.o.requires:

.PHONY : CMakeFiles/IdolScheme.dir/src/Color.cpp.o.requires

CMakeFiles/IdolScheme.dir/src/Color.cpp.o.provides: CMakeFiles/IdolScheme.dir/src/Color.cpp.o.requires
	$(MAKE) -f CMakeFiles/IdolScheme.dir/build.make CMakeFiles/IdolScheme.dir/src/Color.cpp.o.provides.build
.PHONY : CMakeFiles/IdolScheme.dir/src/Color.cpp.o.provides

CMakeFiles/IdolScheme.dir/src/Color.cpp.o.provides.build: CMakeFiles/IdolScheme.dir/src/Color.cpp.o


# Object files for target IdolScheme
IdolScheme_OBJECTS = \
"CMakeFiles/IdolScheme.dir/assets/glad.c.o" \
"CMakeFiles/IdolScheme.dir/src/Vector3.cpp.o" \
"CMakeFiles/IdolScheme.dir/src/Triangle.cpp.o" \
"CMakeFiles/IdolScheme.dir/src/TextureLoading.cpp.o" \
"CMakeFiles/IdolScheme.dir/src/RegularPolygon.cpp.o" \
"CMakeFiles/IdolScheme.dir/src/Source.cpp.o" \
"CMakeFiles/IdolScheme.dir/src/Note.cpp.o" \
"CMakeFiles/IdolScheme.dir/src/DebugVertexController.cpp.o" \
"CMakeFiles/IdolScheme.dir/src/stb_image.cpp.o" \
"CMakeFiles/IdolScheme.dir/src/Color.cpp.o"

# External object files for target IdolScheme
IdolScheme_EXTERNAL_OBJECTS =

IdolScheme: CMakeFiles/IdolScheme.dir/assets/glad.c.o
IdolScheme: CMakeFiles/IdolScheme.dir/src/Vector3.cpp.o
IdolScheme: CMakeFiles/IdolScheme.dir/src/Triangle.cpp.o
IdolScheme: CMakeFiles/IdolScheme.dir/src/TextureLoading.cpp.o
IdolScheme: CMakeFiles/IdolScheme.dir/src/RegularPolygon.cpp.o
IdolScheme: CMakeFiles/IdolScheme.dir/src/Source.cpp.o
IdolScheme: CMakeFiles/IdolScheme.dir/src/Note.cpp.o
IdolScheme: CMakeFiles/IdolScheme.dir/src/DebugVertexController.cpp.o
IdolScheme: CMakeFiles/IdolScheme.dir/src/stb_image.cpp.o
IdolScheme: CMakeFiles/IdolScheme.dir/src/Color.cpp.o
IdolScheme: CMakeFiles/IdolScheme.dir/build.make
IdolScheme: CMakeFiles/IdolScheme.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable IdolScheme"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/IdolScheme.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/IdolScheme.dir/build: IdolScheme

.PHONY : CMakeFiles/IdolScheme.dir/build

CMakeFiles/IdolScheme.dir/requires: CMakeFiles/IdolScheme.dir/assets/glad.c.o.requires
CMakeFiles/IdolScheme.dir/requires: CMakeFiles/IdolScheme.dir/src/Vector3.cpp.o.requires
CMakeFiles/IdolScheme.dir/requires: CMakeFiles/IdolScheme.dir/src/Triangle.cpp.o.requires
CMakeFiles/IdolScheme.dir/requires: CMakeFiles/IdolScheme.dir/src/TextureLoading.cpp.o.requires
CMakeFiles/IdolScheme.dir/requires: CMakeFiles/IdolScheme.dir/src/RegularPolygon.cpp.o.requires
CMakeFiles/IdolScheme.dir/requires: CMakeFiles/IdolScheme.dir/src/Source.cpp.o.requires
CMakeFiles/IdolScheme.dir/requires: CMakeFiles/IdolScheme.dir/src/Note.cpp.o.requires
CMakeFiles/IdolScheme.dir/requires: CMakeFiles/IdolScheme.dir/src/DebugVertexController.cpp.o.requires
CMakeFiles/IdolScheme.dir/requires: CMakeFiles/IdolScheme.dir/src/stb_image.cpp.o.requires
CMakeFiles/IdolScheme.dir/requires: CMakeFiles/IdolScheme.dir/src/Color.cpp.o.requires

.PHONY : CMakeFiles/IdolScheme.dir/requires

CMakeFiles/IdolScheme.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/IdolScheme.dir/cmake_clean.cmake
.PHONY : CMakeFiles/IdolScheme.dir/clean

CMakeFiles/IdolScheme.dir/depend:
	cd /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/build /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/build /home/damien/Documents/git/OpenDepictor/OpenGLTestingEnvironment_/OpenGLTestingEnvironment/build/CMakeFiles/IdolScheme.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/IdolScheme.dir/depend

