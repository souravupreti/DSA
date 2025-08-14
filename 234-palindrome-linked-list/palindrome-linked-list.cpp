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
    ListNode* reverse(ListNode* head){
        if(!head||!(head->next)){
            return head;
        }
        ListNode* prev=nullptr;
        ListNode* temp=head;
        while(temp){
            ListNode* temp1=temp->next;
            temp->next=prev;
            prev=temp;
            temp=temp1;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next&&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newNode=reverse(slow->next);
        ListNode* first=head;
        ListNode* second=newNode;
        while(second){
            if(first->val!=second->val){
                reverse(newNode);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverse(newNode);
        return true;
        
    }
};