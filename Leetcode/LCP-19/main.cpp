/*!
 * @brief 力扣杯-秋叶收藏集
 *
 * 小扣出去秋游，途中收集了一些红叶和黄叶，他利用这些叶子初步整理了一份秋叶收藏集 leaves， 字符串 leaves 仅包含小写字符 r 和 y， 其中字符 r 表示一片红叶，字符 y 表示一片黄叶。
 * 出于美观整齐的考虑，小扣想要将收藏集中树叶的排列调整成「红、黄、红」三部分。
 * 每部分树叶数量可以不相等，但均需大于等于 1。
 * 每次调整操作，小扣可以将一片红叶替换成黄叶或者将一片黄叶替换成红叶。
 * 请问小扣最少需要多少次调整操作才能将秋叶收藏集调整完毕。
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    /*!
     * f[i][j]表示对于第 0 片到第 i 片叶子（记为 leaves[0..i]）进行调整操作，并且第 i 片叶子处于状态 j 时的最小操作次数
     * 当 j=0 时，我们需要将第 i 片叶子变成红色，并且第 i−1 片叶子也只能处于 j=0 的状态（因为没有编号更小的状态了），因此有状态转移方程：
     * f[i][0] = f[i-1][0] + isYellow(i)
     *
     * 其中 isYellow(i) 为示性函数，当第 i 片叶子为黄色时为 1，红色时为 0。
     *
     * 当 j=1 时，我们需要将第 i 片叶子变成黄色，而第 i−1 片叶子既可以处于 j=1 的状态，也可以处于 j=0 的状态，我们选择其中的较小值，因此有状态转移方程：
     * f[i][1]=min{f[i−1][0],f[i−1][1]}+isRed(i)
     * 其中 isRed(i) 为示性函数，当第 i 片叶子为红色时为 1，黄色时为 0。
     *
     * 当 j=2 时，我们需要将第 i 片叶子变成红色，而第 i−1 片叶子即可以处于 j=2 的状态，也可以处于 j=1 的状态
     * （注意这里不能处于 j=0 的状态，因为每一种状态包含的叶子数量必须至少为 1），我们选择其中的较小值，因此有状态转移方程：
     * f[i][2]=min{f[i−1][1],f[i−1][2]}+isYellow(i)
     *
     * 最终的答案即为 f[n-1][2]f[n−1][2]，其中 nn 是字符串 leaves 的长度，也就是树叶的总数。
     *
     * @param leaves 乱序的叶子
     * @return result
     */
    int minimumOperations(string leaves) {
        vector<vector<int>> dp(leaves.size(), vector<int>(3, 0));
        dp[0][0] = (leaves[0] == 'y');
        dp[0][1] = dp[0][2] = dp[1][2] = INT_MAX;
        for (int i = 1; i < leaves.size(); i++) {
            dp[i][0] = dp[i - 1][0] + (leaves[i] == 'y');
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (leaves[i] == 'r');
            if(i >= 2) dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + (leaves[i] == 'y');
        }
        return dp.back().back();
    }
};

int main() {
    string leaves1 = "rrryyyrryyyrr";
    string leaves2 = "ryr";
    Solution s;
    std::cout << s.minimumOperations(leaves1) << std::endl; // 2
    std::cout << s.minimumOperations(leaves2) << std::endl; // 1
    return 0;
}
