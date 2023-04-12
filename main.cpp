#include <iostream>
#include <ctime>
#include <vector>
#include "Alien.h"


void printAlienDetails(const Alien& alien) {
    std::cout << "\n--- Alien (" << alien.getGender() << ") ---" << std::endl;
    std::cout << "Weight: " << alien.getWeight() << std::endl;
    std::cout << "Height: " << alien.getHeight() << std::endl;
    std::cout << "Offspring: " << alien.getOffspring() << std::endl;
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
                aliens.emplace_back(weight, height, 'M', false);

                std::cout << "--- Create Female Alien ---" << std::endl;
                std::cout << "Enter Height: ";
                std::cin >> height;
                std::cout << "Enter Weight: ";
                std::cin >> weight;
                aliens.emplace_back(weight, height, 'F', false);

                break;
            }
            case 2: //Create offspring
            {
                std::cout << "--- TODO: ---\n- Create offspring" << std::endl;
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
