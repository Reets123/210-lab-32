// Lab 32: Toll Booth
// COMSC-210 - Ibrahim Alatig 

#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"

using namespace std;

const int INITIAL_CAR_COUNT = 2;

void displayQueue(const deque<Car>& tollQueue) {
    if (tollQueue.empty()) {
        cout << "Queue:\n    Empty" << endl;
    } else {
        cout << "Queue:" << endl;
        for (const Car& car : tollQueue) {
            car.print();
            cout << endl;
        }
    }
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    deque<Car> tollQueue;

    // Initialize the queue with a number of cars
    for (int i = 0; i < INITIAL_CAR_COUNT; ++i) {
        tollQueue.push_back(Car());
    }

    // Display initial queue
    cout << "Initial queue:" << endl;
    displayQueue(tollQueue);
    cout << endl;

    int time = 1; // Start the time counter
    int totalCycles = 0; // Count of total cycles

    while (!tollQueue.empty()) {
        totalCycles++;
        int operation = rand() % 100; // Random number (0-99)

        if (operation < 55) { // 55% chance 
            cout << "Time: " << time << " Operation: Car paid: ";
            tollQueue.front().print();
            cout << endl;
            tollQueue.pop_front(); 
        } else { // 45% chance 
            tollQueue.push_back(Car());
            cout << "Time: " << time << " Operation: Joined lane: ";
            tollQueue.back().print();
            cout << endl;
        }

        displayQueue(tollQueue);
        cout << endl;

        time++; 
    }

    cout << "This simulation ran " << totalCycles << " cycles until the queue was empty." << endl;

    return 0;
}