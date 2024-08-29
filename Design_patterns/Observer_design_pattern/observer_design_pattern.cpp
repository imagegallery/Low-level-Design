/*
    Its behavioural design pattern that defines one to many dependency between objects, meaning that when one object(the subject)
    changes its state, all its dependents(observers) are notified and updated automatically.

    Key Concepts of the Observer Pattern
    Before diving into the implementation of the Observer Pattern in C++, let’s understand its key components:

    1) Subject: This is the object that is being observed. It maintains a list of observers and notifies them of state changes. 
    2) Observer: Observers are objects that are interested in the state changes of the subject. They register with the subject to receive updates.
    3) Concrete Subject: The concrete subject class inherits from the subject interface or class and is responsible for maintaining the state and notifying observers when changes occur.
    4) Concrete Observer: Concrete observers implement the observer interface or inherit from an observer class. They register themselves with a concrete subject and react to state changes.

    Advantages of the Observer Pattern in C++ Design Patterns
    1) Decoupling: The Observer Pattern promotes loose coupling between subjects and observers. Subjects don’t need to know the concrete types of their observers.
    2) Scalability: You can easily add or remove observers without modifying the subject. This makes it a flexible solution for systems with dynamic requirements.
    3) Reusability: Observers can be reused in different contexts, provided they adhere to the observer interface or class.
    4) Event Handling: The pattern is instrumental in event handling systems, such as GUI frameworks, where components need to respond to user actions.

    Disadvantages of the Observer Pattern in C++ Design Patterns
    1) Memory and Performance Overhead: The use of dynamic lists of observers can introduce memory overhead, and notifying many observers can have a performance impact in large-scale systems.
    2) Order of Notification: The order in which observers are notified might be significant in some cases, but the pattern doesn’t inherently guarantee a specific order.
    3) Unintended Updates: Observers can receive updates even when they are not interested in certain changes, leading to potentially unnecessary processing.


    Observer design patterns are useful for implementing notify me, weather forcasting applicaton to display updated temp.
    where change of behaviour needs to be observed.

    we have observable and observer classes, whenever there is state change in observable this needs 
    to be updated to all the observers. observers could be as many as possible.
*/



#include <bits/stdc++.h>
using namespace std;

class Iobserver{
    public:
    virtual void update() = 0;  //to update all kinds of observers
};

class Iobservable{
    //vector<Iobserver *> observers;  //1 to many "has a" relationship between observable and observer. 
                                          //this needs to defined in concrete class because it becomes const and can't be canged.
    public:
    virtual void add(Iobserver *obj) = 0;  //add observer in the list of observers
    virtual void remove(Iobserver *obj) = 0;  //remove observer from list of observers
    virtual void notify() = 0; //notify all observers about the state change.
    virtual void setdata(int t) = 0;
    virtual int getdata() = 0;
};



class Observable : public Iobservable{
    list<Iobserver* > observers;
    int temp;

    public:
    Observable(){
        temp = 0;
    }
    void add(Iobserver *obj){
        observers.push_back(obj);
    }
    void remove(Iobserver *obj){
        observers.remove(obj);
    }
    void notify(){
        for(auto obj: observers){
            obj->update();
        }
    }
    void setdata(int t){
        if(this->temp == 0)
            notify();
        this->temp += t;
        
    }
    int getdata(){
        return this->temp;
    }
};

class Observer : public Iobserver{
    Iobservable *obj;
    public:
    Observer(Iobservable *obj){
        this->obj = obj;
    }
    void update(){
        cout << "updating data " << obj->getdata() << endl;
        //obj->getdata();
    }
};

int main(){
    Iobservable *observable = new Observable();
    
    Iobserver *observer1 = new Observer(observable);
    Iobserver *observer2 = new Observer(observable);

    observable->add(observer1);
    observable->add(observer2);

    observable->setdata(10);

    observable->setdata(100);
    cout << "data is: " << observable->getdata() << endl;


}