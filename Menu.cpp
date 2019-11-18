//
//  Author: Taylor Bauer
//  Date:   12.8.2019
//          EECS 560
//          Lab 11
//

#include "Menu.h"
#include <iostream>
using namespace std;
//#include "BinomialHeap.h"

Menu::Menu(BinomialHeap h) {
    heap = h;
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
            cout << "What value would you like to insert (positive, unique integers only please): ";
            int insertion = 0;
            cin >> insertion;
            heap.insert(insertion);
            cout << "Successfully inserted " << insertion << " into the heap!\n";
            
        }
        else if (selection == 2) {
           cout << "Deleting minimum value from the heap...\n";
           heap.deleteMin();
           cout << "Success!\n";
        }
        else if (selection == 3) {
            cout << "Here is the heap in level-order:\n";
            heap.print();


        }
        else {
            cout << "\n\n~~Goodbye~~\n\n";
        }
    }
}
