/**
28. 实现 strStr()

实现 strStr() 函数。

给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。
*/

class Solution {
    func numDecodings(_ s: String) -> Int {
        // 对于第i个字符，可能性是自己组成一个字母，或者和前面的数字一起结合形成一个字母
        // 所以对于第一个字符，就是1，第二个字符对应1或者2，从第三个开始依照上面的规律   
        // 然后就是注意边界条件
        let str = Array(s)
        var dp = Array<Int>(repeating: 0, count: str.count + 1)

        if str[0] == "0" || s.isEmpty { return 0 }

        dp[0] = 1
        dp[1] = 1

        for i in 2..<dp.count {            
            let pre = str[i - 2]
            let ele = str[i - 1]

            if pre == "0" {
                if ele == "0" { return 0 }

                dp[i] = dp[i - 1]
            } else {
                let tmp = String([pre, ele])

                if ("10"..."26").contains(tmp) {
                    dp[i] += dp[i - 2]
                }
                if ele != "0" {
                    dp[i] += dp[i - 1]
                }
            }
        }
        return dp.last!
    }
}

var s = ["12", "226", "0", "06"]

var so = Solution()

for i in 0..<s.count {
    print(so.numDecodings(s[i]))
}

