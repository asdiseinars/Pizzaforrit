#include "GlobalHelp.h"

void GlobalHelp::clearScreen() {

    system("cls");
}

void GlobalHelp::displayLogo(){
    cout << "  _____ _                _  ___ _       _                 " << endl;
    cout << " |  __ (_)              | |/ (_) |     | |                " << endl;
    cout << " | |__) | __________ _  | ' / _| |_ ___| |__   ___ _ __   " << endl;
    cout << " |  ___/ |_  /_  / _` | |  < | | __| __| '_   / _  '_   | " << endl;
    cout << " | |   | |/ / / / (_| | | .  | | || (__| | | |  __/ | | | " << endl;
    cout << " |_|   |_/___/___|__,_| |_||_|_|___|___|_| |_||___|_| |_| " << endl;
    cout << endl << endl;
}

void GlobalHelp::displayAdminLogo(){
    cout << "---- ADMIN -----" << endl;
}
