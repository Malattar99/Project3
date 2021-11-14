#include "SimulationKreis.h"

void SimulationKreis::initWahrscheinlichkeiten(int WKFahrer1, int WKFahrer2, int WKFahrer3)
{
	WkFahrer1 = WKFahrer1;
	WkFahrer2 = WKFahrer2;
	WkFahrer3 = WKFahrer3;
}

SimulationKreis::SimulationKreis()
{

}

SimulationKreis::~SimulationKreis()
{

}

void SimulationKreis::run()
{
	//this->spawnAutos();
	//this->updateAutos();
	this->moveAutos();
	this->deleteAutosO();
}

void SimulationKreis::moveAutosInKV()
{
	for (int i = 0; i < autosOInKV.size(); i++)
	{
		autosOInKV[i]->checkDestination();

		if (autosOInKV[i]->leave == false)
		{
			autosOInKV[i]->beschleunigeInKV();
			autosOInKV[i]->Kreisbewegung(autosOInKV[i]->spawn);
			autosOInKV[i]->moveInKV();
		}

		else
		{
			autosOOutKv.push_back(autosOInKV[i]);
			autosOInKV.erase(autosOInKV.begin() + i);
			std::cout << autosOOutKv.size() << std::endl;
		}
	}
}

void SimulationKreis::moveAutosbeforeKV()
{
	for (int i = 0; i < autosO.size(); i++)
	{
		if (pow(autosO[i]->getPos().x - 500, 2) + pow(autosO[i]->getPos().y - 500, 2) > pow(350, 2))
		{
			autosO[i]->beschleunige();
			autosO[i]->moveBeforeKV(autosO[i]->spawn, autosO[i]->weg);
		}
		else if (autosOInKV.size() <= 2)
		{
			autosOInKV.push_back(autosO[i]);
			autosO.erase(autosO.begin() + i);
		}
	}
}

void SimulationKreis::moveAutosOutKV()
{
	for (int i = 0; i < autosOOutKv.size(); i++)
	{
		//autosOOutKv[i]->internalTimer.restart();
		autosOOutKv[i]->RotateAuto(autosOOutKv[i]->originalDirection);
		autosOOutKv[i]->beschleunigeOutKv();
		autosOOutKv[i]->moveOutKV(autosOOutKv[i]->originalDirection, autosOOutKv[i]->weg);
	}
}
void SimulationKreis::moveAutos()
{
	this->moveAutosbeforeKV();
	this->moveAutosInKV();
	this->moveAutosOutKV();
}

void SimulationKreis::spawnAutos()
{
	while (autosO.size() <= 3)
	{
		rndValueSpawn = rand() % 100;
		rndValueDirection = rand() % 100;
		rndValueType = rand() % 100;

		if (rndValueSpawn <= 14 && !Functions::checkSpawnNorth1(autosO))
		{

			spawnAutosNord();

		}
		else if (rndValueSpawn > 15 && rndValueSpawn <= 49 && !Functions::checkSpawnEast1(autosO))
		{

			spawnAutosOst();


		}
		else if (rndValueSpawn > 49 && rndValueSpawn <= 64 && !Functions::checkSpawnWest1(autosO))
		{

			spawnAutosWest();

		}
		else if (rndValueSpawn > 65 && rndValueSpawn <= 99 && !Functions::checkSpawnSouth1(autosO))
		{

			spawnAutosSued();

		}
		else
			break;
	}

}

void SimulationKreis::renderAutosO(sf::RenderTarget& target)
{
	for (auto* x : this->autosO)
	{
		x->render(target);
	}
	for (auto* x : this->autosOInKV)
	{
		x->render(target);
	}
	for (auto* x : this->autosOOutKv)
	{
		x->render(target);
	}
}


void SimulationKreis::spawnAutosNord()//spawn im Norden
{

	startCounterNorthKV++;
	if (rndValueDirection < 10)//fahr nach Norden
	{
	}
	else if (rndValueDirection >= 10 && rndValueDirection < 50)//fahr nach Osten
	{
		if (rndValueType <= WkFahrer1)
		{
			this->autosO.push_back(new AutosO(Direction::NORTH, Color::RED, Direction::EAST, 0.75));
		}
		else if (rndValueType > WkFahrer1 && rndValueType <= WkFahrer1 + WkFahrer2)
		{
			this->autosO.push_back(new AutosO(Direction::NORTH, Color::YELLOW, Direction::EAST, 1.f));
		}
		else
		{
			this->autosO.push_back(new AutosO(Direction::NORTH, Color::BLUE, Direction::EAST, 2.f));
		}

	}
	else if (rndValueDirection >= 50 && rndValueDirection < 60)//Fahr nach Sueden
	{
		if (rndValueType <= WkFahrer1)
		{
			this->autosO.push_back(new AutosO(Direction::NORTH, Color::RED, Direction::SOUTH, 0.75));
		}
		else if (rndValueType > WkFahrer1 && rndValueType <= WkFahrer1 + WkFahrer2)
		{
			this->autosO.push_back(new AutosO(Direction::NORTH, Color::YELLOW, Direction::SOUTH, 1.f));
		}
		else
		{
			this->autosO.push_back(new AutosO(Direction::NORTH, Color::BLUE, Direction::SOUTH, 2.f));
		}

	}
	else //Fahr nach Westen
	{
		if (rndValueType <= WkFahrer1)
		{
			this->autosO.push_back(new AutosO(Direction::NORTH, Color::RED, Direction::WEST, 0.75));
		}
		else if (rndValueType > WkFahrer1 && rndValueType <= WkFahrer1 + WkFahrer2)
		{
			this->autosO.push_back(new AutosO(Direction::NORTH, Color::YELLOW, Direction::WEST, 1.f));
		}
		else
		{
			this->autosO.push_back(new AutosO(Direction::NORTH, Color::BLUE, Direction::WEST, 2.f));
		}
	}
}

void SimulationKreis::spawnAutosWest()
{
	startCounterWestKV++;
	if (rndValueDirection < 10)//fahr bach Norden
	{
		if (rndValueType <= WkFahrer1)
		{
			this->autosO.push_back(new AutosO(Direction::WEST, Color::RED, Direction::NORTH, 0.75));
		}
		else if (rndValueType > WkFahrer1 && rndValueType <= WkFahrer1 + WkFahrer2)
		{
			this->autosO.push_back(new AutosO(Direction::WEST, Color::YELLOW, Direction::NORTH, 1.f));
		}
		else
		{
			this->autosO.push_back(new AutosO(Direction::WEST, Color::BLUE, Direction::NORTH, 2.f));
		}
	}
	else if (rndValueDirection >= 10 && rndValueDirection < 50)//fahr nach Osten
	{
		if (rndValueType <= WkFahrer1)
		{
			this->autosO.push_back(new AutosO(Direction::WEST, Color::RED, Direction::EAST, 0.75));
		}
		else if (rndValueType > WkFahrer1 && rndValueType <= WkFahrer1 + WkFahrer2)
		{
			this->autosO.push_back(new AutosO(Direction::WEST, Color::YELLOW, Direction::EAST, 1.f));
		}
		else
		{
			this->autosO.push_back(new AutosO(Direction::WEST, Color::BLUE, Direction::EAST, 2.f));
		}
	}
	else if (rndValueDirection >= 50 && rndValueDirection < 60)//Fahr nach Sueden
	{
		if (rndValueType <= WkFahrer1)
		{
			this->autosO.push_back(new AutosO(Direction::WEST, Color::RED, Direction::SOUTH, 0.75));
		}
		else if (rndValueType > WkFahrer1 && rndValueType <= WkFahrer1 + WkFahrer2)
		{
			this->autosO.push_back(new AutosO(Direction::WEST, Color::YELLOW, Direction::SOUTH, 1.f));
		}
		else
		{
			this->autosO.push_back(new AutosO(Direction::WEST, Color::BLUE, Direction::SOUTH, 2.f));
		}

	}
	else //Fahr nach Westen
	{
		//geht nicht
	}
}

void SimulationKreis::spawnAutosOst()
{
	startCounterEastKV++;
	if (rndValueDirection < 10)//fahr bach Norden
	{
		if (rndValueType <= WkFahrer1)
		{
			this->autosO.push_back(new AutosO(Direction::EAST, Color::RED, Direction::NORTH, 0.75));
		}
		else if (rndValueType > WkFahrer1 && rndValueType <= WkFahrer1 + WkFahrer2)
		{
			this->autosO.push_back(new AutosO(Direction::EAST, Color::YELLOW, Direction::NORTH, 1.f));
		}
		else
		{
			this->autosO.push_back(new AutosO(Direction::EAST, Color::BLUE, Direction::NORTH, 2.f));
		}
	}


	else if (rndValueDirection >= 10 && rndValueDirection < 50)//fahr nach Osten
	{
		//geht nicht
	}


	else if (rndValueDirection >= 50 && rndValueDirection < 60)//Fahr nach Sueden
	{
		if (rndValueType <= WkFahrer1)
		{
			this->autosO.push_back(new AutosO(Direction::EAST, Color::RED, Direction::SOUTH, 0.75));
		}
		else if (rndValueType > WkFahrer1 && rndValueType <= WkFahrer1 + WkFahrer2)
		{
			this->autosO.push_back(new AutosO(Direction::EAST, Color::YELLOW, Direction::SOUTH, 1.f));
		}
		else
		{
			this->autosO.push_back(new AutosO(Direction::EAST, Color::BLUE, Direction::SOUTH, 2.f));
		}

	}


	else //Fahr nach Westen
	{
		if (rndValueType <= WkFahrer1)
		{
			this->autosO.push_back(new AutosO(Direction::EAST, Color::RED, Direction::WEST, 0.75));
		}
		else if (rndValueType > WkFahrer1 && rndValueType <= WkFahrer1 + WkFahrer2)
		{
			this->autosO.push_back(new AutosO(Direction::EAST, Color::YELLOW, Direction::WEST, 1.f));
		}
		else
		{
			this->autosO.push_back(new AutosO(Direction::EAST, Color::BLUE, Direction::WEST, 2.f));
		}

	}
}

void SimulationKreis::spawnAutosSued()
{
	startCounterSouthKV++;
	if (rndValueDirection < 10)//fahr bach Norden
	{
		if (rndValueType <= WkFahrer1)
		{
			this->autosO.push_back(new AutosO(Direction::SOUTH, Color::RED, Direction::NORTH, 0.75));
		}
		else if (rndValueType > WkFahrer1 && rndValueType <= WkFahrer1 + WkFahrer2)
		{
			this->autosO.push_back(new AutosO(Direction::SOUTH, Color::YELLOW, Direction::NORTH, 1.f));
		}
		else
		{
			this->autosO.push_back(new AutosO(Direction::SOUTH, Color::BLUE, Direction::NORTH, 2.f));
		}
	}
	else if (rndValueDirection >= 10 && rndValueDirection < 50)//fahr nach Osten
	{
		if (rndValueType <= WkFahrer1)
		{
			this->autosO.push_back(new AutosO(Direction::SOUTH, Color::RED, Direction::EAST, 0.75));
		}
		else if (rndValueType > WkFahrer1 && rndValueType <= WkFahrer1 + WkFahrer2)
		{
			this->autosO.push_back(new AutosO(Direction::SOUTH, Color::YELLOW, Direction::EAST, 1.f));
		}
		else
		{
			this->autosO.push_back(new AutosO(Direction::SOUTH, Color::BLUE, Direction::EAST, 2.f));
		}
	}
	else if (rndValueDirection >= 50 && rndValueDirection < 60)//Fahr nach Sueden
	{
		//geht nicht
	}
	else //Fahr nach Westen
	{
		if (rndValueType <= WkFahrer1)
		{
			this->autosO.push_back(new AutosO(Direction::SOUTH, Color::RED, Direction::WEST, 0.75));
		}
		else if (rndValueType > WkFahrer1 && rndValueType <= WkFahrer1 + WkFahrer2)
		{
			this->autosO.push_back(new AutosO(Direction::SOUTH, Color::YELLOW, Direction::WEST, 1.f));
		}
		else
		{
			this->autosO.push_back(new AutosO(Direction::SOUTH, Color::BLUE, Direction::WEST, 2.f));
		}
	}
}

void SimulationKreis::deleteAutosO()
{
	for (int i = 0; i < autosOOutKv.size(); i++) {
		if (autosOOutKv[i]->getPos().x < 0) {
			autosOOutKv.erase(autosOOutKv.begin() + i);
			endCounterWestKV++;
			//std::cout << endCounterWestKV << std::endl;
		}

		else if (autosOOutKv[i]->getPos().x > 1000) {
			autosOOutKv.erase(autosOOutKv.begin() + i);
			endCounterEastKV++;
		}

		else if (autosOOutKv[i]->getPos().y > 1000) {
			autosOOutKv.erase(autosOOutKv.begin() + i);
			endCounterSouthKV++;
		}
		else if (autosOOutKv[i]->getPos().y < 0) {
			autosOOutKv.erase(autosOOutKv.begin() + i);
			endCounterNorthKV++;
		}

	}
}