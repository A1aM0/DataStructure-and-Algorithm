/*!
 * @brief 数组拆分 I
 * @details
 * 给定长度为 2n 的数组，你的任务是将这些数分成 n 对，例如 (a1, b1), (a2, b2), ..., (an, bn)，使得从 1 到 n 的 min(ai, bi) 总和最大。
 *
 * @warning
 * n 是正整数,范围在 [1, 10000]；
 * 数组中的元素范围在 [-10000, 10000]。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 思路有点像先排序，由小到大，再两两选最小的，这样能让两者间较小的总和能尽量大
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            ++i;
        }
        return sum;
    }
};

int main() {
    vector<int> nums1 = {1, 4, 3, 2};

    Solution s;
    cout << "Sum is " << s.arrayPairSum(nums1);
    return 0;
}