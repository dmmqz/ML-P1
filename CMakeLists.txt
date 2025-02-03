cmake_minimum_required(VERSION 3.25.1)
project(perceptron)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    test/include
    src/include
)

add_executable(main
    src/perceptron.cpp
    main.cpp
)
