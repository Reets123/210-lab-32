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
         cycle++;
        int operationType = rand() % 100; // random value between 0-99

        // Determine operation based on probabilities
        if (operationType < 55) { // 55% probability 
            Car paidCar = tollQueue.front();
            tollQueue.pop_front(); // Car pays and leaves
            cout << "Time: " << cycle << " Operation: Car paid: ";
            paidCar.print();
        } else { // 45% probability 
            Car newCar;
            tollQueue.push_back(newCar);
