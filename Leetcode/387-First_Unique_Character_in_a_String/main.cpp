/*!
 * @brief 字符串中的第一个唯一字符
 *
 * 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
 */

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); ++i) {
            mp[s[i]] += 1;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (mp[s[i]] == 1) return i;
        }
        return -1;
    }
};

int main() {
    string str = "loveleetcode";
    Solution s;
    std::cout << "result is " << s.firstUniqChar(str) << std::endl;
    return 0;
}
