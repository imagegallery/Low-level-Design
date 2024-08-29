#include <bits/stdc++.h>

using namespace std;
// Single Responsibity Principle
// A class should have only one responsibility to change

/*
    1) As soon as we need to handle discount and tax details, we need to change the calculateTotal method.
    2) As we change the calculateTotal we need to reprint or change domething in print function
    3) Now we need to save to file as well, so we need changes in save to DB as well.
*/
class Marker{
    string name;
    string color;
    int year;
    int price;
    
    public:

    Marker(string name, string color, int year, int price){
        name = name;
        color = color;
        year = year;
        price = price;
    }
}; 

class Invoice{
    Marker marker;  //has a relation with Marker
    int quantity;
    public:
    Invoice(Marker m, int q){
        marker = m;
        quantity = q;
    }
    int calculateTotal(){
        return (marker.price) * quantity;
    }
    void printInvoice(){
        // Print thr invoice
    }
    void saveToDb(){
        // Save the data tp DB
    }
};



// To follow the SRP
/*  
    Break down the responsibility of each classes so that it becomes easy to maintain and easy to understand
*/

class Invoice{
    Marker marker;
    int quantity;
    public:
    Invoice(Marker m, int q){
        marker = m;
        quantity = q;
    }
    int calculateTotal(){
        int price = marker.price * quantity;
        return price;
    }
};
class InvoiceDao {  //data access object
    Invoice invoice;
    public:
    InvoiceDao(Invoice inv){
        invoice = inv;
    }
    void saveToDb(){
        // Save to DB
    }
};

class InvoicePrinter{
    Invoice invoice;
    public:
    InvoicePrinter(Invoice inv){
        invoice = inv;
    }
    void print(){
        // Print the invoice
    }
};
