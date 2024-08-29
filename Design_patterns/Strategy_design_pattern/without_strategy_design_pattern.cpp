/*
When derived classes, start sharing some common functionality diff from parent.

        Base
        /   \
      c1     c2

Base class have some function lets say "drive" and c1 and c2 which are inherited from base class, have drive function
but needs to implement their own "drive" function as they need diff capabilites and that implementation is same for both.
which leads to duplication of code. 
*/


#include <bits/stdc++.h>
using namespace std;
class Vehicle{
    public:
    virtual void drive(){
        cout << "Normal drive capability\n";
    }
};

class SportsVehicle :public Vehicle{
    public:
    void drive(){
        cout << "SportsVehicle needs Sports drive capability\n";
    }
};

class PassengerVehicle : public Vehicle{
   //inherits base class drive functionality
    
};
class OffRoadVehicle :public Vehicle{
    public:
    void drive(){
        cout << "OffRoadVehicle needs Sports drive capability\n";
    }
};
class GoodsVehicle : public Vehicle{
   //inherits base class drive functionality
    
};
int main(){
    OffRoadVehicle obj;
    obj.drive();
    PassengerVehicle p;
    p.drive();
}