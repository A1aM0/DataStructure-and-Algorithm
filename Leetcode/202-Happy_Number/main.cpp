/*!
 * @brief 快乐数
 *
 * 编写一个算法来判断一个数 n 是不是快乐数。
 * 「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。如果 可以变为  1，那么这个数就是快乐数。
 * 如果 n 是快乐数就返回 True ；不是，则返回 False 。
 */

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while (n != 1) {
            if (st.count(n) > 0) return false;
            st.insert(n);
            n = cal(n);
        }
        return true;
    }

    int cal(int n) {
        int sum = 0;
        while (n) {
            int tmp = n % 10;
            sum += tmp * tmp;
            n = n / 10;
        }
        return sum;
    }
};

int main() {
    Solution s;
    std::cout << "result is " << s.isHappy(19) << std::endl; // 1+9^2=82,8^2+2^2=68,...1+0+0=1,true
    return 0;
}
