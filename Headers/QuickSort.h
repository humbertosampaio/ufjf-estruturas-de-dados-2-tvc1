//
// Created by viniman on 11/04/18.
//

#ifndef TRABALHO_ED2_QUICKSORT_H
#define TRABALHO_ED2_QUICKSORT_H

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include "Question.h"

class QuickSort {
public:
    template<class T> static void quickSort(vector<T> &vet, int began, int end);
    template<class T> static void quickSortMediana(vector<T> &values, int began, int end, int k);
    template<class T> static void quickSortInsercao(vector<T> &vet, int began, int end, int k);
};


#endif //TRABALHO_ED2_QUICKSORT_H
