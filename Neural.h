#ifndef NEURAL_H
#define NEURAL_H

#include <list>
#include <vector>


class Neural{
private:
	std::vector<std::vector<double>> internal_nodes_values;
	std::vector<std::vector<std::vector<double>>> weight_values;

	std::vector<double> input_values;
	std::vector<double> output_values;

	double logical_reg(const std::vector<double> & coefs, const std::vector<double> & inputs);

public:
	Neural(const std::vector<int>& NN_structure);
	Neural(const Neural & nn);
	void set_input(const std::vector<double> &input_values_arg);
	void display();
	Neural();


	std::vector<double> compute_output_values();
};

#endif // NEURAL_H
