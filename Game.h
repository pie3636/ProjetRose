#ifndef GAME_H
#define GAME_H

#include <list>

#define BAR_SPACING 18
#define GAME_HEIGHT 63

class Game {
    private:
        int nextBarX = BAR_SPACING;
        double speed = 0.;
        double currentY = GAME_HEIGHT / 2;
        std::list<int> lowY = {0, 0, 0, 0, 0};
        // Si graphiques, stocker pastY
        int passedBars = 0;

        void nextBar() {
            nextBarX = BAR_SPACING;
            passedBars++;
            lowY.pop_front();
            lowY.push_back(0 /* une hauteur random en fonction de passedBars */);
        }

    public:
        // @return true if the player has lost
        bool step(bool isPressed) {
            nextBarX--;
            speed += isPressed ? .32 : -.32;
            currentY += speed;
            if (currentY < 0 || currentY > GAME_HEIGHT) {
                return true;
            }
            if (nextBarX == 0) {
                nextBar();
            }
            return false;
        }

        void display() {
            // TODO
        }

        // @return The input data for the neural network
        std::list<int> getData() {
            // Y courant
            // speed courante
            // nextBarX
            // nextYcenter
            // nextNextYcenter
            return {};
        }
};


#endif // GAME_H
