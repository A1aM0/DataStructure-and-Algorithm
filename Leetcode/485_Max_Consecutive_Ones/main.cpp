/*!
 * @brief 最大连续1的个数
 * @details 给定一个二进制数组， 计算其中最大连续1的个数。
 *
 * @warning
 * 输入的数组只包含 0 和1；
 * 输入数组的长度是正整数，且不超过 10,000。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.empty()) return 0;
        int result = 0, temp = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) ++temp;
            else {
                result = result > temp ? result : temp;
                temp = 0;
            }
        }
        result = result > temp ? result : temp; ///< 再多比较一次考虑到，数组最后一个数为1，是不会进入到遍历的比较中，只能在后面再比较一次
        return result;
    }
};

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    Solution s;

    cout << "result is: " << s.findMaxConsecutiveOnes(nums);
    return 0;
}