/*!
 * @brief 实现 strStr()
 * @details
 * 实现 strStr() 函数。
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。
 * 如果不存在，则返回  -1。
 *
 * @warning
 * 当 needle 是空字符串时，我们应当返回什么值呢？
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*!
     * 暴力破解，非常慢的算法，时间复杂度O(M*N)
     * @param haystack
     * @param needle
     * @return
     */
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()) return -1;
        if (haystack.empty() || needle.empty()) return 0;
        for (int i = 0; i < haystack.size(); ++i) {
            for (int ii = i, j = 0; j < needle.size(); ++j, ++ii) {
                if (haystack[ii] != needle[j]) break;
                if (j == needle.size() - 1) return i;
            }
        }
        return -1;
    }

    /*!
     * @brief KMP算法，时间复杂度O(N)
     * @param haystack
     * @param needle
     * @return
     */
    int strStr2(string haystack, string needle) {
    }

    /*!
     * 复制自翟神，翟神牛逼
     * @param haystack
     * @param needle
     * @return
     */
    int strStr3(string haystack, string needle) {
        if(needle.size()==0)return 0;
        for(int i=0,j=0;i<haystack.size()&&j<needle.size();){
            if(haystack[i]==needle[j]){
                i++;
                j++;
                if(j==needle.size())return i-j;
            } else{
                i=i-j+1;
                j=0;
            }
        }
        return -1;
    }
};

int main() {
    string haystack = "hello", needle = "ll";
    string haystack2 = "mississippi", needle2 = "mississippi";
    Solution s;

    cout << "position: " << s.strStr(haystack2, needle2) << endl;
    return 0;
}