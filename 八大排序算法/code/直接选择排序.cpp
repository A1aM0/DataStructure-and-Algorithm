//
// Created by y on 2019/11/21.
//

#include <iostream>
#include <vector>

// 显示输出
void show(std::vector<int> &array);
void straight_Selection_Sort(std::vector<int> &array);

int main () {
    std::vector<int> array = {3, 44, 38, 5, 47, 15, 36,
                              26, 27, 2, 46, 4, 19, 50, 48};
    std::cout << "输入：";
    show(array);
    std::cout << std::endl;

    straight_Selection_Sort(array);

    return 0;
}

void show(std::vector<int> &array) {
    for (int i = 0; i < array.size(); ++i) {
        std::cout << array[i] << " ";
    }
}

void straight_Selection_Sort(std::vector<int> &array) {
    for (int i = 0; i < array.size(); ++i) {
        for (int j = i+1; j < array.size(); ++j) {
            if (array[i] > array[j]) std::swap(array[i], array[j]);
        }
        std::cout << "第" << i << "轮结果：";
        show(array);
        std::cout << std::endl;
    }
}