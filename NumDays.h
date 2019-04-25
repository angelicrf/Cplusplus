#pragma once
// External Definition files
#include <string>
#include <iostream>

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
					  // "std" are utilized in this program


/******************************************************************************
*      Class: Numdays
* Base Class: None
*
* Programmer: Robert Main
*
* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/23/2019  Initial Release
*
* ----------------------------- Public Interface ------------------------------
*       Method                               Description
* ------------------  ---------------------------------------------------------
* NumDays              Parameterless Constructor: Overrides the "Default"
* NumDays              Conversion Constructor: New object from caller's name
* setName              Set/change the "NumDays" object's name
* getName              RETurns the "NumDays" object's name
*
*
* --------------------------------- Private Methods ---------------------------
*                              *** No private methods ***
*
*
* -------------------------- Private Data Members -----------------------------
*              Data
*    Type      Type   Name                    Description
* ----------  ------  ----  ---------------------------------------------------
* non-static  int  number  NumDays's number
*
*
* --------------------------- Public Data Members -----------------------------
*                         *** No public data members ***
*
*******************************************************************************
*/
class NumDays
{
private:
	// 1. Non-static (instance) Variable Declarations
	double number;
	static const double value;
	

public:
	// 1. Constructors
	//    A. Parameterless Constructor
	//       Overrides the compiler's "Default" Constructor
	
	NumDays();
	//    B. Conversion Constructor
	//       Creates a "NumDays" object from the specified name of the number
	NumDays(double pNumber);
	//
	// 2. Class Destructor
	~NumDays();

	void setHours(double pNumber);
	int getHours();

	double getDays();
	double addHours(double pNumber);


	NumDays operator++();
	NumDays operator--();

	NumDays operator++(int);
	NumDays operator--(int);
	NumDays operator-=(NumDays c1);


	friend NumDays operator+(NumDays c1, NumDays c2);
	friend NumDays operator-(NumDays c1, NumDays c2);
	friend ostream& operator<< (ostream& c1, NumDays c2);

};	// End Class: NumDays
