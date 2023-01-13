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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* newhead;
        if(temp1->val <= temp2->val){
            newhead = temp1;
            temp1 = temp1->next;
        }
        else{
            newhead = temp2;
            temp2 = temp2->next;
        }
        ListNode* temp3 = newhead;
        while(temp1 && temp2){
            if(temp1->val <= temp2->val){
                temp3->next = temp1;
                temp1 = temp1->next;
                temp3 = temp3->next;
            }
            else{
                temp3->next=temp2;
                temp2=temp2->next;
                temp3 = temp3->next;
            }
        }
        if(temp1){
            temp3->next = temp1;
        }
        if(temp2){
            temp3->next = temp2;
        }
        return newhead;
    }
};
