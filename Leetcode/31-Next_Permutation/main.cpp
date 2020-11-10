/*!
 * @brief  下一个排列
 *
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 必须原地修改，只允许使用额外常数空间。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 以排列 [4,5,2,6,3,1]为例：
        // 我们能找到的符合条件的一对「较小数」与「较大数」的组合为 2 与 3，满足「较小数」尽量靠右，而「较大数」尽可能小。
        // 当我们完成交换后排列变为 [4,5,3,6,2,1]，
        // 此时我们可以重排「较小数」右边的序列，序列变为 [4,5,3,1,2,6]。
        // 具体地，我们这样描述该算法，对于长度为 n 的排列 a：
        // 首先从后向前查找第一个顺序对 (i,i+1)，满足 a[i] < a[i+1]。这样「较小数」即为 a[i]。
        // 此时 [i+1,n) 必然是下降序列。
        // 如果找到了顺序对，那么在区间 [i+1,n) 中从后向前查找第一个元素 j 满足 a[i]<a[j]。
        // 这样「较大数」即为 a[j]。
        // 交换 a[i] 与 a[j]，此时可以证明区间 [i+1,n) 必为降序。
        // 我们可以直接使用双指针反转区间 [i+1,n) 使其变为升序，而无需对该区间进行排序。

        if (nums.size() < 2) return;
        int i = nums.size() - 2;
        for (; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) break;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            for (; j > i; j--) {
                if (nums[j] > nums[i]) break;
            }
            swap(nums[i], nums[j]);
        }
        for (int l = i + 1, r = nums.size() - 1; l < r; l++, r--) {
            swap(nums[l], nums[r]);
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
