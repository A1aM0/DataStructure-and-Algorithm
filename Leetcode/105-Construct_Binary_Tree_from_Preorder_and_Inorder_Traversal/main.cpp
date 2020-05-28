/*!
 * @brief 从前序与中序遍历序列构造二叉树
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 注意:
 * 你可以假设树中没有重复的元素。
 */

#include <iostream>
#include <vector>
#include "../dataStructure.hxx"
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* buildTree(vector<int> preorder, int beginPreorder, int endPreorder, vector<int> inorder, int beginInorder, int endInorder) {
        //
        if (beginInorder > endInorder || beginPreorder > endPreorder) return NULL;
        TreeNode* root = new TreeNode(preorder[beginPreorder]);
        int inorderRootIndex = beginInorder;
        while (inorderRootIndex <= endInorder && root->val != inorder[inorderRootIndex]) inorderRootIndex++;
        int leftTreeLen = inorderRootIndex - beginInorder;
        root->left = buildTree(preorder, beginPreorder + 1, beginPreorder + leftTreeLen, inorder, beginInorder, inorderRootIndex - 1);
        root->right = buildTree(preorder, beginPreorder + leftTreeLen + 1, endPreorder, inorder, inorderRootIndex + 1, endInorder);
        return root;
    }
};

int main() {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    Solution s;
    TreeNode* res = s.buildTree(preorder, inorder);
    return 0;
}
