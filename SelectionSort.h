#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <iostream>
#include "AbstractSort.h"

using namespace std;

class SelectionSort:public AbstractSort
{

public:

	SelectionSort();

	virtual void sort(int* myArray, int size);
	
	~SelectionSort();

};
#endif;

