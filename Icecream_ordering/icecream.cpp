#include <bits/stdc++.h>
#include "icecream.h"
using namespace std;


class VanillaIcecream : public Icecream{  //Is a relationship with Ibase
    public:
    string getDescrition(){
        return "Vanilla Ice cream";
    }
    int cost(){
        return 100;
    }
};

class StrawberryIcecream : public Icecream{ //Is a relationship with Ibase
    public:
    string getDescrition(){
        return "Strawberry Ice cream";
    }
    int cost(){
        return 200;
    }
};