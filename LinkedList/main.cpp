#include "LinkedList.h"
#include <iostream>

int main() {
    // 测试初始化列表构造
    SingleLinkedList<int> list = {1, 2, 3, 4, 5};
    std::cout << "Initial list: ";
    list.printList();

    // 测试插入
    int value = 10;
    list.insert(value);
    std::cout << "After inserting 10: ";
    list.printList();

    // 测试查找
    if (list.find(3)) {
        std::cout << "Found 3, current value: " << list.getCurrentVal() << std::endl;
    } else {
        std::cout << "3 not found." << std::endl;
    }

    // 测试设置当前值
    list.setCurrentVal(30);
    std::cout << "After setting current value to 30: ";
    list.printList();

    // 测试删除
    list.remove();
    std::cout << "After removing current position element: ";
    list.printList();

    // 测试清空链表
    list.emptyList();
    std::cout << "After emptying the list: ";
    list.printList();

    return 0;
}
