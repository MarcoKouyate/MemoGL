set(LIBRARY_DIR googletest)
set(GTEST_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${LIBRARY_DIR}/googletest/include PARENT_SCOPE)
set(GMOCK_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${LIBRARY_DIR}/googlemock/include PARENT_SCOPE)

#==== TESTING
option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    #subdirectory
    add_subdirectory(${LIBRARY_DIR})

    #to keep the CACHE clean
    mark_as_advanced(
        BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
        gmock_build_tests gtest_build_samples gtest_build_tests
        gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
    )

    set_target_properties(gtest PROPERTIES FOLDER ${THIRD_PARTY_PROJECT_FOLDER})
    set_target_properties(gtest_main PROPERTIES FOLDER ${THIRD_PARTY_PROJECT_FOLDER})
    set_target_properties(gmock PROPERTIES FOLDER ${THIRD_PARTY_PROJECT_FOLDER})
    set_target_properties(gmock_main PROPERTIES FOLDER ${THIRD_PARTY_PROJECT_FOLDER})

endif()


