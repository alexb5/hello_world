cmake_minimum_required(VERSION 3.2)

project(hello_world VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

configure_file(version.h.in version.h)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(${PROJECT_NAME} "main.cpp")

add_library(library "lib.cpp")

set_target_properties(${PROJECT_NAME}  PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

add_executable(test_${PROJECT_NAME} test_main.cpp)

set_target_properties(${PROJECT_NAME}  test_${PROJECT_NAME} PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)


set_target_properties(test_${PROJECT_NAME} PROPERTIES
  INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} library)

target_link_libraries(test_${PROJECT_NAME}
  ${GTEST_BOTH_LIBRARIES}
  library
  pthread
)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT alexb5@mail.ru)

include (CPack)

enable_testing()

add_test(tests test_${PROJECT_NAME})
