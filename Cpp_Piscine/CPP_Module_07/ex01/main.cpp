#include <iostream>
#include <string>
#include "Iter.hpp"

void func1(int &num) {
    num+=2;
}

void func2(std::string &str) {
    str = str.substr(1);
}

int main() {
    int arr1[5] = {1, 2, 3, 4, 5};
    iter(arr1, 5, &func1);
    for (int i = 0; i < 5; i++)
        std::cout << arr1[i] << " ";
    std::cout << std::endl;
    std::string arr2[5] = {"test1", "test2", "test3", "test4", "test5"};
    iter(arr2, 5, &func2);
    for (int i = 0; i < 5; i++)
        std::cout << arr2[i] << " ";
    std::cout << std::endl;
    return 0;
}