#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <bits/stdc++.h>
using namespace std;

class Inotification;

class Istock {
    public:
    
    virtual void add(Inotification *observer) = 0;
    virtual void remove(Inotification *observer) = 0;
    virtual void notifySubscibers() = 0;
    virtual void setStockCount(int newStockCount) = 0;
    virtual int getStockCount() = 0;
};
#endif
