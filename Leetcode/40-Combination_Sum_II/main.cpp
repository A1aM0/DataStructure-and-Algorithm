/*!
 * @brief 组合总和 II
 *
 * 给定一个数组 candidates 和一个目标数 target ，
 * 找出 candidates 中所有可以使数字和为 target 的组合。
 * candidates 中的每个数字在每个组合中只能使用一次。
 *
 * 说明：
 * 所有数字（包括目标数）都是正整数。
 * 解集不能包含重复的组合。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 回溯剪枝，剪枝的地方很关键，这个url的图片可以很好的说明一个剪枝的策略，
    // https://pic.leetcode-cn.com/1599709072-OaJSmU-40.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8CII.png。
    // “同一层使用过”就会被减掉，而”同一树使用过“的可以不管。
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> arr;
        sort(candidates.begin(), candidates.end()); // 剪枝策略导致需要先排序
        for (int i = 0; i < candidates.size(); i ++) {
            if (i > 0 && candidates[i] == candidates[i - 1]) continue; // 剪枝
            dfs(res, candidates, arr, i, 0, target);
        }
        return res;
    }

    /// @param res 结果
    /// @param candidates 查找的数组
    /// @param arr 临时保存结果的数组
    /// @param pos 当前将要插入临时数组的数字在candidates里的位置
    /// @param sum 临时和
    /// @param target 目标和
    void dfs (vector<vector<int>> &res, vector<int> &candidates, vector<int> &arr, int pos, int sum, int target) {
        if (pos == candidates.size()) return; // 边界

        sum += candidates[pos];
        arr.emplace_back(candidates[pos]);

        if (sum == target) {
            res.emplace_back(arr);
        }
        else if (sum < target) {
            for (int i = pos + 1; i < candidates.size(); i++) {
                if (i > pos + 1 && candidates[i] == candidates[i - 1]) continue; // 剪枝
                dfs(res, candidates, arr, i, sum, target);
            }
        }

        sum -= candidates[pos]; // 回溯
        arr.pop_back();
    }
};

int main() {
    vector<int> candidates{10,1,2,7,6,1,5};
    Solution s;
    vector<vector<int>> res = s.combinationSum2(candidates, 8);
    for (vector<int> row : res) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
