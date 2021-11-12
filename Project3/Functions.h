#pragma once
#include "Autos.h"
#include "AutosO.h"

class Functions
{

public:


    static  bool checkSpawnNorth(std::vector<Autos*> cars)
    {
        //std::cout << "checkSpawn aufgerufen" << std::endl;
        bool blocked;
        //std::cout << "blocked erstellt\n";

        if (cars.empty()) {
            blocked = 0;
            //std::cout << "cars noch empty\n";
            return blocked;
        }

        else {
            for (int i = 0; i < cars.size(); i++)
            {
                //std::cout << "Schleife beginnt\n";
                //std::cout << i << std::endl;
                switch (cars[i]->getCurrentDir()) {

                case Direction::SOUTH:
                    if (cars[i]->getPos().y < 150) {
                        return blocked = 1;
                        //std::cout << "blocked" << std::endl;
                    }
                    

                    else { blocked = 0; }

                    break;
                    break;

                default: blocked = 0;
                    break;

                }

            }
            return blocked;
            //std::cout << "blocked returned" << std::endl;
        }

    }

    static  bool checkSpawnNorth1(std::vector<AutosO*> cars)
    {
        //std::cout << "checkSpawn aufgerufen" << std::endl;
        bool blocked;
        //std::cout << "blocked erstellt\n";

        if (cars.empty()) {
            blocked = 0;
            //std::cout << "cars noch empty\n";
            return blocked;
        }

        else {
            for (int i = 0; i < cars.size(); i++)
            {
                //std::cout << "Schleife beginnt\n";
                //std::cout << i << std::endl;
                switch (cars[i]->getCurrentDir()) {

                case Direction::SOUTH:
                    if (cars[i]->getPos().y < 150) {
                        return blocked = 1;
                        //std::cout << "blocked" << std::endl;
                    }

                    else { blocked = 0; }

                    break;
                    break;

                default: blocked = 0;
                    break;

                }

            }
            return blocked;
            //std::cout << "blocked returned" << std::endl;
        }

    }

    static  bool checkSpawnSouth1(std::vector<AutosO*> cars)
    {
        //std::cout << "checkSpawn aufgerufen" << std::endl;
        bool blocked;
        //std::cout << "blocked erstellt\n";

        if (cars.empty()) {
            blocked = 0;
            // std::cout << "cars noch empty\n";
            return blocked;
        }

        else {
            for (int i = 0; i < cars.size(); i++)
            {
                //std::cout << "Schleife beginnt\n";
                //std::cout << i << std::endl;
                switch (cars[i]->getCurrentDir()) {

                case Direction::NORTH:
                    if (cars[i]->getPos().y > 850) {
                        return blocked = 1;
                        // std::cout << "blocked" << std::endl;
                    }

                    else { blocked = 0; }

                    break;
                    break;

                default: blocked = 0;
                    break;

                }

            }
            return blocked;
            //std::cout << "blocked returned" << std::endl;
        }

    }

    static  bool checkSpawnSouth(std::vector<Autos*> cars)
    {
        //std::cout << "checkSpawn aufgerufen" << std::endl;
        bool blocked;
        //std::cout << "blocked erstellt\n";

        if (cars.empty()) {
            blocked = 0;
            // std::cout << "cars noch empty\n";
            return blocked;
        }

        else {
            for (int i = 0; i < cars.size(); i++)
            {
                //std::cout << "Schleife beginnt\n";
                //std::cout << i << std::endl;
                switch (cars[i]->getCurrentDir()) {

                case Direction::NORTH:
                    if (cars[i]->getPos().y > 850) {
                        return blocked = 1;
                        // std::cout << "blocked" << std::endl;
                    }

                    else { blocked = 0; }

                    break;
                    break;

                default: blocked = 0;
                    break;

                }

            }
            return blocked;
            //std::cout << "blocked returned" << std::endl;
        }

    }



    static  bool checkSpawnEast(std::vector<Autos*> cars)
    {
        // std::cout << "checkSpawn aufgerufen" << std::endl;
        bool blocked;
        // std::cout << "blocked erstellt\n";

        if (cars.empty()) {
            blocked = 0;
            //  std::cout << "cars noch empty\n";
            return blocked;
        }

        else {
            for (int i = 0; i < cars.size(); i++)
            {
                //  std::cout << "Schleife beginnt\n";
                 // std::cout << i << std::endl;
                switch (cars[i]->getCurrentDir()) {

                case Direction::WEST:
                    if (cars[i]->getPos().x > 850) {
                        return blocked = 1;
                        //  std::cout << "blocked" << std::endl;
                    }

                    else { blocked = 0; }

                    break;
                case Direction::WEST_E:
                    if (cars[i]->getPos().x > 850) {
                        return blocked = 1;
                        //  std::cout << "blocked" << std::endl;
                    }

                    else { blocked = 0; }

                    break;
                
                    break;

                default: blocked = 0;
                    break;

                }

            }
            return blocked;
            //std::cout << "blocked returned" << std::endl;
        }

    }

    static  bool checkSpawnEast1(std::vector<AutosO*> cars)
    {
        // std::cout << "checkSpawn aufgerufen" << std::endl;
        bool blocked;
        // std::cout << "blocked erstellt\n";

        if (cars.empty()) {
            blocked = 0;
            //  std::cout << "cars noch empty\n";
            return blocked;
        }

        else {
            for (int i = 0; i < cars.size(); i++)
            {
                //  std::cout << "Schleife beginnt\n";
                 // std::cout << i << std::endl;
                switch (cars[i]->getCurrentDir()) {

                case Direction::WEST:
                    if (cars[i]->getPos().x > 850) {
                        return blocked = 1;
                        //  std::cout << "blocked" << std::endl;
                    }

                    else { blocked = 0; }

                    break;
                
                    break;

                default: blocked = 0;
                    break;

                }

            }
            return blocked;
            //std::cout << "blocked returned" << std::endl;
        }

    }

    static  bool checkSpawnWest(std::vector<Autos*> cars)
    {
        //std::cout << "checkSpawn aufgerufen" << std::endl;
        bool blocked;
        // std::cout << "blocked erstellt\n";

        if (cars.empty()) {
            blocked = 0;
            //std::cout << "cars noch empty\n";
            return blocked;
        }

        else {
            for (int i = 0; i < cars.size(); i++)
            {
                //  std::cout << "Schleife beginnt\n";
                //  std::cout << i << std::endl;
                switch (cars[i]->getCurrentDir()) {

                case Direction::EAST:
                    if (cars[i]->getPos().x < 150) {
                        return blocked = 1;
                        //     std::cout << "blocked" << std::endl;
                    }

                    else { blocked = 0; }

                    break;
                case Direction::EAST_W:
                    if (cars[i]->getPos().x < 150) {
                        return blocked = 1;
                        //     std::cout << "blocked" << std::endl;
                    }

                    else { blocked = 0; }

                    break;
                    break;

                default: blocked = 0;
                    break;

                }

            }
            return blocked;
            // std::cout << "blocked returned" << std::endl;
        }

    }

    static  bool checkSpawnWest1(std::vector<AutosO*> cars)
    {
        //std::cout << "checkSpawn aufgerufen" << std::endl;
        bool blocked;
        // std::cout << "blocked erstellt\n";

        if (cars.empty()) {
            blocked = 0;
            //std::cout << "cars noch empty\n";
            return blocked;
        }

        else {
            for (int i = 0; i < cars.size(); i++)
            {
                //  std::cout << "Schleife beginnt\n";
                //  std::cout << i << std::endl;
                switch (cars[i]->getCurrentDir()) {

                case Direction::EAST:
                    if (cars[i]->getPos().x < 150) {
                        return blocked = 1;
                        //     std::cout << "blocked" << std::endl;
                    }

                    else { blocked = 0; }

                    break;
                    break;

                default: blocked = 0;
                    break;

                }

            }
            return blocked;
            // std::cout << "blocked returned" << std::endl;
        }

    }
};