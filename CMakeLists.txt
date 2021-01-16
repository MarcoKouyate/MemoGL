
# project settings
cmake_minimum_required(VERSION 3.1)
set(PROJECT_TITLE MemoGL)
set(PROJECT_EXE MemoExe)

project(${PROJECT_TITLE})

include(cmake/macros.cmake)



# for testing
enable_testing()


#=== BUILD
add_executable(${PROJECT_EXE} main.cpp)

# options
target_compile_options(${PROJECT_EXE} PRIVATE -Wall)
target_compile_features(${PROJECT_EXE} PRIVATE cxx_std_17)

set(RESOURCES_SRC ${CMAKE_SOURCE_DIR}/res)

if(APPLE)
    set(RESOURCES_DST $<TARGET_FILE_DIR:${PROJECT_EXE}>/res)
else ()
    set(RESOURCES_DST ${CMAKE_BINARY_DIR}/res)
endif()

add_custom_command(TARGET ${PROJECT_EXE} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${RESOURCES_SRC} ${RESOURCES_DST}
                   COMMENT "symbolic link resources folder from ${RESOURCES_SRC} => ${RESOURCES_DST}"
                   )


#===== THIRD PARTIES
set(THIRD_PARTY_DIR third-party)
add_subdirectory(${THIRD_PARTY_DIR})



#===== SOURCES
add_subdirectory(src)
target_include_directories(${PROJECT_EXE} PRIVATE src)
target_link_libraries(${PROJECT_EXE} PRIVATE MemoLib)

