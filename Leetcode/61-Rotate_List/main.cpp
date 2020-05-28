/*!
 * @brief 旋转链表
 *
 * 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 * 示例 1:
 * 输入: 1->2->3->4->5->NULL, k = 2
 * 输出: 4->5->1->2->3->NULL
 * 解释:
 * 向右旋转 1 步: 5->1->2->3->4->NULL
 * 向右旋转 2 步: 4->5->1->2->3->NULL
 *
 * 示例 2:
 * 输入: 0->1->2->NULL, k = 4
 * 输出: 2->0->1->NULL
 * 解释:
 * 向右旋转 1 步: 2->0->1->NULL
 * 向右旋转 2 步: 1->2->0->NULL
 * 向右旋转 3 步: 0->1->2->NULL
 * 向右旋转 4 步: 2->0->1->NULL
 */

#include <iostream>
#include "../dataStructure.hxx"

class Solution {
public:
    static ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        if (!head->next) return head;

        // 遍历第一遍链表，同时记录链表长度cnt，以及将尾结点的next接到head上，相当于形成环形链表
        int cnt = 0;
        ListNode *p = head;
        while (p) {
            cnt++;
            if (p->next) p = p->next;
            else {
                p->next = head;
                break;
            }
        }

        // 旋转k个，k可能大于链表长度，所以直接取余，结果不变
        k %= cnt;

        // 再进行一次遍历，需要找到旋转后的头结点，位置是原来链表的第cnt-k个，找到后把它前一个节点的next设为NULL，再返回它即可
        int newHeadPre = cnt - k - 1;
        ListNode *res;
        while (head) {
            if (newHeadPre != 0) {
                newHeadPre--;
                head = head->next;
            } else {
                res = head->next;
                head->next = NULL;
                break;
            }
        }
        return res;
    }
};

int main() {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    ListNode *res = Solution::rotateRight(node1, 2);
    while (res) {
        std::cout << res->val << std::endl;
        res = res->next;
    }
    return 0;
}
