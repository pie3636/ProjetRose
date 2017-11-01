#ifndef NEURAL_H
#define NEURAL_H

#include <list>
#include <vector>

#define MUT_PROB 0.01
#define RANGE_MAX  30.0
#define BREEDING_PROB  30.0

class Neural{
private:
	std::vector<std::vector<double>> internal_nodes_values;
	std::vector<std::vector<std::vector<double>>> weight_values;

	std::vector<double> input_values;
	std::vector<double> output_values;

	double mutation_probability_ = MUT_PROB;
	double logical_reg(const std::vector<double> & coefs, const std::vector<double> & inputs);

public:
	Neural(const std::vector<int>& NN_structure);
	Neural(const Neural & nn);
	void set_input(const std::vector<double> &input_values_arg);
	void display();
	Neural();
	void mutate();
	Neural breed(const Neural& n);

	std::vector<double> compute_output_values();
};

#endif // NEURAL_H
