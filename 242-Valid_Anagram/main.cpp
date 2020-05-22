/*!
 * @brief 有效的字母异位词
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 *
 * 说明:
 * 你可以假设字符串只包含小写字母。
 *
 * 进阶:
 * 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 */

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        if (s.size() != t.size()) return false;
        for (char ch : s) {
            map[ch]++;
        }
        for (char ch : t) {
            if (map[ch] == 0) return false;
            map[ch]--;
        }
        return true;
    }
};

int main() {
//    string s{"anagram"}, t{"nagaram"};
    string s{"rat"}, t{"car"};
    Solution so;
    std::cout << "result is " << (so.isAnagram(s, t) ? "true" : "false") << std::endl;
    return 0;
}
