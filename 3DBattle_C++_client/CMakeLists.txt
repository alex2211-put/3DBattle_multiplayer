cmake_minimum_required(VERSION 3.15)
project(3DSeeButtle)

set(CMAKE_CXX_STANDARD 20)

add_executable(3DSeeButtle main.cpp ChooseSide.h WorkWithKeys.h)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(3DSeeButtle ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

# find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

# target_link_libraries(3DSeeButtle sfml-graphics sfml-audio)
