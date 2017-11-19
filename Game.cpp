#include "Game.h"
#include <cstdlib>
#include <iostream>
#include <cmath>

#define GRAVITY .32

Game::Game() {
    std::cout << "[Game] Default ctor" << std::endl;
}

Game::Game(const Game &other) {
    std::cout << "[Game] Copy ctor" << std::endl;
}

Game& Game::operator=(Game rhs) {
    std::cout << "[Game] Assignment operator" << std::endl;
    swap(*this, rhs);
    return *this;
}

void Game::nextBar() {
    nextBarX = BAR_SPACING;
    passedBars++;
    if (passedBars % FREQ == 0) ySpacing = ySpacing * DECR_POWER;
    centerY.pop_front();

    double newH = rand() % (63 - int(ySpacing)) + int(ySpacing);

    centerY.push_back(newH);
}

bool Game::step(bool isPressed) {
    nextBarX--;
    speed += isPressed ? GRAVITY : -GRAVITY;
    currentY += speed;
    if (currentY < 0 || currentY > GAME_HEIGHT) {
        return true;
    }
    if (nextBarX == 0) {
        if (currentY < centerY.front() - ySpacing || currentY > centerY.front() + ySpacing) {
            return true;
        }
        nextBar();
    }
    return false;
}

void Game::display() {
    for (int y = 0; y < GAME_HEIGHT; ++y) {
        for (int x = 0; x < GAME_WIDTH; ++x) {
            if (x == 0 && y == int(currentY)) {
                std::cout << "O";
                x++;
            }
            if (x % BAR_SPACING == nextBarX) {
                if (y < getNcenter(x / BAR_SPACING) - ySpacing || y > getNcenter(x / BAR_SPACING) + ySpacing) {
                    std::cout << "X";
                } else {
                    std::cout << " ";
                }
            } else {
                std::cout << " ";
            }
            if (x == GAME_WIDTH - 1) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "nextBarX : " << nextBarX << std::endl;
    std::cout << "speed : " << speed << std::endl;
    std::cout << "ySpacing : " << ySpacing << std::endl;
    std::cout << "currentY : " << currentY << std::endl;
    auto it = centerY.begin();

    for (int j = 0; it != centerY.end(); ++it, j++) {
        std::cout << "centerY n" << j << " : " << *it << std::endl;

    }
    std::cout << "passedBars : " << passedBars << std::endl;

}

std::vector <double> Game::getData() {
    auto it = centerY.begin();
    constexpr double MAX_SPEED = (sqrt(8*GAME_HEIGHT/GRAVITY + 1) - 1)/2;
    std::vector <double> input = {currentY/GAME_HEIGHT, speed/MAX_SPEED + .5,
                                  (double) nextBarX/BAR_SPACING, centerY.front()/GAME_HEIGHT, *(it++)/GAME_HEIGHT};
    // Y courant
    // speed courante
    // nextBarX
    // nextYcenter
    // nextNextYcenter
    return input;
}

double Game::getNcenter(int n) {
    auto it = centerY.begin();
    std::advance(it, n);
    return *it;
}

int Game::getScore() {
    return passedBars;
}

