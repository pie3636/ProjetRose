#include "IA.h"
#include <stdlib.h>
#include <iostream>

IA::IA(int pop_size, std::vector<int> nn_schema){
	sim_ = std::vector<Simul>(pop_size);
	for(int i =  0; i < pop_size ; ++i){
		sim_[i] = Simul(Neural(nn_schema));
	}	
}    

