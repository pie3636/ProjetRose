#ifndef NEURAL_H
#define NEURAL_H

#include <vector>

#define MUT_PROB 0.03
#define RANGE_MAX  30.0
#define BREEDING_PROB  0.15

class Neural {
private:
	std::vector <std::vector <double>> internal_nodes_values;
	std::vector <std::vector <std::vector <double>>> weight_values;

	double logical_reg(const std::vector <double> &coefs, const std::vector <double> &inputs);

public:
	explicit Neural(const std::vector <int> &NN_structure);
	Neural(const Neural &nn);
	void print();
	void set_input(const std::vector <double> &input_values_arg);
	//void display();
	Neural();
	void mutate();
	Neural breed(const Neural &n);
	~Neural();
	std::vector <double> compute_output_values();


	Neural& operator=(Neural rhs);
};

#endif // NEURAL_H
