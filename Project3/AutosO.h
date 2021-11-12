#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include "CarProp.h"
#include <math.h>
using namespace std;
class AutosO
{

private:

	sf::Texture texture;

	void initTexture(Color c);
	void initSprite();
	void initFahrtweg(Direction spawn, Direction direction);
	int rndValue = rand() % 10;

public:
	sf::Sprite sprite;
	AutosO(Direction spawn, Color color, Direction direction, float reactionTime);
	virtual ~AutosO();

	//Eigenschaften vom Auto
	float reactionTime;
	float fahrtweg;
	float weg;
	float beschleunigung;
	float bremsbeschleunigung;
	float geschwindigkeit;
	float anfangsgeschwindigkeit;
	sf::Clock internalTimer;
	Direction currentDirection;
	Direction originalDirection;

	int stopNS();
	//bool const stopWO;
	const sf::Vector2f getPos() const;
	const bool checkIfInFront() const;
	const Direction getOriginalDir() const;
	const Direction getCurrentDir() const;

	
	void Kreisbewegung();
	void bremsung();
	void beschleunige();
	float rechnungszeit();
	float speedp = 0.5;
	float speedm = -0.5;
	float x = 0.005;
	float y;
	float phi;

	void update();
	void render(sf::RenderTarget& target);



};