/*!
 * @brief 406. 根据身高重建队列
 *
 * 假设有打乱顺序的一群人站成一个队列。
 * 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。
 * 编写一个算法来重建这个队列。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 从高到低考虑
        // 我们也可以将每个人按照身高从大到小进行排序，处理身高相同的人使用的方法类似，即：按照 h_i
        // 为第一关键字降序，k_i为第二关键字升序进行排序。如果我们按照排完序后的顺序，依次将每个人放入队列中，那么当我们放入第 i 个人时：
        // 第 0,⋯,i−1 个人已经在队列中被安排了位置，他们只要站在第 i 个人的前面，就会对第 i 个人产生影响，因为他们都比第 i 个人高；
        // 而第 i+1,⋯,n−1 个人还没有被放入队列中，并且他们无论站在哪里，对第 i 个人都没有任何影响，因为他们都比第 i 个人矮。
        // 在这种情况下，我们无从得知应该给后面的人安排多少个「空」位置，因此就不能沿用方法一。
        // 但我们可以发现，后面的人既然不会对第 i 个人造成影响，我们可以采用「插空」的方法，依次给每一个人在当前的队列中选择一个插入的位置。
        // 也就是说，当我们放入第 i 个人时，只需要将其插入队列中，使得他的前面恰好有 k_i 个人即可。
        sort(people.begin(), people.end(), [](vector<int>p1, vector<int>p2){
            if (p1[0] == p2[0]) {
                return p1[1] < p2[1];
            }
            return p1[0] > p2[0];
        });
        list<vector<int>> nodeList;
        for (int i = 0; i < people.size(); i++) {
            auto it = nodeList.begin();
            int n = people[i][1];
            while (n--) it++;
            nodeList.insert(it, people[i]);
        }
        return vector<vector<int>>(nodeList.begin(), nodeList.end());
    }
};

int main() {
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    Solution s;
    vector<vector<int>> res = s.reconstructQueue(people);
    for (vector<int> &row : res) {
        for (int n : row) cout << n << " ";
        cout << endl;
    }
    return 0;
}
