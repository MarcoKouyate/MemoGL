#==== MACRO
macro(package_add_test TESTNAME FILES LIBRARIES TEST_WORKING_DIRECTORY)
    add_executable(${TESTNAME} ${FILES})
    target_link_libraries(${TESTNAME} gtest gmock gtest_main ${LIBRARIES})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
    add_test(${TESTNAME} ${TESTNAME})
endmacro()
