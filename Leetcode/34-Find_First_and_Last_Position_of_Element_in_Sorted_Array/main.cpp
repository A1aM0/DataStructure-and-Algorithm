/*!
 *  @brief 在排序数组中查找元素的第一个和最后一个位置
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 如果数组中不存在目标值，返回 [-1, -1]。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range(2, -1);
        if (nums.empty()) return range;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            // 找左边界。所以让=的判定和>放在一起，不用考虑右边界right在target的中间还是两边。
            // 只用找到左边最后一个不是target的坐标，则下一个就是target的起始位置
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        // 虽然找到了左边离target最近的值，但是它的下一个元素可能不是target（因为nums里就没有target）。
        // 因此还需要判断一下左边界left对应的值是不是target，不是的话可以直接返回{-1, -1}了。
        if (nums[left] != target) return range;

        range[0] = left;

        // 让right回到nums.size而不是nums.size-1，是因为如果nums.size==1的话，不会执行下面的while循环，
        // 然后返回left-1 = 0-1 = -1，出错。
        right = nums.size();
        while (left < right) {
            // 找到最右边第一个不是target的位置记为left，右边界就是left-1。
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) left = mid + 1;
            else right = mid;
        }
        range[1] = left - 1;
        return range;
    }
};

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    Solution s;
    std::cout << "result is: " << s.searchRange(nums, 8)[0] << s.searchRange(nums, 8)[1] << std::endl;
    return 0;
}
