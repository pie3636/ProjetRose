#ifndef SIMUL_H
#define SIMUL_H

#include "Game.h"
#include "Neural.h"

class Simul{
private:
	
	Game g;
	Neural nn;
	bool ask_if_press();
	Simul(std::vector<int> vect_scheme);

public:
	/**
	*Simulation d'une partie
	*@return score de la partie simulée
	*/
	int play();
	Simul(const Neural& nn_);
	Simul();
};

#endif // SIMUL_H



