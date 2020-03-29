/*!
 * @brief 存在重复元素
 *
 * @details
 * 给定一个整数数组，判断是否存在重复元素。
 * 如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    static bool containsDuplicate(vector<int>& nums) { // 先排序，再一一对应过去。或者哈希表。
        return false;
    }
};

int main() {
//    vector<int> nums = {1, 2, 3, 1}; // output is true
    vector<int> nums = {1, 2, 3, 4}; // output is false
//    vector<int> nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2}; // output is true
//    vector<int> nums = {3, 1};
    cout << "result is " << Solution::containsDuplicate(nums) << endl;
    return 0;
}
