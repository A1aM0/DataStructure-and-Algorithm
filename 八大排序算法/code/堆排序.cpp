//
// Created by y on 2019/11/22.
//

#include <iostream>
#include <vector>

// 显示输出
void show(std::vector<int> &array);
// 堆排序
void heapSort(std::vector<int> &array);
// 构建堆
void adjustHeapElement(std::vector<int> &array, int begin, int end);

int main () {
    std::vector<int> array = {12, 34, 6, 21, 4, 33, 45, 53, 15, 5};
    std::cout << "输入：";
    show(array);

    heapSort(array);

    return 0;
}

void show(std::vector<int> &array) {
    for (int i = 0; i < array.size(); ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void heapSort(std::vector<int> &array) {
    for (int i = (array.size()-1)/2; i >= 0; --i) { // 先构建一个初始的大顶堆，从最后一个父节点向前遍历
        adjustHeapElement(array, i, array.size());
    }
    std::cout << "初始大顶堆：";
    show(array);

    for (int i = array.size()-1; i >= 1; --i) {
        std::swap(array[0], array[i]);
        std::cout << "交换：";
        show(array);

        adjustHeapElement(array, 0, i);
        std::cout << "第" << array.size() - i << "次调整顶堆：";
        show(array);
    }
}

void adjustHeapElement(std::vector<int> &array, int begin, int end) { // 对父节点及子节点比较及交换
    int tmp = array[begin];
    for (int i = begin*2+1; i < end; i = i*2+1) {
        if (array[i] < array[i+1] && i < end - 1) ++i; // 让i指向子节点的最大者
        if (array[i] > array[begin]) { // i和父节点进行比较交换
//            array[begin] = array[i];
            std::swap(array[begin], array[i]);
            begin = i;
        } else break;
//        array[begin] = tmp;
    }
}