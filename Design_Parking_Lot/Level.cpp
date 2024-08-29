#include "bits/stdc++.h"
//#include "Vehicle.cpp"
#include "ParkingSpot.cpp"

using namespace std;

class Level{
    private:
    int floor;
    vector<ParkingSpot*> parkingSpots;
    //mutex mtx;

    public:
    Level(int floor, int numSpots, vector<VehicleType> spotType){
        this->floor = floor;
        if(spotType.size() != numSpots)
            throw runtime_error("Spot types are not as much as num of spots !! ");
        for(int i  = 0; i < numSpots; i++){
            parkingSpots.push_back(new ParkingSpot(i, spotType[i]));
        }
    }

    /*synchronized*/
    bool parkVehicle(Vehicle *vehicle){
        //unique_lock<mutex> lock(mtx);
        //lock_guard<mutex> lock(mtx);
        for(auto spot:parkingSpots){
            if(spot->isAvailable() && spot->getVehicleType() == vehicle->getType()){
                spot->parkVehicle(vehicle);
                return true;
            }
        }
        
        return false;
    }

    /*synchronized*/
    bool unparkVehicle(Vehicle* vehicle){
        //unique_lock<mutex> lock(mtx);
        //lock_guard<mutex> lock(mtx);
        for(auto spot: parkingSpots){
            if(!spot->isAvailable()  && spot->getParkedVehicle() == vehicle){  //doubt
                spot->unparkVehicle();
                return true;
            }
        }
        return false;
    }

    void displayAvailability() {
        cout << "Level " << floor << " Availability: \n";
        for( auto spot: parkingSpots){
            cout << "spot " << spot->getSpotNumber() << " : " << (spot->isAvailable() ? "Available " : "Occupied by " + spot->getParkedVehicle()->getlicenseType()) << endl;
        }
        cout << endl;
    }

};