/*!
 * @brief 回文数
 *
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 *
 * 进阶:
 * 你能不将整数转为字符串来解决这个问题吗？
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) { // 转成字符串，对比的过程是O(n/2)，但是转化的过程是O(n)，费时
        string str = to_string(x);
        for (int i = 0, j = str.size() - 1; i <= j; ++i, --j) {
            if (str[i] != str[j]) return false;
        }
        return true;
    }
    bool isPalindrome2(int x) { // 为了避免数字反转可能导致的溢出问题，考虑只反转 int 数字的一半，后半部分反转后应该与原始数字的前半部分相同
        int reverseNum = 0;
        if (x % 10 == 0 && x != 0) return false; // 如果数字的最后一位是 0，为了使该数字为回文，则其第一位数字也应该是 0，只有 0 满足这一属性
        if (x < 0) return false; // x < 0 时，x 不是回文数。

        while (x > reverseNum) {
            reverseNum = reverseNum * 10 + x % 10;
            x /= 10;
        }
        return x == reverseNum || x == reverseNum / 10; // 当数字长度为奇数时，可以通过 revertedNumber/10 去除处于中位的数字。由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
    }
};

int main() {
    Solution s;
    std::cout << s.isPalindrome(121) << std::endl;
    return 0;
}
