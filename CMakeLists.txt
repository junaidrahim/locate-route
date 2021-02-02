cmake_minimum_required(VERSION 3.17)
project(locate_route)

set(CMAKE_CXX_STANDARD 17)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(locate_route main.cpp include/httplib.h include/CLI11.hpp src/TracerouteRunner.cpp include/TracerouteRunner.h src/Location.cpp include/Location.h include/json.hpp)
target_link_libraries(locate_route PRIVATE Threads::Threads)