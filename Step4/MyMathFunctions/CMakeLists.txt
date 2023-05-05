add_library(MathFunctions mysqrt.cxx)

# MathFunctions指的是库名
target_include_directories(MathFunctions
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )
          
# link our compiler flags interface library
target_link_libraries(MathFunctions tutorial_compiler_flags)
