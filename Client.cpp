/******************************************************************************
	* Bellevue Class: PROG-113
	*           Term: Spring 2019
	*     Instructor: Robert Main
	*
	* Solution/Project Name: **Project7**
	*             File Name: **SelectionSort**.cpp
	*
	* This file defines the entry point method, main(), for a C++ Console
	* application. When the executable file is selected for execution, the OS
	* will transfer execution to the first line of code in method main(). Other
	* methods called from main() may be defined here as well.
	*
	* Programmer: **Angelique Refahiyat**
	*
	* Assigned Project Number: **See Syllabus, for example: 2A**
	*
	* Revision     Date                        Release Comment
	* --------  ----------  ------------------------------------------------------
	*   1.0     05/22/2019  Initial Release
	*   2.0     05/23/2019  **Added two more classes and headers**
	*   3.0     05/26/2019  *Changed the bobble sort method to a selection sort*
	* Program Inputs
	* --------------
	*  Device                              Description
	* --------  ------------------------------------------------------------------
	* Keyboard    ** Describe User input(s); otherwise, EXPLICITY state: None **
	*
	* Program Outputs
	* ---------------
	*  Device                            Description
	* --------  ------------------------------------------------------------------
	* Monitor    ** Describe Console display; otherwise, EXPLICITY state: None **
	*
	* File Methods
	* ------------
	*     Name                             Description
	* ------------  --------------------------------------------------------------
	* main          Program entry point method
	***** Add name and description of any other methods defined in this file****
	*
	******************************************************************************
	*/
#include "SelectionSort.h"
//#include "AbstractSort.h"
#include "QuickSort.h"
#include "Client.h"
#include <cstdlib> 
#include <ctime> 
#include <iostream> 

Client::Client() {

}
Client::~Client() {

}
	// External Definition Files
	// 1. C++ Library files
 // Defines objects and classes used for stream I/O
// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the
					 // namespace "std" are utilized in this program
/******************************************************************************
* Method: main()
*
* Method Description
* ------------------
* ** For method main(), describe the application program from the client's
* ** perspective, which includes any User inputs required and expected
* ** Console output, and any other pertinent information about the program.
* ** For other methods, describe the functionality of the method.
* ** This WILL take several lines for a satisfactory description!
*
* Preconditions
* -------------
* ** Describe any assumptions made by the method; otherwise specify: None **
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  ----------------------------------------------------
* No Arguments required
*
* Return Value
* ------------
*   Type                              Description
* --------  -------------------------------------------------------------------
* int       Program execution status: 0 - No errors
*
* Invoked File Methods
* --------------------
*     Name                             Description
* ------------  --------------------------------------------------------------
* None
*
*******************************************************************************
*/


int main()
{
	// Constant "const" Value Declarations
	const int NO_ERRORS = 0;  // Program Execution status: No errors

	// Initialized Variable Declarations
	int programStatus = NO_ERRORS;  // Assume no program errors

	// Uninitialized Variable Declarations
	const int  LENGTH = 500;

	//int Array_1 [LENGTH];
	int* Array_1 = new int[LENGTH];

	srand((unsigned)time(0));

	for (int i = 0; i < LENGTH; i++) {

		Array_1[i] = (rand() % LENGTH) + 1;
	}

	int* Array_2 = new int[LENGTH];
	srand((unsigned)time(0));

	for (int i = 0; i < LENGTH; i++) {

		Array_2[i] = (rand() % LENGTH) + 1;
	}

	SelectionSort st;
	QuickSort qs;

	st.sort(Array_1, LENGTH);
	qs.quickSort(Array_2, LENGTH);

	for (int i = 1; i < 21; i++) {
		cout << "The first 20 element sof the array_1: " << Array_1[i] << endl;
	}
	cout << endl;
	for (int i = 1; i < 20; i++) {
		cout << "The first 20 element sof the array_2: " << Array_2[i] << endl;
	}
	cout << endl;
	int getResult = st.CalcAnswer();
	cout << "The calculated result using the sort method is : " << getResult;

	cout << endl;
	int getResult_2 = qs.CalcAnswer();
	cout << "The calculated result using the quickSort method is : " << getResult_2;

	delete[] Array_1, Array_2;
	Array_1 = nullptr;
	Array_2 = nullptr;

	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	// Inform the OS of the execution status of the program
	return programStatus;

}

