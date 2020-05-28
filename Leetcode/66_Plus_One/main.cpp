/*!
 * @brief 加一
 *
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*!
     * 普通的直接给末位加一就行
     * 坑是末位是9的话要进位，还有9999的进位。
     * @param digits
     * @return
     */
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; i >= 0; i--){
            if(digits[i] == 9){
                digits[i] = 0;
                continue;
            } else{
                digits[i] += 1;
                return digits;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

void printout (vector<int>& nums){
    for (int i = 0; i < nums.size(); i++){
        cout << nums[i];
    }
}
int main() {
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {4,3,2,1};
    vector<int> nums3 = {9, 9, 9};

    Solution s;
    cout << "result: ";
    vector<int> result = s.plusOne(nums3);
    printout(result);
    return 0;
}