#include "include/perceptronlayer.hpp"
#include "include/perceptron.hpp"

PerceptronLayer::PerceptronLayer(std::vector<Perceptron> perceptrons,
                                 std::string name) {
    this->perceptrons = perceptrons;
    this->name = name;
}

std::vector<bool> PerceptronLayer::output(std::vector<bool> inputs) {
    std::vector<bool> outputs;
    for (Perceptron &perceptron : this->perceptrons) {
        outputs.push_back(perceptron.output(inputs));
    }
    return outputs;
}

std::string PerceptronLayer::__str__() { return this->name; }
