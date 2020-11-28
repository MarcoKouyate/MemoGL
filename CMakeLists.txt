
# project settings
cmake_minimum_required(VERSION 3.1)
set(PROJECT_TITLE MemoGL)
set(PROJECT_EXE MemoExe)

project(${PROJECT_TITLE})

# executable
add_executable(${PROJECT_EXE} main.cpp)

# options
set_property(TARGET ${PROJECT_EXE} PROPERTY CXX_STANDARD 14)
target_compile_options(${PROJECT_EXE} PRIVATE -Wall)



#===== THIRD PARTIES

set(THIRD_PARTY_DIR third-party)
add_subdirectory(${THIRD_PARTY_DIR})


#===== SOURCES
add_subdirectory(src)
target_include_directories(${PROJECT_EXE} PRIVATE src)
target_link_libraries(${PROJECT_EXE} PRIVATE MemoLib)
