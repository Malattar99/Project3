#include "Simulation.h"
#include "Ampel.h"
#include<time.h>

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	Simulation simulation;

	simulation.run();

	return 0;
}