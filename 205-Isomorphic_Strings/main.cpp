/*!
 * @brief 同构字符串
 *
 * 给定两个字符串 s 和 t，判断它们是否是同构的。
 * 如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
 * 所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
 *
 * 说明:
 * 你可以假设 s 和 t 具有相同的长度。
 */

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // 两个字符串同构的含义就是字符串 s 可以唯一的映射到 t ，同时 t 也可以唯一的映射到 s
        unordered_map<char, int> mp1, mp2;
        for (int i = 0; i < s.size(); ++i) {
            mp1[s[i]] = i;
            mp2[t[i]] = i;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (mp1[s[i]] != mp2[t[i]]) return false;
        }
        return true;
    }
};

int main() {
    Solution so;
//    string s = "egg", t = "add"; // T
//    string s = "foo", t = "bar"; // F
    string s = "paper", t = "title"; // T
    std::cout << "result is " << so.isIsomorphic(s, t) << std::endl;
    return 0;
}
