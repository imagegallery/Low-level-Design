

/*
Strategy Pattern is a behavioral design pattern that defines a family of interchangeable algorithms and allows them to be used interchangeably within a context. 
This pattern enables the algorithm to be selected at runtime, providing flexibility and promoting code reusability.

Key Component of Strategy Patterns :

1) Context: The class that contains a reference to the strategy interface and is responsible for executing the algorithm.
2) Strategy Interface: An interface or abstract class that declares the method(s) for the algorithm. Different strategies implement this interface.
3) Concrete Strategies: The different algorithms that implement the strategy interface.


Advantages of the Strategy Pattern in C++ Design Patterns
1) Flexibility: Easily switch between different algorithms at runtime.
2) Code Reusability: Strategies can be reused across different contexts.
3) Promotes Single Responsibility: Each strategy focuses on a specific algorithm.

Disadvantages of the Strategy Pattern in C++ Design Patterns
1) May lead to an increased number of classes, which can be overwhelming for small-scale applications.
2) Context and the Strategy classes normally communicate through the interface specified by the abstract Strategy base class. Strategy base class must expose interface for all the required behaviours, which some concrete Strategy classes might not implement.
3) In most cases, the application configures the Context with the required Strategy object. Therefore, the application needs to create and maintain two objects in place of one.

When derived classes, start sharing some common functionality diff from parent.

        Base
        /   \
      c1     c2

Base class have some function lets say "drive" and c1 and c2 which are inherited from base class, have drive function
but needs to implement their own "drive" function as they need diff capabilites and that implementation is same for both.
then its good to adopt strategy design pattern.
*/


#include <bits/stdc++.h>
using namespace std;

class DriveStrategy{
    public:
    virtual void drive() = 0;
};
class NormalDrive :public DriveStrategy{
    public:
    void drive(){
        cout << "Normal drive strategy \n";
    }
};
class SpecialDrive : public DriveStrategy{
    public:
    void drive(){
        cout << "Special drive strategy \n";
    }
};
class Vehicle{
    DriveStrategy *obj;  // Has a relationship
    public:
    Vehicle(DriveStrategy *ds){
        this->obj = ds;
        cout << "Parent constructor \n";
    }

    void drive(){
        obj->drive();
    }
};

class SportsVehicle :public Vehicle{
    public:
    SportsVehicle(): Vehicle(new SpecialDrive() ){
        cout << "SportsVehicle constructor \n";
    }  //equivalent of super in java
};

class PassengerVehicle : public Vehicle{
   public:
    PassengerVehicle(): Vehicle(new NormalDrive() ){
        cout << "PassengerVehicle constructor \n";
    }
    
};
class OffRoadVehicle :public Vehicle{
    public:
    OffRoadVehicle(): Vehicle(new SpecialDrive() ){
        cout << "OffRoadVehicle constructor \n";
    }
};
class GoodsVehicle : public Vehicle{
    public:
    GoodsVehicle(): Vehicle(new NormalDrive() ){
        cout << "GoodsVehicle constructor \n";
    }
    
};

int main(){
    OffRoadVehicle obj;
    obj.drive();
    PassengerVehicle p;
    p.drive();
}





















