#include "Simul.h"
#include <cstdlib>
#include <iostream>
#include "stdafx.h"

int Simul::play(){
	bool stillPlaying = true;
	g.reset();
	this->Score_ = 0;

	while (stillPlaying){
		//g.display();
		bool pressed = ask_if_press();
		stillPlaying = !g.step(pressed);
		if (g.getScore() > 100){
			this->Score_ = g.getScore();
			return g.getScore();
		}
	}
	this->Score_ = g.getScore();
	return g.getScore();
}


int Simul::getScore() const{

	return g.getScore();
}


bool Simul::operator<(const Simul & s) const{
	return Score_ < s.Score_;
}


int Simul::getAverageScore(int num) {
	int total = 0;
	for (int i = 0; i < num; i++) {
		//std::cout<<"in-";
		g.reset();
		//std::cout<<"OUT";
		total += play();
	}
	return total;
}

bool Simul::ask_if_press(){
	nn.set_input(g.getData());
	return nn.compute_output_values()[0] > 0.5;
}

Simul::Simul(const Neural &n) : nn(n), g(){
	//std::cout << "Simul with neural constructor called" << std::endl;
}

Simul& Simul::operator=(Simul rhs){
	this->g = rhs.g;
	this->nn = rhs.nn;
	return *this;
}
Simul::~Simul(){
}

Simul::Simul(const std::vector <int> &v) : nn(Neural(v)) {
	g = Game();
}

Simul::Simul() : nn(Neural()) {
	g = Game();
}

void Simul::mutate() {
	nn.mutate();
}
void Simul::printNN(){
	nn.print();
}
void Simul::printscore(){
	std::cout << g.givepassedBars() << std::endl;
}
Neural Simul::breed(const Simul &s) {
	return nn.breed(s.nn);
}