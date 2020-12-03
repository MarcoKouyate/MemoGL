set(PROJECT_LIB MemoLib)
set(PROJECT_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCES_F 
    MemoGL.cpp
    IGameEngine.h
    GameEngine.cpp
    GameEngine.h
    graphics/IGraphicsEngine.h
    graphics/rasterization/RasterizationEngine.h
    graphics/rasterization/RasterizationEngine.cpp
    graphics/renderer/IRenderer.h
    graphics/renderer/OpenGL3_3/OpenGL33Renderer.cpp
    graphics/renderer/OpenGL3_3/OpenGL33Renderer.h
    graphics/renderer/OpenGL_Legacy/OpenGLLegacyRenderer.cpp
    graphics/renderer/OpenGL_Legacy/OpenGLLegacyRenderer.h
    graphics/renderer/IWindow.h
    graphics/renderer/OpenGL3_3/OpenGL33Window.h
    graphics/renderer/OpenGL3_3/OpenGL33Window.cpp
    graphics/renderer/OpenGL3_3/OpenGL33Error.h
    graphics/renderer/OpenGL3_3/OpenGL33Error.cpp
    graphics/renderer/OpenGL_Legacy/OpenGLLegacyWindow.cpp
    graphics/renderer/OpenGL_Legacy/OpenGLLegacyWindow.h
    tools/File.cpp 
    tools/File.h
)

add_library(${PROJECT_LIB} STATIC 
    ${SOURCES_F}
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