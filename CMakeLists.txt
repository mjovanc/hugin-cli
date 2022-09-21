cmake_minimum_required(VERSION 3.10)

# set the project name
project(Heimdall)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# google tests
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    crypto_test
  ./test/crypto_test.cpp
)

include(GoogleTest)
gtest_discover_tests(crypto_test)
target_link_libraries(crypto_test gtest_main)

# directories to be included
include_directories(${PROJECT_SOURCE_DIR})

# add the executable
add_executable(${PROJECT_NAME} main.cpp)

# add the subdirectories
add_subdirectory(peer)

# include directories
target_include_directories(
  ${PROJECT_NAME}
  PUBLIC
  crypto
)

# link libraries
target_link_directories(
  ${PROJECT_NAME}
  PRIVATE
  crypto
)
target_link_libraries(
  ${PROJECT_NAME}
  crypto
)