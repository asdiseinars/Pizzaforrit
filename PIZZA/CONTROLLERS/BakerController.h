#ifndef BAKERCONTROLLER_H
#define BAKERCONTROLLER_H
#include "BakerUI.h"
#include "HomeController.h"
#include "GlobalHelp.h"
#include "Location.h"
#include "LocationData.h"
#include <iostream>

using namespace GlobalHelp;
using namespace BakerUI;
using namespace std;

class BakerController {
  private:

  public:
    BakerController();
    void init();
    void chooseLocation();

};

#endif // BAKERCONTROLLER_H
