#ifndef GAME_H
#define GAME_H

#include <list>
#include <vector>

//espace entre chaque nouvelle barre
#define BAR_SPACING 20
//hauteur du jeu
#define GAME_HEIGHT 63
//largeur du jeu
#define GAME_WIDTH 110
//largeur de la fente
#define Y_SPA 10.
//frequence de diminution de fente 
#define FREQ 5
//ratio de diminution de la fente
#define DECR_POWER 0.94

class Game {
private:
	int nextBarX = BAR_SPACING;
	double speed = 0.;
	double ySpacing = Y_SPA;
	double currentY = GAME_HEIGHT / 2.0;
	std::vector<double> centerY;
	// Si graphiques, stocker pastY
	int passedBars = 0;

	void nextBar();
	double getNcenter(int n);

public:
	Game();
	Game(const Game& other);
	int givepassedBars();

	// @return true if the player has lost
	bool step(bool isPressed);

	//void display();

	void reset();

	static double *pos;
	// @return The input data for the neural network
	std::vector<double> getData();
	int getScore() const;
	~Game();
	Game& operator=(Game rhs);


};


#endif // GAME_H
