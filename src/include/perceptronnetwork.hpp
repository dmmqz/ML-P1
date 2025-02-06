/**
 * @file perceptronnetwork.hpp
 * @brief Define PerceptronNetwork class
 * @author Dylan McGivern
 */
#pragma once

#include "perceptronlayer.hpp"

#include <vector>

/**
 * @class PerceptronNetwork
 * @brief Network of perceptrons
 *
 * This class represents a network of perceptrons, that are divided into layers.
 */
class PerceptronNetwork {
  private:
    std::vector<PerceptronLayer> layers;

  public:
    PerceptronNetwork(std::vector<PerceptronLayer> layers);
    /**
     * @brief Gets the output(s) of a network
     * @param inputs The inputs to generate the output with
     * @return std::vector<bool>: Output of the network
     */
    std::vector<bool> output(std::vector<bool> inputs);
    /**
     * @brief Prints the network attributes
     */
    void __str__();
};
