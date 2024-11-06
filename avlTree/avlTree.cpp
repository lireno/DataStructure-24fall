#include "AvlTree.h"

// Test program
int main() {
    AvlTree<int> tree;

    // Insert elements into the AVL tree
    int elementsToAdd[] = {20, 10, 30, 5, 15, 25, 35, 3, 7, 13, 17};
    std::cout << "Inserting elements: ";
    for (int element : elementsToAdd) {
        std::cout << element << " ";
        tree.insert(element);
    }
    std::cout << "\nTree after insertions:\n";
    tree.printTree();
    std::cout << (tree.isBalanced() ? "Tree is balanced.\n" : "Tree is not balanced!\n");

    // Remove elements and print the tree after each removal
    int elementsToRemove[] = {10, 30, 5, 20};
    for (int element : elementsToRemove) {
        std::cout << "\nRemoving element: " << element << "\n";
        tree.remove(element);
        std::cout << "Tree after removing " << element << ":\n";
        tree.printTree();
        std::cout << (tree.isBalanced() ? "Tree is balanced.\n" : "Tree is not balanced!\n");
    }

    return 0;
}