cmake_minimum_required(version 3.28)
project(MarketReplay VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

option(MARKETREPLAY_SANITIZERS "Enable address and undefined behavior checks" OFF)

add_library(market_options INTERFACE)
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(market_options INTERFACE 
    -Wall -Wextra -Wpedantic -Werror=return-type)
    if(MARKETREPLAY_SANITIZERS)
        target_compile_options(market_options INTERFACE 
        -fsanitize=address,undefined -fno-omit-frame-pointer)
        target_link_options(market_options INTERFACE 
        -fsanitize=address,undefined)
    endif()
endif()

add_library(market_core src/quote.cpp)
target_include_directories(market_core PUBLIC include)
target_link_libraries(market_replay PRIVATE market_core)

add_executable(market_replay app/main.cpp)
target_link_libraries(market_replay PRIVATE market_core)

include(CTest)
if(BUILD_TESTING)
    add_executable(quote_tests test/quote_tests.cpp)
    target_link_libraries(quote_tests PRIVATE market_core)
    add_test(NAME quote_contracts COMMAND quote_tests)
endif()
