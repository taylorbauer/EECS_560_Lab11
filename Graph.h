#ifndef GRAPH_H
#define GRAPH_H
#include "DisjointSets.h"

class Graph {
public:
    Graph();
    struct Edge;
    void buildGraph(); // Build graph from data in data1.txt
    void bfs();
    void dfs();
    void kruskal();
    int size;
    int** arr;
};

#endif