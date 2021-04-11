class Solution {
    func nthUglyNumber(_ n: Int) -> Int {
        var dp: [Int] = [0, 1]
        var p2 = 1, p3 = 1, p5 = 1
        while dp.count <= n {
            var num2 = dp[p2] * 2
            var num3 = dp[p3] * 3
            var num5 = dp[p5] * 5
            var tmp = min(num2, min(num3, num5))
            if tmp == num2 {
                p2 += 1
            }
            if tmp == num3 {
                p3 += 1
            }
            if tmp == num5 {
                p5 += 1
            }
            dp.append(tmp)
        }
        return dp[n]
    }
}
