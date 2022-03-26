#include "HashTable.h"

#pragma once

class LinearProbingTable : public HashTable {
	int capacity;	// max value of cells number in table
	int size;		// current value of cells number in table

	const int FREE = 0;
	const int BUSY = 1;
	const int REMOVED = -1;

	struct HashNode {
		TKey key;
		TValue value;
		int state;
	};

	HashNode* cells;

public:
	LinearProbingTable(int tableSize);
	LinearProbingTable(const LinearProbingTable& table);

	void insert(TKey key, TValue value);
	bool remove(TKey key);
	bool find(TKey key);

	void clear();

	int getSize();
	bool isEmpty();

	TValue get(TKey key);

	void print();

	~LinearProbingTable();

protected:
	int hash(TKey key);
};