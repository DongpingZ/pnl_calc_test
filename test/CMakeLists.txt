set(TEST_SOURCES
    test_pnl_calc.cpp
    test_trade.cpp
)

add_executable(pnl_calc_tests ${TEST_SOURCES})

target_link_libraries(pnl_calc_tests
    GTest::gtest
    GTest::gtest_main
)

target_sources(pnl_calc_tests PRIVATE
    ${PROJECT_SOURCE_DIR}/src/pnl_calc.cpp
    ${PROJECT_SOURCE_DIR}/src/trade.cpp
)

add_test(NAME pnl_calc_tests
        COMMAND pnl_calc_tests)