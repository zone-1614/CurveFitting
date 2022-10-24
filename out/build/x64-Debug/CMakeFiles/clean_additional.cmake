# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\CurveFitting_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CurveFitting_autogen.dir\\ParseCache.txt"
  "CurveFitting_autogen"
  )
endif()
