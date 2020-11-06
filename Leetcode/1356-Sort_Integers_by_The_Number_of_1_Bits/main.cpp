/*!
 * @brief 根据数字二进制下 1 的数目排序
 *
 * 给你一个整数数组 arr 。请你将数组中的元素按照其二进制表示中数字 1 的数目升序排序。
 * 如果存在多个数字二进制中 1 的数目相同，则必须将它们按照数值大小升序排列。
 * 请你返回排序后的数组。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto cnt = [](int x) {
            int res = 0;
            while (x) { // 最多循环32次。
                // x%2 即看是不是奇数，奇数的话，二进制表示是末位必为1，这句话就等价于 res += (x & 1)
                res += (x % 2);
                // 判断完最后一位是不是1，右移，即 x >> 1
                x /= 2;
            }
            return res;
        };

        sort(arr.begin(), arr.end(), [&](int x, int y) -> bool {
            if (cnt(x) < cnt(y)) return true;
            if (cnt(x) > cnt(y)) return false;
            return x <= y;
        });
        return arr;
    }

    vector<int> sortByBits2(vector<int>& arr) {
        auto cnt = [](int x) {
            // 运算次数与输入n的大小无关，只与n中1的个数有关。如果n的二进制表示中有k个1，那么这个方法只需要循环k次即可。
            // 其原理是不断清除n的二进制表示中最右边的1，同时累加计数器，直至n为0
            int res = 0;
            while (x) {
                x &= (x - 1);
                res++;
            }
            return res;
        };

        sort(arr.begin(), arr.end(), [&](int x, int y) -> bool {
            if (cnt(x) < cnt(y)) return true;
            if (cnt(x) > cnt(y)) return false;
            return x <= y;
        });
        return arr;
    }
};

int main() {
    vector<int> nums1{0,1,2,3,4,5,6,7,8};
    vector<int> nums2{1024,512,256,128,64,32,16,8,4,2,1};
    vector<int> nums3{10000,10000};
    vector<int> nums4{2,3,5,7,11,13,17,19};
    vector<int> nums5{10,100,1000,10000};

    auto print = [](vector<int> &arr) {
        Solution s;
        vector<int> res = s.sortByBits2(arr);
        for (int n : res) cout << n << " ";
        cout << endl;
    };

    print(nums1);
    print(nums2);
    print(nums3);
    print(nums4);
    print(nums5);

    return 0;
}
