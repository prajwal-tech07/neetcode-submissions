/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
      unordered_map<Node*,Node*> mp;
      Node*newhead=new Node(head->val);
      mp[head]=newhead;
      Node*oldtemp=head->next;
      Node*newtemp=newhead;
      while(oldtemp!=nullptr){
        Node*copynode=new Node(oldtemp->val);
        mp[oldtemp]=copynode;
        newtemp->next=copynode;
        newtemp=newtemp->next;
        oldtemp=oldtemp->next;
      }
      oldtemp=head;
      newtemp=newhead;
      while(oldtemp!=nullptr){
        newtemp->random=mp[oldtemp->random];
        newtemp=newtemp->next;
        oldtemp=oldtemp->next;
      }
      return newhead;
    }
};
