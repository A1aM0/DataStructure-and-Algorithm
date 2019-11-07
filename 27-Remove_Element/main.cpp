/*!
 * @brief 移除元素
 *
 * 给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
 * 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
 * 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0; ///< 空向量的话直接返回0
        vector<int>::iterator it;
        int i = 0; ///< 计数
        for(it = nums.begin(); it < nums.end(); ){
            if(val == *it) nums.erase(it);
            else {
                ++it;
                ++i;
            }
        }
        return nums.size();
    }

    /*!
     * 双指针，快指针遍历数组，慢指针指向符合条件的元素
     * 和上面的思路差不多
     */
    int removeElement2(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        int i = 0, j = 0;
        for(i, j; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[j] = nums[i];
                ++j;
            }
        }
        return j;
    }
};

int main() {
    vector<int> num1 = {3, 2, 2, 3};
    int val1 = 3;
    vector<int> num2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    vector<int> num0 = {};
    int val0 = 0;
    Solution solution;
    cout << solution.removeElement(num0,val0);
    return 0;
}