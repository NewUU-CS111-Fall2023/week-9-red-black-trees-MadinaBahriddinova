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

    // Given tree nodes
    tree.insert(9);
    tree.insert(10);
    tree.insert(13);
    tree.insert(3);
    tree.insert(6);
    tree.insert(2);
    tree.insert(7);
    tree.insert(5);

    std::cout << "Initial Red-Black Tree (inorder traversal):" << std::endl;
    tree.inorder();

    // Inserting 4 to the tree
    tree.insert(4);
    std::cout << "Red-Black Tree after inserting 4 (inorder traversal):" << std::endl;
    tree.inorder();

    std::cout << "Task 2" << std::endl;
    // call for task 2
    std::cout << "Task 3" << std::endl;
    // call for task 3
    std::cout << "Task 4" << std::endl;
    // call for task 4
    std::cout << "Task 5" << std::endl;
    // call for task 5
    return 0;
}
