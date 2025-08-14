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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head||!head->next){
            return NULL;
        }

        int count=0;
        ListNode* temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        int k=(count-n);
        temp=head;
        ListNode* prev=nullptr;
        if(k==0){
            head=head->next;
            delete temp;
            return head;
        }
        
        while(k--){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        delete temp;
        return head;


    }
};