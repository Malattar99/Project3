#include "Simulation.h"
#include "CarProp.h"

void Simulation::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1500, 1000), "Kreuzverkehr", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(165);
	this->window->setVerticalSyncEnabled(false);

	this->window2 = new sf::RenderWindow(sf::VideoMode(1000, 1000), "Kreisverkehr", sf::Style::Close | sf::Style::Titlebar);
	this->window2->setFramerateLimit(165);
	this->window2->setVerticalSyncEnabled(false);
}

void Simulation::initAuto()
{
	this->spawnTimerMax = 20.f;
}


void Simulation::initKreuzverkehr()
{
	if (!this->KreuzverkehrTex.loadFromFile("images/Kreuzverkehr.png"));
	{
		//std::cout << "kein hintergrund\n";
	}
	this->Kreuzverkehr.setTexture(this->KreuzverkehrTex);
}

void Simulation::initKreisverkehr()
{
	if (!this->KreisverkehrTex.loadFromFile("images/Kreisverkehr.png"));
	{
		//std::cout << "kein hintergrund\n";
	}
	this->Kreisverkehr.setTexture(this->KreisverkehrTex);
	this->Kreisverkehr.setOrigin(240.f, 240.f);
	this->Kreisverkehr.setScale(2, 2);
}

void Simulation::renderWorld()
{
	this->window->draw(this->Kreuzverkehr);
	this->window2->draw(this->Kreisverkehr);

}

void Simulation::initGUI()
{
	gui = new GUI(this->window);
}

void Simulation::initSimulationKreisverkehr()
{
	simulationKreisverkehr = new SimulationKreis;
}

void Simulation::initAmpel()
{
	ampel = new Ampel();

}

void Simulation::initCounter()
{
	endCounterNorth = 0;
	endCounterEast = 0;
	endCounterSouth = 0;
	endCounterWest = 0;

	startCounterEast = 0;
	startCounterWest = 0;
	startCounterNorth = 0;
	startCounterSouth = 0;
}

void Simulation::backToGUI() {
	this->gui->takeElapsedTime(clock.getElapsedTime().asSeconds(), clock.getElapsedTime().asMilliseconds());
}


Simulation::Simulation()
{
	this->initWindow();
	this->initAuto();
	this->initKreuzverkehr();
	this->initKreisverkehr();
	this->initGUI();
	this->initCounter();
	this->initAmpel();
	this->initSimulationKreisverkehr();
}



Simulation::~Simulation()
{
	delete this->window;
	for (auto* i : this->autos)
	{
		delete i;
	}

	delete this->window2;


	delete this->ampel;
}
//funktionen

void Simulation::run()
{
	this->ampel->startTimer();

	while (this->window->isOpen() && this->window2->isOpen())
	{
		this->update();
		this->render();

		if (startIsAllowed) {
			this->updateAfterStart();
			this->simulationKreisverkehr->run();
			if (clock.getElapsedTime().asSeconds() >= this->gui->getTimeFromEditBox()) {
				startIsAllowed = false;
			}
		}
	}
}


void Simulation::deleteAutos()
{
	for (int i = 0; i < autos.size(); i++) {
		if (autos[i]->getPos().x < 0) {
			autos.erase(autos.begin() + i);
			endCounterWest++;
		}

		else if (autos[i]->getPos().x > 1000) {
			autos.erase(autos.begin() + i);
			endCounterEast++;
		}

		else if (autos[i]->getPos().y > 1000) {
			autos.erase(autos.begin() + i);
			endCounterSouth++;
		}
		else if (autos[i]->getPos().y < 0) {
			autos.erase(autos.begin() + i);
			endCounterNorth++;
		}

	}
}




void Simulation::updateAuto()
{

	int rndValue = rand() % 10;
	//std::cout << rndValue << std::endl;
	int rndAnfahrt = rand() % 100;
	Direction spawn;
	if (rndAnfahrt < 15) {
		if (Functions::checkSpawnNorth(autos) == 0) {
			spawn = Direction::NORTH;
			//std::cout << "spawn auf nord" << std::endl;
		}
		else { spawn = Direction::NOWHERE; }
	}
	else if (rndAnfahrt < 18.5) {
		if (Functions::checkSpawnEast(autos) == 0) {
			spawn = Direction::EAST;
			//std::cout << "spawn auf ost" << std::endl;
		}
		else { spawn = Direction::NOWHERE; }
	}//wk dass auto von osten nach norden oder süden fährt = 31.5%
	else if (rndAnfahrt < 50) {
		if (Functions::checkSpawnEast(autos) == 0) {
			spawn = Direction::EAST_W;
			//std::cout << "spawn auf ost" << std::endl;
		}
		else { spawn = Direction::NOWHERE; }
	}
	else if (rndAnfahrt < 65) {
		if (Functions::checkSpawnSouth(autos) == 0) {
			spawn = Direction::SOUTH;
			//std::cout << "spawn auf sued" << std::endl;
		}
		else { spawn = Direction::NOWHERE; }
	}//wahrscheinlichkeit, dass der wagen von westen nach osten || nach süden fährt = 31.5%
	else if (rndAnfahrt < 96.5) {
		if (Functions::checkSpawnWest(autos) == 0) {
			spawn = Direction::WEST_E;
			//std::cout << "spawn auf west" << std::endl;
		}
		else { spawn = Direction::NOWHERE; }
	}
	else {
		if (Functions::checkSpawnWest(autos) == 0) {
			spawn = Direction::WEST;
			//std::cout << "spawn auf west" << std::endl;
		}
		else { spawn = Direction::NOWHERE; }
	}

	if (spawn != Direction::NOWHERE) {
		//rotes auto generieren
		if (rndValue < 2) // rotes Auto 20 %
		{
			this->autos.push_back(new Autos(spawn, Color::RED, Direction::EAST));
			//std::cout << "pushed back" << std::endl;
		}
		//Gelbes Auto generieren
		if (rndValue >= 2 && rndValue < 9) // gelbes Auto 70%
		{
			this->autos.push_back(new Autos(spawn, Color::YELLOW, Direction::WEST));
			//std::cout << "pushed back" << std::endl;
		}
		//Blaues Auto generieren
		if (rndValue == 9) // blaues Auto 10 %
		{
			this->autos.push_back(new Autos(spawn, Color::BLUE, Direction::EAST));
			//std::cout << "pushed back" << std::endl;
		}
	}
	

}


void Simulation::update()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
		{
			this->window->close();
			this->window2->close();
		}
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
		{
			this->window->close();
			this->window2->close();
		}

		this->gui->checkStartButton(startIsAllowed, clock);

		this->gui->ClickedOnClose(window, e);

		this->gui->checkStopButton(startIsAllowed);




		this->gui->handleEvent(e);
	}

	this->gui->initTimeTextBox();
	this->gui->StartStopSwitch(startIsAllowed);


	//std::cout << clock.getElapsedTime().asSeconds() << std::endl;

}


void Simulation::updateAfterStart() {
	for (auto* car : this->autos)
	{
		car->update(ampel->ampel_n_green, ampel->ampel_s_green, ampel->ampel_o_green, ampel->ampel_w_green);
		
		//std::cout << "Auto moved" << std::endl;
	}



	this->deleteAutos();

	this->backToGUI();

	this->ampel->cycleAmpel();

	this->spawnTimer++;
	//Auto bewegen
	if (this->spawnTimer % 100 == 0) {
		this->updateAuto();
		//std::cout << "updateAuto\n";
		this->simulationKreisverkehr->spawnAutos();
	}

	this->gui->updateCounterOutcome(endCounterNorth, endCounterEast, endCounterSouth, endCounterWest, startCounterNorth, startCounterEast, startCounterSouth, startCounterWest);
	this->gui->updateCounterOutcomeKV(simulationKreisverkehr->endCounterNorthKV, simulationKreisverkehr->endCounterEastKV, simulationKreisverkehr->endCounterSouthKV, simulationKreisverkehr->endCounterWestKV, simulationKreisverkehr->startCounterNorthKV, simulationKreisverkehr->startCounterEastKV, simulationKreisverkehr->startCounterSouthKV, simulationKreisverkehr->startCounterWestKV);
}

void Simulation::render() {

	this->window->clear(sf::Color(200, 200, 200));
	this->window2->clear();

	this->gui->render(this->window);

	this->renderWorld();
	this->simulationKreisverkehr->renderAutosO(*this->window2);

	for (auto* car : this->autos)
	{
		car->render(*this->window);
	}

	this->ampel->render(*this->window);

	this->window->display();
	this->window2->display();
}