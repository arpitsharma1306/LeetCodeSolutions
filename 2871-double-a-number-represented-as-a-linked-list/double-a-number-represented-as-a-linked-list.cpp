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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        while(head){
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }

        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);
        int carry = 0;
        ListNode* curr=head;
        while(curr){
            int sum = curr->val*2 + carry;
            curr->val = sum%10;
            carry = sum/10;

            if(!curr->next && carry){
                curr->next = new ListNode(carry);
                carry = 0;
                break;
            }

            curr = curr->next;
        }

        return reverseList(head);
    }
};