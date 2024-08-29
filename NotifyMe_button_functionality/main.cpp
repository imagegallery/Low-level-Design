#include <bits/stdc++.h>
#include "observable.cpp"

using namespace std;

int main(){
    Istock *iphonestock = new IphoneImpl();

    Inotification *observer1 = new EmailAlert("xyz1@gmail.com", iphonestock);
    Inotification *observer2 = new EmailAlert("xyz2@gmail.com", iphonestock);
    Inotification *observer3 = new MobileAlert("xyz_username", iphonestock);

    iphonestock->add(observer1);
    iphonestock->add(observer2);
    iphonestock->add(observer3);

    iphonestock->setStockCount(1);
    iphonestock->setStockCount(10);
    cout << iphonestock->getStockCount() << endl;
}