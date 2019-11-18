//
//  Author: Taylor Bauer
//  Date:   12.8.2019
//          EECS 560
//          Lab 11
//

#include "Menu.h"
#include <iostream>
using namespace std;
#include "DisjointSets.h"

Menu::Menu(DisjointSets sets) {
    set = sets;
}

void Menu::run() {
    cin.clear();
    int selection = 0;
    cout << "\nWelcome!\n";
    while (selection < 4 && selection >= 0) {
        cout << "\nPlease choose one of the following commands:\n"
            << "1. Insert\n"
            << "2. DeleteMin\n"
            << "3. LevelOrder\n"
            << "4. Exit\n"
            << "Your selection: ";
        cin >> selection;
        if (selection == 1) {
            
        }
        else if (selection == 2) {

        }
        else if (selection == 3) {

        }
        else {
            cout << "\n\n~~Goodbye~~\n\n";
        }
    }
}
