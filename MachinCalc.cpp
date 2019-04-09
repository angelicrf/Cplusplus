/******************************************************************************
* Bellevue Class: PROG-113
*           Term: Spring 2019
*     Instructor: Robert Main
*
* Solution/Project Name: **Solution/Movie Statistics**  (Ex: Project1)
*             File Name: **CalcMechine**.cpp        (Ex: payrate.cpp)
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
*   1.0     04/08/2019       Initial Release
*   X.Y     MM/DD/YYYY  ** Short, 1 line description of changes to program **
*
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
// External Definition files
// 1. C++ Library files
#include <iostream>  // Defines objects and classes used for stream I/O
#include <iomanip>

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the
					 // namespace "std" are utilized in this program

// Method Prototypes
// -----------------
void getUser();
void getNum(int *, int);
void getSource(int *, int);
double findAverage(int *, int);
double findMed(int *, int);
int findMod(int *, int);


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

	// !! Insert your code here (remove this comment line) !!
	getUser();

	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	// Inform the OS of the execution status of the program
	return programStatus;

}
void getUser() {
	// Uninitialized Variable Declarations
	int *allMovies, mod, student;
	double med, avg;


	do {
		cout << "How many students participated on survey? ";
		cin >> student;

		if (student < 3 || student >10) {
			cout << "Wrong input, enter the number of movies you watched (3-10).\n";
		}
		if (!cin) {
			cin.clear();
			cin.ignore(256, '\n');
		}

	} while (student < 3 || student >10 || !cin);

	allMovies = new int[student];
	getNum(allMovies, student);
	getSource(allMovies, student);

	avg = findAverage(allMovies, student);
	med = findMed(allMovies, student);
	mod = findMod(allMovies, student);

	cout << "The result is: \n";
	cout << fixed << showpoint << setprecision(2);
	cout << "Average: " << avg << endl;
	cout << "Median:  " << med << endl;
	cout << "Mode:    " << mod << endl;
	
}
void getNum(int *array, int size) {

		cout << "Enter the number of movies watched (3-10).\n";
	
			for (int i = 0; i < size; i++)
			{
				cout << "The student #" << (i + 1) << ": ";
				cin >> *(array + i);
			}
}
void getSource(int *array, int size) {

	int g, minVal, minI;
	for (g = 0; g < (size - 1); g++)
	{
		minI = g;
		minVal = *(array + g);

		for (int i = g + 1; i < size; i++)
		{
			if (*(array + i) < minVal)
			{
				minVal = *(array + g);
				minI = i;

			}
		}

		*(array + minI) = *(array + g);
		*(array + g) = minI;
	}
}
double findAverage(int *array, int size) {

	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += *(array + i);
	}
	return sum / size;
}

double findMed(int *array, int size) {

	int mid = (size - 1) / 2;
	double med;
	if (size % 2 == 0)
	{
		med = (*(array + mid) + *(array + (mid + 1))) / 2;

	}
	else

		med = *(array + mid);
	return med;
}
int findMod(int *array, int size) {

	int mod, last;
	int count = -0;

	mod = last = 0;
	for (int i = 0; i < size; i++)
	{
		count++;
		if (*(array + i) < *(array + i + 1))
		{
			if (count > last) {
				mod = *(array + i);
				last = count;
			}
			count = 0;
		}

	}
	return mod;

}
