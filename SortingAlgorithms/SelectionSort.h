#pragma once
#include <iostream>
#include "Columns.h"

class SelectionSort{
public:
	static double loopCounter;
	static int placeToStart;

	static void sort(vector<Columns> &columns) {
		int min = placeToStart;
		for (size_t j = placeToStart; j < columns.size(); j++) {
			if (columns[j].number < columns[min].number)
				min = j;
			loopCounter++;
		}
		int temp = columns[min].number;
		columns[min].number = columns[placeToStart].number;
		columns[placeToStart].number = temp;
		placeToStart++;
	}
};