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
        ListNode *dummy=new ListNode(-1);
        ListNode *tail=dummy;
        int carry=0;

        while(l1!=NULL || l2!=NULL || carry==1){
            int x=(l1!=NULL)?l1->val:0;
            int y=(l2!=NULL)?l2->val:0;
            
            int sum=x+y+carry;
            carry=sum/10;
            int digit=sum%10;

            ListNode *newNode=new ListNode(digit);
            tail->next=newNode;
            tail=tail->next;
            
            if(l1!=NULL){
                l1=l1->next;
            }
            if(l2!=NULL){
                l2=l2->next;
            }

            
        }
        return dummy->next;
    }
};
