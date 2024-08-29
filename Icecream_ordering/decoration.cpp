#include <bits/stdc++.h>
#include "icecream.h"
using namespace std;


class IcecreamDecorator : public Icecream{  //Ia s relationship with Ibase (its a type of base obj only it gives you type matching)
    protected:
    Icecream *icecream;  //Has a relationship with Ibase (as base obj always be there on which we are decorating it gives you the bhaviour)

    public:
    IcecreamDecorator(Icecream *b){
        this->icecream = b;
    }
    string getDescrition(){
        return this->icecream->getDescrition();
    }
    int cost(){
        return this->icecream->cost();
    }
};

class ChocolateDecorator : public IcecreamDecorator{
    public:
    ChocolateDecorator(Icecream *b) : IcecreamDecorator(b){
    }
    string getDescrition(){
        return icecream->getDescrition() + " wih chocolate";
    }
    int cost(){
        //return IcecreamDecorator::cost() + 10;
        //or
        return icecream->cost() + 10;
    }
};

class CaramelDecorator : public IcecreamDecorator{
    public:
    CaramelDecorator(Icecream *b) : IcecreamDecorator(b){
    }
    string getDescrition(){
        return icecream->getDescrition() + " wih caramel";
    }
    int cost(){
        return IcecreamDecorator::cost() + 20;
    }
};