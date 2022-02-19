#include <iostream>

#include "HashTable.h"
#include "SeparateChainingTable.h"

using namespace std;

void test(SeparateChainingTable table) {
    table.insert(3, 1);
    table.insert(4, 4);
    table.print();
    cout << endl;
}

int main() {
    SeparateChainingTable table(10);

    table.insert(1, 1);
    table.insert(1, 2);
    table.insert(2, 1);
    table.print();
    cout << endl;

    test(table);

    table.print();
    cout << endl;

    return 0;
}