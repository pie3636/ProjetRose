#include "IA.h"
#include <stdlib.h>
#include <iostream>
#include <random>
#include <algorithm>

IA::IA(int pop_size, const std::vector<int> & nn_schema){
	population_size_ = pop_size;
	sim_ = std::vector<Simul>(pop_size);
	for(int i =  0; i < pop_size ; ++i){
		sim_[i] = Simul(Neural(nn_schema));
	}	
}    

void IA::sort(){
	std::sort(sim_.begin(), sim_.end(), [&](Simul &a, Simul &b) {
	 return a.getAverageScore(NUM_SIMU) > b.getAverageScore(NUM_SIMU); 
	});
}


void IA::select(){
	std::random_shuffle(sim_.begin() + selection_top_, sim_.end());
	sim_.resize(selection_lucky_ + selection_top_);
}


void IA::breed(){
	for (int i = 0; i < population_size_ - (selection_lucky_ + selection_top_); i++) {
		Simul first = sim_[rand() % (selection_lucky_ + selection_top_)];
		Simul second = sim_[rand() % (selection_lucky_ + selection_top_)];
            sim_.push_back(first.breed(second));
        }
}

void IA::mutate(){
	         for (auto s: sim_) {
            s.mutate();
        }
}


void IA::getNewGen(){
		std::cout<<"Start sorting = "<<std::endl;

	sort();
		std::cout<<"Start selecting = "<<std::endl;

	select();
		std::cout<<"Start mutating = "<<std::endl;

	mutate();
		std::cout<<"Start breeding = "<<std::endl;

	breed();
}

void IA::evolve(int n){
	std::cout<<"Start evolving = "<<std::endl;
	for(int i=0; i<n ; i++){
		getNewGen();
	}
		std::cout<<"Finish evolving = "<<std::endl;

	sort();
	int best_score_gotten  = (*sim_.begin()).play();
	std::cout<<"Best score after evolving = "<<best_score_gotten<<std::endl;
}