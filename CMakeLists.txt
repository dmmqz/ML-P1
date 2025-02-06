cmake_minimum_required(VERSION 3.25.1)
project(perceptron)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    test/include
    src/include
)

add_executable(main
    main.cpp
)

add_executable(test
    src/perceptron.cpp
    src/perceptronlayer.cpp
    src/perceptronnetwork.cpp
    test/test.cpp
)
