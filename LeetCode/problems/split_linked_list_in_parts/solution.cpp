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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        for (ListNode *node = head; node; node = node->next) {
            n++;
        }
        int chunk_size = n / k, extra = n % k;
        ListNode *node = head, *prev = nullptr;
        vector<ListNode*> ans(k);
        for (int i = 0; i < k && node; i++) {
            ans[i] = node;
            for (int j = 0; j < chunk_size + (i < extra) && node; j++) {
                prev = node;
                node = node->next;
            }
            prev->next = nullptr;
        }
        return ans;
    }
};