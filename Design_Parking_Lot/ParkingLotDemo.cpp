#include "bits/stdc++.h"
//#include "Vehicle.cpp"
#include "ParkingLot.cpp"

using namespace std;

int main(){
    ParkingLot *parkingLot = ParkingLot::getInstance();

    vector<VehicleType> L1spots = {VehicleType::CAR, VehicleType::CAR, VehicleType::CAR, VehicleType::MOTORCYCLE, VehicleType::TRUCK};
    vector<VehicleType> L2spots = {VehicleType::CAR, VehicleType::CAR, VehicleType::MOTORCYCLE, VehicleType::TRUCK};
    
    parkingLot->addLevel(new Level(1, 5, L1spots));
    parkingLot->addLevel(new Level(2, 4, L2spots));

    Vehicle *car0 = new Car("ABC123");
    Vehicle *car1 = new Car("ABC1231");
    Vehicle *car2 = new Car("ABC1232");
    Vehicle *car3 = new Car("ABC1233");
    Vehicle *truck = new Truck("XYZ789");
    Vehicle *motorcycle = new MotorCycle("M1234");
    
    cout << "Display initial parking lot " << endl;
    parkingLot->displayAvailability();
    
    //park Vehicle
    parkingLot->parkVehicle(car0);
    parkingLot->parkVehicle(car1);
    parkingLot->parkVehicle(car2);
    parkingLot->parkVehicle(car3);
    parkingLot->parkVehicle(truck);
    parkingLot->parkVehicle(motorcycle); 

    //Display Availability
    cout << "\nDisplay availability after parking 3 vehicle: \n\n";
    parkingLot->displayAvailability();

    cout << "\n\n";
    //unpark Vehicle
    parkingLot->unparkVehicle(truck);
   
    cout << "\nDisplay availability after unparking 1 vehicle: \n\n";
    //display updated availability
    parkingLot->displayAvailability();
    cout << "\n\n";

    parkingLot->unparkVehicle(car0);
    cout << "\nDisplay availability after unparking 1 vehicle: \n\n";
    //display updated availability
    parkingLot->displayAvailability();
    cout << "\n\n";

    parkingLot->unparkVehicle(motorcycle);
    cout << "\nDisplay availability after unparking 1 vehicle: \n\n";
    //display updated availability
    parkingLot->displayAvailability();
    cout << "\n\n";

    parkingLot->unparkVehicle(car3);
    cout << "\nDisplay availability after unparking 1 vehicle: \n\n";
    //display updated availability
    parkingLot->displayAvailability();
    cout << "\n\n";
    return 0;
}