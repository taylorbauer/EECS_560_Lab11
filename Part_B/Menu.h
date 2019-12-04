//
//  Author: Taylor Bauer
//  Date:   12.8.2019
//          EECS 560
//          Lab 11
//

#ifndef MENU_H
#define MENU_H
#include "DisjointSets.h"


//  The class that handles all user interaction and manages the heap
class Menu {
public:

    // Constructor that requires a pre-existing heap
    Menu(DisjointSets sets);

    //  Run the menu.  This is where all user interaction takes place.
    void run();
private:
    DisjointSets set;

};

#endif