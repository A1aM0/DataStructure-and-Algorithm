/*!
 * @brief 寻找比目标字母大的最小字母
 *
 * 给你一个排序后的字符列表 letters ，列表中只包含小写英文字母。另给出一个目标字母 target，请你寻找在这一有序列表里比目标字母大的最小字母。
 * 在比较时，字母是依序循环出现的。举个例子：
 * 如果目标字母 target = 'z' 并且字符列表为 letters = ['a', 'b']，则答案返回 'a'
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (letters[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return letters[left % letters.size()];
    }
};

int main() {
    Solution s;
    vector<char> letters = {'c', 'f', 'j'};
    std::cout << "result is " << s.nextGreatestLetter(letters, 'a') << std::endl;
    return 0;
}
