// Lab 32: Toll Booth
// COMSC-210 - Ibrahim Alatig 
// Car.h

#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Car {
private:
    string make;int year;
    int transponder;

    static const vector<string> manufacturers;

public:
    Car() { srand(static_cast<unsigned int>(time(0))); // for randomness
        make = manufacturers[rand() % manufacturers.size()];
        year = rand() % 26 + 1999; // Random year between 1999 to 2024
        transponder = (rand() % 9000) + 1000; // Random number between 1000 to 9999
    }

    void print() const {
        cout << year << " " << make << " (" << transponder << ")" << endl;
    }

};

const vector<string> Car::manufacturers = {"Toyota", "Honda", "Ford", "Chevrolet", "Volkswagen", 
                                            "Nissan", "BMW", "Mercedes", "Tesla", "Lexus", 
                                            "Skoda", "Volvo"};

#endif