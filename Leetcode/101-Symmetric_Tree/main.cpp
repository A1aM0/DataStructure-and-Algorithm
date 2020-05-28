/*!
 * @brief 对称二叉树
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 */

#include <iostream>
#include "../dataStructure.hxx"
using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return childIsSymmetric(root->left, root->right);
    }
    bool childIsSymmetric(TreeNode* lChild, TreeNode *rChild) {
        if (!lChild && !rChild) return true;
        if (!lChild || !rChild) return false;
        if (lChild->val == rChild->val)
            return childIsSymmetric(lChild->left, rChild->right) && childIsSymmetric(lChild->right, rChild->left);
        return false;
    }
};


int main() {
    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(4);
    TreeNode* node3 = new TreeNode(4);
    TreeNode* node4 = new TreeNode(3);
    TreeNode* node5 = new TreeNode(2, node1, node2);
    TreeNode* node6 = new TreeNode(2, node3, node4);
    TreeNode* node7 = new TreeNode(1, node5, node6);
    Solution s;
    cout << "result is: " << (s.isSymmetric(node7) ? "true" : "false") << endl;
    return 0;
}
