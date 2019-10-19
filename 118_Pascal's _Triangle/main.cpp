/*!
 * @brief 杨辉三角
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0) return {};

        vector<vector<int>> res;;
        for(int i = 0; i < numRows; ++i) {
            res.push_back({});
            for(int j = 0; j <= i; ++j) {
                if(j == 0 || j == i) res[i].push_back(1);
                else res[i].push_back(res[i - 1][j] + res[i - 1][j - 1]);
            }
        }

        return res;
    }
};

int main() {
    unsigned int numRows = 5;
    Solution s;
    vector<vector<int>> res = s.generate(numRows);
    return 0;
}