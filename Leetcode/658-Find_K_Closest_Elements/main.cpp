/*!
 * @brief 找到 K 个最接近的元素
 *
 * 给定一个排序好的数组，两个整数 k 和 x，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。如果有两个数与 x 的差值一样，优先选择数值较小的那个数。
 *
 * 说明:
 * k 的值为正数，且总是小于给定排序数组的长度。
 * 数组不为空，且长度不超过 104。
 * 数组里的每个元素与 x 的绝对值不超过 104。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // 思路：https://leetcode-cn.com/problems/find-k-closest-elements/solution/dai-ma-xiang-xi-jie-shi-by-jawhiow/
        // 手画一遍过程就好了
        int left = 0, right = arr.size() - k;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] > arr[mid + k] - x) left = mid + 1;
            else right = mid;
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k - 1);
    }
};

int main() {
    vector<int> nums = {1,2,3,4,5};
    Solution s;
    s.findClosestElements(nums, 4, 3);
    return 0;
}
