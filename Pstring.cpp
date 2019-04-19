/******************************************************************************
* Bellevue Class: PROG-113
*           Term: Spring 2019
*     Instructor: Robert Main
*
* Solution/Project Name: **Palindrom testing **  (Ex: Project1)
*             File Name: **Pstring**.cpp        (Ex: payrate.cpp)
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
*   1.0     04/17/2019  Initial Release
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
// External Definition Files
// 1. C++ Library files
#include <iostream>  // Defines objects and classes used for stream I/O
#include <string>
// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the
					 // namespace "std" are utilized in this program

// Method Prototypes
// -----------------


class pString : public string {

public:

	string userAnswer;

public:

	pString(string getAns);

	bool isPalindrome();

};

pString::pString(string getAns) {

	userAnswer = getAns;
}

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
* calling a boolean method from a class called pString.
*
* Return Value
* ------------
*   Type                              Description
* --------  -------------------------------------------------------------------
* int       Program execution status: 0 - No errors
  bool     check whether the word entered is palindrome or not
*
* Invoked File Methods
* --------------------
*     Name                             Description
* ------------  --------------------------------------------------------------
* None
*
*******************************************************************************
*/
bool pString::isPalindrome() {


	string getAnswer;

	for (int i = 0, j = 0; i < userAnswer.length(); i++)
	{
		if (userAnswer[i] >= 'A' && userAnswer[i] <= 'Z') {

			getAnswer.append(1, userAnswer[i] + 0x20);

		}
		else if (userAnswer[i] >= 'a' && userAnswer[i] <= 'z')
		{
			getAnswer.append(1, userAnswer[i]);
		}
	}
	int lengthAnswer = getAnswer.length();
	for (int i = 0; i < lengthAnswer / 2; i++)
	{
		if (getAnswer[i] != getAnswer[lengthAnswer - i - 1]) {

			cout << "the word entered is not palindrom" << endl;
			return false;
		}
	}

	cout << "The word entered is a palindrome" << endl;
	return true;

}

int main()
{
	// Constant "const" Value Declarations
	const int NO_ERRORS = 0;  // Program Execution status: No errors

	// Initialized Variable Declarations
	int programStatus = NO_ERRORS;  // Assume no program errors

	// Uninitialized Variable Declarations

	string userAnswer;

	// !! Insert your code here (remove this comment line) !!

	cout << "Please enter a word here :" << endl;
	cin >> userAnswer;


	pString obj(userAnswer);
	obj.isPalindrome();

	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	// Inform the OS of the execution status of the program
	return programStatus;

}	// End Method: main()