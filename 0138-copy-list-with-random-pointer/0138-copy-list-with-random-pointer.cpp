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
        unordered_map<Node*,pair<Node*,Node*>>mp;
        Node* temp=head;
        Node* cloneHead=nullptr;
        Node* cloneTail=nullptr;
        while(temp!=nullptr){
            if(cloneHead==nullptr){
                cloneHead=new Node(temp->val);
                cloneTail=cloneHead;
                mp[temp]={cloneTail,temp->random};
            }
            else {
                cloneTail->next=new Node(temp->val);
                
                cloneTail=cloneTail->next;
                mp[temp]={cloneTail,temp->random};
            }
            temp=temp->next;

        }

        temp=head;
        while(temp!=nullptr){
            if(mp[temp].second==nullptr){
                mp[temp].first->random=nullptr;
                
            }
            else {
                mp[temp].first->random=mp[mp[temp].second].first;
            }

            temp=temp->next;
          


            

        }

        return cloneHead;





         
        
    }
};