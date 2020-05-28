/*!
 * @brief 移动0
 *
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 *
 * @warning
 * 必须在原数组上操作，不能拷贝额外的数组。
 * 尽量减少操作次数。
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static void moveZeroes(vector<int>& nums) { // 空间O(1)，时间O(n)，但是对每次遇到0都要操作，比下面复杂
        int end = nums.size();
        for (int i = 0; i < end; ) {
            if (nums[i] == 0) {
                nums.erase(nums.begin()+i);
                nums.push_back(0);
                end--;
            } else ++i;
        }
    }
    static void moveZeroes2(vector<int> &nums) { // 空间O(1)，时间O(n)，比较快了
        for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); ++cur) {
            if (nums[cur] != 0) swap(nums[lastNonZeroFoundAt++], nums[cur]);
        }
    }
};

int main() {
    vector<int> nums = {0, 1, 0, 3, 12}; // output is: 1,3,12,0,0
    vector<int> nums2 = {0, 0, 1}; // output is: 1, 0, 0
    Solution::moveZeroes(nums2);
    for(int i = 0; i < nums2.size(); ++i) cout << nums2[i] << " ";
    cout << endl;
    return 0;
}
