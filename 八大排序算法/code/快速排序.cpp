//
// Created by y on 2019/11/18.
//
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cassert>

void show(std::vector<int> &array);
int partition_WaKeng(std::vector<int> &array, int i, int j);
int partition_TwoPointer(std::vector<int> &array, int left, int right);
void selectKey(std::vector<int> &array, int left, int right, int mode);
void quickSort_recursive(std::vector<int> &array, int begin, int end);

int main() {
    std::vector<int> array = {12, 34, 45, 21, 4, 6, 33, 53, 15, 5};
    std::cout << "输入：";
    show(array);
    std::cout << std::endl;

    quickSort_recursive(array, 0, array.size()-1);

    return 0;
}

/// 显示输出
void show(std::vector<int> &array) {
    for (int i = 0; i < array.size(); ++i) {
        std::cout << array[i] << " ";
    }
}

// 一次划分法 -> 挖坑
int partition_WaKeng(std::vector<int> &array, int i, int j) {
    static int num = 1; ///< 排序次数
    selectKey(array, i, j, 1);
    int key = array[i];
    while (i < j) {
        while (i < j && array[j] >= key) --j;
        array[i] = array[j];
        while (i < j && array[i] <= key) ++i;
        array[j] = array[i];
    }
    array[i] = key;

    std::cout << "第" << num++ << "次排序结果：";
    show(array);
    std::cout << std::endl;
    return i;
}

// 一次划分法 -> 左右指针
int partition_TwoPointer(std::vector<int> &array, int left, int right) {
    selectKey(array, left, right, 1);
    int key = array[left];
    while (left < right) {
        while (array[left] <= key && left < right) ++left;
        while (array[right] >= key && left < right) --right;
        if (left < right) std::swap(array[left], array[right]);
    }
    std::swap(array[left],array[0]);
    show(array);
    return left;
}

// 选取基准数
// mode的作用是控制key的选取方式，1是固定第一个元素，2是随机，3是三分取中
void selectKey(std::vector<int> &array, int left, int right, int mode) {
    if (mode == 1) {
        return;
    } else if (mode == 2) {
        std::default_random_engine e(time(nullptr));
        std::uniform_int_distribution<unsigned> u(0, array.size()-1);
        std::swap(array[left], array[u(e)]);
    } else if (mode == 3) {
        int mid = (left + right) >> 1;
        if (array[left] > array[mid]) std::swap(array[left], array[mid]);
        if (array[mid] > array[right]) std::swap(array[mid], array[right]);
        if (array[mid] > array[left]) std::swap(array[mid], array[left]);
    } else assert(false && "基准数选取有错");
}

// 递归调用
void quickSort_recursive(std::vector<int> &array, int begin, int end) {
    int position = partition_WaKeng(array, begin, end);
    if (begin < position - 1) quickSort_recursive(array, begin, position - 1);
    if (end > position - 1) quickSort_recursive(array, position + 1, end);
}