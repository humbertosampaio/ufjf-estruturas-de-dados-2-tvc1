//
// Created by edson on 13/04/18.
//

#include "HashSeparated.h"

HashSeparated::HashSeparated(unsigned int size)
{
    this->size = size;
    collisionTable = new Vertex[size];
    hashTable = new int[size];
    collisionCounter = 0;
    for (int i = 0; i < size; ++i)
        hashTable[i] = 0;
}

HashSeparated::~HashSeparated()
{
    delete []collisionTable;
    delete []hashTable;
}

unsigned int HashSeparated::keyFunction(int value)
{
    return value%size;
}

void HashSeparated::insert(int value)
{
    unsigned int key = keyFunction(value);
    if (hashTable[key] == 0)
        hashTable[key] = value;
    else
    {
        ++collisionCounter;
        Vertex* vertex = &collisionTable[key];
        if (vertex->value == 0)
            vertex->value = value;
        else {
            while (vertex->next != nullptr)
                vertex = vertex->next;
            vertex->next = new Vertex(value, nullptr);
        }
    }
}

void HashSeparated::printElements()
{
    Vertex* vertex;
    for (int i = 0; i < size; ++i)
    {
        cout << i+1 << ": ";
        if (hashTable[i] != 0) {
            cout << hashTable[i];
            cout << endl;
        }
        vertex = &collisionTable[i];
        if (vertex->value != 0) {
            cout << "colisoes: ";
            while (vertex != nullptr) {
                cout << vertex->value << " ";
                vertex = vertex->next;
            }
            cout << endl;
        }
    }
}