#pragma once

#include "perceptron.hpp"

#include <string>
#include <vector>

class PerceptronLayer {
  private:
    std::string name;
    std::vector<Perceptron> perceptrons;

  public:
    PerceptronLayer(std::vector<Perceptron> perceptrons, std::string name);
    std::vector<bool> output(std::vector<bool> inputs);
    std::string __str__();
};
