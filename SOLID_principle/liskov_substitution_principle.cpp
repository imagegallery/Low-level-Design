#include <bits/stdc++.h>

using namespace std;
/*
    Liskov substitution  principle: If class B is subtype of Class A, 
    then we should be able to replace object of A with B without breaking the behaviour of the program.

    Subclass should extend the capability of parent class not narrow it down.

    If you are doing something with Motorcycle obj in main class and it is working fine 
    then you need to changed the class instance to Bicycle then it start throwing error, which is diff beaviour then usual.

*/
/*
class Bike{
    public:
    virtual void turnOnEngine() = 0;
    virtual void accelerate() = 0;
    virtual ~Bike() = default;
};

class MotorCycle : public Bike{
    bool isEngineOn;
    int speed;
    public:
    void turnOnEngine(){
        cout << "Turning engine on for MotorCycle \n";
        isEngineOn = true;
    }
    void accelerate(){
        speed = speed + 10;
        cout << "Accelerating speed for MotorCycle \n";
    }
};

class Bicycle : public Bike{
    public:
    void turnOnEngine(){
        throw "There is no engine";   
    }
    void accelerate(){
        cout << "Accelerating speed for Bicyle \n";
        // Do something
    }
};

int main(){
    MotorCycle m;
    Bicycle b;
    Bike *p1 = &m;
    Bike *p2 = &b;

    p1->turnOnEngine();
    p1->accelerate();

    p2->turnOnEngine();
    p2-> accelerate();
    return 0;

}
*/

/*
//another example
class Vehicle{
    public:
    virtual int getNumberOfWheels(){
        cout << "From Vehicle class, number of wheels \n";
        return 2;
    }
    virtual bool hasEngine(){
        cout << "From Vehicle class, has engine \n";
        return true;
    }
};

class MotorCycle:public Vehicle{

};
class Car : public Vehicle{
    public:
    int getNumberOfWheels(){
        cout << "From car extended Vehicle function for number of wheels \n";
        return 4;
    }
};
class Bicycle :public Vehicle{
    public:
    bool hasEngine(){
        throw "No Engine present!! \n";
    }
};
int main(){
    vector<Vehicle*> objs;
    objs.push_back(new MotorCycle());
    objs.push_back(new Car());
    //objs.push_back(new Bicycle());  //this obj start throwing exception

    for(int i = 0;i < 3; i++){
        objs[i]->hasEngine();
    }
    return 0;
}
*/

//solution: parent class should have only generic methods
/*
                    Vehicle
            /                     \
         EngineVehicle            Bicycle   
        /         \
     MotorCycle    Car    
*/

class Vehicle{
    public:
    virtual int getNumberOfWheels(){
        cout << "From Vehicle class, number of wheels \n";
        return 2;
    }
    
};

class EngineVehicle :public Vehicle{
    public: 
    virtual bool hasEngine(){
        cout << "From Vehicle class, has engine \n";
        return true;
    }
    
};
class MotorCycle:public EngineVehicle{

};
class Car : public EngineVehicle{
    public:
    int getNumberOfWheels(){
        cout << "From car extended EngineVehicle function for number of wheels \n";
        return 4;
    }
};
class Bicycle :public Vehicle{
};
int main(){
    vector<Vehicle*> objs;
    objs.push_back(new MotorCycle());
    objs.push_back(new Car());
    objs.push_back(new Bicycle()); 

    for(int i = 0;i < 3; i++){
        objs[i]->getNumberOfWheels();
    }
    // for(int i = 0;i < 3; i++){
    //     objs[i]->hasEngine(); //this will give compile time error as Bicycle doesn't have the has Engine function.
    // }

    vector<EngineVehicle*> objs1;
    objs1.push_back(new MotorCycle());
    objs1.push_back(new Car());
    objs1.push_back(new Bicycle());  //compile time error: You can't access Bicycle class as its not inherited from EngineVehicle class.

    
    for(int i = 0;i < 3; i++){
        objs1[i]->hasEngine();
    }

    return 0;
}
