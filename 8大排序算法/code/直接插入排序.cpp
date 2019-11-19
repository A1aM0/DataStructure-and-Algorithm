//
// Created by y on 2019/11/19.
//
#include <iostream>
#include <vector>

// 显示输出
void show(std::vector<int> &array);
// 排序
void straight_Insertion_Sort(std::vector<int> &array);

int main() {
    std::vector<int> array = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    std::cout << "输入：";
    show(array);
    std::cout << std::endl;

    straight_Insertion_Sort(array);
    std::cout << "结果：";
    show(array);
    std::cout << std::endl;
}

void show(std::vector<int> &array) {
    for (int i = 0; i < array.size(); ++i) {
        std::cout << array[i] << " ";
    }
}

void straight_Insertion_Sort(std::vector<int> &array) {
    int len = array.size();
    for (int i = 1; i < len; ++i) {
        int j = i - 1;
        while (j >= 0 && array[j] > array[j+1]) {// >号限制排序为升序，若要降序的话则可改为<
            std::swap(array[j], array[j+1]);
            --j;
        }
        std::cout << "第" << i << "轮结果：";
        show(array);
        std::cout << std::endl;
    }
}