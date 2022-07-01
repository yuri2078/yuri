# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\loginWindow_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\loginWindow_autogen.dir\\ParseCache.txt"
  "loginWindow_autogen"
  )
endif()
