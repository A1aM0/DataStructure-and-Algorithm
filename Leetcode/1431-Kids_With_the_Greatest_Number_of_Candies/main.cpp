/*!
 * @brief  拥有最多糖果的孩子
 *
 * 给你一个数组 candies 和一个整数 extraCandies ，其中 candies[i] 代表第 i 个孩子拥有的糖果数目。
 * 对每一个孩子，检查是否存在一种方案，将额外的 extraCandies 个糖果分配给孩子们之后，此孩子有 最多 的糖果。注意，允许有多个孩子同时拥有 最多 的糖果数目。
 */

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
        int max = 0;
        for (int candyNum : candies) max = max > candyNum ? max : candyNum;
        std::vector<bool> res;
        for (int candyNum : candies) res.push_back(max > candyNum + extraCandies ? false : true);
        return res;
    }
};

int main() {
    std::vector<int> candies{2,3,5,1,3};
    int extraCandies = 3;
    Solution s;
    std::vector<bool> res = s.kidsWithCandies(candies, extraCandies);
    for (auto r : res) std::cout << (r ? "true" : "false") << " ";
    return 0;
}
