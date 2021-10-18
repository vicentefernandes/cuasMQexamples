cmake_minimum_required(VERSION 3.9.2)
project(cuasMQexamples)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS -pthread)
#include_directories(includes)

add_subdirectory(include/cuasMQ)

add_executable(cuas_consumer src/cuas_consumer_example.cpp)
target_link_libraries(cuas_consumer cppkafka cuasMQLib)

add_executable(cuas_producer src/cuas_producer_example.cpp)
target_link_libraries(cuas_producer cppkafka cuasMQLib)
