#include <bits/stdc++.h>

using namespace std;
/*
    Interface segmented principle: Interfaces should be such, 
    that client should not implement unneccesary functions they do not need.


*/

class RestaurantEmployee{
    public:
    virtual void washDishes() = 0;
    virtual void serveCustomers() = 0;
    virtual void cookFood() = 0;
    virtual ~RestaurantEmployee() = default;
};

class Waiter : public RestaurantEmployee{
   
    public:
    void washDishes(){
        cout << "Not my job\n";   //No need for waiter to implement this function but has to implement because of parent abstract class.
    }
    void serveCustomers(){
        cout << "Serving customers \n";
    }
    void cookFood(){
        cout << "Not my job!! \n";      //No need for waiter to implement this function but has to implement because of parent abstract class.
    }
};

/*
    Instead create small interfaces so that derived class not have to implement unneccesary functions
*/

class WaiterInterface{
    public:
    virtual void takeOrder() = 0;
    virtual void serveCustomers() = 0;
    virtual ~WaiterInterface() = default;
};


class ChefInterface{
    public:
    virtual void decideMenu() = 0;
    virtual void cookFood() = 0;
    virtual ~ChefInterface() = default;
};

class Waiter : public WaiterInterface{
   
    public:
    
    void serveCustomers(){
        cout << "Serving customers \n";
    }
    void takeOrder(){
        cout << "Taking order!! \n";      //No need for waiter to implement this function but has to implement because of parent abstract class.
    }
};