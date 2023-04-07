#include <iostream>
#include <cstdlib>
// #include <ctime>
#include <vector>

class Alien {
public:
    int weight;
    int height;
    char gender;
    bool offspring;

    //Constructor
    Alien(int weight, int height, char gender, bool o) : offspring(o) {};

    //Getters
    int getWeight() const {
        return weight;
    }

    int getHeight() const {
        return height;
    }

    char getGender() const {
        return gender;
    }

    int getPrestige() const {
        int genderPoints = (gender == 'M') ? 2 : 3;
        return height * weight * genderPoints;
    }

    bool getOffspring() const {
        return offspring;
    }

    //Operator Overloading
    Alien operator+(const Alien& other) const {
        int offspringWeight = (weight + other.getWeight()) / 2;
        int offspringHeight = (height + other.getHeight()) / 2;
        char offspringGender = (rand() % 2 == 0) ? 'M' : 'F';
        return Alien(offspringWeight, offspringHeight, offspringGender, true);
    }

    bool operator==(const Alien& other) const {
        return getPrestige() == other.getPrestige();
    }

    bool operator!=(const Alien& other) const {
        return !(*this == other);
    }

    bool operator>(const Alien& other) const {
        return getPrestige() > other.getPrestige();
    }

    bool operator<(const Alien& other) const {
        return getPrestige() < other.getPrestige();
    }

    bool operator>=(const Alien& other) const {
        return !(*this < other);
    }

    bool operator<=(const Alien& other) const {
        return !(*this > other);
    }

};
std::vector<Alien> aliens;

Alien createAlien() {
    int weight, height;
    char gender;
    bool offspring;

    std::cout << "Enter Height: ";
    std::cin >> height;
    std::cout << "Enter Weight: ";
    std::cin >> weight;
    offspring = false; // Offspring is always false unless created in a result of breeding

    aliens.emplace_back(weight, height, gender, offspring);
    return aliens.back();
}

int main()
{
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
                char gender;
                bool offspring;

                Alien newAlien = createAlien();
            }
            case 2: //Create offspring
            {

            }
            case 3: //Compare offspring prestige
            {

            }
        }

    } while (choice != 4);

    // for (int i = 0; i < aliens.size(); i++)
    // {
    //     std::cout << "Alien " << i << " has a weight of " << aliens[i].getWeight() << " and a height of " << aliens[i].getHeight() << std::endl;
    // }
    for (const auto& alien : aliens)
    {
        std::cout << "Alien has a weight of " << alien.getWeight() << " and a height of " << alien.getHeight() << std::endl;
    }
}
