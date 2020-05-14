#pragma once
#include <iostream>
#include "Columns.h"

class InsertionSort {
public:
    static double loopCounter;

    static void sort(vector<Columns>& columns){
        int key, j;
        key = columns[(int)loopCounter].number;
        j = (int)loopCounter - 1;

        while (j >= 0 && columns[j].number > key){
            columns[j + 1].number = columns[j].number;
            j = j - 1;
        }
        columns[j + 1].number = key;
        loopCounter++;
    }
};