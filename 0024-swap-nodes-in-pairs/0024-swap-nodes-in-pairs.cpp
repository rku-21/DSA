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
    ListNode* reverse(ListNode* curr, ListNode* next){
        if(curr==nullptr) return next;
        if(next==nullptr) return curr;
        ListNode* next1=next->next;
        
        next->next=curr;
        curr->next=nullptr;
        if(next1==nullptr) return next;
        curr->next=reverse(next1,next1->next);
        return next;

    }
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* curr=head;
        ListNode* next=head->next;
        ListNode* next1=head->next->next;
        
        next->next=curr;
        curr->next=NULL;

        if(next1==nullptr) return next;

        curr->next=reverse(next1,next1->next);

        return next;






        
    }
};