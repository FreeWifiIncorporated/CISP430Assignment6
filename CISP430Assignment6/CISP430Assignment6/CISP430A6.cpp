/*
Nathan Yarrison
CISP 430
Assignment 6
11/16/2017
*/
// Driver file for the assignment 6 program.

#include <stdlib.h>
#include <iostream>
#include <random>
#include "table2.h"

using namespace std;
using namespace CISP430_A6;

int main()
{
	// Instantiate two table objects.
	cout << "Instantiate two Table objects." << endl << endl;
	//typedef int RecordType;
	Table<RecordType> table1;
	Table<RecordType> table2;
	Table<RecordType> emptyTable;

	// Display initial results.
	cout << "          Total records in the first Table object is " << table1.size() << endl;
	cout << "          Contents of the first object displayed below:" << endl;
	
	int index = 0;
	while (index < 10)
	{
		table1.print(index);
		++index;
	}

	default_random_engine generator;
	uniform_int_distribution<int> distribution(0, 200);

	index = 0;
	RecordType tableEntry;
	while (index < 70)
	{
		tableEntry.key = index;
		tableEntry.record = distribution(generator);
		table1.insert(tableEntry);
		++index;
	}
	

	system("pause");
	return 0;
}
