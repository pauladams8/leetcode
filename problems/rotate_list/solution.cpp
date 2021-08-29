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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return nullptr;
        if (k == 0)
            return head;
        ListNode *fast = head, *slow = head;
        for (int i = 1; i <= k; i++) {
            fast = fast->next;
            if (!fast) {
                fast = head;
                k %= i;
                i = 0;
            }
        }
        while (fast && fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = nullptr;
        return head;
    }
};