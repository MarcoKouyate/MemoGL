
# project settings
cmake_minimum_required(VERSION 3.1)
set(PROJECT_TITLE MemoGL)
set(PROJECT_EXE MemoExe)

project(${PROJECT_TITLE})

include(cmake/macros.cmake)

# for MSVC
# the link with google test library doesn't work unless we set all runtime libraries to multi-thead
if(MSVC)
  set(variables 
    CMAKE_CXX_FLAGS_DEBUG
    CMAKE_CXX_FLAGS_RELEASE
	CMAKE_CXX_FLAGS_RELWITHDEBINFO
	CMAKE_CXX_FLAGS_MINSIZEREL
  )
  foreach(variable ${variables})
	if(${variable} MATCHES "/MD")
	  string(REGEX REPLACE "/MD" "/MT" ${variable} "${${variable}}")
	endif()
  endforeach()
endif()

# for testing
enable_testing()


#=== BUILD
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
