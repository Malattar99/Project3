#include "SimulationKreis.h"

SimulationKreis::SimulationKreis()
{

}

SimulationKreis::~SimulationKreis()
{

}

void SimulationKreis::run()
{
	this->spawnAutos();
}


void SimulationKreis::spawnAutos()
{
	rndValueSpawn = rand() % 100;
	rndValueDirection = rand() % 100;
	rndValueType = rand() % 10;

	if (rndValueSpawn <= 14)
	{

		spawnAutosNord();

	}
	else if (rndValueSpawn > 15 && rndValueSpawn <= 49)
	{

		spawnAutosOst();


	}
	else if (rndValueSpawn > 49 && rndValueSpawn <= 64)
	{

		spawnAutosWest();

	}
	else if (rndValueSpawn > 65 && rndValueSpawn <= 99)
	{

		spawnAutosSued();

	}
}

void SimulationKreis::renderAutosO(sf::RenderTarget& target)
{
	for (auto* x : this->autosO)
	{
		x->render(target);
	}
}


void SimulationKreis::spawnAutosNord()//spawn im Norden
{
	if (rndValueDirection < 10)//fahr nach Norden
	{
	}
	else if (rndValueDirection >= 10 && rndValueDirection < 50)//fahr nach Osten
	{
		if (rndValueType <= 1)
		{
			this->autosO.push_back(new AutosO(Direction::NORTH, Color::RED, Direction::EAST, 0.75));
		}
		else if (rndValueType > 1 && rndValueType <= 8)
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
		if (rndValueType <= 1)
		{
			this->autosO.push_back(new AutosO(Direction::NORTH, Color::RED, Direction::SOUTH, 0.75));
		}
		else if (rndValueType > 1 && rndValueType <= 8)
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
		if (rndValueType <= 1)
		{
			this->autosO.push_back(new AutosO(Direction::NORTH, Color::RED, Direction::WEST, 0.75));
		}
		else if (rndValueType > 1 && rndValueType <= 8)
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
	if (rndValueDirection < 10)//fahr bach Norden
	{
		if (rndValueType <= 1)
		{
			this->autosO.push_back(new AutosO(Direction::WEST, Color::RED, Direction::NORTH, 0.75));
		}
		else if (rndValueType > 1 && rndValueType <= 8)
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
		if (rndValueType <= 1)
		{
			this->autosO.push_back(new AutosO(Direction::WEST, Color::RED, Direction::EAST, 0.75));
		}
		else if (rndValueType > 1 && rndValueType <= 8)
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
		if (rndValueType <= 1)
		{
			this->autosO.push_back(new AutosO(Direction::WEST, Color::RED, Direction::SOUTH, 0.75));
		}
		else if (rndValueType > 1 && rndValueType <= 8)
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
	if (rndValueDirection < 10)//fahr bach Norden
	{
		if (rndValueType <= 1)
		{
			this->autosO.push_back(new AutosO(Direction::EAST, Color::RED, Direction::NORTH, 0.75));
		}
		else if (rndValueType > 1 && rndValueType <= 8)
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
		if (rndValueType <= 1)
		{
			this->autosO.push_back(new AutosO(Direction::EAST, Color::RED, Direction::SOUTH, 0.75));
		}
		else if (rndValueType > 1 && rndValueType <= 8)
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
		if (rndValueType <= 1)
		{
			this->autosO.push_back(new AutosO(Direction::EAST, Color::RED, Direction::WEST, 0.75));
		}
		else if (rndValueType > 1 && rndValueType <= 8)
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
	if (rndValueDirection < 10)//fahr bach Norden
	{
		if (rndValueType <= 1)
		{
			this->autosO.push_back(new AutosO(Direction::SOUTH, Color::RED, Direction::NORTH, 0.75));
		}
		else if (rndValueType > 1 && rndValueType <= 8)
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
		if (rndValueType <= 1)
		{
			this->autosO.push_back(new AutosO(Direction::SOUTH, Color::RED, Direction::EAST, 0.75));
		}
		else if (rndValueType > 1 && rndValueType <= 8)
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
		if (rndValueType <= 1)
		{
			this->autosO.push_back(new AutosO(Direction::SOUTH, Color::RED, Direction::WEST, 0.75));
		}
		else if (rndValueType > 1 && rndValueType <= 8)
		{
			this->autosO.push_back(new AutosO(Direction::SOUTH, Color::YELLOW, Direction::WEST, 1.f));
		}
		else
		{
			this->autosO.push_back(new AutosO(Direction::SOUTH, Color::BLUE, Direction::WEST, 2.f));
		}
	}
}