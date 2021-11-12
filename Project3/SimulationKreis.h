#pragma once
#include "AutosO.h"
#include "CarProp.h"
#include "Functions.h"
#include <math.h>
#include <iostream>
#include <time.h>


class SimulationKreis
{
public:
	SimulationKreis();
	~SimulationKreis();

	void run();

	std::vector <AutosO*> autosO;

	void spawnAutosNord();
	void spawnAutosWest();
	void spawnAutosOst();
	void spawnAutosSued();

	void spawnAutos();

	void moveAutos();

	void renderAutosO(sf::RenderTarget& target);

	int rndValueSpawn;
	int rndValueDirection;
	int rndValueType;


};


/*void Simulation::deleteAutosO()
{
	for (int i = 0; i < autoso.size(); i++) {
		if (autoso[i]->getPos().x < 0) {
			autoso.erase(autoso.begin() + i);
			endCounterWestKV++;
			std::cout << endCounterWestKV << std::endl;
		}
		else if (autoso[i]->getPos().x > 1000) {
			autoso.erase(autoso.begin() + i);
			endCounterEastKV++;
		}
		else if (autoso[i]->getPos().y > 1000) {
			autoso.erase(autoso.begin() + i);
			endCounterSouthKV++;
		}
		else if (autoso[i]->getPos().y < 0) {
			autoso.erase(autoso.begin() + i);
			endCounterNorthKV++;
		}
	}
}
for (auto* i : this->autoso)
	{
		delete i;
	}
*/