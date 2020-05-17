/**
 * @brief  宝石与石头
 * 
 * 给定字符串J 代表石头中宝石的类型，和字符串 S代表你拥有的石头。 S 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。
 * J 中的字母不重复，J 和 S中的所有字符都是字母。字母区分大小写，因此"a"和"A"是不同类型的石头。
 */

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> st;
        for (char j : J) {
            st.insert(j);
        }
        int cnt = 0;
        for (char s : S) {
            if (st.find(s) != st.end()) cnt++;
        }
        return cnt;
    }
};
