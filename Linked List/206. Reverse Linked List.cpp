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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)  return head;
        ListNode* newhead = head->next;
        ListNode* temp = head;
        ListNode* temp2;
        temp->next=NULL;
        while(newhead->next!=NULL){
            temp2=newhead;
            newhead=newhead->next;
            temp2->next=temp;
            temp=temp2;
        }
        newhead->next=temp;
        return newhead;
    }
};
