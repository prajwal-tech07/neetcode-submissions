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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
/*
    if(head==nullptr ||head->next==nullptr){
        return nullptr;
    }
     ListNode * temp=head;
     int count=1;
     while(temp->next!=nullptr){
        temp=temp->next;
        count++;
     }   
     int n1=count-n;
     if(n1==0){
        return head->next;
     }
     ListNode *current=head;
     
     for(int i=0;i<n1-1;i++){
       current=current->next; 
     }
     current->next=current->next->next;
     return head;

     */
     ListNode *dummy=new ListNode(-1);
     dummy->next=head;
     ListNode *first=dummy;
     ListNode *slow=dummy;
     for(int i=0;i<n+1;i++){
        first=first->next;
     }

     while(first!=nullptr){
        first=first->next;
        slow=slow->next;
     }
     slow->next=slow->next->next;
     return dummy->next;
    }
};
