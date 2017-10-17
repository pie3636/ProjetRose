#include "Game.h"
#include <stdlib.h>
#include <iostream>

        void Game::nextBar() {
            nextBarX = BAR_SPACING;
            passedBars++;
            if(passedBars% FREQ ==0) yspaceing = yspaceing*DECR_POWER;
            centerY.pop_front();

 		double newH = rand() % 63 -2*int(yspaceing);

            centerY.push_back(newH);
        }

        bool Game::step(bool isPressed) {
            nextBarX--;
            speed += isPressed ? .32 : -.32;
            currentY += speed;
            if (currentY < 0 || currentY > GAME_HEIGHT) {
                return true;
            }
            if (nextBarX == 0) {
            	if (currentY < centerY.front() -  yspaceing|| currentY > centerY.front() + yspaceing) {
                	return true;
            	}
                nextBar();
            }
            return false;
        }

	void Game::display(){

	    std::cout << "nextBarX : " << nextBarX<< std::endl;
	    std::cout << "speed : " << speed<< std::endl;
	    std::cout << "yspaceing : " << yspaceing<< std::endl;
	    std::cout << "currentY : " << currentY<< std::endl;
	    std::list<double>::iterator it = centerY.begin();

	    for(int j = 0 ;it != centerY.end();++it, j++){
	    	std::cout << "centerY n" << j <<" : "<<*it<< std::endl;

	    }
	    std::cout << "passedBars : " << passedBars<< std::endl;

	}

	std::list<double> Game::getData() {
		std::list<double>::iterator it = centerY.begin();
    		
		std::list<double> input = {currentY, speed, double(nextBarX), centerY.front()};//, it++};
            // Y courant
            // speed courante
            // nextBarX
            // nextYcenter
            // nextNextYcenter
            return input;
        }