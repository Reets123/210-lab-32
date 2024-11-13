// Lab 32: Toll Booth
// COMSC-210 - Ibrahim Alatig 

#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h" // Include the Car class

using namespace std;

// Constants
const int INITIAL_CAR_COUNT = 2;
const int TOTAL_YEARS = 26; // 1999 to 2024

int main() {
    deque<Car> tollQueue;

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < INITIAL_CAR_COUNT; ++i) {
        tollQueue.push_back(Car());
    }

    cout << "Initial queue:" << endl;
    for (const Car &car : tolQueue) {
        car.print();
    }
    cout << endl;

    int cycle = 0;
    while (!tollQueue.empty()) {
