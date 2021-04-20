/**
28. 实现 strStr()

实现 strStr() 函数。

给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。
*/


class Solution {
    func strStr(_ haystack: String, _ needle: String) -> Int {
        if needle.count == 0 { return 0 }

        let haystackArr = Array(haystack), needleArr = Array(needle)
        let next = getNext(needleArr)

        var i = 0, j = 0

        while i < haystackArr.count && j < needleArr.count {
            if j == -1 || haystackArr[i] == needleArr[j] {
                i += 1
                j += 1
            } else {
                j = next[j]
            }
        }

        return (j == needleArr.count) ? i - j : -1
    }

    func getNext (_ pattern: [Character]) -> [Int] {
        let n = pattern.count
        var len = 0, i = 1
        var next = Array<Int>(repeating: 0, count: n)
        next[0] = 0

        while i < n {
            if (pattern[len] == pattern[i]) {
                len += 1
                next[i] = len
                i += 1
            } else {
                if len > 0 {
                    len = next[len - 1]
                } else {
                    next[i] = len
                    i += 1
                }
            }
        }

        next.insert(-1, at: 0)
        next.remove(at: next.count - 1)
        return next
    }

    // func strStr(_ haystack: String, _ needle: String) -> Int { // 相对暴力，调用标准库
    //     if haystack == needle{
    //         return 0
    //     }
    //     if haystack.count < needle.count{
    //         return -1
    //     }
    //     var a:String=haystack
    //     for i in 0...(a.count-needle.count){
    //         if a.hasPrefix(needle){
    //             return i
    //         }
    //         a.remove(at:a.startIndex)
    //     }
    //     return -1
    // }
}
var hayStack = ["hello", "aaaaa", ""]
var needle = ["ll", "bba", ""]
var so = Solution()

for i in 0..<hayStack.count {
    print(so.strStr(hayStack[i], needle[i]))
}

