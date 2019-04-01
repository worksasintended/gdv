CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(uebung01)
SET( CMAKE_BUILD_TYPE DEBUG )

SET( CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_CXX_FLAGS} -march=native" )
SET( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -pedantic -D_GLIBCXX_DEBUG -fsanitize=address" )
SET( CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}" )

SET( CMAKE_CXX_STANDARD 17 )

SET( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )
#SET( LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib )

SET( CMAKE_EXPORT_COMPILE_COMMANDS on )

ADD_EXECUTABLE(teapot 
 src/teapot.cpp
 src/backface.cpp 
 src/flatshading.cpp
 src/gouraudshading.cpp
 src/lines.cpp
 src/math3d.cpp
 src/projection.cpp
 src/teapotdata.cpp
 src/trifill.cpp
 src/wireframe.cpp
  )

#TARGET_INCLUDE_DIRECTORIES( bin_test )
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
target_link_libraries(teapot ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
