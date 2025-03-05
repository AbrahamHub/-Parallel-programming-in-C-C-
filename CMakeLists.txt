cmake_minimum_required(VERSION 3.30)
project(Parallel_programming_)

set(CMAKE_CXX_STANDARD 20)

# Añadir la biblioteca pthread
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(Parallel_programming_ main.cpp thread.cpp thread.h)

# Enlazar la biblioteca pthread
target_link_libraries(Parallel_programming_ PRIVATE Threads::Threads)
