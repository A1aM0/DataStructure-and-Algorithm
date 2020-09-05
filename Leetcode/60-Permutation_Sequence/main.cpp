/*!
 * @brief 第k个排列
 *
 * 给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
 * 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 给定 n 和 k，返回第 k 个排列。
 *
 * 说明：
 * 给定 n 的范围是 [1, 9]。
 * 给定 k 的范围是[1,  n!]。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // https://leetcode-cn.com/problems/permutation-sequence/solution/hui-su-jian-zhi-python-dai-ma-java-dai-ma-by-liwei/
    string getPermutation(int n, int k) {
        vector<bool> isUsed(n + 1, false);          // 用于标记每个数是否用过
        string res = "";                            // 用于返回的结果排列序列

        backTrace(isUsed, res, n, k);
        return res;
    }
    void backTrace(vector<bool> &isUsed, string &res, int n, int k) {
        int res_len = res.size();
        if (res_len == n) {    // 结束条件，当前排列已经结束
            return;
        }
        int remain_fac = factorial(n - res_len - 1);  // 剩下的数的全排列的个数
        for (int i = 1; i <= n; ++i) {                  // 遍历 [1, n]
            if (isUsed[i]) {                            // 跳过已使用的数
                continue;
            }
            if (remain_fac > 0 && remain_fac < k) {     // 剩下的数的全排列个数小于当前 k ，说明第 k 个排列肯定不在当前的递归子树中，直接跳过该递归
                k -= remain_fac;                      // 剪枝
                continue;
            }
            res = res + static_cast<char>('0' + i);
            isUsed[i] = true;
            backTrace(isUsed, res, n, k);
            // 因为是一次递归直接到叶子，所以不需要还原状态
        }
    }
    int factorial(int n) {
        int res = 1;
        while(n > 0){
            res *= n;
            n--;
        }
        return res;
    }
};

int main() {
    Solution s;
    std::cout << s.getPermutation(3, 3) << std::endl;
    std::cout << s.getPermutation(4, 9) << std::endl;
    return 0;
}
