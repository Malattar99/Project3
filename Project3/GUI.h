#pragma once

#include "SFML/Graphics.hpp"
#include "TGUI/TGUI.hpp"
#include <iostream>
#include "string.h"
#include "StringConverter.h"


class GUI
{

private:

	~GUI();
	tgui::Gui gui;

	sf::Font font;
	tgui::Button::Ptr closeButton = tgui::Button::create();
	tgui::Button::Ptr startButton = tgui::Button::create();
	tgui::Button::Ptr stopButton = tgui::Button::create();
	tgui::EditBox::Ptr editBoxMinutes = tgui::EditBox::create();
	tgui::EditBox::Ptr editBoxSeconds = tgui::EditBox::create();
	tgui::Label::Ptr labeleditBox = tgui::Label::create();
	tgui::Label::Ptr colon = tgui::Label::create();
	tgui::TextBox::Ptr timeBox = tgui::TextBox::create();
	tgui::Label::Ptr warning = tgui::Label::create();
	tgui::TextBox::Ptr outcomeEast = tgui::TextBox::create();
	tgui::TextBox::Ptr outcomeWest = tgui::TextBox::create();
	tgui::TextBox::Ptr outcomeNorth = tgui::TextBox::create();
	tgui::TextBox::Ptr outcomeSouth = tgui::TextBox::create();

	tgui::TextBox::Ptr incomeEast = tgui::TextBox::create();
	tgui::TextBox::Ptr incomeWest = tgui::TextBox::create();
	tgui::TextBox::Ptr incomeNorth = tgui::TextBox::create();
	tgui::TextBox::Ptr incomeSouth = tgui::TextBox::create();
	tgui::Label::Ptr labelCounterOutcomeStart = tgui::Label::create();
	tgui::Label::Ptr labelCounterOutcomeZiel = tgui::Label::create();

	tgui::Label::Ptr Ost = tgui::Label::create();
	tgui::Label::Ptr West = tgui::Label::create();
	tgui::Label::Ptr Nord = tgui::Label::create();
	tgui::Label::Ptr Sued = tgui::Label::create();


	tgui::Label::Ptr Kreuzung = tgui::Label::create();
	//Für den Kreisverkehr
	tgui::TextBox::Ptr outcomeEastKV = tgui::TextBox::create();
	tgui::TextBox::Ptr outcomeWestKV = tgui::TextBox::create();
	tgui::TextBox::Ptr outcomeNorthKV = tgui::TextBox::create();
	tgui::TextBox::Ptr outcomeSouthKV = tgui::TextBox::create();

	tgui::TextBox::Ptr incomeEastKV = tgui::TextBox::create();
	tgui::TextBox::Ptr incomeWestKV = tgui::TextBox::create();
	tgui::TextBox::Ptr incomeNorthKV = tgui::TextBox::create();
	tgui::TextBox::Ptr incomeSouthKV = tgui::TextBox::create();
	tgui::Label::Ptr labelCounterOutcomeStartKV = tgui::Label::create();
	tgui::Label::Ptr labelCounterOutcomeZielKV = tgui::Label::create();

	tgui::Label::Ptr OstKV = tgui::Label::create();
	tgui::Label::Ptr WestKV = tgui::Label::create();
	tgui::Label::Ptr NordKV = tgui::Label::create();
	tgui::Label::Ptr SuedKV = tgui::Label::create();

	tgui::Label::Ptr Kreisverkehr = tgui::Label::create();

	std::string secondsString;
	std::string msecondsString;


public:


	GUI(sf::RenderWindow* window);

	std::string getTextFromEditBox();
	unsigned int getTimeFromEditBox();

	void initGUI(sf::RenderWindow* window);
	void initCloseButton(sf::RenderWindow* window);
	void initStartButton();
	void initStopButton();
	void initEditBoxTime();
	void initLabelEditBox();
	void loadFont();
	void initWarning();
	void initCounterOutcome();
	void initLabelCounterOutcome();
	void initCounterOutcomeKV();
	void initLabelCounterOutcomeKV();
	void initRichtungen();

	void updateCounterOutcome(int endCounterNorth, int endCounterEast, int endCounterSouth, int endCounterWest, int startCounterNorth, int startCounterEast, int startCounterSouth, int startCounterWest);
	void updateCounterOutcomeKV(int endCounterNorth, int endCounterEast, int endCounterSouth, int endCounterWest, int startCounterNorth, int startCounterEast, int startCounterSouth, int startCounterWest);

	void ClickedOnClose(sf::RenderWindow* window, sf::Event event);
	//bool ClickedOnStart(sf::Event e, bool* startIsAllowed, sf::Clock);
	//bool ClickedOnStop(sf::Event e, bool* stopIsRequired);

	void checkStopButton(bool& startIsAllowed);
	void checkStartButton(bool& startIsAllowed, sf::Clock& clock);

	void close(sf::RenderWindow* window);
	void render(sf::RenderWindow* window);

	void handleEvent(sf::Event event);

	void takeElapsedTime(unsigned int sec, unsigned int ms);

	void secondsToString(unsigned int sec);
	void msecondsToString(unsigned int ms);
	void initTimeTextBox();

	void StartStopSwitch(bool switcher);


};