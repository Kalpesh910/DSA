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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
            // SOLUTION 1: Optimized
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        int aChanged=0, bChanged=0;
        while(tempA!=tempB && aChanged<=1 && bChanged<=1){
            if(tempA==tempB)    return tempA;
            if(tempA->next==NULL){
                tempA = headB;
                aChanged++;
            }
            else
                tempA = tempA->next;
            if(tempB->next==NULL){
                tempB = headA;
                bChanged++;
            }
            else
                tempB=tempB->next;
        }
        if(tempA!=tempB)    return NULL;
        return tempA;
        
            //SOLUTION 2: Using Hashing
        // ListNode* tempA = headA;
        // ListNode* tempB = headB;
        // map<ListNode*, int>mp;
        // int x=1;
        // while(tempA!=NULL){
        //     mp[tempA] = x;
        //     x++;
        //     tempA=tempA->next;
        // }
        // while(tempB!=NULL){
        //     if(mp[tempB])   return tempB;
        //     tempB=tempB->next;
        // }
        // return NULL;
    }
};
