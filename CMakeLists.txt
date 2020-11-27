
# project settings
cmake_minimum_required(VERSION 3.1)
set(PROJECT_TITLE MemoGL)
set(PROJECT_EXE MemoExe)

project(${PROJECT_TITLE})

# executable
add_executable(${PROJECT_EXE} main.cpp)

# options
set_property(TARGET ${PROJECT_EXE} PROPERTY CXX_STANDARD 11)
target_compile_options(${PROJECT_EXE} PRIVATE -Wall)



#=====


#third parties
set(THIRD_PARTY_DIR third-party)
add_subdirectory(${THIRD_PARTY_DIR})

#glfw
target_include_directories(${PROJECT_EXE} PRIVATE ${GLFW_INCLUDE})
target_link_libraries(${PROJECT_EXE} PRIVATE glfw)

#glew
target_include_directories(${PROJECT_EXE} PRIVATE ${GLEW_INCLUDE})
target_link_libraries(${PROJECT_EXE} PRIVATE libglew_static)

#glm
target_include_directories(${PROJECT_EXE} PRIVATE ${GLM_INCLUDE})
target_link_libraries(${PROJECT_EXE} PRIVATE glm)




