#ifndef IA_H
#define IA_H

#include "Simul.h"
#include <vector>

#define NUM_SIMU 10
#define SEL_TOP 4
#define NUM_TAK 1

class IA {
private:
	int population_size_;
	int selection_top_ = SEL_TOP;
	int selection_lucky_ = NUM_TAK;

	std::vector<Simul*> sim_;
	void sortIA();
	void select();
	void breed();
	void mutate();

public:
	void getNewGen();
	void evolve(int n);
	IA(int population_size, const std::vector <int> &nn_schema);
	IA();
	~IA();	

};

#endif //IA_H
