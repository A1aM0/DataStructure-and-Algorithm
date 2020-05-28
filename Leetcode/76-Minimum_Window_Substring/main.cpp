/*!
 * @brief 最小覆盖子串
 *
 * 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。
 *
 * 示例：
 * 输入: S = "ADOBECODEBANC", T = "ABC"
 * 输出: "BANC"
 *
 * 说明：
 * 如果 S 中不存这样的子串，则返回空字符串 ""。
 * 如果 S 中存在这样的子串，我们保证它是唯一的答案。
 */

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tMap;
        unordered_map<char, int> slideWindow;
        for (char t_ch : t) tMap[t_ch]++;

        int left = 0, right = 0, min = INT_MAX;
        int subStrStart = 0; // 子串的起始位置
        int cntMatchNums = 0; // 记录划窗里有几种字符的数量已经和t里的一样了，那么当cntMatchNums==tMap.size()的时候，表示划窗里完全包含了t
        while (right < s.size()) {
            char chRight = s[right]; // 窗口right每向右移一位，判断新的字符是否在t里
            if (tMap.count(chRight)) {
                slideWindow[chRight]++; // 新的char在t里，记录下来
                if (slideWindow[chRight] == tMap[chRight]) cntMatchNums++;
            }
            right++;
            while (cntMatchNums == tMap.size()) { // 划窗已经包含了所有t，可以移动划窗左边界或者return
                if (right - left < min) {
                    min = right - left; // 更新子串的长度
                    subStrStart = left; // 更新子串的起始位置
                }

                char chLeft = s[left];
                // 开始尝试右移left，如果left是t的字符之一，那么划窗里的匹配子串就要减掉这个字符；若不是t里面的，不用管，直接右移left
                if (tMap.count(chLeft)) {
                    slideWindow[chLeft]--;
                    if (slideWindow[chLeft] < tMap[chLeft]) cntMatchNums--;
                }
                left++;
            }
        }
        return min == INT_MAX ? "" : s.substr(subStrStart, min);
    }
};

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    Solution so;
    std::cout << so.minWindow(s, t) << std::endl;
    return 0;
}
