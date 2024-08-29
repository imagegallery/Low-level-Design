#include <bits/stdc++.h>
#include "icecream.cpp"
#include "decoration.cpp"
using namespace std;

int main(){
    Icecream *b = new VanillaIcecream();
    cout << "order: " << b->getDescrition() << ", cost Rs: " << b->cost() << endl;
    
    Icecream *chocolate = new ChocolateDecorator(b);
    cout << "order: " << chocolate->getDescrition() << ", cost Rs: " << chocolate->cost() << endl;
    
    Icecream *caramel = new CaramelDecorator(chocolate);
    cout << "order: " << caramel->getDescrition() << ", cost Rs: " << caramel->cost() << endl;
    
    //cout << "base cost is: " <<  b->cost() << endl;
    
}