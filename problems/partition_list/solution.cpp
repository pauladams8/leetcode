/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *gtHead = new ListNode(0), *gtTail = gtHead, *ltHead = new ListNode(0), *ltTail = ltHead;
        for (ListNode *node = head, *next = nullptr; node; node = next) {
            next = node->next;
            node->next = nullptr;
            if (node->val < x) {
                ltTail->next = node;
                ltTail = node;
            } else {
                gtTail->next = node;
                gtTail = node;
            }
        }
        ltTail->next = gtHead->next;
        return ltHead->next;
    }
};