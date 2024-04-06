cmake_minimum_required(VERSION 3.2)
project(helloworld)
set(CMAKE_CXX_STANDARD 11)
add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/helloworld.cpp ${CMAKE_CURRENT_SOURCE_DIR}/PrimeChecker.cpp)

# This adds the -static flag to the linker, which will cause the executable to be statically linked
# This means that all dependencies will be included in the executable, so that it can run on the scratch image
set_target_properties(helloworld PROPERTIES LINK_FLAGS "-static")

enable_testing()
add_executable(${PROJECT_NAME}-Runner TestPrimeChecker.cpp ${CMAKE_CURRENT_SOURCE_DIR}/PrimeChecker.cpp)
add_test(NAME ${PROJECT_NAME}-Runner COMMAND ${PROJECT_NAME}-Runner)