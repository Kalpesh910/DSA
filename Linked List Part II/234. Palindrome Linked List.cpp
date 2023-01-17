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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        if(head==NULL || head->next==NULL)  return true;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* curr=slow;
        ListNode* prev=NULL;
        
        while(curr){
            ListNode* Nxt = curr->next;    
            curr->next=prev;
            prev = curr;
            curr=Nxt;
        }
        ListNode* temp=head;
        while(prev && temp){
            if(prev->val != temp->val)  return false;
            prev=prev->next;
            temp=temp->next;
        }
        return true;
    }
};
