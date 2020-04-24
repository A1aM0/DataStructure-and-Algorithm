/*!
 * @brief 寻找旋转排序数组中的最小值 II
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 * 请找出其中最小的元素。
 * 注意数组中可能存在重复的元素。
 *
 * 说明：
 * 这道题是 153-寻找旋转排序数组中的最小值 的延伸题目。
 * 允许重复会影响算法的时间复杂度吗？会如何影响，为什么？
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        // 二分法
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) right = mid; // 当 nums[mid] < nums[right] ，那么最小值一定不在右边界，可能在中间 right = mid
            else if (nums[mid] > nums[right]) left = mid + 1; // 当 nums[mid] > nums[right] 则 最小值一定在右边界 left = mid + 1
            else right--; // 当 nums[mid] == nums[right]，那么最小值一定不在右边界，可能在中间，即 nums 只有一个重复的值，比如 {1,1,1,1,1,1,1}，但因为前面已经去重了，所以这里可以省略
        }
        return nums[left];
    }
};

int main() {
    vector<int> nums = {4,5,6,7,0,1,2}; // min = 0;
    Solution s;
    cout << "result is: " << s.findMin(nums) << endl;
    return 0;
}
