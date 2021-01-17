set(LIBRARY_DIR imgui)

set(IMGUI_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${LIBRARY_DIR} PARENT_SCOPE)

file(GLOB SRC_FILES
     "${LIBRARY_DIR}/*.h"
     "${LIBRARY_DIR}/*.cpp"
)

add_library(${LIBRARY_DIR} STATIC 
    ${SRC_FILES}
)

#imgui uses deprecated functions that trigger warning
target_compile_definitions(${LIBRARY_DIR} PUBLIC _CRT_SECURE_NO_WARNINGS)
