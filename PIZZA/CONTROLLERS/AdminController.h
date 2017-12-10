#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H
#include "AdminUI.h"
#include "HomeController.h"
#include "GlobalHelp.h"
#include "pizzadata.h"
#include "ToppingData.h"
#include "LocationData.h"
#include <stdlib.h>
#include "Pizza.h"
#include "BreadsticksData.h"
#include "SodaData.h"
#include "CrustData.h"
#include "GlobalController.h"

using namespace GlobalHelp;
using namespace AdminUI;

class AdminController {
  private:
    PizzaData pizzaData;
    ToppingData toppingData;
    LocationData locationData;
    BreadsticksData breadsticksData;
    SodaData sodaData;
    CrustData crustData;
    GlobalController globalController;

  public:
    AdminController();
    void init();

    void modifyPizzas();
    void addPizzaToMenu();
    void removePizzaFromMenu();
    void pizzaBackFunction();

    void modifyToppings();
    void addTopping();
    void removeTopping();
    void toppingBackFunction();

    void modifyBreadsticks();
    void displayAllBreadsticks();
    void addBreadsticksToMenu();
    void removeBreadsticksFromMenu();
    void breadsticksBackFunction();

    void modifySodas();
    void addSodaToMenu();
    void removeSodaFromMenu();
    void sodaBackFunction();

    void modifyLocations();
    void displayAllLocations();
    void addLocations();
    void removeLocations();

    void modifyCrust();
    void displayAllCrusts();
    void addCrustToMenu();
    void removeCrustFromMenu();
    void crustBackFunction();

    void locationBackFunction();

};

#endif // ADMINCONTROLLER_H
