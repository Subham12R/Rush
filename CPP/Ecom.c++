#include <iostream>
using namespace std;

class Ecommerce {
    public:
    int id;
    int price;

    Ecommerce(int id, int price) : id(id), price(price) {
        cout << "Ecommerce object created with ID: " << id << " and Price: " << price << endl;
    }
};

class Discount : public Ecommerce {
    public:
    Discount(int id, int price) : Ecommerce(id, price) {
    int discount;

        if(price > 5000){
            discount = price * 0.12;
            price -= discount;
            cout << "Discount of 12% applied. New Price: " << price << endl;
        }else if(price > 2000){
            discount = price * 0.05;
            price -= discount;
            cout << "Discount of 7% applied. New Price: " << price << endl;
        }else{
            cout << "No discount applied. Price remains: " << price << endl;
        }
    }
};


int main() {
    Discount item1(101, 6000);
    Discount item2(102, 6000);
    Discount item3(103, 3000);
    Discount item4(104, 1500);

    return 0;
}