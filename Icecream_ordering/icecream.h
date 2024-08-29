#ifndef ICECREAM_H
#define  ICECREAM_H

#include <bits/stdc++.h>
using namespace std;

class Icecream{
    public:
    virtual int cost() = 0;
    virtual string getDescrition() = 0;
    virtual ~Icecream() = default;
};

#endif