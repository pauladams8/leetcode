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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1), l2 = reverse(l2);
        ListNode *head = nullptr;
        int sum = 0;
        while (l1 && l2) {
            sum += l1->val + l2->val;
            ListNode *digit = new ListNode(sum % 10);
            digit->next = head;
            head = digit;
            sum /= 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        head = appendInReverse(head, l1, sum);
        head = appendInReverse(head, l2, sum);
        if (sum) {
            ListNode *node = new ListNode(sum);
            node->next = head;
            head = node;
        }
        return head;
    }
    
    ListNode* reverse(ListNode *head) {
        ListNode *node = head;
        while (node && node->next) {
            ListNode *next = node->next;
            node->next = next->next;
            next->next = head;
            head = next;
        }
        return head;
    }
    
    ListNode* appendInReverse(ListNode *to, ListNode *from, int& sum) {
        while (from) {
            ListNode *node = from;
            sum += node->val;
            node->val = sum % 10;
            sum /= 10;
            from = from->next;
            node->next = to;
            to = node;
        }
        return to;
    }
};