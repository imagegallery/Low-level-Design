#include <mutex>
#include "bits/stdc++.h"
#include "Vehicle.cpp"


using namespace std;

class ParkingSpot{
    private:
    int spotNumber;
    VehicleType vehicleType;
    Vehicle *parkedVehicle;
    //std::mutex mtx;

    public:
    ParkingSpot(int spotNumber, VehicleType vehicleType=VehicleType::CAR){
        this->spotNumber = spotNumber;
        this->vehicleType = vehicleType;  //Default is vehicle type of car
        parkedVehicle = nullptr;
    }

    /*synchronized */ 
    bool isAvailable(){
        //unique_lock<std::mutex> lock(mtx);
        //lock_guard<mutex> lock(mtx);
        if(parkedVehicle == nullptr)
            return true;
        else 
            return false;
        //return parkedVehicle == nullptr;
    }

    /*synchronized*/ 
    void parkVehicle(Vehicle *vehicle){
        //unique_lock<std::mutex> lock(mtx);
        //lock_guard<mutex> lock(mtx);
        if(isAvailable() && vehicle->getType() == vehicleType){
            parkedVehicle = vehicle;
        }else{
            throw runtime_error("Invalid vehicle type or spot already occupied !! ");
        }
    }

    /*synchronized*/ 
    void unparkVehicle(){
        //unique_lock<std::mutex> lock(mtx);
        //lock_guard<mutex> lock(mtx);
        parkedVehicle = nullptr; 
    }
    
    VehicleType getVehicleType() const {
        return vehicleType;
    }

    Vehicle* getParkedVehicle() const {
        return parkedVehicle;
    }

    int getSpotNumber() const {
        return spotNumber;
    }
};
