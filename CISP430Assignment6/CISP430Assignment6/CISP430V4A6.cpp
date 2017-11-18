// Christos Papadopoulos
// CISP430V4A6.cpp

// Driver file for the assignment 6 program.

#include <stdlib.h>
#include <iostream>
#include <random>
#include "table2.h"

using namespace std;
using namespace CISP430V4A6;

struct RecordType
{
	double data;
	int key;
};

void printTables(Table<RecordType> t1, Table<RecordType> t2);

int main()
{	
	/* Instantiate two Table objects and each with 10 fields. */
	Table<RecordType> table1, table2;
	RecordType record;

	/* Display the two Table objects’ information. */
	cout << "Instantiate two Table objects." << endl << endl;
	printTables(table1, table2);

	/* Use random number generator to generate 70 numbers
	each in between 0~200 for the Table objects. */
	cout << endl << "**Using random number generator generates 70 numbers for the objects.**" << endl << endl << endl;

	record.data = 2.5;
	for (int i = 0; i < 70; i++)
	{ //fill our tables with random numbers (0 - 199)
		record.key = rand() % 201;
		table1.insert(record);
		record.key = rand() % 201;
		table2.insert(record);
	}

	/* Display the two Table objects’ information. */
	printTables(table1, table2);

	/* Removes all the data in first object. */
	cout << endl << "**Calling clear function to clear all contents of first object.**" << endl << endl << endl;
	table1.clear();

	/* Display the two Table objects’ information. */
	printTables(table1, table2);

	/* Using = to assign 2nd object to the first one. */
	cout << endl << "**Using table1 = table2 displays the assignment operator overloading.**" << endl << endl << endl;
	table1 = table2;

	/* Display the two Table objects’ information. */
	printTables(table1, table2);

	system("pause");
	//cout << endl << "Press enter key to continue . . . "; //non-windows end
	//fflush(stdin);
	//getchar();
	return 0;
}

void printTables(Table<RecordType> t1, Table<RecordType> t2)
{
	/* Display the two Table objects’ information. */
	cout << "          Total records in the first Table object is " << t1.size();
	cout << endl << "          Contains of the first object display at below: " << endl;

	for (int i = 0; i < 10; i++)
	{
		t1.print(i);
	}

	cout << "----------------------------------------------------------------------------" << endl << endl;
	cout << "          Total records in the second Table object is " << t2.size();
	cout << endl << "          Contains of the second object display at below: " << endl;

	for (int i = 0; i < 10; i++)
	{
		t2.print(i);
	}

	cout << "=============================================================================" << endl << endl;
}

