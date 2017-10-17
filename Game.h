#ifndef GAME_H
#define GAME_H

#include <list>

#define BAR_SPACING 18
#define GAME_HEIGHT 63
#define Y_SPA 10.
#define FREQ 10
#define DECR_POWER 0.9

class Game {
    private:
        int nextBarX = BAR_SPACING;
        double speed = 0.;
        double yspaceing=Y_SPA;
        double currentY = GAME_HEIGHT / 2.0;
        std::list<double> centerY = {30., 30., 30., 30., 30.};
        // Si graphiques, stocker pastY
        int passedBars = 0;

        void nextBar();

    public:
        // @return true if the player has lost
        bool step(bool isPressed) ;

        void display();

        // @return The input data for the neural network
        std::list<double> getData() ;
};


#endif // GAME_H
