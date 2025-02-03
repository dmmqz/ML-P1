#include "include/perceptron.hpp"

#include <string>
#include <vector>

Perceptron::Perceptron(std::vector<double> weights, double bias,
                       std::string name) {
    this->weights = weights;
    this->bias = bias;
    this->name = name;
}

bool Perceptron::output(std::vector<bool> inputs) {
    double total_sum = 0;
    for (int i = 0; i < inputs.size(); i++) {
        if (inputs[i]) {
            total_sum += this->weights[i];
        }
    }
    return (total_sum > -this->bias);
}

std::string Perceptron::__str__() { return this->name; }
