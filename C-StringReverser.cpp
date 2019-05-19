/******************************************************************************
* Bellevue Class: PROG 113
*           Term: Spring 2019
*     Instructor: Robert Main
*
* Solution/Project Name: PROG113_Project6
*             File Name: C-StringReverser.cpp
*
* This file defines the entry point method, main(), for a C++ Console
* application. When the executable file is selected for execution, the OS
* will transfer execution to the first line of code in method main(). Other
* methods called from main() may be defined here as well.
*
* Programmer: ** Angelique Refahiyat **
* Assigned Project: 6
*
* Revision     Date                        Release Comment
* --------  ----------  ------------------------------------------------------
*   1.0     05/dd/2019  Initial Release
*
*
* ADTs (Abstract Data Types) Utilized
* -----------------------------------
* None
*
* Program Inputs
* --------------
*  Device                              Description
* --------  -------------------------------------------------------------------
* Keyboard  User's phrase to display in reverse
*
* Program Outputs
* ---------------
*  Device                              Description
* --------  -------------------------------------------------------------------
* Monitor   User's phrase displayed in reverse order
*
* File Methods
* ------------
*     Name                                Description
* ------------  --------------------------------------------------------------
* main          Program entry point method
* printReverse  Client Recursive method: Display a C-Style string in reverse
*               order.
* printReverse  Recursive method: Display a "C-string" array in reverse order,
*               starting at a specific character in the array.
*
******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
 // Defines IDE required external definition files
#include "stdafx.h" 
#include <iostream>  // Defines objects and classes used for stream I/O

// Namespaces utilized in this program

using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program

// Method Prototype Declarations
// -----------------------------
void printReverse(const char* s);
void printReverse(char* s, int index);


/******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
* 
*
* Preconditions
* -------------
*
* Method Arguments
* ----------------
* No arguments required
* 
* Return Value
* ------------
* Type                              Description
* ----  ----------------------------------------------------------------------
* void  The method RETurns no value
*
* Invoked Methods
* ---------------
*     Name                            Description
* ------------  --------------------------------------------------------------
* printReverse  Client method: Display a "C-string" in reverse order.
*
******************************************************************************
*/
int main()          
{
	// Constant "const" Value Declaration
	const int NO_ERRORS = 0;
	const int MAX_LENGTH = 80;

	// Uninitialized Array Declaration
	char str[MAX_LENGTH + 1];

	// Initialized Variable Declaration
	int programStatus = NO_ERRORS;  // Assume no program execution errors


	cout << "Enter a string: " ;
	cin.getline(str, MAX_LENGTH);

	cout << "The reversed string is :\n";
	// Start the recursion at the first character in the array
	//printReverse(str);
	
	printReverse(str, 0);
	cout << str;


	// This prevents the Console Window from closing during debug mode
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return programStatus;

}	// End method: main()


/******************************************************************************
* Method: printReverse(const char*)
* 
* Method Description
* ------------------
* 
*
* Preconditions
* -------------
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  ---------------------------------------------------
* 
* Return Value
* ------------
* Type                              Description
* ----  ----------------------------------------------------------------------
* void  The method RETurns no value
*
* Invoked Methods
* ---------------
*     Name                            Description
* ------------  --------------------------------------------------------------
* printReverse  Recursive method: Display a "C-string" array in reverse order,
*               starting at a specific character in the array.
*
******************************************************************************
*/
void printReverse(const char* phrase)
{
	//int getLength = strlen(phrase);

	/*char* newStr = new char[getLength + 1];

	strcpy_s(newStr,getLength ,phrase);
	for (int i = 0 , j = (getLength -1); i <j; i++,j--)
	{
		swap(phrase[i], phrase[j]);
	}*/
	int i = 0;
	char getStr[100] = "";

	if (*phrase) {

		printReverse(phrase+1);
		getStr[i++] = *phrase;
		cout << getStr;
	}
}	// End method: printReverse(char*)


/******************************************************************************
* Method: printReverse(const char *phrase, int)
* 
* Method Description
* ------------------
* 
*
* Preconditions
* -------------
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  ----------------------------------------------------
* 
* Return Value
* ------------
* Type                              Description
* ----  -----------------------------------------------------------------------
* void  The method RETurns no value
*
* Invoked Methods
* ---------------
* None
*
*******************************************************************************
*/
void printReverse(char *phrase, int index)
{
	int getLength = strlen(phrase);

	//char find;
	//index = getLength + 1;

	//char* newStr = new char[getLength + 1];

	//strcpy_s(newStr,getLength, phrase);
	//for (int i = 0, j = (getLength - 1); i < j; i++, j--)
	//{
	//	swap(phrase[i], phrase[j]);
	//}

	//if (index < getLength/2) {
	if (getLength <= index) {

		return;
	}
		/*find = phrase[index];

		phrase[index] = phrase[getLength - index - 1];
		phrase[getLength - index - 1] = find;

		index++;*/
	     swap(phrase[0], phrase[getLength-1-index]);
		printReverse(phrase + 1, index + 1);
	
	}	// End method: printReverse(const char *phrase, int)
