#include <bits/stdc++.h>

using namespace std;
/*
    Open/closed principle: Open for extension and closed for modification

    Lets both the below classes are already tested, and now we have to add one more 
    function to print to file as well. we can go ahead and add another function but it voilates the open/closed principle
*/


class Invoice{
    //Marker marker;
    int quantity;
    public:
    Invoice(int q){
        quantity = q;
    }
    int calculateTotal(){
        int price = 5 * quantity;
        return price;
    }
};
/*
class InvoiceDao {  //data access object
    Invoice invoice;
    public:
    InvoiceDao(Invoice inv){
        invoice = inv;
    }
    void saveToDb(){
        // Save to DB
    }

    void saveToFile(string filename){
        // Save to file with a given name
    }
};
*/


/*
    Instaed we have to create the invoicedao class as interface and extend that interface to save to db or to file and many more.
*/

 class InvoiceDao{
    public:
        virtual void save(Invoice invoice) = 0;  //pure virtual function
        virtual ~InvoiceDao() = default; //virtual destructor
 };

 class FileInvoiceDao : public InvoiceDao{
    public:
        void save(Invoice invoice) override {
            cout << "Save to File!!"<<endl;
            // Save to File
        }
 };
 class DbInvoiceDao : public InvoiceDao{
    public:
        void save(Invoice invoice) override{
            cout << "Save to DB!!"<<endl;
            // Save to DB
        }
 };
 int main(){
    Invoice inv(10);
    FileInvoiceDao obj1;
    DbInvoiceDao obj2;

    obj1.save(inv);
    obj2.save(inv);

    //using pointers to the interface
    InvoiceDao *p1 = &obj1;
    InvoiceDao *p2 = &obj2;

    p1->save(inv);
    p2->save(inv);
    return 0;
 }