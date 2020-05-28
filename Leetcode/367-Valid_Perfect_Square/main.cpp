/*!
 * @brief 有效的完全平方数
 *
 * 给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
 * 说明：不要使用任何内置的库函数，如sqrt。
 */
#include <iostream>

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) return true;
        int left = 0, right = num / 2;
        while (left <= right) {
            // 用long为了防止mid*mid越界
            long mid = left + (right - left) / 2;
            long square = mid * mid;
            if (square == num) return true;
            else if (square > num) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};

int main() {
    Solution s;
    std::cout << "result is " << (s.isPerfectSquare(9) ? "true" : "false") << std::endl;
    return 0;
}
