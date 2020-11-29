set(PROJECT_LIB MemoLib)
set(PROJECT_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCES_F 
    MemoGL.cpp
    graphics/renderer/IWindow.h
    graphics/renderer/OpenGL3_3/OpenGL33Window.h
    graphics/renderer/OpenGL3_3/OpenGL33Window.cpp
)

add_library(${PROJECT_LIB} STATIC 
    ${SOURCES_F}
)

target_include_directories(${PROJECT_LIB} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/graphics)



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