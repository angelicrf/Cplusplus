///*
//*****************************************************************************
// * Bellevue Class: PROG 113
// *           Term: Spring 2019
// *     Instructor: Robert Main
// *
// * Solution/Project Name: PROG113_MidtermExam
// *             File Name: MidtermExam.cpp
// *
// * This file defines the entry point method, main(), for a C++ Console
// * application. When the executable file is selected for execution, the OS
// * will transfer execution to the first line of code in method main(). Other
// * methods called from main() may be defined here as well.
// *
// * Programmer: **Angelique Refahiyat**
// *
// * Revision     Date                        Release Comment
// * --------  ----------  ------------------------------------------------------
// *   1.0     05/13/2019  Initial Release
 //    2.0     05/15/2019  Revised
//     3.0     05/17/2019  revised
// *
// * File Methods
// * ------------
// *     Name                             Description
// * ------------  --------------------------------------------------------------
// * main          Program entry point method
// *
// * UDT Classes Utilized
// * --------------------
// *     Name                             Description
// * ------------  --------------------------------------------------------------
// * Mail          Base class: Common services for a mail item of any type
// * Package       Sub-class:  Fixed cost, adds delivery days feature
// *
// * Program Inputs
// * --------------
// *  None
// *
// * Program Outputs
// * ---------------
// *   Stream Type                             Description
// * ---------------  -----------------------------------------------------------
// * Console Monitor  Display of various objects of type "Mail" and "Package"
// *
// ******************************************************************************
// */
// External Definition files
// 1. C++ Library Files
#include <iostream>  // Defines objects and classes used for stream I/O
#include <iomanip>   // Defines I/O Manipulators needed here
#include <string>

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the
					 // namespace "std" are utilized in this program

/******************************************************************************
 * Class Name: Mail
 * Base Class: None
 *
 * This file defines the members of the class: Mail
 * These members include class variable data members, class constant, static
 * data members, and class method declarations only and/or class method
 * declarations and definitions.
 *
 * Class Description
 * -----------------
 *
 * Class Data Members
 * ------------------
 *     Name        Scope     Type                   Description
 * ------------  ---------  ------  --------------------------------------------
 * TYPE_SIZE     private    char[]  Size of C-Style array: Mail Type    (static)
 * FIRST_CLASS   private    char[]  C-Style string array: "First Class" (static)
 *                ***** add required data member(s) here *****
 *
 * Class Methods
 * -------------
 *           Name          Scope                   Description
 * ----------------------  ------  --------------------------------------------
 * Mail()                  public  Class Default Constructor: First Class, 1 oz
 * Mail(char*,double,int)  public  Class Initializing Constructor
 * Mail(const Mail&)       public  Class Copy Constructor
 * ~Mail()                 public  Class Destructor
 * getCost()               public  RETurn total cost to mail item
 * operator=(const Mail&)  public  Assignment Operator
 * operator+(int)          public  Addition Operator: Add ounces to item
 * operator<<()            public  Insertion Operator: "string" description
 *
 ******************************************************************************
 */
class Mail
{
	// Public Interface
public:
	// Class Constructor(s)
	Mail();
	Mail(const char* type, double perOunceCost, int weight);

	Mail(const Mail& other);

	// Class Destructor
	~Mail();

	// Mutator Methods
	Mail operator=(const Mail& rValue);
	Mail operator+(int ounces);

	// Observer Methods
	double getCost() const;
	friend ostream& operator<<(ostream& stream, const Mail letter);
	static const char FIRST_CLASS[];
	static const int TYPE_SIZE = 30;
	
private:
	// Class "static, const" Constant Values
	// **** Add any other "static, const" values here ****
	const double FixedCost = 0.49;
	static const int fixedWeight = 1;
	// Variable Declarations
	//char type[TYPE_SIZE];	// C-Style "string" array (Required!)
	//  ****** Add required class data member(s) here ******
	
	string type;
	double perOunceCost;
	int weight;
};

// Class "static, const" Value Declarations
// 1. Description of first class mail item
const char Mail::FIRST_CLASS[] = "First Class";

// Define the external methods for class "Mail" here
Mail::Mail() : type(FIRST_CLASS),weight(fixedWeight), perOunceCost(FixedCost)
{
	//strcpy_s(type, FIRST_CLASS);
}

Mail::Mail(const Mail& other) : type(other.type), weight(move(other.weight)), perOunceCost(other.perOunceCost)
{
	//strcpy_s(type, other.FIRST_CLASS);
}

Mail::~Mail() {

}
Mail::Mail(const char* type, double perOunceCost, int weight):type(type), weight(move(weight)), perOunceCost(perOunceCost) {

}
double Mail::getCost() const {

	return (move(weight) * perOunceCost);
}
ostream& operator<< (ostream& stream, const Mail letter) {

	stream << "Mail Class: " << letter.type << endl;
	stream << "Mail Weight: " << letter.weight << endl;
	stream << "Total Cost: " << letter.getCost() << endl;

	return stream;
}

Mail Mail:: operator=(const Mail& rValue) {

	(this->weight) = (rValue.weight);

	return move(*this);
}
Mail Mail:: operator+(int ounces) {

	//Mail m;
	weight = (weight + ounces);

	return move(*this);
}

/******************************************************************************
 * Class Name: Package
 * Base Class: Mail
 *
 * This file defines the members of the class: Package
 * These members include class variable data members, class constant, static
 * data members, and class method declarations only and/or class method
 * declarations and definitions.
 *
 * Class Description
 * -----------------
 *
 * Class Data Members
 * ------------------
 * Name   Scope    Type                     Description
 * ---- --------- ------ ------------------------------------------------------
 *                ***** add required data member(s) here *****
 *
 * Class Methods
 * -------------
 *           Name            Scope                   Description
 * -----------------------  -------  ------------------------------------------
 * Package(double,int,int)  public   Class Initializing Constructor
 * Package(const Package&)  public   Class Copy Constructor
 * ~Package()               public   Class Destructor
 * operator<<()             public   Overloaded, friend Insertion Operator
 *
 ******************************************************************************
 */
class Package : public Mail
{
	// Public Interface
public:
	// Class Constructor(s)
	Package();
	Package(double cost, int weight, int days);
	Package(const Package&);

	// Class Destructor
	~Package()
	{

	}  // Nothing to do, included for completeness

	// Mutator Methods
	// None

	// Observer Methods
	friend ostream& operator<<(ostream& stream, const Package package);
	static const char EXPRESS_MAIL[];

private:
	// Class static, "const" Constant Values

	const double PACKAGE_COST = 7.50;     // Dollars
	static const int PACKAGE_WEIGHT = 42;
	static const int PACKAGE_DELIVERY_TIME = 3;
	// Variable Declarations
	//  ****** Add required class data member(s) here ******
	int days;

};
// Class "static, const" Value Declarations
// 1. Description of first class mail item
const char Package::EXPRESS_MAIL[] = "Express Mail";

// Define the external methods for class "Package" here
Package::Package():Mail(EXPRESS_MAIL, PACKAGE_COST, PACKAGE_WEIGHT), days(PACKAGE_DELIVERY_TIME) {

}
Package::Package(double cost, int weight, int days):Mail(EXPRESS_MAIL, cost, weight), days(days) {

}
Package::Package(const Package& other) : Mail(other), days(other.days)
{ 
}
//Package::Package(const Package&) 
ostream& operator<<(ostream& stream, const Package package) {

	stream << static_cast<Mail>(package);
	return stream;
}

/******************************************************************************
 * Method: main()
 *
 * Method Description
 * ------------------
 * This Client program will test the various requirements for creating,"
 * copying, adding an "int" value to an object, and assigning one object"
 * to another object. The objects are of two types, 1) A base class,"
 * "Mail", and 2) A derived class (sub-class), "Package".
 *
 * Method Arguments
 * ----------------
 * None
 *
 * Pre-Conditions
 * --------------
 * None
 *
 * Return Value (Post-Condition)
 * -----------------------------
 * Type                              Description
 * ----  ---------------------------------------------------------------
 * int   Program Status to OS: 0 - No errors
 *
 ***************************************************************************
 */
int main()
{
	// Constant "const" Value Declaration
	const int NO_ERRORS = 0;   // Program execution status: No errors

	const int ADDITIONAL_WEIGHT = 5;      // Ounces
	const double PACKAGE_COST = 7.50;     // Dollars
	const int PACKAGE_WEIGHT = 42;        // Ounces
	const int PACKAGE_DELIVERY_TIME = 3;  // Days

	// Initialized ADT Objects
	// 1. A "Mail" object, default type (First class, 1 oz, @ .49 per ounce)
	Mail mailItem1;
	
	// 2. A copy of the default "Mail" object
	Mail mailItem2(mailItem1);

	// 3. An object of type "Package"
	Package package1(PACKAGE_COST, PACKAGE_WEIGHT, PACKAGE_DELIVERY_TIME);
	// 4. A copy of the "Package" object
	Package package2(package1);

	// Initialized Variable Declarations
	int programStatus = NO_ERRORS;  // Assume no program execution errors


   // Describe the program to the User
	cout << "                       PROG-113: Midterm Exam\n\n"
		<< "This Client program will test the various requirements for creating,"
		<< "\ncopying, adding an \"int\" value to an object, and assigning one object"
		<< "\nto another object. The objects are of two types, 1) A base class,"
		<< "\n\"Mail\", and 2) A derived class (sub-class), \"Package\".\n" << endl;


	// Test the Insertion Operator for class "Mail"
	cout << "\"mailItem1\":\n" << mailItem1 << endl;
	cout << "\n\"mailItem2\", a copy of \"mailItem1\":\n"
		<< mailItem2 << endl;

	//// Test the Addition and Assignment Operators, class "Mail"
	mailItem1 = mailItem1 + ADDITIONAL_WEIGHT;
	cout << "\nAdding " << ADDITIONAL_WEIGHT << " oz. to weight of \"mailItem1\":\n"
		<< mailItem1 << endl;
	cout << "\n\"mailItem2\", AFTER adding weight to \"mailItem1\":\n"
		<< mailItem2 << endl;

	cout << "\n\"package1\":\n" << package1 << endl;

	cout << "\n\"package2\", a copy of \"package1\":\n" << package2 << endl;

	cout << "\nCost of \"mailItem1\": " << mailItem1.getCost() << endl;
	cout << "Cost of \"mailItem2\": " << mailItem2.getCost() << endl;
	cout << "Cost of \"package1\":  " << package1.getCost() << endl;



	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return programStatus;

}	// End method: main()
