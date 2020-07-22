/*!
 * @brief 旋转数组的最小数字
 *
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 * 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
 * 例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        // 二分找最小值
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (numbers[r] > numbers[mid]) r = mid;
            else if (numbers[r] < numbers[mid]) l = mid + 1;
            else r--;
        }
        return numbers[l];
    }

    int minArray2 (vector<int> &nums) {
        // 顺序遍历，本来应是递增的，若遇到比前一个小的，则必为旋转前的最小，二分O(logN)更快
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (nums[i] > nums[(i + 1) % len]) return nums[(i + 1) % len]; // 加一取余，防止旋转之后数组没变，最小的数组在头
        }
        return nums[0]; // 防止数组只有一个元素
    }
};

int main() {
    vector<int> nums = {3,4,5,1,2};
    Solution s;
    std::cout << s.minArray2(nums) << std::endl;
    return 0;
}
