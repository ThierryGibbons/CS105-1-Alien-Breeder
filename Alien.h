#ifndef ALIEN_H
#define ALIEN_H

#include <cstdlib>

class Alien
{
private:
    //Define the constructor
    int weight_;
    int height_;
    char gender_;
    bool offspring_;

public:

    //Constructor
    Alien(int weight, int height, char gender, bool offspring);

/*
    Getters
*/
    int getWeight() const;
    int getHeight() const;
    char getGender() const;
    bool getOffspring() const;
    int getPrestige() const;
/*
    Operator Overloading
*/
    Alien operator+(const Alien& other) const;

    bool operator==(const Alien& other) const;

    bool operator!=(const Alien& other) const;

    bool operator>(const Alien& other) const;

    bool operator<(const Alien& other) const;

    bool operator>=(const Alien& other) const;

    bool operator<=(const Alien& other) const;
};
#endif