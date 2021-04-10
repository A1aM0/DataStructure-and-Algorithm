class Solution {
    func isUgly(_ n: Int) -> Bool {
        // n 的范围是[-2^31, 2^31-1]，根据题目要求只有正整数才有可能返回true，直接排除掉小于等于0的数
        if n <= 0 {
            return false
        }
        
        // 不断用2，3，5去除，只有结果为1才表示满足条件，否则不满足
        let dividers: [Int] = [2, 3, 5]
        var num = n
        for divider in dividers {
            while num % divider == 0 {
                num /= divider
            }
        }
        return num == 1
    }
}

var solution = Solution()
var nums = [6, 8, 14, 1]
for num in nums {
    print(solution.isUgly(num))
}

