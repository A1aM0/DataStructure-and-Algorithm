/*!
 * @brief 二叉树的层平均值
 *
 * 给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。
 */
#include <iostream>
#include <vector>
#include <queue>
#include "../dataStructure.hxx"
using namespace std;

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        vector<double> res;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* tmp = q.front();
                q.pop();
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
                sum += tmp->val;
            }
            res.emplace_back(sum / size);
        }
        return res;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
