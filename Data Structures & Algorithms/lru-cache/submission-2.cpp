class LRUCache {
public:
    class Node{
    public:
        int key,val;
        Node* prev;
        Node* next;

        Node(int k,int v){
            key=k;
            val=v;
            prev=next=NULL;
        }

    };
    Node*head=new Node(-1,-1);
    Node*tail=new Node(-1,-1);

    unordered_map<int,Node*> mp;
    int limit;
    LRUCache(int capacity) {
        limit=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void delNode(Node*oldNode){
        oldNode->prev->next=oldNode->next;
        oldNode->next->prev=oldNode->prev;
    }
    void addNode(Node *newNode){
       Node *oldnext=head->next;
       head->next=newNode;
       newNode->next=oldnext;
       oldnext->prev=newNode;
       newNode->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        Node *newNode=mp[key];
        delNode(mp[key]);
        addNode(newNode);
        return newNode->val;
    }
    
    void put(int key, int value) {
       if(mp.find(key)!=mp.end()){
        Node*oldNode=mp[key];
        delNode(oldNode);
        mp.erase(key);
       }
       
       if(mp.size()==limit){
        mp.erase(tail->prev->key);
        delNode(tail->prev);
        }
       Node *newNode=new Node(key,value);
       addNode(newNode);
       mp[key]=newNode;
    }
};
