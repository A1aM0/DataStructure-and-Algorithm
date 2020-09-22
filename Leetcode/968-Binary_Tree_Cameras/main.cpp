/*!
 * @brief 监控二叉树
 *
 * 给定一个二叉树，我们在树的节点上安装摄像头。
 * 节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。
 * 计算监控树的所有节点所需的最小摄像头数量。
 */

#include <iostream>
#include "../dataStructure.hxx"

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        int res = 0; // 摄像头数量
        return dfs(root, res) ? res : res + 1; // 若遍历至最上面，root标志为0，则多加一个摄像头
    }

    /*!
     * 后序遍历，自底向上的判断当前节点状态
     * @param root
     * @param res
     * @return 当前节点的状态
     * @retval 0 未被覆盖(当前节点未被照到)
     * @retval 1 已被覆盖(摄像头已经照到这个节点)
     * @retval 2 需放置摄像头
     */
    int dfs (TreeNode* root, int &res) {
        if (!root) return 1; // 到达叶子节点的孩子（NULL），认为已覆盖

        int left = dfs(root->left, res); // 左孩子的状态
        int right = dfs(root->right, res); // 右孩子的状态

        if (left == 0 || right == 0) { // 有一个孩子没有被覆盖，当前节点一定要装摄像头，才能保证孩子被照到
            res++;
            return 2;
        }
        if (left == 1 && right == 1) { // 两个孩子都被照到，当前就不需要装摄像头，同时，当前节点应未被照到，且照到它的摄像头应该在它父节点的位置
            return 0;
        }
        if (left + right > 2) { // 两个子节点中任何一个装了摄像头，当前节点作为父亲必被照到，所以返回1
            return 1;
        }
        return 0;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
