/**
 * @file perceptronlayer.hpp
 * @brief Define PerceptronLayer class
 * @author Dylan McGivern
 */
#pragma once

#include "perceptron.hpp"

#include <vector>

/**
 * @class PerceptronLayer
 * @brief Layer in a network
 *
 * This class represents a layer in a network of perceptrons. The constructor
 * takes a vector of perceptrons.
 */
class PerceptronLayer {
  private:
    std::vector<Perceptron> perceptrons;

  public:
    /**
     * @brief Constructs a layer of perceptrons
     * @param perceptrons Perceptrons of this layer
     */
    PerceptronLayer(std::vector<Perceptron> perceptrons);
    /**
     * @brief Gets output of the layer given inputs
     * @param inputs Inputs for this layer
     * @return std::vector<bool>: All outputs of the perceptrons
     */
    std::vector<bool> output(std::vector<bool> inputs);
    /**
     * @brief Prints the layer attributes
     */
    void __str__();
};
