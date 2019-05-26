#ifndef AbstractSort_H
#define AbstractSort_H


#include <iostream>

using namespace std; // Announces to the compiler that members of the

class AbstractSort{

private:

	int findItem = 0;

public:

	AbstractSort();

	int Comparaison(int a, int b);

	/*virtual void sort(int myArray[], int size) = 0;
	virtual void quickSort(int * myArray, int size) = 0;*/

	int CalcAnswer() {
		
		/*cout << findItem;*/
		return findItem;
	}

	~AbstractSort();

};

#endif;