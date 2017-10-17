#include <iostream>
#include "Game.h"
// a = .32
// h = 124/(n+2) (h_m = 63)

int main() {
	std::cout << "Hello, World!" << std::endl;
	srand(time(NULL));
    Game g;
    bool stillPlaying = true;
        g.getData();

    while(stillPlaying){
bool pressed = rand()%2 == 0;
    	stillPlaying = !g.step(pressed);
    	if(pressed) std::cout<<"KEY PRESSED ! "<<std::endl;
    	g.display();
    }



    return 0;
}