#include <iostream>
#include <string>
#include <stdexcept>

#include "HufffmanBinaryTree.h"

void HuffmanBinaryTree::insert(int value, std::string key)
{
    std::cout << "add key: " << key << std::endl;
    add(0, value, key);
}

int HuffmanBinaryTree::getNextIndex() {
    // TODO: make sure that this check is correct
    if (nextIndex > treeSize) {
        throw std::out_of_range("out of range");
    }
    nextIndex++;
    std::cout << "create index: " << nextIndex << std::endl;
    return nextIndex;
}

int HuffmanBinaryTree::add(int index, int value, std::string key)
{
    if (key == "") {
        std::cout << "add content index: " << index << std::endl;
        tree[index].payload = value;
        tree[index].filled = true;
    } else {
        char first = key.at(0);
        std::string childKey = key.substr(1);
        if (first == '0') {
            if (tree[index].left == 0) {
                tree[index].left = getNextIndex();
            }
            add(tree[index].left, value, childKey);
        } else {
            if (tree[index].right == 0) {
                tree[index].right = getNextIndex();
            }
            add(tree[index].right, value, childKey);
        }
    }
}

int HuffmanBinaryTree::at(std::string key)
{
    return get(0, key);
}

int HuffmanBinaryTree::get(int index, std::string key)
{
    if (key == "") {
        if (tree[index].filled) {
            std::cout << "get content index: " << index << std::endl;
            return tree[index].payload;
        } else {
            throw std::out_of_range("out of range");
        }
    } else {
        char first = key.at(0);
        std::string childKey = key.substr(1);
        if (first == '0') {
            if (tree[index].left > 0) {
                return get(tree[index].left, childKey);
            } else {
                throw std::out_of_range("out of range");
            }
        } else {
            if (tree[index].right > 0) {
                return get(tree[index].right, childKey);
            } else {
                throw std::out_of_range("out of range");
            }
        }
    }
}
