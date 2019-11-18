#include "DisjointSets.h"

DisjointSets::DisjointSets() {
    pointers = new Node*[8];
}

DisjointSets::DisjointSets(int size) {
    pointers = new Node*[size];
}

void DisjointSets::insert(int value) {
    Node* tempNode = new Node(value);
    pointers[value] = tempNode;
    return;
}