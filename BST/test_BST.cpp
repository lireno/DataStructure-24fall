#include "BST.h" // 假设 BinarySearchTree 类定义在这个头文件中
#include <iostream>

void testBinarySearchTree() {
    BinarySearchTree<int> bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);

    std::cout << "Initial Tree:" << std::endl;
    bst.printTree();

    // 测试删除功能
    bst.remove(7);
    std::cout << "Tree after removing 7:" << std::endl;
    bst.printTree();

    bst.remove(12);
    std::cout << "Tree after removing 12:" << std::endl;
    bst.printTree();

    bst.remove(15);
    std::cout << "Tree after removing 15:" << std::endl;
    bst.printTree();

    bst.remove(10);
    std::cout << "Tree after removing 10:" << std::endl;
    bst.printTree();
}

int main() {
    testBinarySearchTree();
    return 0;
}