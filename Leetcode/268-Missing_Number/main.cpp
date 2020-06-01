/*!
 * @brief 缺失数字
 *
 * 给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
 *
 * 说明:
 * 你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + i - nums[i];
        }
        return sum + nums.size();
    }
};

int main() {
    std::vector<int> nums{9,6,4,2,3,5,7,0,1};
    Solution s;
    std::cout << s.missingNumber(nums) << std::endl;
    return 0;
}
