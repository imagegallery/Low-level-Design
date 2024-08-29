#include <bits/stdc++.h>
#include "observable.h"
#include "observer.cpp"

using namespace std;

class IphoneImpl : public Istock{
    list<Inotification*> observerList;  //list of customer 
    int stockCount;

    public:
    IphoneImpl(){
        stockCount = 0;
    }
    void add(Inotification *obj){
        observerList.push_back(obj);
    }

    void remove(Inotification *obj){
        observerList.remove(obj);
    }
    void notifySubscibers(){
        for(auto observer: observerList){
            observer->update();
        }
    }
    void setStockCount(int newStockCount){
        if(stockCount == 0){
            notifySubscibers();
        }
        stockCount += newStockCount;
    }
    int getStockCount(){
        return stockCount;
    }
};