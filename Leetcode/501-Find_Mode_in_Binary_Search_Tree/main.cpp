/*!
 * @brief 二叉搜索树中的众数
 *
 * 给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
 *
 * 假定 BST 有如下定义：
 * 结点左子树中所含结点的值小于等于当前结点的值
 * 结点右子树中所含结点的值大于等于当前结点的值
 * 左子树和右子树都是二叉搜索树
 *
 * 提示：如果众数超过1个，不需考虑输出顺序
 * 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
 */

#include <iostream>
#include <vector>
#include "../dataStructure.hxx"
using namespace std;

class Solution {
public:
    void inOrder(TreeNode* root, TreeNode*& pre, int& curTimes,
                 int& maxTimes, vector<int>& res){
        if (!root) return;
        inOrder(root->left, pre, curTimes, maxTimes, res);
        if (pre)
            curTimes = (root->val == pre->val) ? curTimes + 1 : 1;
        if (curTimes == maxTimes)
            res.push_back(root->val);
        else if (curTimes > maxTimes){
            res.clear();
            res.push_back(root->val);
            maxTimes = curTimes;
        }
        pre = root;
        inOrder(root->right, pre, curTimes, maxTimes, res);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        TreeNode* pre = NULL;
        int curTimes = 1, maxTimes = 0;
        inOrder(root, pre, curTimes, maxTimes, res);
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
