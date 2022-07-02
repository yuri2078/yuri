# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\widget_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\widget_autogen.dir\\ParseCache.txt"
  "widget_autogen"
  )
endif()
