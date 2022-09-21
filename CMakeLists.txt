cmake_minimum_required(VERSION 3.10)

# set the project name
project(Hugin)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# google tests
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# for windows: prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    test
    test/crypto_test.cpp
    test/daemon_test.cpp
)

include(GoogleTest)
gtest_discover_tests(test)
target_link_libraries(test GTest::GTest GTest::Main)

# directories to be included
include_directories(${PROJECT_SOURCE_DIR})

# add the executable
add_executable(${PROJECT_NAME} main.cpp)

# add the subdirectories
add_subdirectory(
    crypto
    daemon
)

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

# boost configuration
set(Boost_NO_BOOST_CMAKE ON)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_STATIC_RUNTIME ON)
find_package(Boost REQUIRED COMPONENTS system filesystem thread date_time chrono regex serialization program_options)
message(STATUS "Boost Found: ${Boost_INCLUDE_DIRS}")
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
if(APPLE)
  set(Boost_LIBRARIES "${Boost_LIBRARIES}")
elseif(NOT MSVC)
  set(Boost_LIBRARIES "${Boost_LIBRARIES};rt")
endif()