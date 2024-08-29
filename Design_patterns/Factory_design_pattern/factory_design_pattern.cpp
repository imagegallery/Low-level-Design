/*
 Factory method is a creational design pattern which solves the problem of creating product objects without 
 specifying their concrete classes.
 Its a creational pattern, to create objects on the basis of some conditions.
*/
#include <bits/stdc++.h>
using namespace std;

class IShape{
    public:
    virtual void draw()=0;
};

class Rectangle :public IShape{
    public:
    void draw(){
        cout << "Rectangle !\n";
    }
};

class Circle :public IShape{
    public:
    void draw(){
        cout << "Circle !\n";
    }
};

class ShapeFactory{
    public:
    IShape* getShape(char input){
        switch(input){
            case 'C':
            {
                cout << "Creating circle object !\n";
                return new Circle();
            }
            case 'R':
            {
                cout << "Creating rectangle object !\n";
                return new Rectangle();
            }
            default:
                return NULL;
        }
    }
};

int main(){
    ShapeFactory *obj = new ShapeFactory();
    IShape *shape = obj->getShape('C');
    shape->draw();

    shape = obj->getShape('R');
    shape->draw();
    return 0;
}