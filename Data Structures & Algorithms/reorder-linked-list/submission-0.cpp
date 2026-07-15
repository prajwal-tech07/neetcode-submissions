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
    void reorderList(ListNode* head) {
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast!=nullptr &&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *current=slow->next;
        slow->next=nullptr;
        ListNode *prev=nullptr;
        ListNode *nextP=nullptr;
        while(current!=nullptr){
            nextP=current->next;
            current->next=prev;
            prev=current;
            current=nextP;
        }
       
        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;
        while(head!=nullptr && prev!=nullptr){
           tail->next=head;
           head=head->next;
           tail=tail->next;
           tail->next=prev;
           prev=prev->next;
           tail=tail->next;
        }
        if(head!=nullptr){
            tail->next=head;
        }
        if(prev!=nullptr){
            tail->next=prev;
        }
        return ;
    }
};
