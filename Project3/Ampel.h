#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include "CarProp.h"



class Ampel
{



public:
	Ampel();



	sf::Sprite spriteSued;
	sf::Sprite spriteNord;
	sf::Sprite spriteOst;
	sf::Sprite spriteWest;
	sf::Texture textureSued;
	sf::Texture textureNord;
	sf::Texture textureWest;
	sf::Texture textureOst;

	void initScale();

	virtual ~Ampel();

	void initAmpelSued(Ampel_Farbe color);
	void initAmpelNord(Ampel_Farbe color);
	void initAmpelOst(Ampel_Farbe color);
	void initAmpelWest(Ampel_Farbe color);

	void cycleAmpel();

	bool ampel_n_green;
	bool ampel_o_green;
	bool ampel_s_green;
	bool ampel_w_green;
	

	//zeit funktion, clock zählt sekunden auf
	sf::Clock timer;
	bool cycle;
	void startTimer();

	bool ampel_green_oben_unten;
	bool ampel_green_rechts_links;
	bool Ampel_GreenOben_Unten();
	bool Ampel_GreenRechts_Links();


	void render(sf::RenderTarget& target);

};