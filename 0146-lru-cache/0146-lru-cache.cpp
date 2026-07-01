class LRUCache {
public:
    struct dll {
        int val;
        dll* next;
        dll* prev;
        int key;

        dll(int val,int key){
            this->val=val;
            this->next=nullptr;
            this->prev=nullptr;
            this->key=key;

        }
    };
    int capacity;

    unordered_map<int,dll*>mp;
    dll* head=nullptr;
    dll* tail=nullptr;
    
    LRUCache(int capacity) {
        this->capacity=capacity;
        
    }

    void movetoFront(dll* node){
        if(node==head) return;
        dll* previous=node->prev;
        dll* Next=node->next;
        if(node==tail){
            tail=previous;
        }
        node->prev=nullptr;
        node->next=head;
        head->prev=node;
        if(previous) previous->next=Next;
        if(Next) Next->prev=previous;

        head=node;
    }
    
    int get(int key) {

        if(!mp.count(key)) return -1;

        dll* node=mp[key];

        movetoFront(node);
        mp[key]=head;

        return head->val;


        
    }
    
    void put(int key, int value) {

        if(head==nullptr){
            head=new dll(value,key);
            tail=head;
            mp[key]=head;
        }
        else {
            if(mp.count(key)){
                // update

                dll* node=mp[key];

                movetoFront(node);
                mp[key]=head;
                head->val=value;
            }
            else {
                //insert 

                if(mp.size()==capacity){
                    dll* temp=tail;

                    if(head==tail){
                        head=nullptr;
                        tail=nullptr;
                    }
                    else {
                        tail=tail->prev;
                        tail->next=nullptr;
                    }
                    mp.erase(temp->key);
                    delete temp;
                }

                dll* newnode=new dll(value,key);
               if(head==nullptr){
                   head=newnode;
                   tail=newnode;

               }
               else {
                    newnode->next=head;
                    head->prev=newnode;
                    head=newnode;
                    
               }
               mp[key]=head;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */