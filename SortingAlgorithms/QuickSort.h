#pragma once
#include <iostream>
#include "Columns.h"

class QuickSort {
public:
    static void swap(int* a, int* b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }

    static int partition(vector<Columns>& columns, int low, int high)
    {
        int pivot = columns[high].number; // pivot  
        int i = (low - 1); // Index of smaller element  

        for (int j = low; j <= high - 1; j++)
        {
            // If current element is smaller than the pivot  
            if (columns[j].number < pivot)
            {
                i++; // increment index of smaller element  
                swap(&columns[i].number, &columns[j].number);
            }
        }
        swap(&columns[i + 1].number, &columns[high].number);
        return (i + 1);
    }

    static void sort(vector<Columns>& columns, int low, int high) {
        if (low < high)
        {
            /* pi is partitioning index, arr[p] is now
            at right place */
            int pi = partition(columns, low, high);

            // Separately sort elements before  
            // partition and after partition  
            /*quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);*/

            sort(columns, low, pi - 1);
            sort(columns, pi + 1, high);
        }
    }
};