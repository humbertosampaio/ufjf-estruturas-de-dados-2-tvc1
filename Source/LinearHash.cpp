//
// Created by edson on 13/04/18.
//

#include "../Headers/LinearHash.h"

void LinearHash::insert(int value)
{
    if (elementCounter < size) {
        if (quadratic) insertQuadratic(value);
        else insertLinear(value);
        ++elementCounter;
    }
    else
        cout << "hash cheio, nao foi possivel inserir " << value << endl;
}

void LinearHash::insertLinear(int value)
{
    unsigned int key = Hash::keyFunction(value);
    if (hashTable[key] == 0)
        hashTable[key] = value;
    else
    {
        for (int i = key + 1; i <= size  + key; ++i)
            if (hashTable[i % size] == 0) {
                hashTable[i % size] = value;
                break;
            }
        ++collisionCounter;
    }
}

void LinearHash::insertQuadratic(int value)
{
    unsigned int key = Hash::keyFunction(value);
    if (hashTable[key] == 0)
        hashTable[key] = value;
    else
    {
        int i = 1;
        while (hashTable[key+(i*i) % size] != 0){
            ++i;
            }
        hashTable[key+(i*i) % size] = value;
        ++collisionCounter;
    }
}

void LinearHash::printElements()
{
    for (int i = 0; i < size; ++i)
    {
        cout << i << ":";
        if (hashTable[i] != 0)
           cout <<" " << hashTable[i];
        cout << endl;
    }
}