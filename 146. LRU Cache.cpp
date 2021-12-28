class LRUCache {
public:
     class node{
         public:
            int val,key;
            node*next;
            node*prev;
            node(int key,int val){
                this->key=key;
                this->val=val;
            }
        };
    node*head=new node(-1,-1);
    node*tail=new node(-1,-1);
    int size;
    unordered_map<int,node*>ma;
    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(ma.find(key)!=ma.end()){
            node*curr=ma[key];
            int val=curr->val;
            ma.erase(key);
            deletenode(curr);
            addnode(curr);
            ma[key]=head->next;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(ma.find(key)!=ma.end()){
           node*curr=ma[key];
           ma.erase(key);
           deletenode(curr);
        }
        if(size==ma.size()){
            ma.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        ma[key]=head->next;
    }
    
    void addnode(node* newnode){
        node*temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    
    void deletenode(node* newnode){
        node*temp=newnode->prev;
        temp->next=newnode->next;
        newnode->next->prev=temp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
