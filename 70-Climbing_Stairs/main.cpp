/*!
 * @brief 爬楼梯
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 注意：给定 n 是一个正整数。
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        // 对于中间的某个台阶，到达该台阶的可能性d[i] = d[i-1] + d[i-2]，状态转移方程就得到了
        std::vector<int> possibility{1, 2};
        if (n <= 2) return possibility[n - 1];
        for (int i = 2; i < n; ++i) {
            possibility.push_back(possibility[i - 1] + possibility[i - 2]);
        }
        return possibility[n - 1];
        // 其实可以不设置数组，这样空间复杂度是O(n)，直接设置两个变量记录d[i-1]和d[i-2]就行，空间O(1)
    }
};

int main() {
    Solution s;
    std::cout << "Result is " << s.climbStairs(2) << std::endl;
    return 0;
}
