//
// Created by y on 2019/11/29.
//

#include <iostream>
#include <vector>

// 输出
void show(std::vector<int> &array);
// 归并
void mergeSort(std::vector<int> &array);
// 子序列排序及拼接
void subSequenceSort(std::vector<int> &array, int gap);

int main() {
    std::vector<int> array = {9, 1, 5, 3, 4, 2, 6, 8, 7};
    std::cout << "输入：";
    show(array);

    mergeSort(array);
    std::cout << "排序结果：";
    show(array);

    return 0;
}

void show(std::vector<int> &array) {
    for (int i = 0; i < array.size(); ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void mergeSort(std::vector<int> &array) {
    int n = 1; ///< 排序轮数
    for (int gap = 1; gap < array.size(); gap = gap * 2) {
        subSequenceSort(array, gap);

        std::cout << "第" << n++ << "轮结果：";
        show(array);
    }
}

void subSequenceSort(std::vector<int> &array, int gap) {
    std::vector<int> tmp; //
    int i = 0;
    int start1 = 0, end1 = start1 + gap - 1;
    int start2 = end1 + 1, end2 = start2+gap-1 < array.size() ? start2+gap-1 : array.size();

    while (start2 < array.size()) {
        while (start1 <= end1 && start2 <= end2) {
            if (array[start1] <= array[start2]) tmp[i++] = array[start1++];
            else tmp[i++] = array[start2++];
        }
        while (start1 <= end1) tmp[i++] = array[start1++];
        while (start2 <= end2) tmp[i++] = array[start2++];
        start1 = end2 + 1;
        end1 = start1 + gap - 1;
        start2 = end1 + 1;
        end2 = start2+gap-1 < array.size() ? start2+gap-1 : array.size();
    }
    while (start1 < array.size()) tmp[i++] = array[start1++];
    for (int i = 0; i < array.size(); ++i) array[i] = tmp[i];
}