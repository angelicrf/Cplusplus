
#include "SelectionSort.h"
#include "AbstractSort.h"

#include <iostream>  // Defines objects and classes used for stream I/O


SelectionSort::SelectionSort() {

};
void SelectionSort::sort(int* myArray , int size) {

	/*int* myNewArray = NULL;
	myNewArray = new int [size];
	myArray = myNewArray;*/

	int i, minI, minVal;
	for  (i = 0; (i < (size -1)); i++)
	{
		minI = i;
		minVal = myArray[i];
			for (int j = (i+1); j < size; j++)
			{
				int found = Comparaison(myArray[j], myArray[i]);
				if (myArray[j] < minVal) {

					minVal = myArray[j];
					minI = j;
			  }
			}
		myArray[minI] = myArray[i];
		myArray[i] = minVal;
	}

	
}
SelectionSort::~SelectionSort() {

}
