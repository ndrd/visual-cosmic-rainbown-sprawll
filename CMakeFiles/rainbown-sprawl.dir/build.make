# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/ndrd/Projects/visual-cosmic-rainbown-sprawll

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ndrd/Projects/visual-cosmic-rainbown-sprawll

# Include any dependencies generated for this target.
include CMakeFiles/rainbown-sprawl.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rainbown-sprawl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rainbown-sprawl.dir/flags.make

CMakeFiles/rainbown-sprawl.dir/rainbown-sprawl.cpp.o: CMakeFiles/rainbown-sprawl.dir/flags.make
CMakeFiles/rainbown-sprawl.dir/rainbown-sprawl.cpp.o: rainbown-sprawl.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ndrd/Projects/visual-cosmic-rainbown-sprawll/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/rainbown-sprawl.dir/rainbown-sprawl.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/rainbown-sprawl.dir/rainbown-sprawl.cpp.o -c /home/ndrd/Projects/visual-cosmic-rainbown-sprawll/rainbown-sprawl.cpp

CMakeFiles/rainbown-sprawl.dir/rainbown-sprawl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rainbown-sprawl.dir/rainbown-sprawl.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ndrd/Projects/visual-cosmic-rainbown-sprawll/rainbown-sprawl.cpp > CMakeFiles/rainbown-sprawl.dir/rainbown-sprawl.cpp.i

CMakeFiles/rainbown-sprawl.dir/rainbown-sprawl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rainbown-sprawl.dir/rainbown-sprawl.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ndrd/Projects/visual-cosmic-rainbown-sprawll/rainbown-sprawl.cpp -o CMakeFiles/rainbown-sprawl.dir/rainbown-sprawl.cpp.s

CMakeFiles/rainbown-sprawl.dir/rainbown-sprawl.cpp.o.requires:
.PHONY : CMakeFiles/rainbown-sprawl.dir/rainbown-sprawl.cpp.o.requires

CMakeFiles/rainbown-sprawl.dir/rainbown-sprawl.cpp.o.provides: CMakeFiles/rainbown-sprawl.dir/rainbown-sprawl.cpp.o.requires
	$(MAKE) -f CMakeFiles/rainbown-sprawl.dir/build.make CMakeFiles/rainbown-sprawl.dir/rainbown-sprawl.cpp.o.provides.build
.PHONY : CMakeFiles/rainbown-sprawl.dir/rainbown-sprawl.cpp.o.provides

CMakeFiles/rainbown-sprawl.dir/rainbown-sprawl.cpp.o.provides.build: CMakeFiles/rainbown-sprawl.dir/rainbown-sprawl.cpp.o

# Object files for target rainbown-sprawl
rainbown__sprawl_OBJECTS = \
"CMakeFiles/rainbown-sprawl.dir/rainbown-sprawl.cpp.o"

# External object files for target rainbown-sprawl
rainbown__sprawl_EXTERNAL_OBJECTS =

rainbown-sprawl: CMakeFiles/rainbown-sprawl.dir/rainbown-sprawl.cpp.o
rainbown-sprawl: CMakeFiles/rainbown-sprawl.dir/build.make
rainbown-sprawl: /usr/local/lib/libopencv_viz.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_videostab.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_video.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_ts.a
rainbown-sprawl: /usr/local/lib/libopencv_superres.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_stitching.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_photo.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_ocl.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_objdetect.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_nonfree.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_ml.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_legacy.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_imgproc.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_highgui.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_gpu.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_flann.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_features2d.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_core.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_contrib.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_calib3d.so.2.4.9
rainbown-sprawl: /usr/lib/x86_64-linux-gnu/libGLU.so
rainbown-sprawl: /usr/lib/x86_64-linux-gnu/libGL.so
rainbown-sprawl: /usr/lib/x86_64-linux-gnu/libSM.so
rainbown-sprawl: /usr/lib/x86_64-linux-gnu/libICE.so
rainbown-sprawl: /usr/lib/x86_64-linux-gnu/libX11.so
rainbown-sprawl: /usr/lib/x86_64-linux-gnu/libXext.so
rainbown-sprawl: /usr/local/lib/libopencv_nonfree.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_ocl.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_gpu.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_photo.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_objdetect.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_legacy.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_video.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_ml.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_calib3d.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_features2d.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_highgui.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_imgproc.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_flann.so.2.4.9
rainbown-sprawl: /usr/local/lib/libopencv_core.so.2.4.9
rainbown-sprawl: CMakeFiles/rainbown-sprawl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable rainbown-sprawl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rainbown-sprawl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rainbown-sprawl.dir/build: rainbown-sprawl
.PHONY : CMakeFiles/rainbown-sprawl.dir/build

CMakeFiles/rainbown-sprawl.dir/requires: CMakeFiles/rainbown-sprawl.dir/rainbown-sprawl.cpp.o.requires
.PHONY : CMakeFiles/rainbown-sprawl.dir/requires

CMakeFiles/rainbown-sprawl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rainbown-sprawl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rainbown-sprawl.dir/clean

CMakeFiles/rainbown-sprawl.dir/depend:
	cd /home/ndrd/Projects/visual-cosmic-rainbown-sprawll && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ndrd/Projects/visual-cosmic-rainbown-sprawll /home/ndrd/Projects/visual-cosmic-rainbown-sprawll /home/ndrd/Projects/visual-cosmic-rainbown-sprawll /home/ndrd/Projects/visual-cosmic-rainbown-sprawll /home/ndrd/Projects/visual-cosmic-rainbown-sprawll/CMakeFiles/rainbown-sprawl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rainbown-sprawl.dir/depend

