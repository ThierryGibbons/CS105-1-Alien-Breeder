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
    bool bred_;

public:

    //Constructor
    Alien(int weight, int height, char gender, bool offspring, bool bred);

/*
    Getters
*/
    int getWeight() const;
    int getHeight() const;
    char getGender() const;
    bool getOffspring() const;
    int getPrestige() const;
    bool getBred() const;

/*
Setters
*/
    void setBred(bool bred);

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