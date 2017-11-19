#ifndef GAME_H
#define GAME_H

#include <list>
#include <vector>

//espace entre chaque nouvelle barre
#define BAR_SPACING 8
//hauteur du jeu
#define GAME_HEIGHT 63
//largeur du jeu
#define GAME_WIDTH 42
//largeur de la fente
#define Y_SPA 10.
//frequence d apparition d'un nouvelle barre
#define FREQ 10
//ratio de diminution de la fente
#define DECR_POWER 0.9

class Game {
    private:
        int nextBarX = BAR_SPACING;
        double speed = 0.;
        double ySpacing = Y_SPA;
        double currentY = GAME_HEIGHT / 2.0;
        std::list <double> centerY = {30., 30., 30., 30., 30.};
        // Si graphiques, stocker pastY
        int passedBars = 0;

        void nextBar();
        double getNcenter(int n);

    public:
        Game();
        Game(const Game& other);

        // @return true if the player has lost
        bool step(bool isPressed);

        void display();

        // @return The input data for the neural network
        std::vector <double> getData();
        int getScore();

        Game& operator=(Game rhs);

        friend void swap(Game& first, Game& second) { // nothrow
            using std::swap;

            swap(first.nextBarX, second.nextBarX);
            swap(first.speed, second.speed);
            swap(first.ySpacing, second.ySpacing);
            swap(first.currentY, second.currentY);
            swap(first.centerY, second.centerY);
            swap(first.passedBars, second.passedBars);
        }
};


#endif // GAME_H
