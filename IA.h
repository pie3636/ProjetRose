#ifndef IA_H
#define IA_H

#include "Simul.h"
#include <vector>

class IA{
private:
	
	std::vector<Simul> sim_;
public:


	IA(int population_size, std::vector<int> nn_schema);
};

#endif // IA_H
