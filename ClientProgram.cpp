/******************************************************************************
* Bellevue Class: PROG-113
*     Instructor: Robert Main
*
* Solution/Project Name: Solution-Project3
*             File Name: ClientProgram.cpp
*
* This file defines the entry point method, main(), for a C++ Console
* application. When the executable file is selected for execution, the OS
* will transfer execution to the first line of code in method main(). Other
* methods called from main() may be defined here as well.
*
* Instructor Project Solution
* Assigned Project: 3
*
* Revision     Date                        Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/24/2019  Initial Release
*
* File Methods
* ------------
*     Name                             Description
* ------------  ---------------------------------------------------------------
* main          Program entry point method
*
* ADT (Abstract Data Type) Classes Utilized
* -----------------------------------------
*   Name                             Description
* --------  -------------------------------------------------------------------
* NumDays   Encapsulates hours worked with methods to indicate days and hours
*
* Program Inputs
* --------------
* None
*
* Program Outputs
* ---------------
*  Device                           Description
* ---------  ------------------------------------------------------------------
* Monitor    Display of various applications of features supported by the
*            various Class Client methods and Operators
* 
*******************************************************************************
 */
// External Definition files
// 1. C++ Library Files
#include <iostream>   // Defines objects and classes used for stream I/O
// 2. ADT Class Definitions
#include "NumDays.h"  // Defines Class: NumDays

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program

/******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
* This client code provides tests for the following "NumDays" required methods
* and Operators:
* 1.  Default Constructor: Sets hours worked to 0
* 2.  Initializing Constructor: hours worked
* 3.  getDays(): Number of whole days for the hours worked
* 4.  getHours(): Number of residual hours after whole days calculated
* 5.  addHours(double): Add hours to the Class object
* 6.  Operator Addition: Adds hours of two Class objects, RETurns a Class object
* 7.  Operator Subtraction: Subtract's one Class hours from another
* 8.  Combined Subtraction Operator: Subtracts hours from one object
* 9.  Prefix Increment Operator: Increments class object's hours by 1 hour
* 10. Postfix Increment Operator: Increments class object's hours by 1 hour
* 11. Prefix Decrement Operator: Decrements class object's hours by 1 hour
* 10. Postfix Decrement Operator: Decrements class object's hours by 1 hour
* 11. Stream Insertion Operator: Inserts days/hours worked into stream object
*
*
* Preconditions
* --------------
* None
*
* Method Arguments
* ----------------
* No arguments required
*
* Return Value
* ------------
* Type                              Description
* ----  -----------------------------------------------------------------------
* int   Program execution status: 0 - No errors
*
* Invoked Methods
* ---------------
* None
*
*******************************************************************************
 */
 int main()          
{
	// Constant "const" Value Declarations
	 const int NO_ERRORS = 0;  // Program execution status: No errors

	// Initialized UDT object Declarations
	NumDays hoursWorked_John;       // Instantiate with Default Constructor
	NumDays hoursWorked_Sue(36.9);  // Instantiate with Initializing Constructor
	NumDays hoursUsed_Sue(4.5);     // Instantiate with Initializing Constructor


	// Describe the Project Assignment to the User
	cout << "                  PROG-113: Project #3\n"
			<< "                     Class: NumDays\n"
			<< "                 Hours Lower Limit: 0.0\n"
			<< "                  Client Test Program\n" << endl;


	cout << "John's initial hours worked: " << hoursWorked_John << endl;
	hoursWorked_John.addHours(56.78);
	cout << "  John's final hours worked: " << hoursWorked_John << endl << endl;

	cout << "Sue's hours worked: " << hoursWorked_Sue << endl;
	cout << "Total hours worked: " << (hoursWorked_John + hoursWorked_Sue)
			<< endl << endl;

	
	cout << "    Sue's hours Used: " << hoursUsed_Sue << endl;
	hoursWorked_Sue = (hoursWorked_Sue - hoursUsed_Sue);
	cout << "Sue's adjusted hours: " << hoursWorked_Sue << endl;
	cout << "Adjusted Total hours: " << (hoursWorked_John + hoursWorked_Sue)
			<< endl << endl;

	cout << "Adding 39.5 hours to Sue's Used hours" << endl;
	hoursUsed_Sue.addHours(39.5);
	hoursWorked_Sue = hoursWorked_Sue - hoursUsed_Sue;
	cout << "    Sue's hours Used: " << hoursUsed_Sue << endl;
	cout << "Sue's adjusted hours: " << hoursWorked_Sue
		 << "  (invariant condition enforced)" << endl;

	cout << "Adjusted Total hours: " << (hoursWorked_John + hoursWorked_Sue)
			<< endl << endl;

	cout << "Adding 39.5 hours to Sue's Hours Worked" << endl;
	hoursWorked_Sue.addHours(39.5);
	cout << "  Sue's adjusted Hours worked: " << hoursWorked_Sue << endl;
	cout << "Prefix increment Sue's hours worked in the display statement:" << endl;
	cout <<  "  Sue's hours worked: " << ++hoursWorked_Sue << endl;
	cout <<  "   Sue's Final hours: " << hoursWorked_Sue << endl <<endl;
	cout << "Postfix increment Sue's hours worked in the display statement:" << endl;
	cout <<  "  Sue's hours worked: " << ++hoursWorked_Sue << endl;
	cout <<  "   Sue's Final hours: " << hoursWorked_Sue << endl <<endl;

	cout << "Adding 5.67 hours to John's hours worked" << endl;
	cout << "   John's current hours worked: " << hoursWorked_John << endl;
	hoursWorked_John.addHours(5.67);
	cout << "  John's adjusted Hours worked: " << hoursWorked_John << endl;
	cout << "Prefix decrement John's hours worked in the display statement:" << endl;
	cout <<  "   John's Final hours: " << hoursWorked_John << endl;
	cout <<  "  John's hours worked: " << --hoursWorked_John << endl;
	cout << "Postfix decrement John's hours worked in the display statement:" << endl;
	cout <<  "  John's hours worked: " << hoursWorked_John-- << endl;
	cout <<  "   John's Final hours: " << hoursWorked_John << endl;


	// This prevents the Console Window from closing during debug mode
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;

}	// End Method: main()