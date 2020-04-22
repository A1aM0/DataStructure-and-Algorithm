/*!
 * @brief 寻找旋转排序数组中的最小值
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 * 请找出其中最小的元素。
 * 你可以假设数组中不存在重复元素。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) {
                // 数组右半边是升序的，即mid是最小的
                right = mid;
            } else {
                // 左半边是升序的
                left = mid + 1;
            }
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
