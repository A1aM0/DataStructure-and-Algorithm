/*!
 * @brief 插入区间
 *
 * 给出一个无重叠的 ，按照区间起始端点排序的区间列表。
 * 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.emplace_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); i++) {
            if (res.empty() || res.back().back() < intervals[i][0]) {
                res.emplace_back(intervals[i]);
            } else {
                res.back().back() = max(res.back().back(), intervals[i][1]);
            }
        }
        return res;
    }

    // https://leetcode-cn.com/problems/insert-interval/solution/57-cha-ru-qu-jian-mo-ni-cha-ru-xiang-jie-by-carlsu/
    vector<vector<int>> insert2(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int index = 0;
        while (index < intervals.size() && intervals[index][1] < newInterval[0]) {
            result.push_back(intervals[index++]);
        }
        while (index < intervals.size() && intervals[index][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[index][0], newInterval[0]);
            newInterval[1] = max(intervals[index][1], newInterval[1]);
            index++;
        }
        result.push_back(newInterval);
        while (index < intervals.size()) {
            result.push_back(intervals[index++]);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> intervals{{1, 3}, {6, 9}};
    vector<int> newInterval{2, 5};
    auto result = s.insert(intervals, newInterval);
    for (auto row : result) {
        for (auto e : row) {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}
