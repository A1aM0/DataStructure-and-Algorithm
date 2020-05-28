/*!
 * @brief 数据流中的第K大元素
 *
 * 设计一个找到数据流中第K大元素的类（class）。注意是排序后的第K大元素，不是第K个不同的元素。
 * 你的 KthLargest 类需要一个同时接收整数 k 和整数数组nums 的构造器，它包含数据流中的初始元素。每次调用 KthLargest.add，返回当前数据流中第K大的元素。
 */

#include <iostream>
#include <vector>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        bst = new TreeNode(NULL);
        for (int i = 0; i < nums.size(); ++i) bst = insertNode(bst, nums[i]);
        nth = k;
    }

    int add(int val) {
        insertNode(bst, val);
        return findNode(bst, nth)->val;
    }

private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        int nodeCount = 1; // 以当前结点组成的二叉搜索树的结点数量（自己及其子树）
        TreeNode(int x, TreeNode *l = NULL, TreeNode *r = NULL) : val(x), left(l), right(r) {}
    };

    TreeNode *bst;
    int nth;

    TreeNode* insertNode(TreeNode *root, int num) {
        if (!root) return new TreeNode(num);
        root->nodeCount++;
        if (num > root->val) root->right = insertNode(root->right, num);
        else root->left = insertNode(root->left, num);
        return root;
    }

    TreeNode* findNode(TreeNode *root, int nth) { // 找以当前结点为根结点的二叉树中第n大的值
        int cnt = 0;
        if (root->right) cnt = root->right->nodeCount;
        if (cnt + 1 == nth) return root;
        else if (cnt + 1 > nth) return findNode(root->right, nth);
        else return findNode(root->left, nth - cnt - 1);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
