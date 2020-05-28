/*!
 * @brief 环形链表 II
 *
 * 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
 * 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
 * 如果 pos 是 -1，则在该链表中没有环。
 *
 * @warning
 * 不允许修改给定的链表。
 * 尽量空间复杂度为O(1)。
 */

#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    static ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL; // 空表和只有一个结点的表当然返回NULL
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next){ // 快指针走的快，如果没有循环的话则先走到尾结点，则跳出循环，返回NULL
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow && fast) { // 如果快指针追上慢指针，则表示快指针从后面追上了慢指针，比慢指针多跑了一圈；判断出是环，现在找环的入口
                fast = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            };
        }
        return NULL;
    }
};

int main() {
    Solution::ListNode* list_1_first = new Solution::ListNode(3);
    Solution::ListNode* list_1_second = new Solution::ListNode(2);
    Solution::ListNode* list_1_third = new Solution::ListNode(0);
    Solution::ListNode* list_1_forth = new Solution::ListNode(-4);
    list_1_first->next = list_1_second;
    list_1_second->next = list_1_third;
    list_1_third->next = list_1_forth;
    list_1_forth->next = list_1_second;

    Solution::ListNode* list_2_first = new Solution::ListNode(1);
    Solution::ListNode* list_2_second = new Solution::ListNode(2);
    list_2_first->next = list_2_second;
    list_2_second->next = list_2_first;

    Solution::ListNode* list_3_first = new Solution::ListNode(1);

    Solution::ListNode* list_4_first = new Solution::ListNode(1);
    Solution::ListNode* list_4_second = new Solution::ListNode(2);
    list_4_first->next = list_4_second;

    std::cout << "node's val connected by the tail is " << Solution::detectCycle(list_1_first)->val << std::endl;
    std::cout << "node's val connected by the tail is " << Solution::detectCycle(list_2_first)->val << std::endl;
    std::cout << "node's val connected by the tail is " << Solution::detectCycle(list_4_first)->val << std::endl;
    return 0;
}
