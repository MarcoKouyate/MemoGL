    
    file(GLOB_RECURSE ALL_PLATFORM_SPECIFIC_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    )

    list (REMOVE_ITEM SRC_FILES ${ALL_PLATFORM_SPECIFIC_FILES})
 

    if(UNIX AND NOT APPLE)
        set(LINUX TRUE)
    endif()
    
    
    if(WIN32)

       message(STATUS "adding file specific files for Windows:")
       file(GLOB_RECURSE WINDOWS_SPECIFIC_FILES PARENT_SCOPE
            "${CMAKE_CURRENT_SOURCE_DIR}/windows/*.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/windows/*.h"   
        )
       list (APPEND SRC_FILES ${WINDOWS_SPECIFIC_FILES})

       foreach (filename ${WINDOWS_SPECIFIC_FILES})
            message(STATUS "${filename}")
       endforeach()

    endif()
    
    if(APPLE)
       message(STATUS "adding file specific files for Apple")
       file(GLOB_RECURSE APPLE_SPECIFIC_FILES PARENT_SCOPE
            "${CMAKE_CURRENT_SOURCE_DIR}/apple/*.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/apple/*.h"
        )
        list (APPEND SRC_FILES ${APPLE_SPECIFIC_FILES})

       foreach (filename ${APPLE_SPECIFIC_FILES})
            message(STATUS "${filename}")
       endforeach()
    endif()
    
    if(LINUX)
       message(STATUS "adding file specific files for Linux")
       file(GLOB_RECURSE LINUX_SPECIFIC_FILES PARENT_SCOPE
            "${CMAKE_CURRENT_SOURCE_DIR}/linux/*.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/linux/*.h"
            list (APPEND SRC_FILES ${LINUX_SPECIFIC_FILES})
        )

       foreach (filename ${LINUX_SPECIFIC_FILES})
            message(STATUS "${filename}")
       endforeach()
    endif()
    

    set(SRC_FILES ${SRC_FILES} PARENT_SCOPE)

