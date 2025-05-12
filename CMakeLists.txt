cmake_minimum_required(VERSION 3.10)
project(pnl_calc VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)

option(BUILD_TESTS "Build tests" ON)
if(BUILD_TESTS)
  enable_testing()
  
  find_package(GTest QUIET)
  if(NOT GTest_FOUND)
    message(STATUS "GTest not found, using FetchContent to download it")
    include(FetchContent)
    FetchContent_Declare(
      googletest
      GIT_REPOSITORY https://github.com/google/googletest.git
      GIT_TAG release-1.12.1
    )
    set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
  endif()
  
  add_subdirectory(test)
endif()

install(TARGETS pnl_calc
        RUNTIME DESTINATION bin)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
        DESTINATION include
        FILES_MATCHING PATTERN "*.h")