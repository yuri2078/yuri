# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Qfile_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Qfile_autogen.dir\\ParseCache.txt"
  "Qfile_autogen"
  )
endif()
