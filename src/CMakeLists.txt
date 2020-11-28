set(PROJECT_LIB MemoLib)


add_library(${PROJECT_LIB} MemoGL.cpp)


#glfw
target_include_directories(${PROJECT_LIB} PRIVATE ${GLFW_INCLUDE})
target_link_libraries(${PROJECT_LIB} PRIVATE glfw)

#glew
target_include_directories(${PROJECT_LIB} PRIVATE ${GLEW_INCLUDE})
target_link_libraries(${PROJECT_LIB} PRIVATE libglew_static)

#glm
target_include_directories(${PROJECT_LIB} PRIVATE ${GLM_INCLUDE})
target_link_libraries(${PROJECT_LIB} PRIVATE glm)