/*!
 * @brief 数组中的第K个最大元素
 *
 * 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        quickSort(nums, 0, nums.size() - 1);
        return nums[nums.size() - k];
    }

    void quickSort (vector<int> &arr, int l, int r) {
        if (l < r) {
            int key = arr[l];
            int i = l, j = r;
            while (i < j) {
                while (i < j && arr[j] >= key) j--;
                if (i < j) arr[i++] = arr[j];
                while  (i < j && arr[i] <= key) i++;
                if (i < j) arr[j--] = arr[i];
            }
            arr[i] = key;
            quickSort(arr, l, i - 1);
            quickSort(arr, i + 1, r);
        }
    }
};

int main() {
    vector<int> nums1{3,2,1,5,6,4};
    vector<int> nums2{3,2,3,1,2,4,5,5,6};
    Solution s;
    std::cout << s.findKthLargest(nums1, 2) << std::endl;
    std::cout << s.findKthLargest(nums2, 4) << std::endl;
    return 0;
}
