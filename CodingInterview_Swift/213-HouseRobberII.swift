/**
213 打家劫舍 II
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，能够偷窃到的最高金额。
*/

class Solution {
    func rob(_ nums: [Int]) -> Int {
        if (nums.count == 1) { return nums[0] }
        else if (nums.count == 2) { return max(nums[0], nums[1]) }
        else { return max(dp(nums, 0, nums.count - 2), dp(nums, 1, nums.count - 1)) }
    }

    func dp(_ nums: [Int], _ start: Int, _ end: Int) -> Int {
        var first = nums[start], second = max(first, nums[start + 1])
        var index = start + 2
        while index <= end {
            var tmp = second
            second = max(first + nums[index], second)
            first = tmp
            index += 1
        }
        return second
    }
}

var nums = [[2, 3, 2], [1, 2, 3, 1], [0]]
var so = Solution()

for arr in nums {
    print(so.rob(arr))
}
