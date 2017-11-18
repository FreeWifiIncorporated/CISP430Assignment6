/*
	Nathan Yarrison
	CISP 430
	Assignment 6
	11/16/2017
*/
// Header file for Table class. Template Class.
// This class is a container table class for a Table of records.
// The table parameter, RecordType, is the data type of the records in Table.
// It may be any type with a default constructor, a copy constructor, an assignment operator, and an integer member variable key.

// FUNCTIONS IN TABLE2 CLASS:
// Constructors and destructors:
/*
	template <class RecordType>
	Table();
	Postcondition: The Table has been initialized as an empty Table.
*/

/*
	template <class RecordType>
	Table(const table& source);
	Postcondition: Copy of source table is made.
*/

/*
	template <class RecordType>
	~Table();
	Postcondtion: The table has been deleted from memory.
*/

// MODIFICATION MEMBER FUNCTIONS:
/*
	template <class RecordType>
	void insert(const RecordType& entry);
	Precondition: entry>= 0. Also if entry is not already a key in the table, then the Table has space for another record.   (i.e., size( ) < CAPACITY).
	Postcondition: If the table already had a record with a key equal to entry, then that record is replaced by entry. Otherwise, the entry will be added as a new record of the Table.
*/

/*
	template <class RecordType>
	void remove(int key);
	Postcondition: If a record was in the Table with the specified key, then that record has been removed; otherwise the table is unchanged.
*/

/*
	template <class RecordType>
	void operator=(const Table& source);
	Postcondition: values from source table have been assigned to the target table.
*/

/*
	template <class RecordType>
	void print(int index);
	Postcondition: If the Table with the index has data, then print the index and data in a chaining format.
*/

/*
	template <class RecordType>
	void clear();
	Postcondtition: The table has been cleared of all values.
*/

// CONSTANT MEMBER FUNCTIONS:
/*
	template <class RecordType>
	bool isPresent(const RecordType& target);
	Postcondition: The return value is true if there is a record in the Table with the specified key. Otherwise, the return value is false.
*/

/*
	template <class RecordType>
	void find(int key, bool& found, RecordType& result) const;
	Postcondition: If a record is in the Table with the specified key, then found is true and result is set to a copy of the record with that key.  
	Otherwise found is false and the result contains garbage.
*/

/*
	template <class RecordType>
	size_t size() const;
	Postcondtion: Value returned is the number of records in the Table.
*/

#ifndef table2_H
#define table2_H
#include <stdlib.h>
#include <iostream>
#include "link2.h"

using namespace std;

namespace CISP430_A6
{
	template <class RecordType>
	class Table
	{
	public:
		// MEMBER CONSTANT
		static const size_t TABLE_SIZE = 10;

		// Constructors and destructor.
		Table();
		Table(const Table& source);
		~Table();

		// Modification member functions.
		void insert(const RecordType& entry);
		void remove(int key);
		void operator=(const Table& source);
		void print(int index);
		void clear();

		// Constant member functions.
		bool is_present(int key) const;
		void find(int key, bool& found, RecordType& result) const;
		size_t size() const { return total_records; };

	private:
		Node<RecordType> *data[TABLE_SIZE];
		size_t total_records;

		// Helper functions:
		size_t hash(int key) const;
	};
}
#include "table2.template" // Include implementation.
#endif