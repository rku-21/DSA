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
    tuple<ListNode*, ListNode* , ListNode*> reverseLL(ListNode* curr, int cnt){
        ListNode* prev=nullptr;
         
         ListNode* next=nullptr;
         ListNode* tail=curr;
        while(cnt--){
            next=curr->next;
           
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return {prev,tail,next};
        


    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;
       ListNode* temp=head;

       int len=0;
       while(temp!=NULL){
           temp=temp->next;
           len++;
       }
       ListNode* finalHead=nullptr;
       ListNode* tail=nullptr;
       ListNode* nextToRev=head;
       while(len>=k && nextToRev!=nullptr){
          auto nodes=reverseLL(nextToRev,k);
          if(!finalHead){
              finalHead=get<0>(nodes);
              tail=get<1>(nodes);

          }
          else {
             tail->next=get<0>(nodes);
             tail=get<1>(nodes);
          }
          nextToRev=get<2>(nodes);
          len-=k;
          

       }
       tail->next=nextToRev;

       return finalHead;

        
    }
};