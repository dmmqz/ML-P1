#pragma once

#include <string>
#include <vector>

class Perceptron {
  private:
    std::vector<double> weights;
    double bias;
    std::string name;

  public:
    Perceptron(std::vector<double> weights, double bias, std::string name);
    bool output(std::vector<bool> inputs);
    std::string __str__();
};
