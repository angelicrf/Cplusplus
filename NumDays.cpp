
/******************************************************************************
	* Bellevue Class: PROG-113
	*           Term: Spring 2019
	*     Instructor: Robert Main
	*
	* Solution/Project Name: **Number of Days **  (Project3)
	*             File Name: NumDays.cpp       
	*
	* This file defines the entry point method, main(), for a C++ Console
	* application. When the executable file is selected for execution, the OS
	* will transfer execution to the first line of code in method main(). Other
	* methods called from main() may be defined here as well.
	*
	* Programmer: **Angelique Refahiyat**
	*
	* Assigned Project Number: **: 3**
	*
	* Revision     Date                        Release Comment
	* --------  ----------  ------------------------------------------------------
	*   1.0     04/23/2019  Initial Release
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
#include <string>
#include <iostream>  // Defines objects and classes used for stream I/O
#include "NumDays.h"

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the
					 // namespace "std" are utilized in this program


// Method Prototypes
// -----------------
// None
//***************************************************
// Class Paramterless Constructor                   *
//                                                  *
// Overrides the compiler's "Default" Constructor   *
// for the sole purpose to show when it is invoked. *
//                                                  *
//***************************************************
NumDays::NumDays()
{
	//number = 0.0;
	setHours(0);
}
// Method Prototypes
// -----------------
// None
//***************************************************
// Class Paramterless Constructor                   *
//                                                  *
//add hours to the actual hours *
//                                                  *
//***************************************************
double NumDays::addHours(double pNumber)
{
	double added = pNumber + getHours();
	setHours(added);
	return added;
}
//*********************************************** 
// Class Conversion Constructor                 *
//                                              *
// Creates a Class object from a "double" value *
//                                              *
//***********************************************
NumDays::NumDays(double pNumber)
{
	setDays(pNumber);
}


//***************************************************
// Class Destructor                                 *
//                                                  *
// No action is necessary, but is included for the  *
// sole purpose to show when it is invoked.         *
//                                                  *
//***************************************************
NumDays::~NumDays()
{

}

//********************************************* 
// Method: setName(double pName)             *
//                                            *
// Modifies the "NumDays" object's hours       *
//                                            *
//*********************************************
void NumDays::setHours(double pNumber)
{
		number = pNumber / 8.0;
}
//********************************************* 
// Method: getHours()                          *
//                                            *
// Retrieves the "NumDays" object's name as a  *
// "int" object.                           *
//                                            *
//*********************************************
int NumDays::getHours()
{
	return static_cast<int>(number * 8);
}

//********************************************* 
// Method: getDays()                          
//                                            *
// Retrieves the "NumDays" object's name as a  *
// "double" object.     

//*********************************************
double NumDays::getDays()
{
	return number;
}


//********************************************* 
// Method: setDays()                          
                      
//Modifies the "NumDays" object's days                                            *
//*********************************************
void NumDays::setDays(double pNumber)
{
	number = pNumber;
}
//********************************************* 
// Method: operator++()                                                                    
//*********************************************
NumDays NumDays::operator++() 
{
	
	setHours(getHours() + 1);
	return *this;
}
//********************************************* 
// Method: operator--()                          
//                                                                                   
//*********************************************
NumDays NumDays::operator--()
{
	setHours(getHours() - 1);
	return *this;
}
//********************************************* 
// Method: operator++(int)                          
                                         
//*********************************************
NumDays NumDays::operator++(int)
{
	NumDays pr = *this;
	setHours(getHours() + 1);
	return pr;
}
//********************************************* 
// Method: operator--(int)   

//*********************************************
NumDays NumDays::operator--(int)
{
	NumDays pr = *this;

	setHours(getHours() + 1);
	return pr;
}
//********************************************* 
// Method: operator+ (NumDays one , NumDays two)

                                           
//*********************************************
NumDays operator+ (NumDays one , NumDays two)
{

	return NumDays(one.getHours() + two.getHours());
}
//********************************************* 
// Method: operator- (NumDays one , NumDays two)
                                       
//*********************************************
NumDays operator- (NumDays one, NumDays two)
{

	return NumDays(one.getHours() - two.getHours());
}
//********************************************* 
// Method: ostream operator<< (ostream one, NumDays two)

//*********************************************
ostream& operator<< (ostream& o, NumDays two)
{
	o << two.getHours();
	return o;
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


//int main()
//{
//	// Constant "const" Value Declarations
//	const int NO_ERRORS = 0;  // Program Execution status: No errors
//
//	// Initialized Variable Declarations
//	int programStatus = NO_ERRORS;  // Assume no program errors
//	int userAnswer1,userAnswer2;
//	// Uninitialized Variable Declarations
//
//	cout << "please enter the first number of the days here: " << endl;
//	cin >> userAnswer1;
//
//	cout << "please enter the second number of the days here: " << endl;
//	cin >> userAnswer2;
//
//
//	NumDays one(userAnswer1);
//
//	NumDays two(userAnswer2);
//
//	NumDays total, difference;
//	total = one + two;
//	difference = one - two;
//
//	// !! Insert your code here (remove this comment line) !!
//
//	cout <<"The number of hourse calculeted: "<< one.getHours() << endl;
//	cout << "The number of hourse calculeted: " << two.getHours() << endl;
//
//
//
//	//cout << one.getDays() << endl;
//	//cout << two.getDays() << endl;
//
//	cout << "The total number of days' one and two is : " << total.getDays() << endl;
//	cout << "The total number of days' one and two is : " << total.getHours() << endl;
//	cout << "The difference between days' one and two is: " << difference.getDays() << endl;
//	cout << "The difference between hours' one from two is: " << difference.getHours() << endl;
//
//	one++;
//	cout <<"The number of days' one incremented by 1: "  << one.getHours() << endl;
//	two--;
//	cout << "The number of days' two incremented by 1: " << two.getHours() << endl;
//
//
//
//
//
//
//
//
//
//	// This prevents the Console Window from closing during debug mode using
//	// the Visual Studio IDE.
//	// Note: Generally, you should not remove this code
//	cin.ignore(cin.rdbuf()->in_avail());
//	cout << "\nPress only the 'Enter' key to exit program: ";
//	cin.get();
//
//	// Inform the OS of the execution status of the program
//	return programStatus;
//
//}
//

