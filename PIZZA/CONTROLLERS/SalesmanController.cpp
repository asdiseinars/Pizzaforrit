#include "SalesmanController.h"

SalesmanController::SalesmanController() {
    //ctor
}

void SalesmanController::endMessage() {
    cout << "Press any button if you would like to continue" << endl;
    cout << "Press q to quit" << endl;

    char input = '\0';
    cin >> input;

    if (input == 'q') {
        return;
    }
    else {
        clearScreen();
        displayLogo();
        displaySalesmanLogo();
    }
}

void SalesmanController::init() {
    displayLogo();
    displaySalesmanLogo();
    string yourLocation = globalController.chooseLocation();
    modifySalesman(yourLocation);

}

void SalesmanController::modifySalesman(string yourLocation) {
    clearScreen();
    displayLogo();
    displaySalesmanLogo();

    cout << "\e[1m" << "Your location is " << yourLocation << "\e[0m" << endl << endl;
    displayStepsOfOrdering();
    string phoneNumber = "";

    endMessage();

    cout << "\e[1m" << "Your location is " << yourLocation << "\e[0m" << endl << endl;
    cout << "\e[1m" << "STEP 1: " << "\e[0m";
    cout << "Input phone number (7 digits): " << endl << endl;

    cin >> phoneNumber;
    while(phoneNumber.length() != 7) {
        cin >> phoneNumber;
        cout << "Invalid phone number!";
    }
    cout << endl;

    endMessage();

    cout << "\e[1m" << "Your location is " << yourLocation << "\e[0m" << endl << endl;
    cout << "\e[1m" << "STEP 2: " << "\e[0m";
    cout << "Order pizza/s from menu" << endl << endl;

    cout << "PIZZA MENU" << endl;
    cout << "------------------------------------------" << endl;
    globalController.displayAllPizzas();
    cout << "------------------------------------------" << endl;

    int pizzaFromMenuCount = getPizzaFromMenuCount();
    vector<Pizza> pizzasToOrder = orderPizzaFromMenu(pizzaFromMenuCount);
    cout << "Current Price: " << getTotalPriceOfPizzasFromMenu(pizzasToOrder);

    cout << endl << endl;

    endMessage();

    cout << "\e[1m" << "Your location is " << yourLocation << "\e[0m" << endl << endl;
    cout << "\e[1m" << "STEP 3: " << "\e[0m";
    cout << "Order pizza/s made from scratch" << endl << endl;

    int pizzasFromScratchCount = getPizzaFromScratchCount();

    cout << endl;

    vector<Pizza> pizzasFromScratchOrder = orderPizzaFromScratch(pizzasFromScratchCount);
    cout << "Current price: " << getTotalPriceOfPizzasFromScratch(pizzasFromScratchOrder);

    cout << endl << endl;

    endMessage();

    cout << "\e[1m" << "Your location is " << yourLocation << "\e[0m" << endl << endl;
    cout << "\e[1m" << "STEP 4: " << "\e[0m";
    cout << "Order side orders" << endl << endl;

    int breadsticksCount = getBreadsticksCount();
    cout << endl;
    vector<Breadsticks> breadsticksToOrder = orderBreadsticksFromMenu(breadsticksCount);
    cout << endl << "Current Price: " << getTotalPriceOfBreadsticks(breadsticksToOrder) + getTotalPriceOfPizzasFromScratch(pizzasFromScratchOrder);

    cout << endl << endl;

    endMessage();

    cout << "\e[1m" << "Your location is " << yourLocation << "\e[0m" << endl << endl;
    cout << "\e[1m" << "STEP 5: " << "\e[0m";
    cout << "Order drinks" << endl << endl;

    int sodaCount = getSodaCount();
    vector<Soda> sodasToOrder = orderSodaFromMenu(sodaCount);
    cout << endl;

    cout << "Current price: " << getTotalPriceOfSodas(sodasToOrder) + getTotalPriceOfBreadsticks(breadsticksToOrder) + getTotalPriceOfPizzasFromScratch(pizzasFromScratchOrder);

    cout << endl << endl;

    endMessage(); ///eitthva� lost eftir �etta

    double totalPrice = getTotalPriceOfPizzasFromMenu(pizzasToOrder) + getTotalPriceOfPizzasFromScratch(pizzasFromScratchOrder) + getTotalPriceOfBreadsticks(breadsticksToOrder)
                        + getTotalPriceOfSodas(sodasToOrder);
    cout << "Total price: " << totalPrice << endl;

    int orderStatus = 1;

    clearScreen();

    displayLogo();
    ///complete order
    //display

    Order newOrder(yourLocation, pizzasToOrder, pizzaFromMenuCount, pizzasFromScratchOrder, pizzasFromScratchCount,
                    breadsticksToOrder, breadsticksCount, sodasToOrder, sodaCount, totalPrice, orderStatus, phoneNumber);
    orderData.addOrderToOrders(newOrder);

}

int SalesmanController::getPizzaFromMenuCount() {
    cout << "How many pizzas do you want to order from menu? " << endl;
    int pizzasFromMenuCount = 0;
    cin >> pizzasFromMenuCount;
    return pizzasFromMenuCount;
}

vector<Pizza> SalesmanController::orderPizzaFromMenu(int pizzasFromMenuCount) {
    vector<Pizza> pizzas = pizzaData.retrieveAllPizzas();

    vector<Pizza> pizzaToOrder;

    cout << "What pizzas do you want to add to your order? " << endl;
    int input = 0;
    for(int i = 0; i < pizzasFromMenuCount; i++) {
        cin >> input;
        input -= 1;
        pizzaToOrder.push_back(pizzas.at(input));
    }

    return pizzaToOrder;
}

double SalesmanController::getTotalPriceOfPizzasFromMenu(vector<Pizza> pizzasFromMenu) {
    double sumOfOrder = 0;
    for(unsigned int i = 0; i < pizzasFromMenu.size(); i++) {
        sumOfOrder += pizzasFromMenu[i].getPrice();
    }
    return sumOfOrder;
}

int SalesmanController::getPizzaFromScratchCount() {
    cout << "How many pizzas do you want to make from scratch? " << endl;
    int pizzasFromScratchCount = 0;
    cin >> pizzasFromScratchCount;
    return pizzasFromScratchCount;
}

vector<Pizza> SalesmanController::orderPizzaFromScratch(int pizzasFromScratchCount) {
    vector<Pizza> pizzaToOrderFromScratch;

    for(int i = 0; i < pizzasFromScratchCount; i++) {
        string myName = "Customized";
        vector<Topping> myToppings;
        double myPrice = 3400;

        cout << endl;

        cout << "CRUSTS" << endl;
        cout << "------------------------------------------" << endl;
        vector<Crust> crusts = crustData.retrieveAllCrusts();
        for(unsigned int i = 0; i < crusts.size(); i++) {
            Crust crust = crusts.at(i);
            cout << "[" << i+1 << "]: " << crust.getName() << "\t" << crust.getPrice() << " kr." << endl;
        }
        cout << "------------------------------------------" << endl;

        char inputCrust;
        cout << "Please select a crust." << endl;
        cin >> inputCrust;
        int inputIntCrust = inputCrust - 48;
        Crust myCrust = crusts.at(inputIntCrust - 1);

        cout << "TOPPINGS" << endl;
        cout << "------------------------------------------" << endl;
        vector<Topping> toppings = toppingData.retrieveAllToppings();
        for(unsigned int i = 0; i < toppings.size(); i++) {
            Topping topping = toppings.at(i);
            cout << "[" << i+1 << "]: " << topping.getName() << "\t" << topping.getPrice() << " kr." << endl;
        }
        cout << "------------------------------------------" << endl;

        int toppingCount = 0;
        int inputTopping = 0;

        cout << endl << "How many toppings do you want to add to your pizza?" << endl;
        cin >> toppingCount;

        cout << "Please enter the number of toppings you want to add to your pizza. " << endl;
        for(int i = 0; i < toppingCount; i++) {
        cin >> inputTopping;
        Topping topping = toppings.at(inputTopping - 1);
        cout << "Name: " << topping.getName() << "\t" <<"Price: " << topping.getPrice() << endl;
        myToppings.push_back(topping);
    }

        Pizza newPizza(myName, myPrice, toppingCount, myToppings, myCrust);
        pizzaToOrderFromScratch.push_back(newPizza);
    }

    return pizzaToOrderFromScratch;
}

double SalesmanController::getTotalPriceOfPizzasFromScratch(vector<Pizza> pizzasFromScratch) {
    double startingPizzaPrice = 1500;
    double sumOfOrder = 0;
    for(unsigned int i = 0; i < pizzasFromScratch.size(); i++) {
        sumOfOrder += startingPizzaPrice;
        sumOfOrder += pizzasFromScratch[i].getCrust().getPrice();
        for(unsigned int j = 0; j < pizzasFromScratch[i].getToppings().size(); j++) {
            sumOfOrder += pizzasFromScratch[i].getToppings()[j].getPrice();
        }
    }
    return sumOfOrder;
}

int SalesmanController::getBreadsticksCount() {
    cout << "How many side orders do you want to order? " << endl;
    int breadsticksCount = 0;
    cin >> breadsticksCount;
    return breadsticksCount;
}

vector<Breadsticks> SalesmanController::orderBreadsticksFromMenu(int breadsticksCount) {
    vector<Breadsticks> breadsticks = breadsticksData.retrieveAllBreadsticks();
    globalController.displayAllBreadsticks();

    vector<Breadsticks> breadsticksToOrder;

    cout << "What side order do you want to add to your order? " << endl;
    int input = 0;
    for(int i = 0; i < breadsticksCount; i++) {
        cin >> input;
        input -= 1;
        breadsticksToOrder.push_back(breadsticks.at(input));
    }

    return breadsticksToOrder;
}

double SalesmanController::getTotalPriceOfBreadsticks(vector<Breadsticks> breadsticks) {
    double sumOfOrder = 0;
    for(unsigned int i = 0; i < breadsticks.size(); i++) {
        sumOfOrder += breadsticks[i].getPrice();
    }
    return sumOfOrder;
}

int SalesmanController::getSodaCount() {
    cout << "How many sodas do you want to order? " << endl;
    int sodaCount = 0;
    cin >> sodaCount;

    return sodaCount;
}

vector<Soda> SalesmanController::orderSodaFromMenu(int sodaCount) {
    vector<Soda> sodas = sodaData.retrieveAllSodas();
    globalController.displayAllSodas();

    vector<Soda> sodasToOrder;

    cout << "What soda do you want to add to your order? " << endl;
    int input = 0;
    for(int i = 0; i < sodaCount; i++) {
        cin >> input;
        input -= 1;
        sodasToOrder.push_back(sodas.at(input));
    }
    return sodasToOrder;
}

double SalesmanController::getTotalPriceOfSodas(vector<Soda> sodas) {
    double sumOfOrder = 0;
    for(unsigned int i = 0; i < sodas.size(); i++) {
        sumOfOrder += sodas[i].getPrice();
    }
    return sumOfOrder;
}
