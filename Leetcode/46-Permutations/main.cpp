/*!
 * @brief 全排列
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        backTrack(nums, 0);
        return res;
    }
    void backTrack (vector<int> &nums, int start) {
        if (start == nums.size()) {
            res.emplace_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            backTrack(nums, start + 1);
            swap(nums[i], nums[start]);
        }
    }
};

int main() {
    Solution s;
    vector<int> nums{1, 2, 3};
    vector<vector<int>> res = s.permute(nums);
    for (vector<int> row : res) {
        for (int num : row) {
            std::cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
