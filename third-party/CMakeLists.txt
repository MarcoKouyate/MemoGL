
add_subdirectory(glfw)
add_subdirectory(glm)
add_subdirectory(glew)

#includes directories
set(GLFW_INCLUDE_DIR ${GLFW_INCLUDE_DIR} PARENT_SCOPE)
set(GLEW_INCLUDE_DIR ${GLEW_INCLUDE_DIR} PARENT_SCOPE)
set(GLM_INCLUDE_DIR ${GLM_INCLUDE_DIR} PARENT_SCOPE)
