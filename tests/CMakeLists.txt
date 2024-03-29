if(BUILD_TESTING)
    add_custom_target(check COMMAND CTEST_OUTPUT_ON_FAILURE=true ${CMAKE_CTEST_COMMAND})

    message(STATUS "(EC) Generating librmn tests")

    add_executable(clib_isalpha EXCLUDE_FROM_ALL ${CMAKE_CURRENT_SOURCE_DIR}/clib_isalpha.F90)
    target_link_libraries(clib_isalpha rmn::rmn)
    add_test(NAME clib_isalpha COMMAND ${CMAKE_CURRENT_BINARY_DIR}/clib_isalpha ${CMAKE_CURRENT_SOURCE_DIR}/spp.dict)
    add_dependencies(check clib_isalpha)

    foreach(DATATYPE float double)
        add_executable(fst_${DATATYPE} EXCLUDE_FROM_ALL fst.c)
        target_compile_definitions(fst_${DATATYPE} PRIVATE DATATYPE=${DATATYPE})
        target_link_libraries(fst_${DATATYPE} PRIVATE rmn::rmn m)
        add_test(NAME fst_${DATATYPE} COMMAND ${CMAKE_CURRENT_BINARY_DIR}/fst_${DATATYPE})
        add_dependencies(check fst_${DATATYPE})
    endforeach()

    add_executable(wb_read EXCLUDE_FROM_ALL wb_read.F90)
    target_link_libraries(wb_read rmn::rmn)
    add_test(NAME wb_read COMMAND ${CMAKE_CURRENT_BINARY_DIR}/wb_read ${CMAKE_CURRENT_SOURCE_DIR}/spp.dict)
    add_dependencies(check wb_read)

    add_executable(wb_putget EXCLUDE_FROM_ALL wb_putget.F90)
    target_link_libraries(wb_putget rmn::rmn)
    target_include_directories(wb_putget PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src/whiteboard)
    add_test(NAME wb_putget COMMAND ${CMAKE_CURRENT_BINARY_DIR}/wb_putget)
    add_dependencies(check wb_putget)

    add_executable(wb_test EXCLUDE_FROM_ALL wb_test.c)
    target_link_libraries(wb_test rmn::rmn)
    target_include_directories(wb_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src/whiteboard)
    add_test(NAME wb_test COMMAND ${CMAKE_CURRENT_BINARY_DIR}/wb_test)
    add_dependencies(check wb_test)

    add_executable(wb_test_f90 EXCLUDE_FROM_ALL wb_test.F90)
    target_link_libraries(wb_test_f90 rmn::rmn)
    target_include_directories(wb_test_f90 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src/whiteboard)
    add_test(NAME wb_test_f90  COMMAND ${CMAKE_CURRENT_BINARY_DIR}/wb_test_f90)
    add_dependencies(check wb_test_f90)

# This test is weird and I need moretime to understand it
#    add_executable(wb_get EXCLUDE_FROM_ALL wb_get.c)
#    target_link_libraries(wb_get rmn::rmn)
#    target_include_directories(wb_get PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src/whiteboard)
#    add_test(NAME wb_get COMMAND ${CMAKE_CURRENT_BINARY_DIR}/wb_get)
#    add_dependencies(check wb_get)

    add_executable(prog_filename EXCLUDE_FROM_ALL prog_filename.c)
    target_link_libraries(prog_filename rmn::rmn)
    add_test(NAME prog_filename COMMAND ${CMAKE_CURRENT_BINARY_DIR}/prog_filename)
    add_dependencies(check prog_filename)

    add_executable(gmm EXCLUDE_FROM_ALL gmm.F90)
    target_link_libraries(gmm rmn::rmn)
    add_test(NAME gmm COMMAND ${CMAKE_CURRENT_BINARY_DIR}/gmm)
    add_dependencies(check gmm)

    add_executable(c_ccard EXCLUDE_FROM_ALL c_ccard.c)
    target_link_libraries(c_ccard rmn::rmn)
    add_test(NAME c_ccard COMMAND ${CMAKE_CURRENT_BINARY_DIR}/c_ccard)
    add_dependencies(check c_ccard)

    add_executable(burp_f EXCLUDE_FROM_ALL burp_f.f)
    target_link_libraries(burp_f rmn::rmn)
    add_test(NAME burp_f COMMAND ${CMAKE_CURRENT_BINARY_DIR}/burp_f)
    add_dependencies(check burp_f)

    add_executable(burp_c EXCLUDE_FROM_ALL burp_c.c)
    target_link_libraries(burp_c rmn::rmn)
    add_test(NAME burp_c COMMAND ${CMAKE_CURRENT_BINARY_DIR}/burp_c)
    add_dependencies(check burp_c)
endif()
