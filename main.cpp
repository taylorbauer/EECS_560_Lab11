//
//  Author: Taylor Bauer
//  Date:   12.8.2019
//          EECS 560
//          Lab 11
//

#include <iostream>
#include <fstream>
#include <chrono>
#include "Menu.h"
#include "DisjointSets.h"
//#include "BinomialHeap.h"


using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "\nPlease make sure you are including a filename in the command line!\n";
        cout << "Ex: ./Lab11 data.txt\n\n";
        return 0;
    }

    fstream myFile;
    myFile.open(argv[1]);

    if (!myFile) {
        cout << "\nError opening file! Please make sure it is a valid file and try again.\n\n";
        return 0;
    }
    else {
        cout << "\nSuccessfully opened file.\n\n";
    }

    int valueCount = 0;
    int currentValue = ' ';
    while (!myFile.eof()){
        myFile >> currentValue;
        valueCount ++;
    }
    
    myFile.close();
    myFile.open(argv[1]);

    int tempArr[valueCount];

    for (int i = 0; i < valueCount; i++) {
        myFile >> tempArr[i];
    }
    myFile.close();

    for (int i = 0; i < valueCount; i++) {
        for (int j = 0; j < valueCount; j ++) {
            if (i != j && tempArr[i] == tempArr[j]) {
                cout << argv[1] << " contains multiple entries of \"" << tempArr[i] << "\"\n";
                cout << "Please make sure datafile does not contain duplicate elements!\n";
                return 0;
            }
        }
    }

    int largest = 0;

    for (int i = 0; i < valueCount; i++) {
        if (tempArr[i] > largest) {
            largest = tempArr[i];
        }
    }

    DisjointSets set(largest);

    for (int i; i < valueCount; i++) {
        set.insert(tempArr[i]);
    }
    
    Menu mainMenu(set);
    mainMenu.run();

    return 0;
}