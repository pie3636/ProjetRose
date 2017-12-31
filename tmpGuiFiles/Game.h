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
//frequence d apparition d'un nouvelle barre
#define FREQ 10
//ratio de diminution de la fente
#define DECR_POWER 1.0

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

	// @return The input data for the neural network
	std::vector<double> getData();
	int getScore();
	~Game();
	Game& operator=(Game rhs);


};


#endif // GAME_H
