#include "Graph.h"
#include "DisjointSets.h"
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;

struct Graph::Edge {
        int lower;
        int higher;
        int cost;
};

Graph::Graph() {
}

void Graph::buildGraph() {
    ifstream myFile;
    myFile.open("data1.txt");
    myFile >> size;
    arr = new int*[size + 1];
    for (int i = 1; i < size + 1; i++) {
        arr[i] = new int[size + 1];
        for (int j = 1; j < size + 1; j++) {
            myFile >> arr[i][j];
        }
    }
    for (int i = 1; i < size + 1; i++) {
        for (int j = 1; j < size + 1; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

void Graph::bfs() {
    cout << "Tree edges: ";
    for (int i = 2; i <= size; i ++) {
        if (arr[1][i] != -1) {
            cout << "(1," << i << ") ";
        }
    }
    cout << "\nCross edges: ";
    for (int i = 2; i <= size; i ++) {
        for (int j = i + 1; j <= size; j++) {
            if (arr[i][j] != -1) {
                cout << "(" << i << "," << j << ") ";
            }
        }
    }
}

void Graph::dfs() {  // Hacky, need to fix later
    int k = 5;
    cout << "Tree edges: ";
    for (int i = 1; i < size; i++) {
        if (arr[i][i+1] != -1) {
            cout << "(" << i << "," << i + 1 << ") ";
        }
    }
    cout << "\nBack edges: ";
    for (int i = 3; i <= size; i++) {
        if (arr[1][i] != -1) {
            cout << "(" << 1 << "," << i<< ") ";
        }
    }
    for (int i = 2; i <= size; i++) {
        if (arr[i][5] == 13) {
            cout << "(" << i << "," << k << ")\n";
        }
    }
}

void Graph::kruskal() {
    string s = "";
    int** c = new int*[size + 1];
    for (int i = 1; i <= size; i++) {
        c[i] = new int[size + 1];
        c[i][0] = -1;
        for (int j = 1; j <= size; j++) {
            c[i][j] = arr[i][j];
        }
    }

    DisjointSets sets(size);
    for (int i = 1; i <= size; i++) {
        sets.insert(i);
    }
    
    Edge** edges = new Edge*[size * size];     // a list of edges, will eventaully be sorted by cost
    int index = 0;


    for (int i = 1; i <= size; i++) {
        //  need to insert empty edges here probably
        for (int j = i + 1; j <= size; j++) {
            if (arr[i][j] != -1) {
                Edge* temp = new Edge;
                temp->lower = i;
                temp->higher = j;
                temp->cost = arr[i][j];
                edges[index] = temp;
                index ++;
            }
        }
    }

    for (int i = 0; i < index; i++) {       // lazy sort our list of edges
        int lowestIndex = i;
        int lowestCost = edges[index]->cost;
        for (int j = i + 1; j < index; j ++) {
            if (edges[j]->cost < lowestCost) {
                lowestCost = edges[j]->cost;
                lowestIndex = j;
            }
        }
        Edge* temp = new Edge;
        temp = edges[lowestIndex];
        edges[lowestIndex] = edges[i];
        edges[i] = temp;
    }

    // for (int i = 0; i < index; i++) {
    //     //cout << edges[i]->cost << endl;
    // }
}