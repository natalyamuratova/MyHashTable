#include <string>
#include <iostream>
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

void rehash() {
	// 0. ��������� ������ ������ cells � tempCells

	// 1. �������� ���������� ���������:
	// �������� capacity
	// �������� ������ ��� ������ � ������������ � capacity (������ cells)

	// 2. ��������� ������ �� ������ ������� � �����:
	// for (int i = 0; i < capacity / 2; i++) {
	//	if (tempCells[i].state == BUSY) {
	//		insert(tempCells[i].key, tempCells[i].value);
	//	}
	// }

	// 3. ���������� ������, ���������� �������� tempCells.
}

void LinearProbingTable::insert(TKey key, TValue value) {
	if (size == capacity) {
		rehash();
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

bool LinearProbingTable::remove(TKey key) {
	int index = hash(key);
	int iteration = 0;

	while (cells[index].state != FREE && cells[index].key != key && iteration < capacity) {
		index = (index + 1) % capacity;
		iteration++;
	}

	if (cells[index].state == FREE || iteration >= capacity) {
		return false;
	}

	cells[index].state = REMOVED;
	size--;
	return true;
}


bool LinearProbingTable::find(TKey key)
{
	int index = hash(key);
	int iteration = 0;

	while (cells[index].state != FREE && cells[index].key != key && iteration < capacity) {
		index = (index + 1) % capacity;
		iteration++;
	}
	return iteration != capacity && cells[index].state == BUSY;
}

TValue LinearProbingTable::get(TKey key)
{
	int index = hash(key);
	int iteration = 0;
	
	while(cells[index].state != FREE && cells[index].key != key && iteration < capacity) {
		index = (index + 1) % capacity;
		iteration++;
	}

	if (iteration == capacity || cells[index].state == FREE) {
		throw std::string("Error: element is not found");
	}

	return cells[index].value;
}


void LinearProbingTable::clear()
{
	for (int i = 0; i < capacity; i++)
		cells[i].state = FREE;

	size = 0;
}

int LinearProbingTable::getSize()
{
	return size;
}

bool LinearProbingTable::isEmpty()
{
	return size == 0;
}

void LinearProbingTable::print() {
	for (int i = 0; i < capacity; i++) {
		std::cout << "[" << i << "]: ";
		if (cells[i].state == BUSY) {
			std::cout << cells[i].value << "(" << cells[i].key << ") ";
		}
		std::cout << std::endl;
	}
}

LinearProbingTable::~LinearProbingTable()
{
	clear();
	delete[] cells;
}
