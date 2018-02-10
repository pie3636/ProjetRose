#ifndef SIMUL_H
#define SIMUL_H

#include "Game.h"
#include "Neural.h"

class Simul {
private:
	Game g;
	Neural nn;
	bool ask_if_press();
	explicit Simul(const std::vector <int> &vect_scheme);
	
public:	
	bool operator<( const Simul& v) const;
	int getScore() const;
	int Score_;
	/**
	*Simulation d'une partie
	*@return score de la partie simulée
	*/
	int play() ;
	void mutate();
	void printNN();
	void printscore();

	Neural breed(const Simul &s);
	int getAverageScore(int num);
	explicit Simul(const Neural &nn_);
	~Simul();
	Simul();
	Simul& operator=(Simul rhs);
};
#endif // SIMUL_H


