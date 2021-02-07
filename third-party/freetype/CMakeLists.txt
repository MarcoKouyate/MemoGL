
set(LIBRARY_DIR freetype)

set(FREETYPE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${LIBRARY_DIR}/include PARENT_SCOPE)

add_subdirectory_with_folder( ${THIRD_PARTY_PROJECT_FOLDER} ${LIBRARY_DIR})


# Visual studio doesn't link glfw if its runtime library isn't MultiThreaded /MT 
if(MSVC) 
    set_property(TARGET glfw PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded")
endif()
