/*!
 * @brief 合并区间
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 *
 * @example
 * 输入: [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res = {};

        for (int i = 0; i < intervals.size(); ++i){
            // 不用在前面检车intervals是否为空，本身res在初始化的时候就是空，如果本循环运行不起来的话，则可直接返回为空的res。
            if (res.empty() || res.back()[1] < intervals[i][0]) {
                // 先把第一组放进来，后面每一组再进行比较。
                // res的最后一组的右边界和新组的左边界比较，若res的右边界较小，则说明新组的范围已经和res不连续了，直接push_back新组。
                res.push_back(intervals[i]);
            } else {
                // 若是res与新组连续，则比较双方的右边界，更新res的右边界即可
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    Solution s;
    vector<vector<int>> res = s.merge(intervals);
    for (vector<int> row : res) {
        for (int col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}
