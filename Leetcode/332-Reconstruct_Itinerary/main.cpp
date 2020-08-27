/*!
 * @brief 重新安排行程
 *
 * 给定一个机票的字符串二维数组 [from, to]，子数组中的两个成员分别表示飞机出发和降落的机场地点，对该行程进行重新规划排序。
 * 所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。
 *
 * 说明:
 * 如果存在多种有效的行程，你可以按字符自然排序返回最小的行程组合。例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前。
 * 所有的机场都用三个大写字母表示（机场代码）。
 * 假定所有机票至少存在一种合理的行程。
 */

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (vector<string> tic : tickets) {
            vec[tic[0]].emplace(tic[1]);
        }
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(const string &str) {
        while (vec.count(str) != 0 && vec[str].size() > 0) {
            string tmp = vec[str].top();
            vec[str].pop();
            dfs(tmp);
        }
        res.emplace_back(str);
    }

    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> vec;
    vector<string> res;
};

int main() {
    vector<vector<string>> tickets{{"MUC", "LHR"},
                                   {"JFK", "MUC"},
                                   {"SFO", "SJC"},
                                   {"LHR", "SFO"}};
    Solution s;
    vector<string> res = s.findItinerary(tickets);
    for (auto &str : res) {
        cout << str << " ";
    }
    std::cout << std::endl;
    return 0;
}
