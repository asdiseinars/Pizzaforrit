#include <fstream>
#include "Topping.h"

Topping::Topping() {
    name = '\0';
    price = 0;
    verbose = true;
}

Topping::Topping(string name, double price) {
    this->name = name;
    this->price = price;
}

string Topping::getName() {
    return name;
}
double Topping::getPrice() {
    return price;
}

void Topping::setName(string name) {
    this->name = name;
}

void Topping::setPrice(double price) {
    this->price = price;
}

void Topping::setVerbose(bool verbose) {
    this->verbose = verbose;
}

ifstream& operator >> (ifstream& in, Topping& topping) {
    in >> ws;
    getline(in, topping.name);

    in >> topping.price;

    return in;
}

ofstream& operator << (ofstream& out, Topping& topping) {
    out << topping.name << endl;
    out << topping.price << endl;

    return out;
}

istream& operator >> (istream& in, Topping& topping) {
    if(topping.verbose)
        cout << "Topping name: ";
    in >> ws;
    getline(in, topping.name);

    if(topping.verbose)
        cout << "Topping price: ";
    in >> topping.price;

    return in;
}

ostream& operator << (ostream& out, Topping& topping) {
    cout << "Topping: ";
    out << topping.name << endl;

    cout << "Price: ";
    out << topping.price << endl;

    return out;
}

