/*!
 * @brief 组合总和
 *
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * candidates 中的数字可以无限制重复被选取。
 *
 * 说明：
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) { // 明显回溯，但我直接暴力回溯了，没优化
        vector<int> tmp;
        for (int i = 0; i < candidates.size(); i++) {
            dfs(candidates, target, tmp, i);
        }
        return res;
    }
    void dfs (vector<int>& candidates, int target, vector<int> &arr, int pos) {
        arr.emplace_back(candidates[pos]);

        int sum = 0;
        for (int num : arr) sum += num;

        if (sum == target) {
            res.emplace_back(arr);
            arr.pop_back();
            return;
        }
        else if (sum < target) {
            for (int i = pos; i < candidates.size(); i++) {
                dfs(candidates, target, arr, i);
            }
            arr.pop_back();
        }
        else {
            arr.pop_back();
            return;
        }
    }

    vector<vector<int>> res;
};

int main() {
//    vector<int> nums{2, 3, 6, 7};
    vector<int> nums{2, 3, 5};
    Solution s;
//    vector<vector<int>> res = s.combinationSum(nums, 7);
    vector<vector<int>> res = s.combinationSum(nums, 8);
    for (vector<int> row:res) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
