# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "BuzvisPlus_autogen"
  "CMakeFiles/BuzvisPlus_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/BuzvisPlus_autogen.dir/ParseCache.txt"
  )
endif()
