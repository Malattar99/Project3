#pragma once
#include "AutosO.h"
#include "CarProp.h"
#include "Functions.h"
#include <math.h>
#include <iostream>
#include <time.h>
#include "GUI.h"


class SimulationKreis
{

private:

	//Übernehmen der Wk´s aus dem GUI
	int WkFahrer1;
	int WkFahrer2;
	int WkFahrer3;

public:
	SimulationKreis();
	~SimulationKreis();

	void run();

	std::vector <AutosO*> autosO;//Vektor für Autos, die vor dem Kreisverkehr sind
	std::vector <AutosO*> autosOInKV;
	std::vector <AutosO*> autosOOutKv;


	void spawnAutosNord();
	void spawnAutosWest();
	void spawnAutosOst();
	void spawnAutosSued();

	void spawnAutos();
	void deleteAutosO();
	void moveAutosInKV();
	void moveAutosbeforeKV();
	void moveAutosOutKV();
	void moveAutos();


	void checkDestination();

	void initWahrscheinlichkeiten(int WKFahrer1, int WKFahrer2, int WKFahrer3);

	void renderAutosO(sf::RenderTarget& target);

	int rndValueSpawn;
	int rndValueDirection;
	int rndValueType;

	int endCounterNorthKV;
	int endCounterEastKV;
	int endCounterSouthKV;
	int endCounterWestKV;

	int startCounterNorthKV;
	int startCounterEastKV;
	int startCounterSouthKV;
	int startCounterWestKV;



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