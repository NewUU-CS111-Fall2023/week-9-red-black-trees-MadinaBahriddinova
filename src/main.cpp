/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include "task_1.h"

int main() {
    std::cout << "Task 1" << std::endl;
    RedBlackTree tree;

    int N, value;
    std::cout << "Enter the number of nodes: ";
    std::cin >> N;

    std::cout << "Enter the values of nodes: ";
    for (int i = 0; i < N; ++i) {
        std::cin >> value;
        tree.insert(value);
    }
    std::cout << "Tree Structure:" << std::endl;
    tree.printTree();
    
    
    std::cout << "Task 2" << std::endl;
    std::cout << "Performing left rotation:" << std::endl;
    tree.leftRotate();
    tree.printTree();

    std::cout << "Performing right rotation:" << std::endl;
    tree.rightRotate();
    tree.printTree();
    
    
    std::cout << "Task 3" << std::endl;
    std::cout << "Enter the number of nodes: ";
    std::cin >> N;

    std::cout << "Enter the values of nodes: ";
    for (int i = 0; i < N; ++i) {
        std::cin >> value;
        tree.insert(value);
    }

    std::cout << "Tree Structure:" << std::endl;
    tree.printTree();

    int deleteValue;
    std::cout << "Enter the value to delete: ";
    std::cin >> deleteValue;
    tree.deleteNode(deleteValue);

    std::cout << "Tree Structure after deletion:" << std::endl;
    tree.printTree();
    
    
    std::cout << "Task 4" << std::endl;
    std::cout << "Enter the number of nodes: ";
    std::cin >> N;

    std::cout << "Enter the values of nodes: ";
    for (int i = 0; i < N; ++i) {
        std::cin >> value;
        tree.insert(value);
    }

    std::cout << "Tree Structure:" << std::endl;
    tree.printTree();
    
    
    std::cout << "Task 5" << std::endl;
    // call for task 5
    return 0;
}
