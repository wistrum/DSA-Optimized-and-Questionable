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
    int pairSum(ListNode* head) {
        ListNode* end = head;
        ListNode* mid = head;
        ListNode* prev = nullptr;
        ListNode* next;
        while(end && end->next){
            end = end->next->next;
            next = mid->next;
            mid->next = prev;
            prev = mid;
            mid = next;
        }
        int max_sum = 0;
        while(prev){
            max_sum = max(prev->val + mid->val, max_sum);
            prev = prev->next;
            mid = mid->next;
        }
        return max_sum;
    }
};