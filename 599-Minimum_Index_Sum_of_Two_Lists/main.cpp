/*!
 * @brief 两个列表的最小索引总和
 *
 * 假设Andy和Doris想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。
 * 你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设总是存在一个答案。
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;
        for (int i = 0; i < list1.size(); ++i) mp[list1[i]] = i;

        int min = INT_MAX;
        vector<string> res;
        for (int i = 0; i < list2.size(); i++) {
            if (mp.count(list2[i])) {
                if (mp[list2[i]] + i == min) res.push_back(list2[i]);
                else if (mp[list2[i]] + i < min) {
                    res.clear();
                    res.push_back(list2[i]);
                    min = mp[list2[i]] + i;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    Solution s;
    vector<string> res = s.findRestaurant(list1, list2);
    for (string str : res) {
        cout << str << endl;
    }
    return 0;
}
