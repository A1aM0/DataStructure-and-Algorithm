/*!
 * @brief 正则表达式匹配
 *
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 *
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 * 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
 *
 * 说明:
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
 */

#include <iostream>
#include <cstring>

using namespace std;

class Solution { // DP
public:
    bool isMatch(string s, string p) { //初始化了dp[0][0]为真，在s和p前面加了一个空格(其他符号也行)，解决了s为空时的特殊情况，避免了繁琐的初始化
        s=" "+s;//防止该案例：""\n"c*"
        p=" "+p;
        int m=s.size(),n=p.size();
        bool dp[m+1][n+1];
        memset(dp,false,(m+1)*(n+1));
        dp[0][0]=true;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='.'){ // p[j] == s[i] : dp[i][j] = dp[i-1][j-1] 以及 p[j] == "." : dp[i][j] = dp[i-1][j-1]
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    if(s[i-1]!=p[j-2] && p[j-2]!='.')
                        dp[i][j]=dp[i][j-2]; //in this case, a* only counts as empty
                    else{
                        dp[i][j]=dp[i][j-1] || dp[i][j-2] || dp[i-1][j];
                        // a* counts as multiple a, a* counts as single a, a* counts as empty
                    }
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    string s = "mississippi";
    string p = "mis*is*p*.";
    Solution so;
    std::cout << so.isMatch(s, p) << std::endl;
    return 0;
}
