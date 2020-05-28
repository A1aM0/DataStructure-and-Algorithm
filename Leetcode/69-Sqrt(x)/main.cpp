/*!
 * @brief x的平方根
 *
 * 实现 int sqrt(int x) 函数。
 * 计算并返回 x 的平方根，其中 x 是非负整数。
 * 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
 */
#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int left = 2, right = x / 2;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (mid > x / mid) right = mid - 1;
            else if (mid < x / mid) left = mid + 1;
            else return mid;
        }
        return right;
    }
};

int main() {
    Solution s;
    std::cout << "result is: " << s.mySqrt(2147395599) << std::endl;
    return 0;
}
