#ifndef TOPPING_H
#define TOPPING_H
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;


class Topping {

  private:
    string name;
    double price;

  public:
    Topping();
    Topping(string name, double price);
    string getName();
    double getPrice();

    void setName(string name);
    void setPrice(double price);

    friend ifstream& operator >> (ifstream& fin, Topping& topping);
    friend ofstream& operator << (ofstream& fout, Topping& topping);
};


#endif // TOPPING_H
