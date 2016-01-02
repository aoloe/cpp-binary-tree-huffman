#include <iostream>
#include <string>
#include <stdexcept>

#include "HufffmanBinaryTree.h"

int main() {

    HuffmanBinaryTree tree{};

    tree.insert(0, "10110"); // map["10110"] = 0;
    std::cout << "0 at 10110: " << tree.at("10110") << std::endl;
    tree.insert(1, "1011");
    std::cout << "1 at 10110: " << tree.at("1011") << std::endl;

    try {
    std::cout << "exception at 10100: " << tree.at("10100") << std::endl;
    } catch (std::out_of_range) {
        std::cout << "out of range at 10100" << std::endl;
    }

}
