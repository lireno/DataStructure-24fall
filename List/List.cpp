#include "List.h"
#include <iostream>

void testList() {
    // 测试默认构造函数
    List<int> myList;
    std::cout << "List initialized. Size: " << myList.size() << std::endl;

    // 测试插入元素到列表尾部
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    std::cout << "After push_back 10, 20, 30: ";
    myList.printList(); // 输出列表

    // 测试插入元素到列表头部
    myList.push_front(5);
    std::cout << "After push_front 5: " << std::endl;
    myList.printList(); // 输出列表

    // 测试动态迭代器的 ++ 和 -- 运算符
    std::cout << "Testing dynamic iterator ++ and --:" << std::endl;
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " "; // 测试前置++运算符
    }
    std::cout << std::endl;

    // 测试后置++运算符
    std::cout << "Using post-increment (it++): " << std::endl;
    for (auto it = myList.begin(); it != myList.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 测试前置--运算符
    std::cout << "Using pre-decrement (--it): " << std::endl;
    auto it = myList.end();
    --it; // 迭代器指向最后一个元素
    while (it != myList.begin()) {
        std::cout << *it << " ";
        --it; // 前置自减
    }
    std::cout << *it << " "; // 输出第一个元素
    std::cout << std::endl;

    // 测试后置--运算符
    std::cout << "Using post-decrement (it--):" << std::endl;
    it = myList.end();
    it--; // 后置自减
    while (it != myList.begin()) {
        std::cout << *it << " ";
        it--;
    }
    std::cout << *it << " "; // 输出第一个元素
    std::cout << std::endl;
    std::cout << "---" << std::endl;

    // 测试输出头部元素和尾部元素
    std::cout << "Front element: " << myList.front() << std::endl;
    std::cout << "Back element: " << myList.back() << std::endl;

    // 测试删除头部和尾部元素
    myList.pop_front();
    std::cout << "After pop_front: ";
    myList.printList();

    myList.pop_back();
    std::cout << "After pop_back: ";
    myList.printList();

    // 测试插入多个元素
    myList.push_back(40);
    myList.push_back(50);
    std::cout << "After push_back 40, 50: ";
    myList.printList();

    // 测试删除指定位置的元素
    it = myList.begin();
    ++it;
    myList.erase(it);
    std::cout << "After erasing second element: ";
    myList.printList();

    // 测试拷贝构造函数
    List<int> copyList = myList;
    std::cout << "After copying myList to copyList: ";
    copyList.printList();

    // 测试赋值运算符
    List<int> assignedList;
    assignedList = myList;
    std::cout << "After assigning myList to assignedList: ";
    assignedList.printList();

    // 测试移动构造函数
    List<int> movedList = std::move(assignedList);
    std::cout << "After moving assignedList to movedList: ";
    movedList.printList();
    std::cout << "After moving, is assignedList empty? " << (assignedList.empty() ? "Yes" : "No") << std::endl;

    // 测试插入和删除右值引用
    myList.push_back(60);
    myList.push_front(1);
    std::cout << "After push_back 60 and push_front 1: ";
    myList.printList();

    // 测试 clear 函数
    myList.clear();
    std::cout << "After clear. Is myList empty? " << (myList.empty() ? "Yes" : "No") << std::endl;
}

void testbug() {
    List<int> myList;

    std::cout << "Testing potential bugs in List implementation..." << std::endl;
    std::cout << "the first element of an empty link is " << myList.front() << std::endl;
    std::cout << "the last element of an empty link is " << myList.back() << std::endl;
    myList.erase(myList.begin());
}

int main() {
    testList();
    // testbug();
    return 0;
}
