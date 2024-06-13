cmake_minimum_required(VERSION 3.26)
project(Implementation_SOIL)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXE_LINKER_FLAGS "-static")

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(include lib ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

add_executable(ImplementationSOIL
        include/Block.h
        include/Camera.h
        include/Map.h
        include/Skybox.h
        include/SOIL.h
#        include/Quaternion.h
        src/Block.cpp
        src/Camera.cpp
        src/main.cpp
        src/Map.cpp
        include/Quaternion.h
        include/Quaternion.h
        #        src/Quaternion.cpp

)

add_library(
        soil_lib STATIC
        SOIL/src/image_helper.c
        SOIL/src/stb_image_aug.c
        SOIL/src/image_DXT.c
        SOIL/src/SOIL.c
)

target_link_libraries(ImplementationSOIL soil_lib ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})