#include <iostream>
#include <ctime>
#include <vector>
#include "Alien.h"

int o = 0;
void printAlienDetails(const Alien& alien) {
    std::cout << "--- Alien" << o << "(" << alien.getGender() << ") ---" << std::endl;
    std::cout << "Weight: " << alien.getWeight() << std::endl;
    std::cout << "Height: " << alien.getHeight() << std::endl;
    (alien.getOffspring() == false) ? std::cout << "Parent: " : std::cout << "Offspring: ";
    (alien.getBred() == false) ? std::cout << "Not bred" << std::endl : std::cout << "Bred" << std::endl;

    if (alien.getOffspring() == true && alien.getBred() == true)
    {
        std::cout << "Error: Offspring and bred status do not match." << std::endl;
    }

    std::cout << "-----------------\n" << std::endl;
    o++;
}

int main()
{
    srand(time(NULL));
    std::vector<Alien> aliens;
    int choice = 0;

    std::cout << "Welcome to the Alien Breeding Program!" << std::endl;

    do
    {
        bool validChoice = false;

        while (!validChoice)
        {
            std::cout << "1. Create Alien pairs." << std::endl;
            std::cout << "2. Create offspring." << std::endl;
            std::cout << "3. Compare offspring prestige." << std::endl;
            std::cout << "4. Exit" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            if (choice >= 1 && choice <= 4)
            {
                validChoice = true;
            } else
            {
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }

        switch (choice)
        {
            case 1: //Create alien pair
            {
                int weight, height;

                // Alien newAlien_M = createAlien();
                // Alien newAlien_F = createAlien();

                //Create Alien's
                std::cout << "--- Create Male Alien ---" << std::endl;
                std::cout << "Enter Height: ";
                std::cin >> height;
                std::cout << "Enter Weight: ";
                std::cin >> weight;
                aliens.emplace_back(weight, height, 'M', false, false);

                std::cout << "--- Create Female Alien ---" << std::endl;
                std::cout << "Enter Height: ";
                std::cin >> height;
                std::cout << "Enter Weight: ";
                std::cin >> weight;
                aliens.emplace_back(weight, height, 'F', false, false);

                break;
            }
            case 2: //Create offspring
            {
                //link every two aliens, that are not offspring, together
                for (int i = 1; i < aliens.size(); i++)
                {
                    if (aliens[i].getOffspring() == false && aliens[i].getBred() == false)
                    {
                        for (int j = 0; j < aliens.size(); j++)
                        {
                            if (aliens[j].getOffspring() == false && aliens[j].getBred() == false)
                            {
                                if (i != j)
                                {
                                    Alien offspring = aliens[i] + aliens[j];
                                    aliens.emplace_back(offspring);
                                    aliens.emplace_back(offspring);
                                    aliens[i].setBred(true);
                                    aliens[j].setBred(true);
                                    std::cout << "Offspring created from alien(" << i << ") & alien(" << j << ")" << std::endl;
                                    i = j + 1;
                                    break;
                                }
                            }
                        }
                    }
                }

                break;
            }
            case 3: //Compare offspring prestige
            {
                for (int x = 0; x < aliens.size(); x++)
                {
                    if (aliens[x].getOffspring() == true)
                    {
                        for (int y = 0; y < aliens.size(); y++)
                        {
                            if (aliens[y].getOffspring() == true)
                            {
                                std::cout << "\n--------------------" << std::endl;

                                std::cout << "Comparing Alien" << x << " with Alien" << y << std::endl << std::endl;

                                std::cout << "Alien" << x << " == Alien" << y << " ? ";
                                (aliens[x] == aliens[y]) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;

                                std::cout << "Alien" << x << " != Alien" << y << " ? ";
                                (aliens[x] != aliens[y]) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;

                                std::cout << "Alien" << x << " > Alien" << y << " ? ";
                                (aliens[x] > aliens[y]) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;

                                std::cout << "Alien" << x << " < Alien" << y << " ? ";
                                (aliens[x] < aliens[y]) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;

                                std::cout << "Alien" << x << " >= Alien" << y << " ? ";
                                (aliens[x] >= aliens[y]) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;

                                std::cout << "Alien" << x << " <= Alien" << y << " ? ";
                                (aliens[x] <= aliens[y]) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;

                                std::cout << "--------------------" << std::endl;
                            }
                        }
                    }
                }
            }
        }

    } while (choice != 4);

    std::cout << "\nAll Aliens:" << std::endl;

    int o = 0;
    for (const auto& alien : aliens)
    {
        printAlienDetails(alien);
    }
}
