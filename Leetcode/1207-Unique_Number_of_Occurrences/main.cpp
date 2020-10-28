/*!
 * @brief 独一无二的出现次数
 *
 * 给你一个整数数组 arr，请你帮忙统计数组中每个数的出现次数。
 * 如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        for (int n : arr) {
            map[n]++;
        }
        unordered_set<int> set;
        for (auto p : map) {
            if (set.find(p.second) != set.end()) return false;
            set.insert(p.second);
        }
        return true;
    }
};

int main() {
    vector<int> arr1{1,2,2,1,1,3};
    vector<int> arr2{1,2};
    vector<int> arr3{-3,0,1,-3,1,1,1,-3,10,0};
    Solution s;
    cout << s.uniqueOccurrences(arr1) << endl; // 1
    cout << s.uniqueOccurrences(arr2) << endl; // 0
    cout << s.uniqueOccurrences(arr3) << endl; // 1
    return 0;
}
