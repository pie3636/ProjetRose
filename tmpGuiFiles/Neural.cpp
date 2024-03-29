#include "stdafx.h"
#include "Neural.h"
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <cmath>       /* exp */

Neural::~Neural(){}



Neural& Neural::operator=(Neural rhs){
	this->internal_nodes_values = rhs.internal_nodes_values;
	this->weight_values = rhs.weight_values;
	return *this;
}


Neural::Neural(const std::vector <int> &NN_structure) {


	internal_nodes_values = std::vector <std::vector <double>>(NN_structure.size());
	std::vector <double> inputData(NN_structure[0]);
	inputData[0] = 1;
	internal_nodes_values[0] = inputData;

	weight_values = std::vector <std::vector <std::vector <double>>>(NN_structure.size());
	std::vector <std::vector <double>> inputLayer(NN_structure[0]);
	for (int i = 0; i < NN_structure[0]; i++) {
		inputLayer[i] = std::vector <double>(0);
	}
	weight_values[0] = inputLayer;

	for (int i = 1; i < NN_structure.size(); ++i) {
		std::vector <double> hiddenData(NN_structure[i]);
		hiddenData[0] = 1;
		std::vector <std::vector <double>> someHiddenLayer(NN_structure[i]);
		for (int j = 0; j < NN_structure[i]; ++j) {
			std::vector <double> weight_node(NN_structure[i - 1]);
			for (double &k : weight_node) {
				k = double(rand()) / (double(RAND_MAX)) - 0.5;
			}
			someHiddenLayer[j] = weight_node;
		}
		internal_nodes_values[i] = hiddenData;
		weight_values[i] = someHiddenLayer;
	}

}

void Neural::set_input(const std::vector <double> &data_from_game_input) {
	auto jt = data_from_game_input.begin();
	assert(data_from_game_input.size() + 1 ==
		internal_nodes_values[0].size());//, " inputvalues size  +1 must be inputLayer size ");
	for (int i = 1; jt != data_from_game_input.end(); ++i, ++jt) {
		internal_nodes_values[0][i] = (*jt);
	}
	internal_nodes_values[0][0] = 1;
}

/*void Neural::display() {
for (int i = 0; i < internal_nodes_values.size(); ++i) {
std::cout << "Layer " << i << " : ";
for (double j : internal_nodes_values[i]) {
std::cout << j << " ";
}
std::cout << std::endl;
}
}*/
void Neural::print() {
for (int i = 0; i < internal_nodes_values.size(); ++i) {
std::cout << "Layer " << i << " : ";
for (double j : internal_nodes_values[i]) {
std::cout << j << " ";
}
std::cout << std::endl;
}
}

double Neural::logical_reg(const std::vector <double> &coefs, const std::vector <double> &inputs) {
	double sum = 0.0;
	assert(coefs.size() == inputs.size());//, "Erreur: les arguments ne possedent pas la m�me taille !");
	auto it = coefs.begin();
	auto jt = inputs.begin();
	for (; it != coefs.end() || jt != inputs.end(); ++it, ++jt) {
		sum += (*it) * (*jt);
	}
	return 1.0 / (1.0 + exp(-1.0 * sum));
}

std::vector <double> Neural::compute_output_values() {
	int i;
	int j;
	for (i = 1; i < internal_nodes_values.size() - 1; ++i) {
		for (j = 1; j < internal_nodes_values[i].size(); j++) {
			internal_nodes_values[i][j] = logical_reg(weight_values[i][j], internal_nodes_values[i - 1]);
		}
	}

	internal_nodes_values[i][0] = logical_reg(weight_values[i][0], internal_nodes_values[i - 1]);

	return internal_nodes_values[i];
}

Neural::Neural(const Neural &nn) : internal_nodes_values(nn.internal_nodes_values), weight_values(nn.weight_values) {
	//std::cout << "Neural copy constructor called" << std::endl;
}

Neural::Neural() {
	//std::cout << "Neural default constructor called" << std::endl;
	internal_nodes_values = std::vector <std::vector <double>>(0);
	weight_values = std::vector <std::vector <std::vector <double>>>(0);
}

void Neural::mutate() {

	for (int i = 1; i < weight_values.size(); ++i) {
		for (int j = 0; j < weight_values[i].size(); ++j) {
			for (int k = 0; k < weight_values[i - 1].size(); k++) {
				if (double(rand()) / (double(RAND_MAX)) < MUT_PROB) {
					weight_values[i][j][k] = (double(rand()) / (double(RAND_MAX)) - 0.5) * 2 * RANGE_MAX;
				}
			}
		}
	}
}

Neural Neural::breed(const Neural &n) {
	Neural new_neural = Neural(*this);
	for (int i = 1; i < weight_values.size(); ++i) {
		for (int j = 0; j < weight_values[i].size(); ++j) {
			for (int k = 0; k < weight_values[i - 1].size(); k++) {
				if (double(rand()) / (double(RAND_MAX)) < BREEDING_PROB) {
					//std::cout << "Entering here";
					new_neural.weight_values[i][j][k] = n.weight_values[i][j][k];
					//std::cout << "OUT here" << std::endl;
				}
			}
		}
	}
	return new_neural;
}
