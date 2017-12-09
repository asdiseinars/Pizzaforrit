#ifndef SALESMANCONTROLLER_H
#define SALESMANCONTROLLER_H
#include <iostream>
#include "SalesmanUI.h"
#include "HomeController.h"
#include "GlobalHelp.h"
#include "GlobalController.h"
#include "Location.h"
#include "LocationData.h"

using namespace GlobalHelp;
using namespace std;
using namespace SalesmanUI;


class SalesmanController {
  private:
      LocationData locationData;
      GlobalController globalController;

  public:
    SalesmanController();
    void chooseLocation();
    void init();
    void modifySalesman(string yourLocation);


};

#endif // SALESMANCONTROLLER_H
