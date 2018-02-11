#include "IA.h"
#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <random>
#include <algorithm>

IA::~IA(){
}

IA::IA(int pop_size, const std::vector<int> &nn_schema){
	population_size_ = pop_size;
	sim_ = std::vector<Simul*>(pop_size);
	for (int i = 0; i < pop_size; ++i) {
		Neural n = Neural(nn_schema);
		sim_[i] = new Simul(n);
	}
}
IA::IA() {
	population_size_ = 0;
	sim_ = std::vector<Simul*>(population_size_);
	for (int i = 0; i < population_size_; ++i) {
		sim_[i] = new Simul(Neural());
	}
}


bool ScoreSort(const Simul *one, const Simul* two)
{
	return one->getScore() > (two->getScore());
}

void IA::sortIA() {

	for (int i = 0; i < sim_.size(); i++)
	{
		sim_[i]->play();

	}
	std::sort(sim_.begin(), sim_.end(), ScoreSort);
}

void IA::select() {
	sortIA();
	std::shuffle(sim_.begin() + selection_top_, sim_.end(), std::mt19937(std::random_device()()));
	sim_.resize(selection_lucky_ + selection_top_);
}

void IA::breed() {
	for (int i = 0; i < population_size_ - (selection_lucky_ + selection_top_); i++) {
		Simul* first = sim_[rand() % (selection_lucky_ + selection_top_)];
		Simul* second = sim_[rand() % (selection_lucky_ + selection_top_)];
		sim_.emplace_back(new Simul(first->breed(*second)));
	}
}

void IA::mutate() {
	for (auto s : sim_) {
		s->mutate();
	}
}

void IA::getNewGen() {
	//std::cout << "Start sorting = " << std::endl;

	//sortIA();
	/****** DEBUT DEBUG ******/
	//sortIA();
	//int best_score_gotten = (*sim_.begin()).play();
	//std::cout << "Best score after sorting = " << best_score_gotten << std::endl;
	//std::cout << "Start selecting = " << std::endl;
	/****** FIN DEBUG ******/
	select();
	//std::cout << "Start mutating = " << std::endl;

	mutate();
	/****** DEBUT DEBUG ******/
	//sortIA();
	//best_score_gotten = (*sim_.begin()).play();
	//std::cout << "Best score after mutating = " << best_score_gotten << std::endl;
	//std::cout << "Start breeding = " << std::endl;
	/****** FIN DEBUG ******/
	breed();
	/****** DEBUT DEBUG ******/
	//sortIA();
	//best_score_gotten = (*sim_.begin()).play();
	//std::cout << "Best score after breeding = " << best_score_gotten << std::endl;
	/****** FIN DEBUG ******/
}

void IA::evolve(int n) {
	std::cout << "Start evolving = " << std::endl;
	int best_score_gotten;

	for (int i = 0; i < n; i++) {
		//best_score_gotten = (*sim_.begin()).play();
		//std::cout << "Best score of this generation: " << best_score_gotten << std::endl;
		getNewGen();
		sortIA();
		best_score_gotten = (*sim_.begin())->play();
		(*sim_.begin())->printNN();
		std::cout << "Best score after evolving = " << best_score_gotten << std::endl;
		//(*sim_.begin()).printscore();
	}
	std::cout << "Finish evolving = " << std::endl;

	sortIA();
	best_score_gotten = (*sim_.begin())->play();
	(*sim_.begin())->printNN();
	std::cout << "Best score after evolving = " << best_score_gotten << std::endl;
}

