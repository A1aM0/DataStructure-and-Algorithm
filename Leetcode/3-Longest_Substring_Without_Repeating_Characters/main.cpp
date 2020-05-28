/**
 * @brief 无重复字符的最长子串
 * 
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        unordered_map<char, int> m;
        int start = 0;
        int res;
        // 一次遍历，字符作key，位置作val。当遇到重复项时，意味当前s[i]以前的子串无重复，计算前面无重复的长度，保留最大的记作result。
        // 然后更新字典里的map[s[i]]的val，然后可以把无重复子串的起始位置向后移一位
        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[i]) != m.end()) {
                start = m[s[i]] + 1 > start ? m[s[i]] + 1 : start;
            }
            m[s[i]] = i;
            res = (i - start + 1) > res ? (i - start + 1) : res; // 一直在更新res，+1是因为start已经更新到下一个位置了。
        }
        return res;
    }
};
