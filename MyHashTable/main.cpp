#include <iostream>

#include "SeparateChainingTable.h"

void test(SeparateChainingTable table) {
    table.insert(3, 1);
    table.insert(4, 4);
    table.print();
    std::cout << std::endl;
}

int main() {
    SeparateChainingTable table(10);

    table.insert(1, 1);
    table.insert(1, 2);
    table.insert(2, 1);
    table.print();
    std::cout << std::endl;

    test(table);

    table.print();
    std::cout << std::endl;

    try {
        std::cout << table.get(7);
    }
    catch (std::string e) {
        std::cout << "Search value not found.";
    }


    return 0;
}