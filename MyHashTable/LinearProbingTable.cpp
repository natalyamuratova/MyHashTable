#include "LinearProbingTable.h"

LinearProbingTable::LinearProbingTable(int tableSize) {
	this->capacity = tableSize;
	this->size = 0;
	this->cells = new HashNode[tableSize];
	for (int i = 0; i < tableSize; i++)
		cells[i].state = FREE;
}

LinearProbingTable::LinearProbingTable(const LinearProbingTable& table) {
	this->capacity = table.capacity;
	this->size = table.size;
	this->cells = new HashNode[this->capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->cells[i].value = table.cells[i].value;
		this->cells[i].key = table.cells[i].key;
		this->cells[i].state = table.cells[i].state;
	}
}

int LinearProbingTable::hash(TKey key) {
	return key % capacity;
}

void LinearProbingTable::insert(TKey key, TValue value) {
	if (size == capacity) {
		// rehash();
	}

	int index = hash(key);

	while (cells[index].state == BUSY) {
		index = (index + 1) % capacity;
	}

	cells[index].key = key;
	cells[index].value = value;
	cells[index].state = BUSY;

	size++;
}