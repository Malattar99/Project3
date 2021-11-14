#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include "CarProp.h"
#include <math.h>
# define M_PI 3.14159265358979323846
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
	float radius;
	sf::Clock internalTimer;
	Direction currentDirection;
	Direction originalDirection;
	Direction spawn;
	bool leave;
	bool change;


	int stopNS();
	//bool const stopWO;
	const sf::Vector2f getPos() const;
	const bool checkIfInFront() const;
	const Direction getOriginalDir() const;
	const Direction getCurrentDir() const;

	//für  die Berechnung des Fahrtweges
	float alpha;
	float x;
	float y;
	float gesamtWeg;
	float alphaBefore;


	void Kreisbewegung(Direction spawn);
	void bremsungInKV();
	void beschleunigeInKV();
	void beschleunige();
	void beschleunigeOutKv();
	void bremsung();
	float rechnungszeit();

	void checkDestination();
	void checkChangeEast();
	void checkChangeWest();
	void checkChangeNorth();
	void checkChangeSouth();
	void RotateAuto(Direction direction);
	void moveBeforeKV(Direction direction, float weg);
	void moveInKV();
	void moveOutKV(Direction direction, float weg);
	void update();
	void render(sf::RenderTarget& target);



};