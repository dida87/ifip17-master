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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dida/OpenCVTP/Fourier

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dida/OpenCVTP/Fourier

# Include any dependencies generated for this target.
include CMakeFiles/fourier.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fourier.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fourier.dir/flags.make

CMakeFiles/fourier.dir/fourier.cpp.o: CMakeFiles/fourier.dir/flags.make
CMakeFiles/fourier.dir/fourier.cpp.o: fourier.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dida/OpenCVTP/Fourier/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/fourier.dir/fourier.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/fourier.dir/fourier.cpp.o -c /home/dida/OpenCVTP/Fourier/fourier.cpp

CMakeFiles/fourier.dir/fourier.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fourier.dir/fourier.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dida/OpenCVTP/Fourier/fourier.cpp > CMakeFiles/fourier.dir/fourier.cpp.i

CMakeFiles/fourier.dir/fourier.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fourier.dir/fourier.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dida/OpenCVTP/Fourier/fourier.cpp -o CMakeFiles/fourier.dir/fourier.cpp.s

CMakeFiles/fourier.dir/fourier.cpp.o.requires:
.PHONY : CMakeFiles/fourier.dir/fourier.cpp.o.requires

CMakeFiles/fourier.dir/fourier.cpp.o.provides: CMakeFiles/fourier.dir/fourier.cpp.o.requires
	$(MAKE) -f CMakeFiles/fourier.dir/build.make CMakeFiles/fourier.dir/fourier.cpp.o.provides.build
.PHONY : CMakeFiles/fourier.dir/fourier.cpp.o.provides

CMakeFiles/fourier.dir/fourier.cpp.o.provides.build: CMakeFiles/fourier.dir/fourier.cpp.o

# Object files for target fourier
fourier_OBJECTS = \
"CMakeFiles/fourier.dir/fourier.cpp.o"

# External object files for target fourier
fourier_EXTERNAL_OBJECTS =

fourier: CMakeFiles/fourier.dir/fourier.cpp.o
fourier: /usr/local/lib/libopencv_videostab.so.2.4.8
fourier: /usr/local/lib/libopencv_video.so.2.4.8
fourier: /usr/local/lib/libopencv_ts.a
fourier: /usr/local/lib/libopencv_superres.so.2.4.8
fourier: /usr/local/lib/libopencv_stitching.so.2.4.8
fourier: /usr/local/lib/libopencv_photo.so.2.4.8
fourier: /usr/local/lib/libopencv_ocl.so.2.4.8
fourier: /usr/local/lib/libopencv_objdetect.so.2.4.8
fourier: /usr/local/lib/libopencv_nonfree.so.2.4.8
fourier: /usr/local/lib/libopencv_ml.so.2.4.8
fourier: /usr/local/lib/libopencv_legacy.so.2.4.8
fourier: /usr/local/lib/libopencv_imgproc.so.2.4.8
fourier: /usr/local/lib/libopencv_highgui.so.2.4.8
fourier: /usr/local/lib/libopencv_gpu.so.2.4.8
fourier: /usr/local/lib/libopencv_flann.so.2.4.8
fourier: /usr/local/lib/libopencv_features2d.so.2.4.8
fourier: /usr/local/lib/libopencv_core.so.2.4.8
fourier: /usr/local/lib/libopencv_contrib.so.2.4.8
fourier: /usr/local/lib/libopencv_calib3d.so.2.4.8
fourier: /usr/lib/i386-linux-gnu/libGLU.so
fourier: /usr/lib/i386-linux-gnu/libGL.so
fourier: /usr/lib/i386-linux-gnu/libSM.so
fourier: /usr/lib/i386-linux-gnu/libICE.so
fourier: /usr/lib/i386-linux-gnu/libX11.so
fourier: /usr/lib/i386-linux-gnu/libXext.so
fourier: /usr/local/lib/libopencv_nonfree.so.2.4.8
fourier: /usr/local/lib/libopencv_ocl.so.2.4.8
fourier: /usr/local/lib/libopencv_gpu.so.2.4.8
fourier: /usr/local/lib/libopencv_photo.so.2.4.8
fourier: /usr/local/lib/libopencv_objdetect.so.2.4.8
fourier: /usr/local/lib/libopencv_legacy.so.2.4.8
fourier: /usr/local/lib/libopencv_video.so.2.4.8
fourier: /usr/local/lib/libopencv_ml.so.2.4.8
fourier: /usr/local/lib/libopencv_calib3d.so.2.4.8
fourier: /usr/local/lib/libopencv_features2d.so.2.4.8
fourier: /usr/local/lib/libopencv_highgui.so.2.4.8
fourier: /usr/local/lib/libopencv_imgproc.so.2.4.8
fourier: /usr/local/lib/libopencv_flann.so.2.4.8
fourier: /usr/local/lib/libopencv_core.so.2.4.8
fourier: CMakeFiles/fourier.dir/build.make
fourier: CMakeFiles/fourier.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable fourier"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fourier.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fourier.dir/build: fourier
.PHONY : CMakeFiles/fourier.dir/build

CMakeFiles/fourier.dir/requires: CMakeFiles/fourier.dir/fourier.cpp.o.requires
.PHONY : CMakeFiles/fourier.dir/requires

CMakeFiles/fourier.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fourier.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fourier.dir/clean

CMakeFiles/fourier.dir/depend:
	cd /home/dida/OpenCVTP/Fourier && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dida/OpenCVTP/Fourier /home/dida/OpenCVTP/Fourier /home/dida/OpenCVTP/Fourier /home/dida/OpenCVTP/Fourier /home/dida/OpenCVTP/Fourier/CMakeFiles/fourier.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fourier.dir/depend

