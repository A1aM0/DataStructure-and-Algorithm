/*!
 * @brief 组合
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        backTrace(res, tmp, n, k, 1);
        return res;
    }
    void backTrace(vector<vector<int>> &res, vector<int> &nums, int n, int k, int insert) {
        // 剪枝：temp 长度加上区间 [cur, n] 的长度小于 k，不可能构造出长度为 k 的 temp
        if (nums.size() + (n - insert + 1) < k) return;

        if (nums.size() == k) { // 记录合法的答案
            res.emplace_back(nums);
            return;
        }

        // 考虑选择当前位置
        nums.emplace_back(insert);
        backTrace(res, nums, n, k, insert + 1);
        nums.pop_back();

        // 考虑不选择当前位置
        backTrace(res, nums, n, k, insert + 1);
    }
};

int main() {
    Solution s;
    vector<vector<int>> res = s.combine(4, 2);
    for (vector<int> row : res) {
        for (int num : row) cout << num << " ";
        cout << endl;
    }
    return 0;
}
