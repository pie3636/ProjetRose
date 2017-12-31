#include "Game.h"
#include <cstdlib>
#include <iostream>
#include <cmath>
#include "stdafx.h"

#define GRAVITY .32

Game::Game() {
	 nextBarX = BAR_SPACING;
	 speed = 0.;
	 ySpacing = Y_SPA;
	 currentY = GAME_HEIGHT / 2.0;

	// Si graphiques, stocker pastY
	passedBars = 0;
	//std::cout << "[Game] Default ctor" << std::endl;
	centerY = std::vector<double>(5);
	centerY[0] = 30.0;
	centerY[1] = 30.0;
	centerY[2] = 30.0;
	centerY[3] = 30.0;
	centerY[4] = 30.0;
}

Game::Game(const Game &other) {
	// std::cout << "[Game] Copy ctor" << std::endl;
}

Game::~Game(){
}

Game& Game::operator=(Game rhs) {
	//std::cout << "[Game] Assignment operator" << std::endl;
		this->centerY = std::vector<double>(5);
	this->centerY = rhs.centerY;
	this->currentY = rhs.currentY;
	this->nextBarX = rhs.nextBarX;
	this->passedBars = rhs.passedBars;
	this->speed = rhs.speed;
	this->ySpacing = rhs.ySpacing;


	return *this;
}

void Game::nextBar() {
	nextBarX = BAR_SPACING;
	passedBars++;
	if (passedBars % FREQ == 0) ySpacing = ySpacing * DECR_POWER;
	for (int i = 0; i < centerY.size() - 1; i++){
		centerY[i] = centerY[i + 1];
	}
	/*double newH;
	if (passedBars % 2 == 0){
		 newH = 35.0;
	}
	else{
		 newH = 25.0;
	}*/
	double newH = 30.0 + (rand()% 10) -5; //; rand() % (63 - int(ySpacing)) + int(ySpacing);

	centerY[centerY.size() - 1] = (newH);
}

int Game::givepassedBars(){
	return passedBars;
}
bool Game::step(bool isPressed) {
	nextBarX--;
	speed += isPressed ? GRAVITY : -GRAVITY;
	//TODO : REMOVE LINE HERE
	speed = isPressed ? 0.5 : -0.5;
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

/*void Game::display() {
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

}*/

std::vector <double> Game::getData() {
	auto it = centerY.begin();
	double MAX_SPEED = (sqrt(8.0*GAME_HEIGHT / GRAVITY + 1.0) - 1) / 2.0;
	std::vector <double> input = { currentY / GAME_HEIGHT, speed / MAX_SPEED + .5,
		(double)nextBarX / BAR_SPACING, centerY.front() / GAME_HEIGHT, *(it++) / GAME_HEIGHT };
	// Y courant
	// speed courante
	// nextBarX
	// nextYcenter
	// nextNextYcenter
	return input;
}

double Game::getNcenter(int n) {
	if (n > centerY.size() - 1) return -GAME_HEIGHT;
	auto it = centerY.begin();
	std::advance(it, n);
	return *it;
}

int Game::getScore() {
	//std::cout << "PASSED BARS : " << passedBars<<std::endl;
	return passedBars;// *20 + 20 - nextBarX;
}

void Game::reset(){
	nextBarX = BAR_SPACING;
	speed = 0.;
	ySpacing = Y_SPA;
	currentY = GAME_HEIGHT / 2.0;


	centerY = std::vector<double>(5);
	centerY[0] = 30.0;
	centerY[1] = 30.0;
	centerY[2] = 30.0;
	centerY[3] = 30.0;
	centerY[4] = 30.0;	passedBars = 0;
}