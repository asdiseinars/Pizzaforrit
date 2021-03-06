#ifndef ORDER_H
#define ORDER_H
#include "Breadsticks.h"
#include "Crust.h"
#include "Location.h"
#include "Order.h"
#include "Pizza.h"
#include "Soda.h"
#include "Topping.h"
#include <string>

class Order {
  private:
    string location;
    vector<Pizza> pizzasFromMenu;
    int pizzasFromMenuCount;
    vector<Pizza> pizzasFromScratch;
    int pizzasFromScratchCount;
    vector<Breadsticks> breadsticks;
    int breadsticksCount;
    vector<Soda> sodas;
    int sodasCount;
    double totalPrice;
    int orderStatus;
    string phoneNumber;


  public:
    Order();
    Order(string location, vector<Pizza> pizzasFromMenu, int pizzasFromMenuCount, vector<Pizza> pizzasFromScratch, int pizzasFromScratchCount,
          vector<Breadsticks> breadsticks, int breadsticksCount, vector<Soda> sodas, int sodasCount, double totalPrice, int orderStatus,
          string phoneNumber);

    void setLocation(string location);
    void setPizzasFromMenu(vector<Pizza> pizzasFromMenu);
    void setPizzasFromScratch(vector<Pizza> pizzasFromScratch);
    void setBreadsticks(vector<Breadsticks> breadsticks);
    void setSodas(vector<Soda> sodas);
    void setOrderStatus(int orderStatus);
    void setPhoneNumber(string phoneNumber);

    string getLocation();
    vector<Pizza> getPizzasFromMenu();
    vector<Pizza> getPizzasFromScratch();
    vector<Breadsticks> getBreadsticks();
    vector<Soda> getSodas();
    double getTotalPrice();
    int getOrderStatus();
    string getPhoneNumber();

    friend ofstream& operator << (ofstream& fout, Order& order);
    friend ifstream& operator >> (ifstream& fin, Order& order);
};

#endif // ORDER_H
