#include "GUI.h"


GUI::~GUI()
{
}

GUI::GUI(sf::RenderWindow* window) {

	this->initGUI(window);
	gui.add(closeButton);
	gui.add(stopButton);
	gui.add(startButton);
	gui.add(labeleditBox);
	gui.add(editBoxMinutes);
	gui.add(editBoxSeconds);
	gui.add(colon);
	gui.add(warning);

	gui.add(outcomeEast); std::cout << "incomeEast added" << std::endl;
	gui.add(outcomeNorth);
	gui.add(outcomeSouth);
	gui.add(outcomeWest);

	gui.add(incomeEast); std::cout << "incomeEast added" << std::endl;
	gui.add(incomeNorth);
	gui.add(incomeSouth);
	gui.add(incomeWest);

	gui.add(Ost);
	gui.add(West);
	gui.add(Sued);
	gui.add(Nord);

	gui.add(Kreuzung);

	//Kreisverkehr
	gui.add(outcomeEastKV); std::cout << "incomeEast added" << std::endl;
	gui.add(outcomeNorthKV);
	gui.add(outcomeSouthKV);
	gui.add(outcomeWestKV);

	gui.add(incomeEastKV); std::cout << "incomeEast added" << std::endl;
	gui.add(incomeNorthKV);
	gui.add(incomeSouthKV);
	gui.add(incomeWestKV);

	gui.add(OstKV);
	gui.add(WestKV);
	gui.add(SuedKV);
	gui.add(NordKV);

	gui.add(Kreisverkehr);

	gui.add(labelCounterOutcomeStart);
	gui.add(labelCounterOutcomeZiel);

	gui.add(labelCounterOutcomeStartKV);
	gui.add(labelCounterOutcomeZielKV);
}

void GUI::initGUI(sf::RenderWindow* window) {
	gui.setTarget(*window);
	this->loadFont();
	this->initCloseButton(window);
	this->initStartButton();
	this->initStopButton();
	this->initLabelEditBox();
	this->initEditBoxTime();//Für die Eingabe der Zeit
	this->initWarning();
	this->initCounterOutcome();
	this->initLabelCounterOutcome();
	this->initCounterOutcomeKV();
	this->initLabelCounterOutcomeKV();
	this->initRichtungen();
}


std::string GUI::getTextFromEditBox() {
	return this->editBoxMinutes->getText();
	return this->editBoxSeconds->getText();
}

unsigned int GUI::getTimeFromEditBox() {
	//std::cout << StringConverter::toInt(editBoxMinutes->getText()) * 60  << std::endl;
	if (editBoxMinutes->getText().getSize() == 0) {
		return StringConverter::toInt(editBoxSeconds->getText());
	}
	else if (editBoxSeconds->getText().getSize() == 0) {
		return StringConverter::toInt(editBoxMinutes->getText()) * 60;
	}

	else
		return (StringConverter::toInt(editBoxMinutes->getText()) * 60 + StringConverter::toInt(editBoxSeconds->getText()));

}

void GUI::handleEvent(sf::Event event)
{
	gui.handleEvent(event);
}



void GUI::initCloseButton(sf::RenderWindow* window)
{

	closeButton->setPosition(1350.f, 920.f);
	closeButton->setSize(100.f, 50.f);
	closeButton->setText("Close");
	closeButton->getRenderer()->setFont(font);
	closeButton->setTextSize(20.f);
}

void GUI::initStartButton()
{

	startButton->setPosition(1200.f, 920.f);
	startButton->setSize(100.f, 50.f);
	startButton->setText("Start");
	startButton->getRenderer()->setFont(font);
	startButton->setTextSize(20.f);
	startButton->setVisible(true);
	startButton->setEnabled(true);

}

void GUI::checkStartButton(bool& startIsAllowed, sf::Clock& clock)
{
	startButton->connect("pressed", [&]() {if (this->editBoxMinutes->getText().getSize() != 0 || this->editBoxSeconds->getText().getSize() != 0) {
		startIsAllowed = true;
		//std::cout << "clicked on start" << std::endl;
		this->warning->setVisible(false);
		clock.restart();
	}
	else {
		this->warning->setVisible(true);
	} });
}

void GUI::initStopButton()
{

	stopButton->setPosition(1100.f, 920.f);
	stopButton->setSize(100.f, 50.f);
	stopButton->setText("Stopp");
	stopButton->getRenderer()->setFont(font);
	stopButton->setTextSize(20.f);
	stopButton->setVisible(false);
	stopButton->setEnabled(false);

}


void GUI::checkStopButton(bool& startIsAllowed)
{
	stopButton->connect("pressed", [&]() {startIsAllowed = false; });
}

void GUI::initEditBoxTime()
{
	editBoxMinutes->setSize(60.f, 40.f);
	editBoxMinutes->setPosition(1050.f, 720.f);
	editBoxMinutes->setTextSize(18);
	editBoxMinutes->setDefaultText("Min.");
	editBoxMinutes->setMaximumCharacters(1);
	editBoxMinutes->setInputValidator("[1-9]*");

	editBoxSeconds->setSize(60.f, 40.f);
	editBoxSeconds->setPosition(1115.f, 720.f);
	editBoxSeconds->setTextSize(18);
	editBoxSeconds->setDefaultText("Sek.");
	editBoxSeconds->setMaximumCharacters(2);
	editBoxSeconds->setInputValidator("[1-9]*");


}

void GUI::initLabelEditBox() {
	labeleditBox->setPosition(1050.f, 700.f);
	labeleditBox->setSize(190.f, 50.f);
	labeleditBox->setText("Simulationsdauer eingeben: ");
	labeleditBox->getRenderer()->setFont(font);
	labeleditBox->setTextSize(12.f);

	colon->setPosition(1104.f, 715.f);
	colon->setSize(20.f, 40.f);
	colon->setText(":");
	colon->getRenderer()->setFont(font);
	colon->setTextSize(35);

}

void GUI::initTimeTextBox()//Für die Ausgabe der abgelaufenen Zeit
{
	timeBox->setSize(120.f, 40.f);
	timeBox->setPosition(1300.f, 720.f);
	timeBox->setDefaultText("0.0");
	timeBox->setText(secondsString + " sec");
	timeBox->getRenderer()->setFont(font);
	timeBox->setTextSize(18);
	timeBox->setReadOnly(true);
	gui.add(timeBox);
}

void GUI::initWarning() {
	this->warning->setSize(250.f, 50.f);
	this->warning->setPosition(1150.f, 900.f);
	this->warning->setText("Bitte Simulationsdauer eingeben");
	this->warning->getRenderer()->setFont(font);
	this->warning->setVisible(false);
}

void GUI::initCounterOutcome() {
	outcomeEast->setSize(50.f, 40.f);
	outcomeEast->setPosition(1360.f, 150.f);
	outcomeEast->getRenderer()->setFont(font);
	outcomeEast->setReadOnly(true);

	outcomeWest->setSize(50.f, 40.f);
	outcomeWest->setPosition(1360.f, 200.f);
	outcomeWest->getRenderer()->setFont(font);
	outcomeWest->setReadOnly(true);

	outcomeSouth->setSize(50.f, 40.f);
	outcomeSouth->setPosition(1360.f, 250.f);
	outcomeSouth->getRenderer()->setFont(font);
	outcomeSouth->setReadOnly(true);

	outcomeNorth->setSize(50.f, 40.f);
	outcomeNorth->setPosition(1360.f, 300.f);
	outcomeNorth->getRenderer()->setFont(font);
	outcomeNorth->setReadOnly(true);



	incomeEast->setSize(50.f, 40.f);
	incomeEast->setPosition(1300.f, 150.f);
	incomeEast->getRenderer()->setFont(font);
	incomeEast->setReadOnly(true);

	incomeWest->setSize(50.f, 40.f);
	incomeWest->setPosition(1300.f, 200.f);
	incomeWest->getRenderer()->setFont(font);
	incomeWest->setReadOnly(true);

	incomeSouth->setSize(50.f, 40.f);
	incomeSouth->setPosition(1300.f, 250.f);
	incomeSouth->getRenderer()->setFont(font);
	incomeSouth->setReadOnly(true);

	incomeNorth->setSize(50.f, 40.f);
	incomeNorth->setPosition(1300.f, 300.f);
	incomeNorth->getRenderer()->setFont(font);
	incomeNorth->setReadOnly(true);
}

void GUI::initLabelCounterOutcome() {
	labelCounterOutcomeStart->setSize(75.f, 30.f);
	labelCounterOutcomeStart->setPosition(1300.f, 100.f);
	labelCounterOutcomeStart->setText("Start");
	labelCounterOutcomeStart->getRenderer()->setFont(font);
	labelCounterOutcomeStart->setTextSize(20);

	labelCounterOutcomeZiel->setSize(75.f, 30.f);
	labelCounterOutcomeZiel->setPosition(1360.f, 100.f);
	labelCounterOutcomeZiel->setText("Ziel");
	labelCounterOutcomeZiel->getRenderer()->setFont(font);
	labelCounterOutcomeZiel->setTextSize(20);

	Kreuzung->setSize(150.f, 40.f);
	Kreuzung->setPosition(1310.f, 50.f);
	Kreuzung->setText("Kreuzung");
	Kreuzung->getRenderer()->setFont(font);
	Kreuzung->setTextSize(20);
}

void GUI::initCounterOutcomeKV()
{
	outcomeEastKV->setSize(50.f, 40.f);
	outcomeEastKV->setPosition(1110.f, 150.f);
	outcomeEastKV->getRenderer()->setFont(font);
	outcomeEastKV->setReadOnly(true);

	outcomeWestKV->setSize(50.f, 40.f);
	outcomeWestKV->setPosition(1110.f, 200.f);
	outcomeWestKV->getRenderer()->setFont(font);
	outcomeWestKV->setReadOnly(true);

	outcomeSouthKV->setSize(50.f, 40.f);
	outcomeSouthKV->setPosition(1110.f, 250.f);
	outcomeSouthKV->getRenderer()->setFont(font);
	outcomeSouthKV->setReadOnly(true);

	outcomeNorthKV->setSize(50.f, 40.f);
	outcomeNorthKV->setPosition(1110.f, 300.f);
	outcomeNorthKV->getRenderer()->setFont(font);
	outcomeNorthKV->setReadOnly(true);



	incomeEastKV->setSize(50.f, 40.f);
	incomeEastKV->setPosition(1050.f, 150.f);
	incomeEastKV->getRenderer()->setFont(font);
	incomeEastKV->setReadOnly(true);

	incomeWestKV->setSize(50.f, 40.f);
	incomeWestKV->setPosition(1050.f, 200.f);
	incomeWestKV->getRenderer()->setFont(font);
	incomeWestKV->setReadOnly(true);

	incomeSouthKV->setSize(50.f, 40.f);
	incomeSouthKV->setPosition(1050.f, 250.f);
	incomeSouthKV->getRenderer()->setFont(font);
	incomeSouthKV->setReadOnly(true);

	incomeNorthKV->setSize(50.f, 40.f);
	incomeNorthKV->setPosition(1050.f, 300.f);
	incomeNorthKV->getRenderer()->setFont(font);
	incomeNorthKV->setReadOnly(true);
}

void GUI::initLabelCounterOutcomeKV()
{
	labelCounterOutcomeStartKV->setSize(75.f, 30.f);
	labelCounterOutcomeStartKV->setPosition(1050.f, 100.f);
	labelCounterOutcomeStartKV->setText("Start");
	labelCounterOutcomeStartKV->getRenderer()->setFont(font);
	labelCounterOutcomeStartKV->setTextSize(20);

	labelCounterOutcomeZielKV->setSize(75.f, 30.f);
	labelCounterOutcomeZielKV->setPosition(1110.f, 100.f);
	labelCounterOutcomeZielKV->setText("Ziel");
	labelCounterOutcomeZielKV->getRenderer()->setFont(font);
	labelCounterOutcomeZielKV->setTextSize(20);

	Kreisverkehr->setSize(150.f, 40.f);
	Kreisverkehr->setPosition(1050.f, 50.f);
	Kreisverkehr->setText("Kreisverkehr");
	Kreisverkehr->getRenderer()->setFont(font);
	Kreisverkehr->setTextSize(20);
}


void GUI::initRichtungen()
{
	Ost->setText("Ost");
	Ost->setSize(60.f, 40.f);
	Ost->getRenderer()->setFont(font);
	Ost->setTextSize(18);
	Ost->setPosition(1220.f, 150.f);

	West->setText("West");
	West->setSize(60.f, 40.f);
	West->getRenderer()->setFont(font);
	West->setTextSize(18);
	West->setPosition(1220.f, 200.f);

	Sued->setText("Sued");
	Sued->setSize(60.f, 40.f);
	Sued->getRenderer()->setFont(font);
	Sued->setTextSize(18);
	Sued->setPosition(1220.f, 250.f);

	Nord->setText("Nord");
	Nord->setSize(60.f, 40.f);
	Nord->getRenderer()->setFont(font);
	Nord->setTextSize(18);
	Nord->setPosition(1220.f, 300.f);

	//Kreisverkehr
	OstKV->setText("Ost");
	OstKV->setSize(60.f, 40.f);
	OstKV->getRenderer()->setFont(font);
	OstKV->setTextSize(18);
	OstKV->setPosition(1000.f, 150.f);

	WestKV->setText("West");
	WestKV->setSize(60.f, 40.f);
	WestKV->getRenderer()->setFont(font);
	WestKV->setTextSize(18);
	WestKV->setPosition(1000.f, 200.f);

	SuedKV->setText("Sued");
	SuedKV->setSize(60.f, 40.f);
	SuedKV->getRenderer()->setFont(font);
	SuedKV->setTextSize(18);
	SuedKV->setPosition(1000.f, 250.f);

	NordKV->setText("Nord");
	NordKV->setSize(60.f, 40.f);
	NordKV->getRenderer()->setFont(font);
	NordKV->setTextSize(18);
	NordKV->setPosition(1000.f, 300.f);
}


void GUI::updateCounterOutcome(int endCounterNorth, int endCounterEast, int endCounterSouth, int endCounterWest, int startCounterNorth, int startCounterEast, int startCounterSouth, int startCounterWest) {
	outcomeEast->setText(StringConverter::toString(endCounterEast));
	outcomeWest->setText(StringConverter::toString(endCounterWest));
	outcomeSouth->setText(StringConverter::toString(endCounterSouth));
	outcomeNorth->setText(StringConverter::toString(endCounterNorth));

	incomeEast->setText(StringConverter::toString(startCounterEast));
	incomeWest->setText(StringConverter::toString(startCounterWest));
	incomeSouth->setText(StringConverter::toString(startCounterSouth));
	incomeNorth->setText(StringConverter::toString(startCounterNorth));
}

void GUI::updateCounterOutcomeKV(int endCounterNorth, int endCounterEast, int endCounterSouth, int endCounterWest, int startCounterNorth, int startCounterEast, int startCounterSouth, int startCounterWest)
{
	outcomeEastKV->setText(StringConverter::toString(endCounterEast));
	outcomeWestKV->setText(StringConverter::toString(endCounterWest));
	outcomeSouthKV->setText(StringConverter::toString(endCounterSouth));
	outcomeNorthKV->setText(StringConverter::toString(endCounterNorth));

	incomeEastKV->setText(StringConverter::toString(startCounterEast));
	incomeWestKV->setText(StringConverter::toString(startCounterWest));
	incomeSouthKV->setText(StringConverter::toString(startCounterSouth));
	incomeNorthKV->setText(StringConverter::toString(startCounterNorth));
}

void GUI::loadFont()
{
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "font konnte nicht geladen werde!" << std::endl;
	}
}

void GUI::ClickedOnClose(sf::RenderWindow* window, sf::Event event) {

	if (this->closeButton->mouseOnWidget(tgui::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
		this->close(window);
	}
}


/*bool GUI::ClickedOnStart(sf::Event event, bool* startIsAllowed, sf::Clock clock)
{
	if (this->startButton->mouseOnWidget(tgui::Vector2f(event.mouseButton.x, event.mouseButton.y)) || event.key.code == sf::Keyboard::Enter) {
		if (this->editBoxMinutes->getText().getSize() != 0 || this->editBoxSeconds->getText().getSize() != 0) {
			*startIsAllowed = true;
			std::cout << "clicked on start" << std::endl;
			this->warning->setVisible(false);
			clock.restart();
			return *startIsAllowed;
		}
		else {
			this->warning->setVisible(true);
		}
	}
}*/


/*bool GUI::ClickedOnStop(sf::Event event, bool* startIsAllowed)
{
	if (this->stopButton->mouseOnWidget(tgui::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
		*startIsAllowed = false;
		return *startIsAllowed;
	}
	}
	*/

void GUI::close(sf::RenderWindow* window) {
	window->close();
}

void GUI::render(sf::RenderWindow* window)
{
	gui.draw();
}


void GUI::takeElapsedTime(unsigned int sec, unsigned int ms)
{
	this->secondsToString(sec);
	this->msecondsToString(ms);
}



void GUI::secondsToString(unsigned int sec)
{
	secondsString = StringConverter::toString(sec);
}


void GUI::msecondsToString(unsigned int ms)
{
	msecondsString = StringConverter::toString(ms);
}


void GUI::StartStopSwitch(bool switcher) {
	if (switcher) {
		this->stopButton->setEnabled(true);
		this->stopButton->setVisible(true);
		this->startButton->setEnabled(false);
		this->startButton->setVisible(false);
	}
	else {
		this->startButton->setEnabled(true);
		this->startButton->setVisible(true);
		this->stopButton->setEnabled(false);
		this->stopButton->setVisible(false);
	}

}
