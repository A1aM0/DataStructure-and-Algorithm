/*!
 * @brief 跳跃游戏
 *
 * 给定一个非负整数数组，你最初位于数组的第一个位置。
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 判断你是否能够到达最后一个位置。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxCanReach = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (maxCanReach < i) return false;
            maxCanReach = max(maxCanReach, i + nums[i]);
        }
        return true;
    }
};

int main() {
    vector<int> nums = {2,3,1,1,4}; // T
    vector<int> nums2 = {3,2,1,0,4}; // F
    Solution s;
    cout << "result is: " << (s.canJump(nums) ? "true" : "false") << endl;
    return 0;
}
