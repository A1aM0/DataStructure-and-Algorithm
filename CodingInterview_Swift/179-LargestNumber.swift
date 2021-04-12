/**
179. 最大数
给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。
*/

class Solution {
    func largestNumber(_ nums: [Int]) -> String {
        // 对于输入数组没有相同数字开头的：比较输入数组的每个元素的最高位，最高位相同的时候比较次高位，以此类推，完成排序，然后把它们拼接起来。
        // 对于输入数组有相同数字开头的情况:比较两个数不同的拼接顺序的结果，进而决定它们在结果中的排列顺序。
        let sortedNums = nums.sorted(by: {(n1: Int, n2: Int) -> Bool in 
            // 使用字符串进行比较，可直接比较最高位
            let l = String(n1)
            let r = String(n2)
            return l + r > r + l
        })

        if sortedNums[0] == 0 {
            return "0"
        }

        var res = ""
        for num in sortedNums {
            res.append(String(num))
        }
        return res
    }
}

var solution = Solution()
var nums = [[10, 2], [3,30,34,5,9], [1], [10]]

for arr in nums {
    print(solution.largestNumber(arr))
}
