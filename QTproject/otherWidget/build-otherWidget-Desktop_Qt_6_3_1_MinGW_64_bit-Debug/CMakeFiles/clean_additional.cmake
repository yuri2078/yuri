# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\otherWidget_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\otherWidget_autogen.dir\\ParseCache.txt"
  "otherWidget_autogen"
  )
endif()
