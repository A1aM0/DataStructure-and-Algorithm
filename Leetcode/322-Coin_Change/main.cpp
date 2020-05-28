/*!
 * @brief 零钱兑换
 *
 * 给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。
 * 如果没有任何一种硬币组合能组成总金额，返回 -1。
 *
 * @example
 * 输入: coins = [1, 2, 5], amount = 11
 * 输出: 3
 * 解释: 11 = 5 + 5 + 1
 *
 * @example
 * 输入: coins = [2], amount = 3
 * 输出: -1
 *
 * @warning
 * 你可以认为每种硬币的数量是无限的。
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        sort(coins.rbegin(), coins.rend()); ///< 降序排列，用反向迭代器
        int count = 0; ///< 记录找到的方案的硬币数
        int res = INT_MAX; ///< 假设是最大解，e.g. 只用coins = [1]，去组合amount = INT_MAX
        int index = 0; ///< 数组下标，0指到最大的那个硬币
        dfs(coins, amount, index, count, res);
        return res == INT_MAX ? -1 : res; ///< 如果无解的话，res还是INT_MAX，就返回-1；反之返回解
    }

private:
    static void dfs(vector<int>coins, int amount, int index, int count, int& res) {
        if (amount == 0) {
            res = min(res, count);
            ///< amount为0意味着找到了硬币组合，所以减到0了，将本次迭代的计数器count值与以前的最小计数器值res比较，找一个最小的
            return;
        }
        if (index == coins.size()) return; ///< 递归过程中，使用到最后一个也即最小的硬币之后，就可以return了；这条主要针对无解的情况，即搜索到最小的硬币了，amount也未减到0，只能直接返回了

        for (int k = amount / coins[index]; k >= 0 && k + count < res; k--) { // 递归
            dfs(coins, amount - k * coins[index], index + 1, count + k, res);
            ///< 下一轮的递归，应减去最大的硬币求和出来的数额，找剩下的数额怎么用次大的硬币求和；
            ///< 相应的，coins数组的下标指向次小的硬币，count计数器增加k个最大硬币的数量
        }
        ///< 用for循环（贪心），先用最大的硬币组合出最接近amount的数额；
        ///< 但是可能少用几个最大的硬币，换成次大甚至稍小一些的硬币，可能会使计数器结果更小
    }
};

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    std::cout << "result is: " << Solution::coinChange(coins, amount) << std::endl;
    return 0;
}
