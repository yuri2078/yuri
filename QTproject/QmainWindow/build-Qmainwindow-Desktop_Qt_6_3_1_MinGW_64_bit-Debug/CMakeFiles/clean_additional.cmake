# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Qmainwindow_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Qmainwindow_autogen.dir\\ParseCache.txt"
  "Qmainwindow_autogen"
  )
endif()
