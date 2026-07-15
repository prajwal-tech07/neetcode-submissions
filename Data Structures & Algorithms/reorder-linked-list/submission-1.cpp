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
       
        ListNode* next1=nullptr;
        ListNode* next2=nullptr;
        while(head!=nullptr && prev!=nullptr){
           next1=head->next;
           next2=prev->next;

           head->next=prev;
           prev->next=next1;

           head=next1;
           prev=next2;
        }
        
        return ;
    }
};
