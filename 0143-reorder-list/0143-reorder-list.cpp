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
    ListNode * reverseLL(ListNode* prev){
        ListNode* curr=prev->next;
        ListNode* last=nullptr;
        while(curr!=nullptr){
            ListNode* next=curr->next;
            curr->next=last;
            last=curr;
            curr=next;
        }
        prev->next=nullptr;
        return last;
        

    }
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return ;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            fast=fast->next;
            if(fast) fast=fast->next;
            slow=slow->next;
        }

        ListNode* head2=reverseLL(slow);
        
       

        ListNode* head1=head;


        while(head1!=slow && head2!=nullptr){
            ListNode* next1=head1->next;
            ListNode* next2=head2->next;
            head1->next=head2;
            head2->next=next1;
            head1=next1;
            head2=next2;
        }
        










        
    }
};