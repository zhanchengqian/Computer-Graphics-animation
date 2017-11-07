cmake_minimum_required(VERSION 3.0)
project(prog2)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
link_libraries(${OPENGL_LIBRARIES})

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})
link_libraries(${GLUT_LIBRARIES})

find_package(GLU REQUIRED)
include_directories(${GLU_INCLUDE_DIR})
link_libraries(${GLU_LIBRARIES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/helper.h src/ImageHandler.h src/TextureHandler.h src/TextureDrawer.h src/MatrixHandler.h)
add_executable(prog2 ${SOURCE_FILES})