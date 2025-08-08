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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        while(curr && curr->next){
            int a = curr->val, b=curr->next->val;
            int num = gcd(a,b);
            ListNode* temp = curr->next;
            ListNode* node = new ListNode(num);
            curr->next = node;
            node->next = temp;
            curr=temp;
        }

        return head;
    }
};