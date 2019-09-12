/*!
 * @brief 删除排序数组中的重复项
 *
 * 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
 * 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*!
 * 已经是有序向量了，则不需要对每一个元素遍历整个向量来检查重复项
 * 只用检查该元素的相邻位置是否重复
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /// 遍历
//        int len = nums.size();
//        int tmp = 0;
//        vector<int>::iterator it;
//        for(int i = 0; i < len; i++){
//            for(it = nums.begin(), tmp = 0; it < nums.end(); ){
//                if(*it == nums[i]) {
//                    if(tmp == 0){
//                        tmp = 1;
//                        ++it;
//                    } else nums.erase(it);
//                } else ++it;
//            }
//        }
//        return nums.size();
        /// 只检查相邻元素
        int slow = 0;
        if(nums.empty()) return 0;
        for(int fast = 1; fast < nums.size(); fast++){
            if(nums[fast] == nums[slow]) continue;
            else{
                ++slow;
                nums[slow] = nums[fast];
            }
        }
        return ++slow;
    }
};

int main() {
    vector<int> nums = {1, 1, 2};
    vector<int> nums_empty = {}; ///< 还需要测试空向量
    Solution result;
    int len = result.removeDuplicates(nums_empty);
    cout << "new len = " << len << endl;
    for(int i = 0; i < len; i++){
        cout << nums[i] << endl;
    }

    return 0;
}