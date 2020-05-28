/*!
 * @brief 合并两个有序数组
 *
 * 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
 *
 * 说明:
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
 * 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) { // 和注释的思路是一样的，隔了好久又写的，论好看和可读性不能比
//        int p = m-1, q = n-1, i = m+n-1;
//        while (p >= 0 || q >=0) {
//            if (q < 0) nums1[i--] = nums1[p--];
//            else if (p < 0) nums1[i--] = nums2[q--];
//            else if (nums1[p] >= nums2[q]) nums1[i--] = nums1[p--];
//            else nums1[i--] = nums2[q--];
//        }
        int tail = m + n - 1;
        for (int i = m - 1, j = n - 1; i >= 0 || j >= 0; tail--) {
            if (i < 0) {
                nums1[tail] = nums2[j];
                j--;
                continue;
            }
            if (j < 0) {
                break;
            }
            if (nums1[i] > nums2[j]) {
                nums1[tail] = nums1[i];
                i--;
            } else {
                nums1[tail] = nums2[j];
                --j;
            }
        }
    }
};

int main() {
    vector<int> nums1{1, 2, 3, 0, 0, 0};
    vector<int> nums2{4, 5, 6};
    Solution s;
    s.merge(nums1, 3, nums2, 3);
    for (auto num : nums1) cout << num << " ";
    return 0;
}
