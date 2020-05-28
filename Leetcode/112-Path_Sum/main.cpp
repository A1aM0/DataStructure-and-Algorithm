/*!
 * @brief 路径总和
 *
 * 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
 * 说明: 叶子节点是指没有子节点的节点。
 */
#include <iostream>
#include "../dataStructure.hxx"
using namespace std;

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right) return (sum - root->val) == 0;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

int main() {
    TreeNode *node7 = new TreeNode(7);
    TreeNode *node8 = new TreeNode(2);
    TreeNode *node9 = new TreeNode(1);
    TreeNode *node4 = new TreeNode(11, node7, node8);
    TreeNode *node5 = new TreeNode(13);
    TreeNode *node6 = new TreeNode(4, NULL, node9);
    TreeNode *node2 = new TreeNode(4, node4);
    TreeNode *node3 = new TreeNode(8, node5, node6);
    TreeNode *node1 = new TreeNode(5, node2, node3);
    Solution s;
    cout << "result is: " << (s.hasPathSum(node1, 22) ? "true" : "false") << endl;
    return 0;
}
