#include <iostream>
#include <ctime>
#include <vector>
#include "Alien.h"


void printAlienDetails(const Alien& alien) {
    std::cout << "\n--- Alien (" << alien.getGender() << ") ---" << std::endl;
    std::cout << "Weight: " << alien.getWeight() << std::endl;
    std::cout << "Height: " << alien.getHeight() << std::endl;
    (alien.getOffspring() == false) ? std::cout << "Parent" << std::endl : std::cout << "Offspring" << std::endl;
    (alien.getBred() == false) ? std::cout << "Not bred" << std::endl : std::cout << "Bred" << std::endl;
    std::cout << "-----------------" << std::endl;
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
            std::cout << "1. Create Alien" << std::endl;
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
                                    i = j + 1;
                                    Alien offspring = aliens[i] + aliens[j];
                                    aliens.emplace_back(offspring);
                                    aliens[i].setBred(true);
                                    aliens[j].setBred(true);
                                    std::cout << "Offspring created from alien(" << i << ") & alien(" << j << ")" << std::endl;
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
                std::cout << "--- TODO: ---\n- Compare offspring prestige" << std::endl;
            }
        }

    } while (choice != 4);

    for (const auto& alien : aliens)
    {
        printAlienDetails(alien);
    }
}
