/*!
 * @brief 旋转数组
 * @details
 * 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
 * @warning
 * 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题；
 * 要求使用空间复杂度为 O(1) 的 原地 算法。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /// 逐个右移，时间O(k)，空间O(1)
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;
        int temp;
        int end = nums.size() - 1;
        for (int i = 0; i < k; ++i) {
            temp =  nums[end];
            nums.erase(nums.begin() + end);
            nums.insert(nums.begin(), temp);
        }
    }

    /// 截取后面的，往前整段的挪，主要是新建了一个数组，不算原地了
    void rotate2(vector<int>& nums, int k) {
        if (nums.empty()) return;
        k = k % nums.size();
        vector<int> temp(nums.end()-k, nums.end());
        nums.erase(nums.end()-k, nums.end());
        nums.insert(nums.begin(), temp.begin(), temp.end());
    }
};

void output(vector<int>& nums, int k) {
    for(int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
}
int main() {
    Solution s;
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7}; //output = [5,6,7,1,2,3,4]
    vector<int> nums2 = {-1, -100 ,3 , 99}; // output = [3,99,-1,-100]
    int k1 = 3, k2 = 2;
    s.rotate2(nums1, k1);
    output(nums1, k1);
    return 0;
}