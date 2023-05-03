# 定义cmake最低版本
cmake_minimum_required(VERSION 3.10)

# 项目名称，添加版本号
project(Tutorial VERSION 1.2)

# 使用C++标准库
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# ON表示使用库,OFF表示不使用
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# 头文件配置，似乎动态生成头文件
configure_file(tutorial.h.in tutorial.h)

# 添加MathFunctions
if(USE_MYMATH)
  # 添加库目录
  add_subdirectory(MathFunctions)

  # 变量EXTRA_LIBS用来保存需要连接进可执行程序的可选库
  list(APPEND EXTRA_LIBS MathFunctions)

  # 变量EXTRA_INCLUDES用来保存可选的头文件搜索路径
  list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()

# 生成可执行文件Tutorial,文件编译文件
add_executable(Tutorial tutorial.cxx)

# 链接库
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})

# 添加include
target_include_directories(Tutorial PUBLIC
  "${PROJECT_BINARY_DIR}"
  ${EXTRA_INCLUDES}
)
