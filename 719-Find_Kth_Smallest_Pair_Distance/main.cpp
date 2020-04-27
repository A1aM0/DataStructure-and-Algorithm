/*!
 * @brief 找出第 k 小的距离对
 *
 * 给定一个整数数组，返回所有数对之间的第 k 个最小距离。一对 (A, B) 的距离被定义为 A 和 B 之间的绝对差值。
 *
 * @note
 * 2 <= len(nums) <= 10000.
 * 0 <= nums[i] < 1000000.
 * 1 <= k <= len(nums) * (len(nums) - 1) / 2.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 二分的思路：找到距离对的排序数组，然后就可以把第k个返回了。
    // 相应的，设置一个参考距离，要是每计算出一个距离，都小于等于参考距离，计数器加一。当遍历完后计数器值刚好等于k，那么就返回满足计数条件的最大的那个距离。
    // 两个思路结合的话，参考距离就相当于mid，if(count<k)左右边界应放宽，反之。
    // mid选取：既然mid表示了距离，那么需要一个距离的左右边界，对数组排序后，最小为0，最大为back-front。
    // 查找小于mid的距离：双指针，因为数组已排序，...（语言不会说了，直接看底下for循环）
    // 计数器增减：...（看for循环）
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front();
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0, ref = 0;

            for (int i = 0; i < nums.size(); ++i) {
                while (nums[i] - nums[ref] > mid && ref < nums.size()) ref++;
                count = count + (i - ref);
            }


            if (count < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};

int main() {
    vector<int> nums = {1, 3, 1};
    Solution s;
    std::cout << "result is " << s.smallestDistancePair(nums, 1) << std::endl;
    return 0;
}
