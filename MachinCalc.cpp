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
*   X.Y     04/10/2019  **There was a bug found by Mr.Main that I fixed.**
*
* Program Inputs
* --------------
*  Device                              Description
* --------  ------------------------------------------------------------------
* Keyboard    ** None **
*
* Program Outputs
* ---------------
*  Device                            Description
* --------  ------------------------------------------------------------------
* Monitor    ** None **
*
* File Methods
* ------------
*     Name                             Description
* ------------  --------------------------------------------------------------
* main          Program entry point method

*void getUser();   It;ll display the user answer from the prompt into the main
void getNum(int *, int);    It'll ask for the numbers of movies watched by students.
void getSource(int *, int);   Itl'll count the min value and minIndex of the array.
double findAverage(int *, int);   It'll find the average of the anumbers of movies watched by students.
double findMed(int *, int); It'll find the Median number of the movies watched by students.
int findMod(int *, int); it's display the mod through counting.
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
* ** For method main(), it simply calls the method wich holds all the 
prompts to ask from the user about the movies of each student watched 
and display it on the console to execute the code.


* Preconditions
* -------------
* ** None **
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
/******************************************************************************
 *      Class: MachCalc                                                       *
 *     Method: getUser                                                        *
 * Method Type: void                                                          *
 *                                                                            *
 * Parameters                                                                 *
 * ----------                                                                 *
 * None                                                                       *
 *                                                                            *
 * RETurn                                                                     *
 * Value                              Description                             *
 * ------  -------------------------------------------------------------------*
 * Value token from the prompt and store it into an array and display the 
 result on the console and made sure that the entry is qualified and is 
 *integer between 3-10 using a do while loop.                            
 *                                                                            *
 * Methods Called                                                             *
 * --------------                                                             *
 * None                                                                       *
 *                                                                            *
 * Function Description                                                       *
 * --------------------                                                       *
 * This method RETurns the object's circumference.                            *
 *                                                                            *
 ******************************************************************************
 */
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
	cout << "The average is: " << avg << endl;
	cout << "The median is: " << med << endl;
	cout << "The mode is: " << mod << endl;
	
}
/******************************************************************************
 *      Class: MachinCalc                                                     *
 *     Method: getNum                                                         *
 * Method Type: void                                                          *
 *                                                                            *
 * Parameters                                                                 *
 * ----------                                                                 *
 * Array pointer   
 * Int
 *                                                                            *
 * RETurn                                                                     *
 * Value                              Description                             *
 * ------  -------------------------------------------------------------------*
 * Print out the prompted result on the screen.      
 *                                                                            *
 * Methods Called                                                             *
 * --------------                                                             *
 * In getUser                                                                 *
 *                                                                            *
 * Function Description                                                       *
 * --------------------                                                       *
 * Through using a for loop, it'll get the data from the prompt and store
 it into an array.                           *
 *                                                                            *
 ******************************************************************************
 */
void getNum(int *array, int size) {

		cout << "Enter the number of movies watched (3-10).\n";
	
			for (int i = 0; i < size; i++)
			{
				cout << "The student # " << (i + 1) << ": ";
				cin >> *(array + i);
			}
}
/******************************************************************************
 *      Class: MachinCalc                                                     *
 *     Method: getSource                                                      *
 * Method Type: void                                                          *
 *                                                                            *
 * Parameters                                                                 *
 * ----------                                                                 *
 * Array pointer 
 * Int
 *                                                                            *
 * RETurn                                                                     *
 * Value                              Description                             *
 * ------  -------------------------------------------------------------------*
 * Calculate the minimum value of the elements inside the array and the 
 minimum index of the elements also to start doing the rest of the calcualtions
 * on the next methods.
 *                                                                            *
 * Methods Called                                                             *
 * --------------                                                             *
 * getUser                                                                    *
 *                                                                            *
 * Function Description                                                       *
 * --------------------                                                       *
 * Passed two parameters one as a pointer array and the second as a size.
 * Through the using for loop, the method will determine the minimum value
 of all the elements inside the array and hold it as a local variable called
 minValue and also calculates the minimum index and holds it into another 
 local variable called minI, This method will prepare the program going to
 the next step of calcualting the average and the median and the mod.
 *                                                                            *
 ******************************************************************************
 */
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
		*(array + g) = minVal;
	}
}
/******************************************************************************
 *      Class: MachinCalc                                                     *
 *     Method: findAverage                                                    *
 * Method Type:  double                                                       *
 *                                                                            *
 * Parameters                                                                 *
 * ----------                                                                 *
 * pointer array
   Int                                                                        *
 *                                                                            *
 * RETurn                                                                     *
 * Value                              Description                             *
 * ------  -------------------------------------------------------------------*
 * double   The method calculates the average of the numbers of the movies
 each students
 watched and returns the average calculated.                                  *
 *                                                                            *
 * Methods Called                                                             *
 * --------------                                                             *
 * getUser                                                                    *
 *                                                                            *
 * Function Description                                                       *
 * --------------------                                                       *
 * This method will generate the average number of the movies watched by each
 * student by getting the sum of them first and deviding it by the size.
 *                                                                            *
 ******************************************************************************
 */
double findAverage(int *array, int size) {

	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += *(array + i);
	}
	return sum / size;
}
/******************************************************************************
 *      Class: MachinCalc                                                     *
 *     Method: findMed                                                        *
 * Method Type: double                                                        *
 *                                                                            *
 * Parameters                                                                 *
 * ----------                                                                 *
 * Pointer array
 * Int
 *                                                                            *
 * RETurn                                                                     *
 * Value                              Description                             *
 * ------  -------------------------------------------------------------------*
 * double  Find the median as number required to calculate the statistical
 purposes.
 *
 *                                                                            *
 * Methods Called                                                             *
 * --------------                                                             *
 * getUser                                                                       *
 *                                                                            *
 * Function Description                                                       *
 * --------------------                                                       *
 * This Method uses the informations token from the user in the previous steps 
 * to calculate the median number of the movies watched by the students and will
 display it on the console.
 *                                                                            *
 ******************************************************************************
 */
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
/******************************************************************************
 *      Class: MachinCalc                                                     *
 *     Method: finMod                                                         *
 * Method Type:  int                                                          *
 *                                                                            *
 * Parameters                                                                 *
 * ----------                                                                 *
 * Pointer array
 *  Int
 *                                                                            *
 * RETurn                                                                     *
 * Value                              Description                             *
 * ------  -------------------------------------------------------------------*
 * Int  It'll display the mod in which calculated in this method.             *
 *                                                                            *
 * Methods Called                                                             *
 * --------------                                                             *
 * getUser                                                                    *
 *                                                                            *
 * Function Description                                                       *
 * --------------------                                                       *
 * This method counts each time  it goes to the loop and used the for loop
 * of values is the value that occurs most often or with the
greatest frequency to determin the mode of the array in which value in the 
array occurs most often.
 *                                                                            *
 ******************************************************************************
 */
int findMod(int *array, int size) {

	int mod, last;
	int count = 0;

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
