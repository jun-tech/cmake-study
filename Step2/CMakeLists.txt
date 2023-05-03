# 定义cmake最低版本
cmake_minimum_required(VERSION 3.10)

# 项目名称，添加版本号
project(Tutorial VERSION 1.2)

# 使用C++标准库
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#头文件配置，似乎动态生成头文件
configure_file(tutorial.h.in tutorial.h)

# 生成可执行文件Tutorial,文件编译文件
add_executable(Tutorial tutorial.cxx)

# 添加include
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

