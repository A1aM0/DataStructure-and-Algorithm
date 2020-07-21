/*!
 * @brief 子集
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 *
 * 说明：解集不能包含重复的子集。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        backTrack(nums, 0, tmp);
        return res;
    }

    void backTrack(vector<int> &nums, int start, vector<int> &track) {
        res.emplace_back(track);
        for (int i = start; i < nums.size(); i++) {
            track.emplace_back(nums[i]);
            backTrack(nums, i + 1, track);
            track.pop_back();
        }
    }
};

int main() {
    vector<int> nums{1, 2, 3};
    Solution s;
    vector<vector<int>> res = s.subsets(nums);
    for (vector<int> row : res) {
        for (int col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}
