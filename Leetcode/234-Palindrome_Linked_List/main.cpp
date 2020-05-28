/*!
 * @brief 回文链表
 *
 * 请判断一个链表是否为回文链表。
 *
 * @example
 * 示例 1:
 * 输入: 1->2
 * 输出: false
 *
 * 示例 2:
 * 输入: 1->2->2->1
 * 输出: true
 *
 * @note
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 */

#include <iostream>
#include "../dataStructure.hxx"

class Solution {
public:
    static bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        // 先找中部的位置，再把后半部分翻转，再从头和中部依次比较，时间是n的一次幂，空间在原链表上操作。
        // 找中部
        ListNode *slow = head, *fast = head;
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 翻转后半部，slow是后半部的开头
        ListNode *curNode = slow, *nextNode = slow->next;
        while (nextNode) {
            ListNode* tmp = nextNode->next;
            nextNode->next = curNode;
            curNode = nextNode;
            nextNode = tmp;
        }
        slow->next = nullptr; // 后半部原头结点的slow变成尾结点，新的头结点是curNode

        // 依次比较
        ListNode *headNode = head;
        while (headNode && curNode) {
            if (headNode->val != curNode->val) return false;
            headNode = headNode->next;
            curNode = curNode->next;
        }
        return true;
    }
};

int main() {
    ListNode *node11 = new ListNode(1);
    ListNode *node12 = new ListNode(2);
    node11->next = node12;
    ListNode *node21 = new ListNode(1);
    ListNode *node22 = new ListNode(2);
    ListNode *node23 = new ListNode(2);
    ListNode *node24 = new ListNode(1);
    node21->next = node22;
    node22->next = node23;
    node23->next = node24;

    std::cout << "result is " << (Solution::isPalindrome(node21) ? "true" : "false") << std::endl;

    return 0;
}
