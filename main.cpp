#include <iostream>
#include "Game.h"
#include "Neural.h"
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

    std::vector<double> input_d = g.getData();

    std::cout<<"Test the NN constructor"<<std::endl;
    std::vector<int> NNstruct({6,3,1});
    Neural n(NNstruct);
        std::cout<<"Thes constructor is ok"<<std::endl;
    std::cout<<"Test the NN set_input"<<std::endl;

    n.set_input(input_d); 
           std::cout<<"The set_input is ok"<<std::endl;


    n.display();

    return 0;
}