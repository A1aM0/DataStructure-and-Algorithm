/**
530 二叉搜索树的最小绝对差
给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。
*/

class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init() { 
        self.val = 0; 
        self.left = nil; 
        self.right = nil; 
    }
    public init(_ val: Int) {
        self.val = val
        self.left = nil
        self.right = nil
    }
    public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
        self.val = val
        self.left = left
        self.right = right
    }
}

class Solution {
    func getMinimumDifference(_ root: TreeNode?) -> Int {
        // 和530题相同
        // 根据题意，找任意两点之间的最小值
        // 又因为是搜索时，只用在中序遍历时找连续两点之间的差值最小值就行
        var minDiff = Int.max, pre: Int! = nil
        
        func dfs(_ root: TreeNode?) {
            if root == nil {
                return
            }
            dfs(root!.left)
            
            if pre != nil {
                minDiff = min(minDiff, abs(root!.val - pre))
            }
            pre = root!.val

            dfs(root!.right)
        }

        dfs(root)
        return minDiff
    }
}


