//
// Created by y on 2019/11/20.
//

#include <iostream>
#include <vector>

// 显示输出
void show(std::vector<int> &array);
// 希尔排序
void shell_Sort(std::vector<int> &array, std::vector<int> &gap);
// 插入排序
void straight_Insertion_Sort(std::vector<int> &array, int step);

int main () {
    std::vector<int> array = {3, 44, 38, 5, 47, 15, 36,
                              26, 27, 2, 46, 4, 19, 50, 48};
    std::cout << "输入：";
    show(array);
    std::cout << std::endl;

    std::vector<int> gap = {5, 2, 1};
    std::cout << "排序增量：";
    show(gap);
    std::cout << std::endl;

    shell_Sort(array, gap);
    std::cout << "结果：";
    show(array);
    std::cout << std::endl;
}

void show(std::vector<int> &array) {
    for (int i = 0; i < array.size(); ++i) {
        std::cout << array[i] << " ";
    }
}

void shell_Sort(std::vector<int> &array, std::vector<int> &gap){
    int n = 1; ///< 排序计数
    for (int i = 0; i < gap.size(); ++i) {
        straight_Insertion_Sort(array, gap[i]);

        std::cout << "第" << n++ << "轮结果：";
        show(array);
        std::cout << std::endl;
    }
}

void straight_Insertion_Sort(std::vector<int> &array, int gap) {
    for (int i = 0; i + gap < array.size(); ++i) {
        int j = i;
        while (j >= 0 && array[j] > array[j+gap]) {
            std::swap(array[j], array[j+gap]);
            j -= gap;
        }
    }
}