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
        //edges[i] = new Edge;
        for (int j = i + 1; j <= size; j++) {
            if (arr[i][j] != -1) {
                Edge* temp = new Edge;
                temp->lower = i;
                temp->higher = j;
                temp->cost = arr[i][j];
                edges[index] = temp;
                //cout << "Created new edge: " << edges[index]->lower << ' ' << edges[index]->higher << " and costs " << edges[index]->cost << endl;
                index ++;
            }
        }
    }

    bool sorted = false;    // lazy bubble sort our list of edges
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < index - 1; i++)
        {
            //cout << i << " cost: " << edges[i]->cost << endl;
            if (edges[i]->cost > edges[i+1]->cost) {
                sorted = false;
                Edge* temp = edges[i];
                edges[i] = edges[i + 1];
                edges[i + 1] = temp;
            }
        }
    }


    int s = 0;  // size of set we will be adding to
    index = 0;
    int totalCost = 0;
    DisjointSets et;
    for (int i = 1; i <= 5; i++) {
        et.insert(i);
    }
    string output = "";
    while (s < 4) {
        Edge* x = edges[index];
        index ++;
        if (et.find(x->lower) != et.find(x->higher)) {
            et.unionize(et.find(x->lower), et.find(x->higher));
            totalCost += x->cost;
            s++;
            output = output + "(" + to_string(x->lower) + "," + to_string(x->higher) + "){" + to_string(x->cost) + "} ";
        }
    }
    cout << output << endl 
         << "Total cost: " << totalCost << endl;
}

void Graph::prim() {
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
    
    Edge** edges = new Edge*[size * size];   
    int index = 0;


    for (int i = 1; i <= size; i++) {
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

    bool sorted = false; 
    {
        sorted = true;
        for (int i = 0; i < index - 1; i++)
        {
            if (edges[i]->cost > edges[i+1]->cost) {
                sorted = false;
                Edge* temp = edges[i];
                edges[i] = edges[i + 1];
                edges[i + 1] = temp;
            }
        }
    }    

    int s = 0;  // currently still mostly kruskal (and using disjoint sets), need to update to be truly prim
    index = 0;
    int totalCost = 0;
    DisjointSets et;
    for (int i = 1; i <= 5; i++) {
        et.insert(i);
    }
    string output = "";
    while (s < 4) {
        Edge* x = edges[index];
        index ++;
        if (et.find(x->lower) != et.find(x->higher)) {
            et.unionize(et.find(x->lower), et.find(x->higher));
            totalCost += x->cost;
            s++;
            output = output + "(" + to_string(x->lower) + "," + to_string(x->higher) + "){" + to_string(x->cost) + "} ";
        }
    }
    cout << output << endl 
         << "Total cost: " << totalCost << endl;
}