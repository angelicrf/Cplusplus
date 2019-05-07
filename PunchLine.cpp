/*****************************************************************************
* Bellevue Class: PROG 113
*           Term: Spring 2019
*     Instructor: Robert Main
*
* Solution/Project Name: Solution-Project5
*             File Name: PunchLine.cpp
*
* This file defines the entry point method, main(), for a C++ Console
* application. When the executable file is selected for execution, the OS
* will transfer execution to the first line of code in method main(). Other
* methods called from main() may be defined here as well.
*
*       Programmer: Angelique Refahiyat
* Assigned Project: 5
*
* Revision     Date                         Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     05/06/2019  Initial Release
*   1.0     05/07/2019  fixed the second method to find the last line from the text file
* 
* ADT (AbstractData Type)Classes Utilized
* ---------------------------------------
* None
*
* Program Inputs
*  Device                              Description
* --------  -------------------------------------------------------------------
* DiskFile  1. File containing the joke question
*           2. File containing the joke punchline, as the last line in the file
*
* Program Outputs
* ---------------
*  Device                            Description
* --------  -------------------------------------------------------------------
* Monitor   Display of all records in the file, indicating each record found
* 
* File Methods
* ------------
*     Name                             Description
* ---------------  ------------------------------------------------------------
* main             Program entry point method
* displayAllLines  Display all lines in the joke file
* displayLastLine  Display the last line (punch line) in the punchline file
*
*******************************************************************************
/
// External Definition files
// 1. C++ Library Files
  // Defines Classes: ifstream and ofstream


// Namespaces utilized in this program


/******************************************************************************
* Method: void displayAllLines(ifstream &J)
*
* Method Description
* ------------------
* Type                              Description
* ----  ----------------------------------------------------------------------
* void   The method displays all lines from the file if the file exists.
*
******************************************************************************
*/
#include <string>    // Defines Class: string
#include <iostream>  // Defines objects and classes used for stream I/O
#include <fstream> 
using namespace std; // Announces to the compiler that members of the
					 // namespace "std" are utilized in this program
void displayAllLines(ifstream &J) {

	string findLine;

	while (getline(J, findLine)) {

		cout << findLine << endl;
	}
	
}
/******************************************************************************
* Method: displayLastLine(ifstream &pl)
*
* Method Description
* ------------------
* Type                              Description
* ----  ----------------------------------------------------------------------
* void   The method displays only the last line from the file if the file exists.
*
******************************************************************************
*/
void displayLastLine(ifstream &pl) {

	string findine = "";

	pl.seekg(-1L, ios::end);

	bool isExist = true;
		while (isExist)
		{
			char f;

				pl.get(f);
			
				if ((int)pl.tellg() <= 1) {

					pl.seekg(0);
					isExist = false;
				}
				else if (f == '\n') {
					isExist = false;
				}
				else {
					pl.seekg(-2L, ios::cur);
				}
		}

	getline(pl, findine);
	cout << findine << endl;
	

}
/******************************************************************************
* Method: main()
* Method Arguments
* ----------------
* None Required
*
* Return Value
* ------------
* Type                              Description
* ----  ----------------------------------------------------------------------
* int   Program execution status
*
******************************************************************************
*/
int main()          
{
	// Constant "const" Value Declarations
	const int NO_ERRORS = 0;
	const int FILE_OPEN_ERROR = 1;
	
	// Initialized Variable Declarations   
	int programStatus = NO_ERRORS;  // Assume no program execution errors
	
	// Uninitialized Variable Declarations
	// 1.Names of files, and file stream objects
	string fileName1, fileName2;
	// 2. File objects
	ifstream jokeFile, punchlineFile;


	// Desribe the assigned project to the User
	cout << "               PROG-113: Project #5\n"
		 << "This program will print a joke and its punch line.\n\n";

   
	// Open the files
	// 1. The joke file
	// Get the file names from the user
	cout << "Enter the name of the joke file (ex. joke.txt): ";
	cin  >> fileName1;

	jokeFile.open(fileName1.data());  
	if (!jokeFile)
	{
		cout << "  The file " << fileName1 << " could not be opened." << endl;
		programStatus = FILE_OPEN_ERROR;
	}

	else
	{	// 2. the punchline file
		cout << "Enter name of punch line file (ex. punchline.txt): ";
		cin  >> fileName2;
		punchlineFile.open(fileName2.data());  
		if (!punchlineFile)
		{
			cout << "  The file " << fileName2 << " could not be opened." << endl;
			programStatus = FILE_OPEN_ERROR;
		}

		else
		{	// Both files were successfully opened for reading...
			cout << endl << endl; 
			// Call method to display contents of the joke file
			displayAllLines(jokeFile);
   
			// Call method to display the last line in the punch line file
			displayLastLine(punchlineFile); 
			cout << endl;

			// Finally, close the files
			jokeFile.close();
			punchlineFile.close();
		}
	}


	// This prevents the Console Window from closing during debug mode
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return programStatus;
	
}	// End Method: main()
