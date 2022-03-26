#include <iostream>
#include <string>
#include "SeparateChainingTable.h"
#include "LinearProbingTable.h"

int main() {
    LinearProbingTable table(10);

    table.insert(1, 1);
    table.insert(1, 2);
    table.insert(2, 1);
    table.print();
    std::cout << std::endl;

    if (table.find(2)) {
        std::cout << "element found" << std::endl;
    }
    else {
        std::cout << "not found" << std::endl;
    }

    try {
        TValue val = table.get(5);
    }
    catch (std::string obj) {
        std::cout << obj << '\n';
   }

    table.remove(1);
    table.remove(2);
    table.print();
    std::cout << std::endl;

    return 0;
}