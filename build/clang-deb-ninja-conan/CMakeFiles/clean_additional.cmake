# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "BuzvisApp_autogen"
  "CMakeFiles/BuzvisApp_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/BuzvisApp_autogen.dir/ParseCache.txt"
  )
endif()
