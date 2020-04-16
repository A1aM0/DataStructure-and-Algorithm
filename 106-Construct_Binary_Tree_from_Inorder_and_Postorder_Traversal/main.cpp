/*!
 * @brief 从中序与后序遍历序列构造二叉树
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 注意:
 * 你可以假设树中没有重复的元素。
 */
#include <iostream>
#include <vector>
#include "../dataStructure.hxx"
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 后序的末位是根节点，对应到中序，左边的是左子树，右边的是右子树。
        // 在子树中，后序的末位是子树的根节点，再对应到中序，左边是左子树，右边是右子树
        return generateTreeNode(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode* generateTreeNode(vector<int> &inorder, int leftin, int rightin,
            vector<int> &postorder, int leftpost, int rightpost) {
        if(leftin > rightin) return NULL; // 最后才添加的边界条件：要是叶子结点再执行本次递归，leftin会大于rightin
        TreeNode* newRoot = new TreeNode(postorder[rightpost]); // 后序的尾结点即是子树的根结点

        // 找根结点在中序的位置
        int rootIndexInorder = leftin;
        while (rootIndexInorder <= rightin && inorder[rootIndexInorder] != newRoot->val) rootIndexInorder++;

        // 找到根结点在中序的位置，则根的左边是该结点的左子树，计算左子树结点的数量，在右子树中可以直接套用
        int inorderLeftTreeLen = rootIndexInorder - leftin;

        // 递归的使用左子树的中序与后序，计算子树的结构
        newRoot->left = generateTreeNode(inorder, leftin, rootIndexInorder - 1, postorder, leftpost, leftpost + inorderLeftTreeLen - 1);
        newRoot->right = generateTreeNode(inorder, rootIndexInorder + 1, rightin, postorder, leftpost + inorderLeftTreeLen, rightpost - 1);
        return newRoot;
    }
};

int main() {
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    Solution s;
    TreeNode* res =  s.buildTree(inorder, postorder);
    return 0;
}
