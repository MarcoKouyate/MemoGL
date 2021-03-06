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


add_subdirectory(platform)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}  FILES ${SRC_FILES})

message(STATUS "SOURCE FILES:")
foreach (filename ${SRC_FILES})
    message(STATUS "${filename}")
endforeach()

add_library(${PROJECT_LIB} STATIC
    ${SRC_FILES}
)

target_compile_features(${PROJECT_LIB} PRIVATE cxx_std_17)
target_compile_options(${PROJECT_EXE} PRIVATE -Wall)

target_include_directories(${PROJECT_LIB} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_precompile_headers(${PROJECT_LIB} PRIVATE pch.h)


#freetype
target_include_directories(${PROJECT_LIB} PRIVATE ${FREETYPE_INCLUDE_DIR})
target_link_libraries(${PROJECT_LIB} PRIVATE freetype)

#glfw
target_include_directories(${PROJECT_LIB} PRIVATE ${GLFW_INCLUDE_DIR})
target_link_libraries(${PROJECT_LIB} PRIVATE glfw)

#glew
target_include_directories(${PROJECT_LIB} PRIVATE ${GLEW_INCLUDE_DIR})
target_link_libraries(${PROJECT_LIB} PRIVATE libglew_static)

#glm
target_include_directories(${PROJECT_LIB} PRIVATE ${GLM_INCLUDE_DIR})
target_link_libraries(${PROJECT_LIB} PRIVATE glm)

#stb
target_include_directories(${PROJECT_LIB} PRIVATE ${STB_INCLUDE_DIR})
target_link_libraries(${PROJECT_LIB} PRIVATE stb)

#imgui
target_include_directories(${PROJECT_LIB} PRIVATE ${IMGUI_INCLUDE_DIR})
target_link_libraries(${PROJECT_LIB} PRIVATE imgui)

#spdlog
message(STATUS ${SPDLOG_INCLUDE_DIR})
target_include_directories(${PROJECT_LIB} PRIVATE ${SPDLOG_INCLUDE_DIR})
target_link_libraries(${PROJECT_LIB} PRIVATE spdlog)

#testing
add_subdirectory(test)
