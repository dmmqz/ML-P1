#pragma once

#include "perceptron.hpp"

#include <vector>

class PerceptronLayer {
  private:
    std::vector<Perceptron> perceptrons;

  public:
    PerceptronLayer(std::vector<Perceptron> perceptrons);
    std::vector<bool> output(std::vector<bool> inputs);
    void __str__();
};
