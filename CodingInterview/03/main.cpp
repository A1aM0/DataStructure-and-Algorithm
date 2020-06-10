/*!
 * @brief 03. 数组中重复的数字
 *
 * 找出数组中重复的数字。
 * 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
 * 数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
 * 请找出数组中任意一个重复的数字。
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) { // 空间换时间，时间O(n)，空间O(n)
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); ++i) {
            if (set.count(nums[i]) > 0) return nums[i];
            set.insert(nums[i]);
        }
        return 0;
    }
    int findRepeatNumber2(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) return nums[i];
        }
        return 0;
    }
    int findRepeatNumber3(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (i != nums[i]) {
                if (nums[i] == nums[nums[i]]) return nums[i];
                swap(nums[i], nums[nums[i]]);
            }
        }
        return 0;
    }
};

int main() {
    vector<int> nums{2, 3, 1, 0, 2, 5, 3};
    Solution s;
    std::cout << s.findRepeatNumber3(nums) << std::endl;
    return 0;
}
