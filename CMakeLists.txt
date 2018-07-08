cmake_minimum_required(VERSION 3.2)

project(hello_world VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

configure_file(version.h.in ${PROJECT_SOURCE_DIR}/version.h)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} "main.cpp")

add_library(library "lib.cpp")

add_executable(test_gtest test_gtest.cpp)

add_executable(test_boost test_boost.cpp)

set_target_properties(${PROJECT_NAME}  PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS -Wpedantic -Wall -Wextra
        )


set_target_properties(${PROJECT_NAME}  test_gtest test_boost PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS -Wpedantic -Wall -Wextra
        )

set_target_properties(test_boost PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
        )

set_target_properties(test_gtest PROPERTIES
        INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS}
        )


target_link_libraries(${PROJECT_NAME} library)

target_link_libraries(test_gtest
        ${GTEST_BOTH_LIBRARIES}
        library
        pthread
        )

target_link_libraries(test_boost
        ${Boost_LIBRARIES}
        library
        )

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT alexb5@mail.ru)

include (CPack)

enable_testing()

add_test(boost_test test_boost)

add_test(gtest_tests test_gtest)
