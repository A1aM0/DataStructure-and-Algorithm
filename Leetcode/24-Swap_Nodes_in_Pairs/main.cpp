/*!
 * @brief 两两交换链表中的节点
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 */

#include <iostream>
#include "../dataStructure.hxx"
using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* node = dummy;
        while (node->next && node->next->next) {
            ListNode* tmp1 = node->next;
            ListNode* tmp2 = node->next->next;
            node->next = tmp2;
            tmp1->next = tmp2->next;
            tmp2->next = tmp1;
            node = tmp1;
        }
        return dummy->next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
