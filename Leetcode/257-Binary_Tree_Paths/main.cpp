/*!
 * @brief 二叉树的所有路径
 *
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 * 说明: 叶子节点是指没有子节点的节点。
 */

#include <iostream>
#include "../dataStructure.hxx"
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        dfs(res, root, "");
        return res;
    }
    void dfs (vector<string> &res, TreeNode* root, string str) {
        str += to_string(root->val);
        if (!root->left && !root->right) {
            res.emplace_back(str);
            return;
        }

        if (root->left) dfs(res, root->left, str + "->");
        if (root->right) dfs(res, root->right, str + "->");
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
