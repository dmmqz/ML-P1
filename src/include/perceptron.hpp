#pragma once

#include <vector>

class Perceptron {
  private:
    std::vector<double> weights;
    double bias;

  public:
    Perceptron(std::vector<double> weights, double bias);
    bool output(std::vector<bool> inputs);
    void __str__();
};
