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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *oddHead = new ListNode(0), *oddTail = oddHead, *evenHead = new ListNode(0), *evenTail = evenHead;
        for (int i = 1; head; i++, head = head->next) {
            if (i % 2) {
                oddTail->next = head;
                oddTail = oddTail->next;
            } else {
                evenTail->next = head;
                evenTail = evenTail->next;
            }
        }
        oddTail->next = evenHead->next;
        evenTail->next = nullptr;
        return oddHead->next;
    }
};