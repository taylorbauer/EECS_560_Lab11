#ifndef DISJOINT_SETS_H
#define DISJOINT_SETS_H
#include "Node.h"

class DisjointSets {
public:
    DisjointSets();
    DisjointSets(int size);
    void insert(int value);
    Node** pointers;
    bool unionize(int first, int second);
    int find(int key);
    int findWithoutCompression(int key);
};

#endif