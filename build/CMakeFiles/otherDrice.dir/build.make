# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Qt\Tools\CMake_64\bin\cmake.exe

# The command to remove a file.
RM = C:\Qt\Tools\CMake_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\vscode\QTproject\otherDrice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\vscode\build

# Include any dependencies generated for this target.
include CMakeFiles/otherDrice.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/otherDrice.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/otherDrice.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/otherDrice.dir/flags.make

otherDrice_autogen/EWIEGA46WW/qrc_image.cpp: E:/vscode/QTproject/otherDrice/image.qrc
otherDrice_autogen/EWIEGA46WW/qrc_image.cpp: CMakeFiles/otherDrice_autogen.dir/AutoRcc_image_EWIEGA46WW_Info.json
otherDrice_autogen/EWIEGA46WW/qrc_image.cpp: E:/vscode/QTproject/otherDrice/image/(15).jpg
otherDrice_autogen/EWIEGA46WW/qrc_image.cpp: C:/Qt/6.3.1/mingw_64/./bin/rcc.exe
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=E:\vscode\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic RCC for image.qrc"
	C:\Qt\Tools\CMake_64\bin\cmake.exe -E cmake_autorcc E:/vscode/build/CMakeFiles/otherDrice_autogen.dir/AutoRcc_image_EWIEGA46WW_Info.json Debug

CMakeFiles/otherDrice.dir/otherDrice_autogen/mocs_compilation.cpp.obj: CMakeFiles/otherDrice.dir/flags.make
CMakeFiles/otherDrice.dir/otherDrice_autogen/mocs_compilation.cpp.obj: CMakeFiles/otherDrice.dir/includes_CXX.rsp
CMakeFiles/otherDrice.dir/otherDrice_autogen/mocs_compilation.cpp.obj: otherDrice_autogen/mocs_compilation.cpp
CMakeFiles/otherDrice.dir/otherDrice_autogen/mocs_compilation.cpp.obj: CMakeFiles/otherDrice.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\vscode\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/otherDrice.dir/otherDrice_autogen/mocs_compilation.cpp.obj"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/otherDrice.dir/otherDrice_autogen/mocs_compilation.cpp.obj -MF CMakeFiles\otherDrice.dir\otherDrice_autogen\mocs_compilation.cpp.obj.d -o CMakeFiles\otherDrice.dir\otherDrice_autogen\mocs_compilation.cpp.obj -c E:\vscode\build\otherDrice_autogen\mocs_compilation.cpp

CMakeFiles/otherDrice.dir/otherDrice_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/otherDrice.dir/otherDrice_autogen/mocs_compilation.cpp.i"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\vscode\build\otherDrice_autogen\mocs_compilation.cpp > CMakeFiles\otherDrice.dir\otherDrice_autogen\mocs_compilation.cpp.i

CMakeFiles/otherDrice.dir/otherDrice_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/otherDrice.dir/otherDrice_autogen/mocs_compilation.cpp.s"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\vscode\build\otherDrice_autogen\mocs_compilation.cpp -o CMakeFiles\otherDrice.dir\otherDrice_autogen\mocs_compilation.cpp.s

CMakeFiles/otherDrice.dir/main.cpp.obj: CMakeFiles/otherDrice.dir/flags.make
CMakeFiles/otherDrice.dir/main.cpp.obj: CMakeFiles/otherDrice.dir/includes_CXX.rsp
CMakeFiles/otherDrice.dir/main.cpp.obj: E:/vscode/QTproject/otherDrice/main.cpp
CMakeFiles/otherDrice.dir/main.cpp.obj: CMakeFiles/otherDrice.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\vscode\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/otherDrice.dir/main.cpp.obj"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/otherDrice.dir/main.cpp.obj -MF CMakeFiles\otherDrice.dir\main.cpp.obj.d -o CMakeFiles\otherDrice.dir\main.cpp.obj -c E:\vscode\QTproject\otherDrice\main.cpp

CMakeFiles/otherDrice.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/otherDrice.dir/main.cpp.i"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\vscode\QTproject\otherDrice\main.cpp > CMakeFiles\otherDrice.dir\main.cpp.i

CMakeFiles/otherDrice.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/otherDrice.dir/main.cpp.s"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\vscode\QTproject\otherDrice\main.cpp -o CMakeFiles\otherDrice.dir\main.cpp.s

CMakeFiles/otherDrice.dir/mainwindow.cpp.obj: CMakeFiles/otherDrice.dir/flags.make
CMakeFiles/otherDrice.dir/mainwindow.cpp.obj: CMakeFiles/otherDrice.dir/includes_CXX.rsp
CMakeFiles/otherDrice.dir/mainwindow.cpp.obj: E:/vscode/QTproject/otherDrice/mainwindow.cpp
CMakeFiles/otherDrice.dir/mainwindow.cpp.obj: CMakeFiles/otherDrice.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\vscode\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/otherDrice.dir/mainwindow.cpp.obj"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/otherDrice.dir/mainwindow.cpp.obj -MF CMakeFiles\otherDrice.dir\mainwindow.cpp.obj.d -o CMakeFiles\otherDrice.dir\mainwindow.cpp.obj -c E:\vscode\QTproject\otherDrice\mainwindow.cpp

CMakeFiles/otherDrice.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/otherDrice.dir/mainwindow.cpp.i"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\vscode\QTproject\otherDrice\mainwindow.cpp > CMakeFiles\otherDrice.dir\mainwindow.cpp.i

CMakeFiles/otherDrice.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/otherDrice.dir/mainwindow.cpp.s"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\vscode\QTproject\otherDrice\mainwindow.cpp -o CMakeFiles\otherDrice.dir\mainwindow.cpp.s

CMakeFiles/otherDrice.dir/otherDrice_autogen/EWIEGA46WW/qrc_image.cpp.obj: CMakeFiles/otherDrice.dir/flags.make
CMakeFiles/otherDrice.dir/otherDrice_autogen/EWIEGA46WW/qrc_image.cpp.obj: CMakeFiles/otherDrice.dir/includes_CXX.rsp
CMakeFiles/otherDrice.dir/otherDrice_autogen/EWIEGA46WW/qrc_image.cpp.obj: otherDrice_autogen/EWIEGA46WW/qrc_image.cpp
CMakeFiles/otherDrice.dir/otherDrice_autogen/EWIEGA46WW/qrc_image.cpp.obj: CMakeFiles/otherDrice.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\vscode\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/otherDrice.dir/otherDrice_autogen/EWIEGA46WW/qrc_image.cpp.obj"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/otherDrice.dir/otherDrice_autogen/EWIEGA46WW/qrc_image.cpp.obj -MF CMakeFiles\otherDrice.dir\otherDrice_autogen\EWIEGA46WW\qrc_image.cpp.obj.d -o CMakeFiles\otherDrice.dir\otherDrice_autogen\EWIEGA46WW\qrc_image.cpp.obj -c E:\vscode\build\otherDrice_autogen\EWIEGA46WW\qrc_image.cpp

CMakeFiles/otherDrice.dir/otherDrice_autogen/EWIEGA46WW/qrc_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/otherDrice.dir/otherDrice_autogen/EWIEGA46WW/qrc_image.cpp.i"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\vscode\build\otherDrice_autogen\EWIEGA46WW\qrc_image.cpp > CMakeFiles\otherDrice.dir\otherDrice_autogen\EWIEGA46WW\qrc_image.cpp.i

CMakeFiles/otherDrice.dir/otherDrice_autogen/EWIEGA46WW/qrc_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/otherDrice.dir/otherDrice_autogen/EWIEGA46WW/qrc_image.cpp.s"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\vscode\build\otherDrice_autogen\EWIEGA46WW\qrc_image.cpp -o CMakeFiles\otherDrice.dir\otherDrice_autogen\EWIEGA46WW\qrc_image.cpp.s

# Object files for target otherDrice
otherDrice_OBJECTS = \
"CMakeFiles/otherDrice.dir/otherDrice_autogen/mocs_compilation.cpp.obj" \
"CMakeFiles/otherDrice.dir/main.cpp.obj" \
"CMakeFiles/otherDrice.dir/mainwindow.cpp.obj" \
"CMakeFiles/otherDrice.dir/otherDrice_autogen/EWIEGA46WW/qrc_image.cpp.obj"

# External object files for target otherDrice
otherDrice_EXTERNAL_OBJECTS =

otherDrice.exe: CMakeFiles/otherDrice.dir/otherDrice_autogen/mocs_compilation.cpp.obj
otherDrice.exe: CMakeFiles/otherDrice.dir/main.cpp.obj
otherDrice.exe: CMakeFiles/otherDrice.dir/mainwindow.cpp.obj
otherDrice.exe: CMakeFiles/otherDrice.dir/otherDrice_autogen/EWIEGA46WW/qrc_image.cpp.obj
otherDrice.exe: CMakeFiles/otherDrice.dir/build.make
otherDrice.exe: C:/Qt/6.3.1/mingw_64/lib/libQt6Widgets.a
otherDrice.exe: C:/Qt/6.3.1/mingw_64/lib/libQt6Gui.a
otherDrice.exe: C:/Qt/6.3.1/mingw_64/lib/libQt6Core.a
otherDrice.exe: C:/Qt/6.3.1/mingw_64/lib/libQt6EntryPoint.a
otherDrice.exe: CMakeFiles/otherDrice.dir/linklibs.rsp
otherDrice.exe: CMakeFiles/otherDrice.dir/objects1.rsp
otherDrice.exe: CMakeFiles/otherDrice.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\vscode\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable otherDrice.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\otherDrice.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/otherDrice.dir/build: otherDrice.exe
.PHONY : CMakeFiles/otherDrice.dir/build

CMakeFiles/otherDrice.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\otherDrice.dir\cmake_clean.cmake
.PHONY : CMakeFiles/otherDrice.dir/clean

CMakeFiles/otherDrice.dir/depend: otherDrice_autogen/EWIEGA46WW/qrc_image.cpp
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\vscode\QTproject\otherDrice E:\vscode\QTproject\otherDrice E:\vscode\build E:\vscode\build E:\vscode\build\CMakeFiles\otherDrice.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/otherDrice.dir/depend

