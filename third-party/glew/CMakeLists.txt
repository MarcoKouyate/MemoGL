set(LIBRARY_DIR glew-cmake)

#options
add_definitions(-DGLEW_STATIC)

#include
set(GLEW_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${LIBRARY_DIR}/include PARENT_SCOPE)


add_subdirectory_with_folder( ${THIRD_PARTY_PROJECT_FOLDER} ${LIBRARY_DIR})

# set_target_properties(libglew_shared PROPERTIES FOLDER ${THIRD_PARTY_PROJECT_FOLDER})
# set_target_properties(libglew_shared PROPERTIES FOLDER ${THIRD_PARTY_PROJECT_FOLDER})

