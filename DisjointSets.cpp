#include "DisjointSets.h"
#include <iostream>
using namespace std;

DisjointSets::DisjointSets() {
    pointers = new Node*[1000];
}

DisjointSets::DisjointSets(int size) {
    pointers = new Node*[size];
}

void DisjointSets::insert(int value) {
    Node* tempNode = new Node(value);
    tempNode->parent = tempNode;
    pointers[value] = tempNode;
    return;
}

bool DisjointSets::unionize(int first, int second) {
    if (first > 1000 || second > 1000 || first < 1 || second < 1) {
        return false;
    }

    pointers[second]->parent = pointers[first];

    return true;
}

int DisjointSets::findWithoutCompression(int key) {
    if (key < 1 || key > 1000) {
        return -1;
    }
    else {
        if (pointers[key]->parent == pointers[key]) {
            return pointers[key]->key;
        }
        else {
            return find(pointers[key]->parent->key);
        }
    }
}

int DisjointSets::find(int key) {
    if (key < 1 || key > 1000) {
        return -1;
    }
    else {
        if (pointers[key]->parent == pointers[key]) {
            return pointers[key]->key;
        }
        else {
            int root = -1;
            root = find(pointers[key]->parent->key);
            pointers[key]->parent = pointers[root];
            return root;
        }
    }
}