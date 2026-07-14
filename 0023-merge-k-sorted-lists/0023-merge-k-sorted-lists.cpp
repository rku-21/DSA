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
    vector<ListNode*>pointers;

    ListNode* getNextValidPointer(auto&  lists){
        ListNode* nextPointer=nullptr;
        int minIdx=-1;
        int idx=0;
        for(auto list:lists){
            if(list){
                if(nextPointer==nullptr || nextPointer->val>list->val){
                    nextPointer=list;
                    minIdx=idx;

                }
            }
            idx++;
        }
        if(minIdx==-1) return nullptr;
        lists[minIdx]=lists[minIdx]->next;
        return nextPointer;
       
        
    }



    ListNode* mergeKLists(vector<ListNode*>& lists) {
       


        ListNode* head=nullptr;
        ListNode* tail=nullptr;

        while(true){
            ListNode* nextPointer=getNextValidPointer(lists);
            if(!nextPointer) break;
            if(head==nullptr){
                head=nextPointer;
                tail=nextPointer;
            }
            else {
                tail->next=nextPointer;
                tail=tail->next;
            }
           
        }
        return head;

       





        
    }
};