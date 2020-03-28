#ifndef DATA_STRUCTURE_HXX
#define DATA_STRUCTURE_HXX

struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

#endif