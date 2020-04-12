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
    ListNode* middleNode(ListNode* head) {
        int sz = 1;
        ListNode* curr = head;
        while(curr) {
            sz++;
            curr = curr->next;
        }
        int target = (sz >> 1) + (sz & 1);
        curr = head;
        while(--target)
            curr = curr->next;
        return curr;
    }
};
