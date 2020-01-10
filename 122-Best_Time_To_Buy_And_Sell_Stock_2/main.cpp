/*!
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
 * 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 */

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    static int maxProfit(vector<int>& prices) { // 计算每个元素与后一位的差值，前者小于后者，则买
        if (prices.empty()) return 0;
        int profit = 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            profit += max(prices[i+1] - prices[i], 0);
        }
        return profit;
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // output is 7
//    vector<int> prices = {1, 2, 3, 4, 5}; // output is 4
//    vector<int> prices = {7, 6, 4, 3, 1}; // output is 0
    cout << Solution::maxProfit(prices);
    return 0;
}