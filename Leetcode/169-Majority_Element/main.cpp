/*!
 * @brief 多数元素
 *
 * 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 */

#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    // 暴力的话就用哈希记录，线性时间，空间O(n)，
    // 但是还可以用传说中的摩尔投票法，真的奇妙
    int majorityElement(vector<int>& nums) {
        int cnt = 0, majEle;
        for (int num : nums) {
            if (!cnt) majEle = num;
            if (num == majEle) cnt++;
            else cnt--;
        }
        return majEle;
    }
};

int main() {
    vector<int> nums{2,2,1,1,1,2,2};
    Solution s;
    std::cout << s.majorityElement(nums) << std::endl;
    return 0;
}
