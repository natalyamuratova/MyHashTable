#pragma once

#include <iostream>
#include "HashTable.h"

using namespace std;

class SeparateChainingTable : public HashTable {
	int capacity;	// емкость таблицы
	int size;		// число элементов в таблице

	struct Node {
		TKey key;
		TValue value;
		Node* next;
	};

	Node** cells;

public:
	SeparateChainingTable(int tableSize);
	SeparateChainingTable(const SeparateChainingTable& table);

	void insert(TKey key, TValue value);
	bool remove(TKey key);
	bool find(TKey key);

	void clear();

	int getSize();
	bool isEmpty();

	TValue get(TKey key);

	void print();

	~SeparateChainingTable();

protected:
	int hash(TKey key);
};