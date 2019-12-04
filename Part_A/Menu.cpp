//
//  Author: Taylor Bauer
//  Date:   12.8.2019
//          EECS 560
//          Lab 11
//

#include "Menu.h"
#include <ctime>
#include <iostream>
#include <chrono>
using namespace std;
#include "DisjointSets.h"

Menu::Menu(DisjointSets sets) {
    set = sets;
}

void Menu::run() {
    cin.clear();
    int selection = 0;
    cout << "\nWelcome!\n";
    while (selection < 7 && selection >= 0) {
        cout << "\nPlease choose one of the following commands:\n"
            << "1. MakeSet\n"
            << "2. Union\n"
            << "3. Find_Timer\n"
            << "4. Path Compression\n"
            << "5. (For Lab report) Join all 1000 sets into 1\n"
            << "6. (For Lab report) Call (and time) find on all 1000 elements\n"
            << "7. Exit\n"
            << "Your selection: ";
        cin >> selection;
        if (selection == 1) {
            cout << "The disjoint sets have been constructed\n";
        }
        else if (selection == 2) {
            cout << "Enter the representative elements for the two sets which you wish to union (they should be between 1 and 1000):\n";
            cout << "First representative element: ";
            int first;
            cin >> first;
            cout << "Second representative element: ";
            int second;
            cin >> second;
            if (set.unionize(first, second)) {
                cout << first << " and " << second << " have been merged successfully!\n";
            }
            else {
                cout << "Unable to merge " << first << " and " << second << ", make sure they are representative elements of sets.\n";
            }
        }
        else if (selection == 3) {
            cout << "What element would you like to find the set representative element of?\n";
            cout << "(Note: elements are numbered 1 to 1000, inclusive)\n";
            cout << "Search term: ";
            int input;
            cin >> input;
            clock_t time_req = clock();
            int root = set.find(input);
            time_req = clock() - time_req;
            if (root == -1) {
                cout << "Unable to find representative of " << input << ". Please make sure it is in range and try again.\n";
            }
            else {
                cout << "The representative of the set containing " << input << " is " << root << ".\n";
                cout << "It took " << (float)time_req/CLOCKS_PER_SEC * 1000 << " ms to find.\n";
            }
        }
        else if (selection == 4) {
            cout << "Which element would you like to perform path compression on? ";
            int input;
            cin >> input;
            if (set.find(input) != -1) {
                cout << "Successfully performed path compression on " << input << ".\n";
            }
            else {
                cout << "Unable to find " << input << ".\n";
            }
        }
        else if (selection == 5) {
            cout << "Starting...\n";
            for (int i = 1; i < 1000; i++) {
                set.unionize(i, i + 1);
            }
            cout << "Done!\n";
        }
        else if (selection == 6) {
            for (int i = 1; i <= 1000; i++) {
                auto start = chrono::high_resolution_clock::now(); 
                set.findWithoutCompression(i);
                auto stop = chrono::high_resolution_clock::now(); 
                auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start); 
                cout << duration.count() << endl;

            }
        }
        else {
            cout << "\n\n~~Goodbye~~\n\n";
        }
    }
}
