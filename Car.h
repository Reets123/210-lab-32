// Lab 32: Toll Booth
// COMSC-210 - Ibrahim Alatig 
// Car.h

#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Car {
public:
    Car();
    void print() const;

private:
    string make;
    int year;
    int transponder;

    static const string makes[];
};

const string Car::makes[] = {"Volkswagen", "Skoda", "Volvo", "Lexus", "Toyota"};

Car::Car() {
    make = makes[rand() % (sizeof(makes) / sizeof(makes[0]))];
    year = rand() % 26 + 1999; // Random year between 1999-2024
    transponder = rand() % 9000 + 1000; // Random transponder between 1000-9999
}

void Car::print() const {
    cout << "[" << year << " " << make << " (" << transponder << ")]";
}

#endif 