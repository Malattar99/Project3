#include "Ampel.h"
#include "CarProp.h"


Ampel::Ampel()
{
    initAmpelNord(Ampel_Farbe::GREEN);
    initAmpelSued(Ampel_Farbe::GREEN);
    initAmpelOst(Ampel_Farbe::RED);
    initAmpelWest(Ampel_Farbe::RED);
    initScale();
    cycle = true;
}

void Ampel::initScale()
{
    spriteNord.setScale(0.4, 0.4);
    spriteSued.setScale(0.4, 0.4);
    spriteOst.setScale(0.4, 0.4);
    spriteWest.setScale(0.4, 0.4);
}

Ampel::~Ampel()
{

}

void Ampel::initAmpelSued(Ampel_Farbe color)
{

    switch (color)
    {
    case Ampel_Farbe::GREEN: this->textureSued.loadFromFile("images/GRUEN1.png"); ampel_s_green = true; break;
    case Ampel_Farbe::YELLOW: this->textureSued.loadFromFile("images/GELB1.png"); ampel_s_green = false; break;
    case Ampel_Farbe::RED: this->textureSued.loadFromFile("images/ROT1.png"); ampel_s_green = false; break;
    }
    this->spriteSued.setTexture(this->textureSued);

    this->spriteSued.setPosition(620.f, 720.f);
    this->spriteSued.setRotation(0.f);
    std::cout << "Sued aufgerufen" << std::endl;


}

void Ampel::initAmpelNord(Ampel_Farbe color)
{

    switch (color)
    {
    case Ampel_Farbe::GREEN: this->textureNord.loadFromFile("images/GRUEN1.png"); ampel_n_green = true; break;
    case Ampel_Farbe::RED: this->textureNord.loadFromFile("images/ROT1.png");  ampel_n_green = false; break;
    case Ampel_Farbe::YELLOW: this->textureNord.loadFromFile("images/GELB1.png"); ampel_n_green = false; break;
    }
    this->spriteNord.setTexture(textureNord);
    this->spriteNord.setPosition(380.f, 280.f);
    this->spriteNord.setRotation(180.f);

}

void Ampel::initAmpelOst(Ampel_Farbe color)
{

    switch (color)
    {
    case Ampel_Farbe::GREEN: this->textureOst.loadFromFile("images/GRUEN1.png"); ampel_o_green = true; break;
    case Ampel_Farbe::RED: this->textureOst.loadFromFile("images/ROT1.png"); ampel_o_green = false; break;
    case Ampel_Farbe::YELLOW: this->textureOst.loadFromFile("images/GELB1.png"); ampel_o_green = false; break;
    }
    this->spriteOst.setTexture(textureOst);

    this->spriteOst.setPosition(620.f, 280.f);
    this->spriteOst.setRotation(270.f);

}

void Ampel::initAmpelWest(Ampel_Farbe color)
{
    switch (color)
    {
    case Ampel_Farbe::GREEN: this->textureWest.loadFromFile("images/GRUEN1.png"); ampel_w_green = true;; break;
    case Ampel_Farbe::RED: this->textureWest.loadFromFile("images/ROT1.png"); ampel_w_green = false; break;
    case Ampel_Farbe::YELLOW: this->textureWest.loadFromFile("images/GELB1.png"); ampel_w_green = false; break;
    }
    this->spriteWest.setTexture(textureWest);

    this->spriteWest.setPosition(380.f, 720.f);
    this->spriteWest.setRotation(90.f);

}

void Ampel::cycleAmpel()
{
    //std::cout << "called" << std::endl;
     //std::cout << timer.getElapsedTime().asSeconds() << std::endl;

    if (timer.getElapsedTime().asSeconds() <= 10 && cycle == true)
    {
        initAmpelNord(Ampel_Farbe::GREEN);
        initAmpelSued(Ampel_Farbe::GREEN);
        initAmpelOst(Ampel_Farbe::RED);
        initAmpelWest(Ampel_Farbe::RED);
        cycle = false;

    }
    else if (timer.getElapsedTime().asSeconds() > 40 && timer.getElapsedTime().asSeconds() <= 41 && cycle == false)
    {
        initAmpelNord(Ampel_Farbe::YELLOW);
        initAmpelSued(Ampel_Farbe::YELLOW);
        initAmpelOst(Ampel_Farbe::YELLOW);
        initAmpelWest(Ampel_Farbe::YELLOW);
        cycle = true;

    }
    else if (timer.getElapsedTime().asSeconds() > 41 && timer.getElapsedTime().asSeconds() <= 50 && cycle == true)
    {
        initAmpelNord(Ampel_Farbe::RED);
        initAmpelSued(Ampel_Farbe::RED);
        initAmpelOst(Ampel_Farbe::GREEN);
        initAmpelWest(Ampel_Farbe::GREEN);
        cycle = false;
    }
    else if (timer.getElapsedTime().asSeconds() > 51 && cycle == false)
    {
        timer.restart();
        cycle = true;
    }


}


void Ampel::startTimer()
{
    timer.restart();
}
bool Ampel::Ampel_GreenOben_Unten()
{
    return ampel_green_oben_unten;
}

bool Ampel::Ampel_GreenRechts_Links()
{
    return ampel_green_rechts_links;
}

void Ampel::render(sf::RenderTarget& target)
{
    target.draw(this->spriteSued);
    target.draw(this->spriteNord);
    target.draw(this->spriteWest);
    target.draw(this->spriteOst);
}