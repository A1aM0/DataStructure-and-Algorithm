/*!
 * @brief 四数之和
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
 * 使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 *
 * 注意：
 * 答案中不可以包含重复的四元组。
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /*!
     * 将 nums 升序排序，并把答案四元组中没确定的个数设为 n。
     *
     * 把剪枝分为了 4 类，括号内的是用什么完成剪枝：
     *
     * 如果剩余可选的数字数量少于 n，则剪掉（递归返回）；
     *
     * 每层递归中，从第二轮循环开始，如果数组中当前数字和前一个相同，则剪掉（进行下一次循环，这条的任务就是去重）；
     *
     * 如果 当前数字 + 已确定数字的和 + (n - 1) * 排序后数组中当前数字的下一个数字 > target，
     * 则说明后面的数无论怎么选，加起来都一定大于 target，所以剪掉（递归返回）；
     *
     * 如果 当前数字 + 已确定数字的和 + (n - 1) * 排序后数组最后一个数字 < target，
     * 则说明后面的数无论怎么选，加起来都一定小于 target，所以剪掉（进行下一次循环）；
     */

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        myNums = nums;
        tar = target;
        numSize = nums.size();
        if (numSize < 4)
            return ans;
        dfs(0, 0);
        return ans;
    }

    void dfs (int low, int sum) {
        if (sum == tar && subans.size() == 4)
        {
            ans.emplace_back(subans);
            return;
        }
        for (int i = low; i < numSize; ++i)
        {
            if (numSize - i < int(4 - subans.size())) //剪枝
                return;
            if (i > low && myNums[i] == myNums[i - 1]) //去重
                continue;
            if (i < numSize - 1 && sum + myNums[i] + int(3 - subans.size()) * myNums[i + 1] > tar) //剪枝
                return;
            if (i < numSize - 1 && sum + myNums[i] + int(3 - subans.size()) * myNums[numSize - 1] < tar) //剪枝
                continue;
            subans.emplace_back(myNums[i]);
            dfs(i + 1, myNums[i] + sum);
            subans.pop_back();
        }
        return;
    }
    vector<vector<int>> ans;
    vector<int> myNums, subans;
    int tar, numSize;
};

int main() {
    vector<int> nums{1, 0, -1, 0, -2, 2};
    Solution s;
    vector<vector<int>> res = s.fourSum(nums, 0);
    for (auto row : res) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
