// Lab 33: Toll Booth
// COMSC-210 - Ibrahim Alatig 

#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"

using namespace std;

const int INITIAL_CAR_COUNT = 2;
const int NUM_LANES = 4;
const int SIMULATION_TIME = 20;

// Probabilities
const int PAY_PROBABILITY = 46;
const int JOIN_PROBABILITY = 39;
const int SWITCH_PROBABILITY = 15;

void displayLane(int laneIndex, const deque<Car>& laneQueue) {
    cout << "Lane " << (laneIndex + 1) << " Queue: ";
    if (laneQueue.empty()) {
        cout << "empty" << endl;
    } else {
        cout << endl;
        for (const Car& car : laneQueue) {
            cout << "        ";
            car.print();
            cout << endl;
        }
    }
}

void displayAllLanes(deque<Car> lanes[]) {
    for (int i = 0; i < NUM_LANES; i++) {
        displayLane(i, lanes[i]);
    }
}

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

    deque<Car> lanes[NUM_LANES];

    for (int i = 0; i < NUM_LANES; ++i) {
        int numCars = rand() % 3 + 1; // Generate 1 to 3 cars
        for (int j = 0; j < numCars; ++j) {
            lanes[i].push_back(Car());
        }
    }

    // Display initial queue
    cout << "Initial queue:" << endl;
    displayAllLanes(lanes);
    cout << endl;

    for (int time = 1; time <= SIMULATION_TIME; ++time) {
        cout << "Time: " << time << endl;

        for (int laneIndex = 0; laneIndex < NUM_LANES; ++laneIndex) {
            int operation = rand() % 100; // Random number (0-99)

             if (!lanes[laneIndex].empty()) {
                if (operation < PAY_PROBABILITY) { // Car pays and leaves
                    cout << "Lane: " << (laneIndex+ 1) << " Paid: ";
                    lanes[laneIndex].front().print();
                    cout << endl;
                    lanes[laneIndex].pop_front();
                } else if (operation < (PAY_PROBABILITY + JOIN_PROBABILITY)) { 
                    lanes[laneIndex].push_back(Car());
                    cout << "Lane: " << (laneIndex + 1) << " Joined: ";
                    lanes[laneIndex].back().print();
                    cout << endl;
                } else { 
                    int switchLaneIndex;
                    do {
                        switchLaneIndex = rand() % NUM_LANES;
                    } while (switchLaneIndex == laneIndex);
                    if (!lanes[laneIndex].empty()) {
                        Car movedCar = lanes[laneIndex].back();
                        lanes[laneIndex].pop_back();
                        lanes[switchLaneIndex].push_back(movedCar);
                        cout << "Lane: " << (laneIndex + 1) << " Switched: ";
                        movedCar.print();
                        cout << " to Lane: " << (switchLaneIndex + 1) << endl;
                    }
                }
            } else { 
                if (rand() % 2 == 0) {
                    lanes[laneIndex].push_back(Car());
                    cout << "Lane: " << (laneIndex + 1) << " Joined: ";
                    lanes[laneIndex].back().print();
                    cout << endl;
                }
            }
        }

        // Display all lanes 
        displayAllLanes(lanes);
        cout << endl;
    }

    return 0;
}