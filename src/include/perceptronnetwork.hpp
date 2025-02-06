#pragma once

#include "perceptronlayer.hpp"

#include <vector>

class PerceptronNetwork {
  private:
    std::vector<PerceptronLayer> layers;

  public:
    PerceptronNetwork(std::vector<PerceptronLayer> layer);
    std::vector<bool> output(std::vector<bool> inputs);
    void __str__();
};
