#define CATCH_CONFIG_MAIN

#include "include/catch.hpp"

#include "../src/include/perceptron.hpp"
#include "../src/include/perceptronlayer.hpp"
#include "../src/include/perceptronnetwork.hpp"

// Test perceptron unit
TEST_CASE("Test INVERT-gate") {
    Perceptron invertGate = Perceptron({-1}, 0.5);

    // Return true if input is false, and vice versa
    REQUIRE(invertGate.output({false}));
    REQUIRE(!invertGate.output({true}));
}

TEST_CASE("Test AND-gate") {
    Perceptron andGate = Perceptron({0.5, 0.5}, -1);

    // Return true only if both inputs are true
    REQUIRE(andGate.output({true, true}));
    REQUIRE(!andGate.output({false, true}));
    REQUIRE(!andGate.output({true, false}));
    REQUIRE(!andGate.output({false, false}));
}

TEST_CASE("Test OR-gate") {
    Perceptron orGate = Perceptron({0.5, 0.5}, -0.5);

    // Return true if atleast one input is true
    REQUIRE(orGate.output({true, true}));
    REQUIRE(orGate.output({true, false}));
    REQUIRE(orGate.output({false, true}));
    REQUIRE(!orGate.output({false, false}));
}

TEST_CASE("Test NOR-gate") {
    Perceptron norGate = Perceptron({-1, -1, -1}, 0);

    // Return true if all inputs are false
    REQUIRE(norGate.output({false, false, false}));
    REQUIRE(!norGate.output({true, false, false}));
    REQUIRE(!norGate.output({true, true, false}));
    REQUIRE(!norGate.output({true, true, true}));
    REQUIRE(!norGate.output({true, false, true}));
    REQUIRE(!norGate.output({false, true, false}));
    REQUIRE(!norGate.output({false, true, true}));
    REQUIRE(!norGate.output({false, false, true}));
}

TEST_CASE("Test custom gate") {
    Perceptron customGate = Perceptron({0.6, 0.3, 0.2}, -0.4);

    // true if inputs[0] OR (inputs[1] AND inputs[2])
    REQUIRE(customGate.output({true, false, false}));
    REQUIRE(customGate.output({true, true, false}));
    REQUIRE(customGate.output({true, true, true}));
    REQUIRE(customGate.output({true, false, true}));
    REQUIRE(customGate.output({false, true, true}));
    REQUIRE(!customGate.output({false, true, false}));
    REQUIRE(!customGate.output({false, false, true}));
    REQUIRE(!customGate.output({false, false, false}));
}

TEST_CASE("Test XOR-gate") {
    PerceptronLayer layer1 = PerceptronLayer(
        {Perceptron({0.5, 0.5}, -0.5), Perceptron({-2, -2}, 3)});
    PerceptronLayer layer2 = PerceptronLayer({Perceptron({0.5, 0.5}, -1)});

    PerceptronNetwork xorGate = PerceptronNetwork({layer1, layer2});

    REQUIRE(!xorGate.output({false, false})[0]);
    REQUIRE(xorGate.output({true, false})[0]);
    REQUIRE(xorGate.output({false, true})[0]);
    REQUIRE(!xorGate.output({true, true})[0]);
}

TEST_CASE("Test Half Adder") {
    PerceptronLayer layer1 = PerceptronLayer(
        {Perceptron({0.5, 0.5}, -0.5), Perceptron({-2, -2}, 3)});
    PerceptronLayer layer2 =
        PerceptronLayer({Perceptron({0.5, 0.5}, -1), Perceptron({1, -2}, -1)});

    PerceptronNetwork xorGate = PerceptronNetwork({layer1, layer2});

    REQUIRE(xorGate.output({false, false}) == std::vector<bool>{false, false});
    REQUIRE(xorGate.output({true, false}) == std::vector<bool>{true, false});
    REQUIRE(xorGate.output({false, true}) == std::vector<bool>{true, false});
    REQUIRE(xorGate.output({true, true}) == std::vector<bool>{false, true});
}
