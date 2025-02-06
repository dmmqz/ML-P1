#include "include/perceptronnetwork.hpp"
#include "include/perceptronlayer.hpp"

#include <iostream>

PerceptronNetwork::PerceptronNetwork(std::vector<PerceptronLayer> layers) {
    this->layers = layers;
}

std::vector<bool> PerceptronNetwork::output(std::vector<bool> inputs) {
    for (int i = 0; i < this->layers.size(); i++) {
        inputs = this->layers[i].output(inputs);
    }
    return inputs;
}

void PerceptronNetwork::__str__() {
    for (auto &layer : this->layers) {
        std::cout << "Network:" << std::endl;
        layer.__str__();
    }
}
