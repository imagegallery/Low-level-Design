#include <bits/stdc++.h>
#include "observable.h"
using namespace std;

class Inotification{
    public:
    virtual void update() = 0;
    virtual ~Inotification() = default;
};

class EmailAlert : public Inotification{
    string emailId;
    Istock *stock;  //constructor injection for maintaining the diff observables 
                    //so that we can call the correct update method for the observable.
    
    public:

    EmailAlert(string emailId, Istock *obj){
        this->emailId = emailId;
        this->stock = obj;
    }
    void update() {
        sendMail (emailId, "Product is in stock. ");
    }
    void sendMail(string emailId, string msg){
        cout << "mail sent to: " << emailId << endl;
    }
};

class MobileAlert : public Inotification{
    string userName;
    Istock *stock;  //constructor injection for maintaining the diff stocks 
                                  //so that we can call the correct update method for the stock.
    
    public:

    MobileAlert(string userName, Istock *obj){
        this->userName = userName;
        this->stock = obj;
    }
    void update() {
        sendMsgOnMobile (userName, "Product is in stock. ");
    }
    void sendMsgOnMobile(string userName, string msg){
        cout << "mail sent to: " << userName << endl;
    }
};