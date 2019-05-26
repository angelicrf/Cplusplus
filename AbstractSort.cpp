//#include "SelectionSort.h"
#include "AbstractSort.h"
//#include "QuickSort.h"

AbstractSort::AbstractSort()
{
}

int AbstractSort::Comparaison(int a, int b) {

	findItem++;

	if (a < b) 
		//findItem++;
		return 1;
	
	if (a > b) 
		//findItem++;
		return -1;
	
	if (a == b) 
		//findItem++;
		return 0;
	

}
AbstractSort::~AbstractSort()
{
}
