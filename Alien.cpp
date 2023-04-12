#include "Alien.h"

//Constructor

Alien::Alien(int weight, int height, char gender, bool offspring)
    : weight_(weight), height_(height), gender_(gender), offspring_(offspring) {}

/*
Getters
*/
int Alien::getWeight() const
{
    return weight_;
}

int Alien::getHeight() const
{
    return height_;
}

char Alien::getGender() const
{
    return gender_;
}

bool Alien::getOffspring() const
{
    return offspring_;
}

int Alien::getPrestige() const
{
    int genderPoints = (gender_ == 'M') ? 2 : 3; //Calculate genderPoints : Male: 2, Female: 3.
    return weight_ * height_ * genderPoints;
}

/*
    Operator Overloading
*/

Alien Alien::operator+(const Alien& other) const
{
    int offspringWeight = (weight_ + other.getWeight()) / 2;
    int offspringHeight = (height_ + other.getHeight()) / 2;
    char offspringGender = (rand() % 2 == 0) ? 'M' : 'F';
    return Alien(offspringWeight, offspringHeight, offspringGender, true);
}

bool Alien::operator==(const Alien& other) const {
    return getPrestige() == other.getPrestige();
}

bool Alien::operator!=(const Alien& other) const {
    return !(*this == other);
}

bool Alien::operator>(const Alien& other) const {
    return getPrestige() > other.getPrestige();
}

bool Alien::operator<(const Alien& other) const {
    return getPrestige() < other.getPrestige();
}

bool Alien::operator>=(const Alien& other) const {
    return !(*this < other);
}

bool Alien::operator<=(const Alien& other) const {
    return !(*this > other);
}