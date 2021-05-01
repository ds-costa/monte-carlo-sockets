cmake_minimum_required(VERSION 3.10)

project(MonteCarloSockets C CXX)
set(CMAKE_C_STANDARD 99)

#add_library(lib src/lib.c)
add_library(socketconfig src/socketconfig.c)

add_executable(client client.c)
add_executable(server server.c)

target_link_libraries(client socketconfig -lm)
target_link_libraries(server socketconfig -lm)

if (WIN32)
    target_link_libraries(MonteCarloSockets -lwsock32)
endif (WIN32)

# target_compile_options(client PRIVATE  -Wall -Wextra)
target_compile_options(client PRIVATE -Wall -Wextra)
target_compile_options(server PRIVATE -Wall -Wextra)