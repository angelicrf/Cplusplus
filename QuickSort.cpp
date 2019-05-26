#include "QuickSort.h"
#include "AbstractSort.h"


QuickSort::QuickSort()
{
}
void QuickSort::quickSort(int* myArray , int size) {

	/*int* myNewArray = NULL;
	myNewArray = new int [size];
	myArray = myNewArray;*/

	int definepivot = myArray[size -1];

	int index = 0;
	for (int i = 0; i < size -1; i++)
	{
		int found = Comparaison(myArray[i],definepivot);

		//if (found == -1) {
			if (myArray[i] < definepivot) {
				int temp = myArray[i];

				myArray[i] = myArray[index];

				myArray[index] = temp;
				index++;
			//}
		}
	}
	int temp = myArray[index];

	myArray[index] = myArray[size-1];
	myArray[size - 1] = temp;

	if (index > 1) {

		quickSort(myArray, index);

	}
	if ((size - index - 1) > 1) {
		quickSort((myArray + index + 1), (size - index - 1));
	}
}

QuickSort::~QuickSort()
{
}
