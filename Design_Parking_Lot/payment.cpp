#include "bits/stdc++.h"

using namespace std;

class Payment{
    public:
        virtual double calculateCost(double hours) = 0;   //pure virtual function so that we can not create the objects of this class
};

class CarPayment :public Payment{
    public:
        double calculateCost(double hours){
            return 2*hours;
        }
};

class MotorCyclePayment :public Payment{
    public:
        double calculateCost(double hours){
            return 1*hours;
        }
};
class TruckPayment :public Payment{
    public:
        double calculateCost(double hours){
            return 3*hours;
        }
};