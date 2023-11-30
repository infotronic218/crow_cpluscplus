cmake_minimum_required(VERSION 3.5)
project (crow_template)

include_directories( ../include)
#include_directories("${PROJECT_SOURCE_DIR}")

find_package(Tcmalloc)
find_package(Threads)
find_package(OpenSSL)
find_package( Boost COMPONENTS system thread REQUIRED )


#add_subdirectory(src)
add_executable(app app.cpp)
target_link_libraries(app ${Boost_LIBRARIES})
target_link_libraries(app ${CMAKE_THREAD_LIBS_INIT})

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g -pg" )
SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -g -pg" )
