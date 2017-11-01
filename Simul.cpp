#include "Simul.h"
#include <stdlib.h>
#include <iostream>

int Simul::play(){

	bool stillPlaying = true;
	

	while(stillPlaying){
		//g.display();
		bool pressed = ask_if_press();
		stillPlaying = !g.step(pressed);
	}

	return g.getScore();
}    

int Simul::getAverageScore(int num){

	int total = 0;
	for( int i = 0 ; i < num ; i++){
		g.reset();
		total += play();
	}
}    

bool Simul::ask_if_press(){

	nn.set_input(g.getData());
	return nn.compute_output_values()[0]>0.5;
}
 
Simul::Simul(const Neural& n): nn(n){
	std::cout<<"Simul with neural constructor called"<<std::endl;
}

Simul::Simul(const std::vector<int> & v): nn(Neural(v)){
}

Simul::Simul(): nn(Neural()){
}

void Simul::mutate(){
	nn.mutate();
}
Neural Simul::breed(const Simul& s){
	return nn.breed(s.nn);
}
