/*!
 * @brief 翻转字符串里的单词
 *
 * 无空格字符构成一个单词。
 * 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 * 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 *
 * @warning
 * 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 * 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 */

#include <bits/stdc++.h>
using namespace std;

class  Solution {
public:
    // 先全反一遍，再每个单词翻转，空间O(1)
    static string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int start = 0, end = s.size() - 1;
        while (s[start] == ' ' && start <= end) start++; // 消除开头的空格
        while (s[end] == ' ' && end >= 0) end--; // 消除末尾的空格

        for (int i = start; i <= end; ) { // 翻转每个单词
            while (s[i] == ' ' && i <= end) ++i; // 不计单词的左空格
            int j = i; // 记录单词开始的位置，为i
            while (s[j] != ' ' && j <= end) ++j; // 不计单词的有空格，单词末位记为j
            reverse(s.begin()+i, s.begin()+j); //翻转单词

            i = j + 1;
        }

        for (int i = start; i <= end; ++i) { // 删除单词间的空格
            if (s[i] == ' ' && s[i-1] == ' ') { // 判断条件，当前和上一个位子都是空格，则删去当前的空格
                s.erase(s.begin() + i);
                i--; // 有++i，所以要先把i减掉
                end--; // 前面有数字删去了，总长度减了，end相应减
            }
        }

        return s.substr(start, end-start+1);
    }
};

int main() {
    string str1 = "the sky is blue";
    string str2 = "  hello world!  ";
    string str3 = "a good   example";
    string str4 = " ";

    cout << Solution::reverseWords(str4) << endl;
    return 0;
}
