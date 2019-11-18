//
// Created by y on 2019/11/18.
//
#include <iostream>
#include <vector>

/// 显示输出
void show(std::vector<int> &array) {
    for (int i = 0; i < array.size(); ++i) {
        std::cout << array[i] << " ";
    }
}

// 一次划分法 -> 挖坑
void quick(std::vector<int> array) {
    int key = array[0];
    int i = 0, j = array.size() - 1;
    while (i < j) {
        while (i < j && array[j] >= key) --j;
        array[i] = array[j];
        while (i < j && array[i] <= key) ++i;
        array[j] = array[i];
    }
    array[i] = key;
    show(array);
}

int main() {
    std::vector<int> array = {12, 34, 45, 21, 4, 6, 33, 53, 15, 5};
    std::cout << "输入：";
    show(array);
    std::cout << std::endl;

    quick(array);
}
