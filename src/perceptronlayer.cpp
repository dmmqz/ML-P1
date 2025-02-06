#include "include/perceptronlayer.hpp"
#include "include/perceptron.hpp"

#include <iostream>

PerceptronLayer::PerceptronLayer(std::vector<Perceptron> perceptrons) {
    this->perceptrons = perceptrons;
}

std::vector<bool> PerceptronLayer::output(std::vector<bool> inputs) {
    std::vector<bool> outputs;
    for (Perceptron &perceptron : this->perceptrons) {
        outputs.push_back(perceptron.output(inputs));
    }
    return outputs;
}

void PerceptronLayer::__str__() {
    for (Perceptron &p : this->perceptrons) {
        std::cout << "Perceptron:" << std::endl;
        p.__str__();
    }
}
