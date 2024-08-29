#include "bits/stdc++.h"
#include "VehicleType.h"
#include "payment.cpp"
using namespace std;

class Vehicle{
    protected:
    string LicenseType;
    VehicleType type;
    Payment* payment;
    std::chrono::time_point<std::chrono::system_clock> parktime;

    public:
    Vehicle( string LicenseType, VehicleType type){
        this->LicenseType = LicenseType;
        this->type = type;
    }

    VehicleType getType() const{
        return type;
    }

    string getlicenseType() const{
        return LicenseType;
    }

    void setParkTime(){
        parktime = std::chrono::system_clock::now();
    }

    std::chrono::time_point<std::chrono::system_clock> getParkTime(){
        return parktime;
    }
    
    virtual double calculateCost(double hours){
        return payment->calculateCost(hours);
    }
};

class Car : public Vehicle{
    public:
    Car(string LicenseType) : Vehicle(LicenseType, VehicleType::CAR){
        payment = new CarPayment();
    }
};

class MotorCycle : public Vehicle{
    public:
    MotorCycle(string LicenseType) : Vehicle(LicenseType, VehicleType::MOTORCYCLE){
        payment = new MotorCyclePayment();
    }
};
class Truck: public Vehicle{
    public:
    Truck(string LicenseType) : Vehicle(LicenseType, VehicleType::TRUCK){
        payment = new TruckPayment();
    }
};