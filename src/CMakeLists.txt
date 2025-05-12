set(SOURCES
    main.cpp
    pnl_calc.cpp
    trade.cpp
)

add_executable(pnl_calc ${SOURCES})

set_target_properties(pnl_calc PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})