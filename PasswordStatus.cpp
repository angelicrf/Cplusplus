//******************************************************************************
/* Bellevue Class : PROG - 113
* Term : Spring 2019
* Instructor : Robert Main
*
* Solution / Project Name : **Project4** 
*             File Name : PasswordStatus.cpp
*
* This file defines the entry point method, main(), for a C++ Console
* application.When the executable file is selected for execution, the OS
* will transfer execution to the first line of code in method main().Other
* methods called from main() may be defined here as well.
*
* Programmer: **Angelique Refahiayt**
*
* Assigned Project Number : **See Syllabus, for example : 4**
*
* Revision     Date                        Release Comment
* --------  ----------  ------------------------------------------------------
*   1.0     05 / 01 / 2019  Initial Release
*   X.Y     05 / 02 / 2019 * * Changed the constructors and add private varibales inside the header and change for loops to while **
*
* Program Inputs
* --------------
*  Device                              Description
* --------  ------------------------------------------------------------------
* Keyboard    ** Describe User input(s); otherwise, EXPLICITY state : None * *
*
* Program Outputs
* -------------- -
*Device                            Description
* --------  ------------------------------------------------------------------
* Monitor    ** Describe Console display; otherwise, EXPLICITY state : None * *
*
* File Methods
* ------------
*     Name                             Description
* ------------  --------------------------------------------------------------
* main          Program entry point method

*
******************************************************************************
*/
// External Definition Files
// 1. C++ Library files

#include <iostream>  // Defines objects and classes used for stream I/O
#include <cctype>
#include <cstring>
#include "PasswordStatus.h"

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the
					 // namespace "std" are utilized in this program

// Method Prototypes
// -----------------
// None


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


//PasswordStatus::PasswordStatus(const char* myArray, int minSize) {
//
//	for (int i = 0; i < minSize; i++) {
//
//		password = myArray;
//		minLength = minSize;
//
//	}
//	
//}
PasswordStatus::~PasswordStatus() {
	//delete[] password;
}
bool PasswordStatus::sufficientLength() {

	if (strlen(password) < minLength){

			return false;
	}
	else
		return true;
}

bool PasswordStatus::hasUpperCase() {	
	//for (int i = 0; i < strlen(password); i++)
	//{
	//	if (isupper(password[i]) != 0) {
	//		
	//			return true;
	//		}
	//	else if (isupper(password[i]) == 0) {
	//		
	//		return false;
	//	}
	//}
	int i = 0;
	
	while (password[i])
	{
		find = password[i];
		if (isupper(find))

			return true;
			find = tolower(find);

		putchar(find);

		i++;
	}
	return false;
}
bool PasswordStatus::hasLowerCase() {
	/*for (int i = 0; i < strlen(password); i++)
	{
		if (islower(password[i]) != 0) {
			
			return true;
		}
		else if (islower(password[i]) == 0) {
	
			return false;
		}
	}
	return false;*/
	int i = 0;

	while (password[i])
	{
		find = password[i];

		if (islower(find))

			return true;
			find = toupper(find);

		putchar(find);
		i++;
	}
	return false;
}
bool PasswordStatus::hasDigit() {

	//for (int i = 0; i < strlen(password); i++)
	//{
	//	//scanf_s("%s", password);
	//	if ((isdigit(password[i])) != 0) {
	//		
	//		digit++;
	//		return true;
	//	}
	//	else if (isdigit(password[i]) == 0) {
	//		return false;
	//	}	
	//}
	//return false;
	int i = 0;
	
	while (password[i])
	{
		find = password[i];

		if (isdigit(find))

			return true;
	
		putchar(find);
		i++;
	}
	return false;
}
bool PasswordStatus::isValid() {

	if (strlen(password) < minLength && hasDigit() == false && hasLowerCase() == false && hasUpperCase() == false )
	{
		return false;
	}
	else {
	
		return true;
	}
}


