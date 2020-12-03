set(PROJECT_LIB MemoLib)
set(PROJECT_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE SRC_FILES
    "*.cpp"
    "*.h"
)

file(GLOB_RECURSE TEST_FILES
    "test/*"
    "test/*"
)
list (REMOVE_ITEM SRC_FILES ${TEST_FILES})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}  FILES ${SRC_FILES})


add_library(${PROJECT_LIB} STATIC 
    ${SRC_FILES}
)

target_include_directories(${PROJECT_LIB} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})



#glfw
target_include_directories(${PROJECT_LIB} PRIVATE ${GLFW_INCLUDE_DIR})
target_link_libraries(${PROJECT_LIB} PRIVATE glfw)

#glew
target_include_directories(${PROJECT_LIB} PRIVATE ${GLEW_INCLUDE_DIR})
target_link_libraries(${PROJECT_LIB} PRIVATE libglew_static)

#glm
target_include_directories(${PROJECT_LIB} PRIVATE ${GLM_INCLUDE_DIR})
target_link_libraries(${PROJECT_LIB} PRIVATE glm)

#testing
add_subdirectory(test)