/*!
 * @brief 有多少小于当前数字的数字
 *
 * 给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。
 * 换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i] 。
 * 以数组形式返回答案。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> cnt(101);
        for (int num : nums) { // 桶，统计nums里各数字出现的次数
            cnt[num]++;
        }
        for (int i = 1; i < cnt.size(); i++) { // 加法出来，比i小的数有几个（这里的i对应nums里的某个数字）
            cnt[i] += cnt[i - 1];
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) { // 把结果推到res里。0的话没有比他小的数了，所以要推0。
            res.emplace_back(nums[i] == 0 ? 0: cnt[nums[i] - 1]);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums{8, 1, 2, 2, 3};
    vector<int> res = s.smallerNumbersThanCurrent(nums);
    for (int i : res) {
        cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
