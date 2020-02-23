/*!
 * @brief 环形链表
 *
 * 给定一个链表，判断链表中是否有环。
 * 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
 * 如果 pos 是 -1，则在该链表中没有环。
 *
 * @warning
 * 空间复杂度尽量为O(1)
 */

#include <iostream>

class Solution {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
public:
    static bool hasCycle(ListNode *head) {
        if (!head) return false; ///< 链表没有数据元素的时候，结果自然为false

        ListNode* fast = head->next;
        ListNode* slow = head;
        while (slow != fast) { // 开始快指针追慢指针
            if (!fast || !fast->next) return false; // 快指针追到链表尾部，若没有环，则其指针域为空；若有环，则指向了新的结点
            slow = slow->next; // 慢指针跳
            fast = fast->next->next; // 快指针跳
        }
        return true; // 有环的情况下，快慢指针最终跳到同一个节点，返回true
    }
};

int main() {
    //链表中有一个环，其尾部连接到第二个节点，pos=1
    Solution::ListNode* list_1_first = new Solution::ListNode(3);
    Solution::ListNode* list_1_second = new Solution::ListNode(2);
    Solution::ListNode* list_1_third = new Solution::ListNode(0);
    Solution::ListNode* list_1_forth = new Solution::ListNode(-4);
    list_1_first->next = list_1_second;
    list_1_second->next = list_1_third;
    list_1_third->next = list_1_forth;
    list_1_forth->next = list_1_second;

    // 链表中有一个环，其尾部连接到第一个节点，pos=0
    Solution::ListNode* list_2_first = new Solution::ListNode(1);
    Solution::ListNode* list_2_second = new Solution::ListNode(2);
    list_2_first->next = list_2_second;
    list_2_second->next = list_2_first;

    // 链表中没有，pos=-1
    Solution::ListNode* list_3_first = new Solution::ListNode(1);

    std::cout << Solution::hasCycle(list_1_first) << std::endl; // output is: true
    std::cout << Solution::hasCycle(list_2_first) << std::endl; // output is: true
    std::cout << Solution::hasCycle(list_3_first) << std::endl; // output is: false
    return 0;
}
