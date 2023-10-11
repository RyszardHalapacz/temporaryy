cmake_minimum_required(VERSION 3.14)
project(MyApp)

#set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("${CMAKE_SOURCE_DIR}/include")
include_directories("${CMAKE_SOURCE_DIR}/lib")
#GTEST

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

#GTEST
enable_testing()

set (MY_SOURCES
src/server.cpp
src/databasehandler.cpp)
set(TEST_SOURCES 
${MY_SOURCES}  
test/test.cpp)

add_executable(
  main_test
  ${TEST_SOURCES}

)
target_link_libraries(main_test GTest::gtest_main
)


include(GoogleTest)
gtest_discover_tests(main_test)


add_executable(MyApp 
    src/main.cpp 
)
target_link_libraries(MyApp -lpqxx -lpq)

