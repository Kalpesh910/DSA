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
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int temp;
        if(temp1==NULL) return temp2;
        if(temp2==NULL) return temp1;
        int carry=0;
        ListNode* last;
        while(temp1->next && temp2->next){
            temp=temp1->val + temp2->val+carry;
            temp1->val = temp%10;
            carry = temp/10;
            last=temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(temp2->next == NULL){
            temp = temp1->val + temp2->val + carry;
            temp1->val = temp%10;
            carry = temp/10;
            last=temp1;
            temp1 = temp1->next;
            while(temp1){
                temp = temp1->val + carry;
                temp1->val = temp%10;
                carry = temp/10;
                last=temp1;
                temp1 = temp1->next;
            }
        }
        else if(temp1->next == NULL){
            temp = temp1->val + temp2->val + carry;
            temp1->val = temp%10;
            carry = temp/10;
            temp1->next = temp2->next;
            temp2==NULL;
            last=temp1;
            temp1 = temp1->next;
            while(temp1){
                temp = temp1->val + carry;
                temp1->val = temp%10;
                carry = temp/10;
                last=temp1;
                temp1 = temp1->next;
            }
        }
        if(carry!=0){
            ListNode *last2 = new ListNode(carry);
            // last->val = carry;
            last->next = last2;
        }
        return l1;
    }
};
