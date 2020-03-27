/*!
 * @brief 卡牌分组
 *
 * 给定一副牌，每张牌上都写着一个整数。
 * 此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：
 * 每组都有 X 张牌。
 * 组内所有的牌上都写着相同的整数。
 * 仅当你可选的 X >= 2 时返回 true。
 *
 * @warning
 * 1 <= deck.length <= 10000
 * 0 <= deck[i] < 10000
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static int gcd(int x, int y){
        return !x ? y : gcd(y % x, x);
    }
    static bool hasGroupsSizeX(vector<int>& deck) {
        //将相同的数放到一组之后，找最大公约数
        int tmp[10000] = {0}; // 定义一个长度为10000的0数组
        int g = 0;

        for (int x : deck)   tmp[x]++; // 遍历deck中的每个元素，若deck中元素的值为x，则tmp中第x位增一，即可得到deck数组中各个数值有多少个。
        for (int b : tmp) g = gcd(b, g);

        return g >= 2;
    }
};

int main() {
    vector<int> deck1 = {1,2,3,4,4,3,2,1};
    vector<int> deck2 = {1,1,1,2,2,2,3,3};
    vector<int> deck3 = {1};
    vector<int> deck4 = {1,1};
    vector<int> deck5 = {1,1,2,2,2,2};
    cout << "result is " << Solution::hasGroupsSizeX(deck1) << endl;
    return 0;
}
