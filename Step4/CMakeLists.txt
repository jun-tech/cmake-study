# 定义cmake最低版本
cmake_minimum_required(VERSION 3.10)

# 项目名称，添加版本号
project(Tutorial VERSION 1.2)

# specify the C++ standard
add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)

# target_compile_options会增加选项(options)到COMPILE_OPTIONS或者INTERFACE_COMPILE_OPOTIONS目标属性(也就是增加编译选项的意思)。
# 这些选项会在编译给定目标(<target>)时使用，给定目标必须已经通过add_executable()或者add_library()这种命令添加到项目中，并且不能是别名目标。
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(tutorial_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

# C++编译器
message("cmake compiler id: ${CMAKE_CXX_COMPILER_ID}")

# ON表示使用库,OFF表示不使用
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# 头文件配置，似乎动态生成头文件
configure_file(tutorial.h.in tutorial.h)

# 添加MathFunctions
if(USE_MYMATH)
  # 添加目录，参数指的是目录名称
  add_subdirectory(MyMathFunctions)

  # 变量EXTRA_LIBS用来保存需要连接进可执行程序的可选库，参数名指库的名称
  list(APPEND EXTRA_LIBS MathFunctions)
endif()

# 生成可执行文件Tutorial,文件编译文件
add_executable(Tutorial tutorial.cxx)

# 链接库
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS} tutorial_compiler_flags)

# 添加include
target_include_directories(Tutorial PUBLIC
  "${PROJECT_BINARY_DIR}"
)
