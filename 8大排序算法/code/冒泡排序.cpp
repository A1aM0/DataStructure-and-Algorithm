// 2019-11-18

#include <iostream>
#include <vector>

/// 显示输出
void show(std::vector<int> &array) {
    for (int i = 0; i < array.size(); ++i) {
        std::cout << array[i] << " ";
    }
}

// 时间复杂度O(n^2)
void bubble(std::vector<int> &array) {
    for (int end = array.size() - 1; end > 0; --end) {
        for (int i = 0; i < end; ++i) {
            if (array[i] > array[i+1]) {
                int tmp = array[i];
                array[i] = array[i+1];
                array[i+1] = tmp;
            }
        }
        std::cout << "第" << array.size()-end << "趟结果：";
        show(array);
        std::cout << std::endl;
    }
}

// 优化的冒泡，减少浪费
void bubble2(std::vector<int> &array) {
    bool flag; ///< flag指每趟排序时元素顺序是否发生变化
    for (int end = array.size() - 1; end > 0; --end) {
        flag = false;
        for (int i = 0; i < end; ++i) {
            if (array[i] > array[i+1]) {
                int tmp = array[i];
                array[i] = array[i+1];
                array[i+1] = tmp;
                flag = true;
            }
        }
        if (flag == false) break;
        std::cout << "第" << array.size()-end << "趟结果：";
        show(array);
        std::cout << std::endl;
    }
}

int main() {
    std::vector<int> array = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};

    std::cout << "输入：";
    show(array);
    std::cout << std::endl;

    bubble2(array);
    return 0;
}