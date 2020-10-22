/*!
 * @brief 划分字母区间
 *
 * 字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。
 * 返回一个表示每个字符串片段的长度的列表。
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        // 同一个字母的第一次出现的下标位置和最后一次出现的下标位置必须出现在同一个片段。
        // 因此需要遍历字符串，得到每个字母最后一次出现的下标位置。
        int start = 0, end = 0;
        unordered_map<char, int> map;
        vector<int> res;
        for (int pos = 0; pos < S.size(); pos++) {
            map[S[pos]] = pos; // 更新字母出现的位置
        }

        for (int i = 0; i < S.size(); i++) {
            // 遍历的同时维护当前片段的开始下标 start 和结束下标 end，初始时 start=end=0。
            // 对于每个访问到的字母 c，得到当前字母的最后一次出现的下标位置end_c，
            // 则当前片段的结束下标一定不会小于 end_c，因此令 end=max(end,end_c)。
            // 当访问到下标 end 时，当前片段访问结束，当前片段的下标范围是 [start,end]，长度为 end−start+1。
            // 添加长度，更新start。
            end = max(end, map[S[i]]);
            if (i == end) {
                res.emplace_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    string S{"ababcbacadefegdehijhklij"};
    vector<int> res = solution.partitionLabels(S);
    for (int num : res) cout << num << " ";
    std::cout << std::endl;
    return 0;
}
