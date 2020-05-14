#pragma once
#include <iostream>
#include "Columns.h"

class ShellSort {
public:
    static int gap;
    static int loopCounter;

    static void sort(vector<Columns>& columns) {
        int temp = columns[loopCounter].number;
        int j;
        for (j = loopCounter; j >= gap && columns[j - gap].number > temp; j -= gap)
            columns[j].number = columns[j - gap].number;
        columns[j].number = temp;
        loopCounter++;
        if (loopCounter >= (int)columns.size()) {
            gap /= 2;
            loopCounter = gap;
        }
    }
};