// ProjetRoseV2.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{

	// a = .32
	// h = 124/(n+2) (h_m = 63)

	std::cout << "Hello, World!" << std::endl;
	srand((unsigned int)time(nullptr));
	Game g;
	//    g.display();
	bool stillPlaying = true;
	g.getData();

	while (stillPlaying) {
		bool pressed = rand() % 2 == 0;
		stillPlaying = !g.step(pressed);
		if (pressed) std::cout << "KEY PRESSED ! " << std::endl;
		//        g.display();
	}

	std::vector <double> input_d = g.getData();

	std::cout << "Test the NN constructor" << std::endl;
	std::vector <int> NNstruct({ 6, 3, 1 });
	Neural n(NNstruct);
	std::cout << "Thes constructor is ok" << std::endl;
	std::cout << "Test the NN set_input" << std::endl;

	n.set_input(input_d);
	std::cout << "The set_input is ok" << std::endl;


	//    n.display();


	std::cout << "Test the NN computation and output" << std::endl;

	std::vector <double> output = n.compute_output_values();
	for (double i : output) {
		std::cout << " " << i;
	}
	std::cout << std::endl;
	std::cout << " the NN computation and output is OK" << std::endl;
	std::cout << "Test a simulation :" << std::endl;
	Simul s = Simul(n);
	int score = s.play();
	std::cout << "Score gotten = " << score << std::endl;

	std::cout << "Start testing the IA" << std::endl;
	IA ia = IA(100, { 6, 4, 1 });
	ia.evolve(50);
	return 0;
}
