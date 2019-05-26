#ifndef QuickSort_H
#define QuickSort_H

#include <iostream>
#include "AbstractSort.h"


using namespace std;

class QuickSort:public AbstractSort
{
public:
	QuickSort();

	virtual void quickSort(int* myArray, int size);
	

	~QuickSort();
};
#endif;

