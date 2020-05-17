/**
 * @brief 寻找重复的子树
 *  
 * 给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。
 * 两棵树重复是指它们具有相同的结构以及相同的结点值。
 */

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> m;
        dfs(root, m, res);
        return res;
    }

    // 用后续遍历，当退到某子树的根结点时，如果重复，那么用string表示的序列应该在哈希表中出现过。
    string dfs(TreeNode* root, unordered_map<string, int> &m, vector<TreeNode*> &res) {
        if (!root) return "#";
        string left = dfs(root->left, m, res);
        string right = dfs(root->right, m ,res);
        
        string str = to_string(root->val) + "," + left + "," + right;
        if (++m[str] == 2) res.push_back(root);
        return str;
    }
};