#pragma once
#include <iostream>
#include "Columns.h"

class BubbleSort{
public:
	static double loopCounter;
	static int numOfCalls;

	static void sort(vector<Columns>& columns) {
		for(size_t j = 0; j < columns.size() - 1 - numOfCalls; j++) {
			if (columns[j].number > columns[j + 1].number) {
				int temp = columns[j].number;
				columns[j].number = columns[j+1].number;
				columns[j+1].number = temp;
			}
			loopCounter++;
		}
		numOfCalls++;
	}
};