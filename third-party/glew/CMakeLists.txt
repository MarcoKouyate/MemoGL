set(LIBRARY_DIR glew-cmake)

#options
add_definitions(-DGLEW_STATIC)

#include
set(GLEW_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${LIBRARY_DIR}/include PARENT_SCOPE)

#subdirectory
add_subdirectory(${LIBRARY_DIR})

