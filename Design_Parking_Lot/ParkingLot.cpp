#include "bits/stdc++.h"
//#include "Vehicle.cpp"
#include "Level.cpp"

using namespace std;

class ParkingLot{
    private:
    vector<Level*> levels;
    ParkingLot(){ } //singleton class private constructor to prevent instantiation from outside

    static ParkingLot *instance;
    //static mutex mtx;
    
    public:

    ParkingLot(const ParkingLot&) = delete;  //delete copy constructor
    ParkingLot& operator=(const ParkingLot&) = delete; //delete assignment operator
    /* static synchronized */
    static ParkingLot* getInstance() {
        //unique_lock<mutex> lock(mtx);
        //lock_guard<mutex> lock(mtx);
        if(instance == nullptr){
            instance = new ParkingLot();
        }
        return instance;
    }

    void addLevel(Level* level){
        //lock_guard<mutex> lock(mtx);
        levels.push_back(level);
    }

    bool parkVehicle(Vehicle *vehicle){
        //lock_guard<mutex> lock(mtx);
        vehicle->setParkTime();
        for (auto level : levels){
            if(level->parkVehicle(vehicle))
                return true;
        }
        return false;
    }

    bool unparkVehicle(Vehicle * vehicle){
        //lock_guard<mutex> lock(mtx);
        for(auto level:levels){
            if(level->unparkVehicle(vehicle)){

                auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now() - vehicle->getParkTime());
                cout << "payment is: " << vehicle->calculateCost(duration.count()) << endl;
                return true;
            }
        }
        return false;
    }

    void displayAvailability() {
        for( auto level:levels){
            level->displayAvailability();
        }
    }
};

ParkingLot* ParkingLot::instance = nullptr;
//mutex ParkingLot::mtx;
