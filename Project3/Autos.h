#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include "CarProp.h"
#include <math.h>
#include "Ampel.h"
#ifndef AUTOS
#define AUTOS
using namespace std;
class Autos
{

private:

	sf::Texture texture;

	void initTexture(Color c);
	void initSprite();
	int rndValue = rand() % 10;
	bool abbiegen;

public:
	sf::Sprite sprite;
	Autos(Direction spawn, Color color, Direction direction);
	virtual ~Autos();
	Direction currentDirection;
	Direction originalDirection;
	Ampel* ampel;
	//reaktionszeit
	sf::Clock ReZeit;
	sf::Time time1 = ReZeit.getElapsedTime();
	void initClock();
	bool reddrive;
	bool bluedrive;
	bool yellowdrive;

	const sf::Vector2f getPos() const;
	//const bool checkIfInFront() const;
	const Direction getOriginalDir() const;
	const Direction getCurrentDir() const;
	
	float speedp = 0.0005;
	float speedm = -0.0005;

	void bremsung();
	void beschleunigung();
	void resetBeschleunigung();

	

	void AntiCrash(bool checkNord, bool checkSued, bool checkOst, bool checkWest);

	void update(bool checkNord, bool checkSued, bool checkOst, bool checkWest);
	void render(sf::RenderTarget& target);
};
#endif // AUTOS