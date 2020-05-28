/*!
 * @brief 二分查找
 *
 * 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (target < nums[mid]) high = mid - 1;
            else if (target > nums[mid]) low = mid + 1;
            else if (target == nums[mid]) return mid;
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {-1,0,3,5,9,12};
    Solution s;
    cout << "result is: " << s.search(nums, 2);
    return 0;
}
