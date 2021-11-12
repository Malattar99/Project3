#include "AutosO.h"
#include "CarProp.h"
#include <math.h>
#include <cmath>
void AutosO::initTexture(Color c)
{
    switch (c) {
    case Color::BLUE: this->texture.loadFromFile("images/BlueCar.png"); break;
    case Color::YELLOW: this->texture.loadFromFile("images/YellowCar.png"); break;
    case Color::RED: this->texture.loadFromFile("images/RedCar.png"); break;
    }
}

void AutosO::initSprite()
{
    this->sprite.setTexture(this->texture);
    //sprite skalieren
    this->sprite.scale(0.075f, 0.075f);
    this->sprite.setOrigin(320, 640);
}

void AutosO::initFahrtweg(Direction spawn, Direction direction) {
    if (spawn == Direction::WEST && direction == Direction::SOUTH || spawn == Direction::SOUTH && direction == Direction::EAST || spawn == Direction::EAST && direction == Direction::NORTH || spawn == Direction::NORTH && direction == Direction::WEST)
    {
        fahrtweg = 0.5 * 3.14159 * 12.5;
    }
    else if (spawn == Direction::WEST && direction == Direction::EAST || spawn == Direction::SOUTH && direction == Direction::NORTH || spawn == Direction::EAST && direction == Direction::WEST || spawn == Direction::NORTH && direction == Direction::SOUTH)
    {
        fahrtweg = 3.14159 * 12.5;
    }
    else if (spawn == Direction::WEST && direction == Direction::NORTH || spawn == Direction::SOUTH && direction == Direction::WEST || spawn == Direction::EAST && direction == Direction::SOUTH || spawn == Direction::NORTH && direction == Direction::EAST)
    {
        fahrtweg = 1.5 * 3.14159 * 12.5;
    }
}

void AutosO::beschleunige()
{
    geschwindigkeit = beschleunigung * rechnungszeit() + anfangsgeschwindigkeit;
    weg = 0.5 * beschleunigung * pow(rechnungszeit(), 2) + anfangsgeschwindigkeit * rechnungszeit();
}

float AutosO::rechnungszeit()
{
    return this->internalTimer.getElapsedTime().asSeconds();
}

void AutosO::Kreisbewegung()
{
    x = x + 0.005;
    if (x >= 25)
    {
        x = 25;
    }
    y = sqrt(25 - pow(2, x));
    phi = atan2(y, x);
}

void AutosO::bremsung()
{
    geschwindigkeit = bremsbeschleunigung * rechnungszeit();
    weg = 0.5 * bremsbeschleunigung * pow(rechnungszeit(), 2) + anfangsgeschwindigkeit * rechnungszeit();
}

AutosO::AutosO(Direction spawn, Color color, Direction direction, float ReactionTime)
{
    this->beschleunigung = 1;
    this->bremsbeschleunigung = -2;
    this->reactionTime = ReactionTime;
    this->internalTimer.restart();
    this->anfangsgeschwindigkeit = 0;
    this->initFahrtweg(spawn, direction);

    this->originalDirection = direction;
    switch (spawn) {
    case Direction::WEST: this->sprite.setPosition(20.f, 550.f); direction = Direction::EAST; break;
    case Direction::NORTH: this->sprite.setPosition(450.f, 30.f); direction = Direction::SOUTH; break;
    case Direction::EAST: this->sprite.setPosition(990.f, 450.f); direction = Direction::WEST; break;
    case Direction::SOUTH: this->sprite.setPosition(550.f, 970.f); direction = Direction::NORTH; break;
    }

    this->initTexture(color);
    this->initSprite();
    this->currentDirection = direction;
    switch (direction) {
    case Direction::NORTH: this->sprite.setRotation(0.f); break;
    case Direction::EAST: this->sprite.setRotation(90.f); break;
    case Direction::SOUTH: this->sprite.setRotation(180.f); break;
    case Direction::WEST: this->sprite.setRotation(270.f); break;
    }
    std::cout << "Konstruktor aufgerufen" << std::endl;

}



AutosO::~AutosO()
{
}

int AutosO::stopNS()
{
    return 0;
}

const sf::Vector2f AutosO::getPos() const
{
    return this->sprite.getPosition();
}


const Direction AutosO::getOriginalDir() const
{
    return this->originalDirection;
}

const Direction AutosO::getCurrentDir() const
{
    return this->currentDirection;
}


void AutosO::update()
{
    switch (this->currentDirection)
    {
    case Direction::SOUTH: {
        //this->beschleunigung();
        //this->bremsung();
        if (sprite.getPosition().y >= 420 && sprite.getPosition().y <= 560)
        {
            if (rndValue < 4)
            {
                this->sprite.move(x, y);
               // this->sprite.move(0.f, -sqrt(2500 - speedp));//richtung westen
                this->sprite.setRotation(phi);
            }
            else if (rndValue >= 4 && rndValue < 8)
            {
                if (sprite.getPosition().y >= 550)
                {
                    this->sprite.move(x,y);
                    this->sprite.setRotation(phi);
                }
                else this->sprite.move(x, y);
            }
            else
            {
                this->sprite.move(x, y);
            }
        }
        else this->sprite.move(0.f, speedp);
        break;
    }
    case Direction::EAST: {
        //this->beschleunigung();
        if (sprite.getPosition().x >= 460 && sprite.getPosition().x <= 560)
        {
            if (rndValue < 8)
            {
                if (sprite.getPosition().x >= 550)
                {
                    this->sprite.move(0.f, speedm); //richtung Norden
                    this->sprite.setRotation(0.f);
                }
                else this->sprite.move(speedp, 0.f);
            }
            else if (rndValue > 8)
            {
                this->sprite.move(0.f, speedp); //richtung s�den
                this->sprite.setRotation(180.f);
            }
            else
            {
                this->sprite.move(speedp, 0.f);
            }
        }
        else this->sprite.move(speedp, 0.f);
        break;
    }
    case Direction::WEST: {
        //this->beschleunigung();
        if (sprite.getPosition().x <= 550 && sprite.getPosition().x >= 440)
        {
            if (rndValue < 9)
            {
                this->sprite.move(0.f, speedm); //richtung Norden
                this->sprite.setRotation(0.f);
            }
            else if (rndValue > 8)
            {
                if (sprite.getPosition().x <= 450)
                {
                    this->sprite.move(0.f, speedp); //richtung s�den
                    this->sprite.setRotation(-180.f);
                }
                else this->sprite.move(speedm, 0.f);
            }
            else
            {
                this->sprite.move(speedm, 0.f);
            }
        }
        else this->sprite.move(speedm, 0.f);
        break;
    }
    case Direction::NORTH: {
        //this->beschleunigung();
        if (sprite.getPosition().y <= 550)
        {
            if (rndValue < 4)
            {
                if (sprite.getPosition().y <= 450)
                {
                    this->sprite.move(speedm, 0.f); //richtung westen
                    this->sprite.setRotation(-90.f);
                }
                else this->sprite.move(0.f, speedm);
            }
            else if (rndValue >= 4 && rndValue < 8)
            {
                this->sprite.move(speedp, 0.f); //richtung osten
                this->sprite.setRotation(90.f);
            }
            else
            {
                this->sprite.move(0.f, speedm);
            }
        }
        else this->sprite.move(0.f, speedm);
        break;
    }
    }
}

void AutosO::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}