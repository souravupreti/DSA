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
    ListNode* kthNode(ListNode* head,int k){
        ListNode* temp=head;
        k=k-1;
        while(k--&&temp){
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverse(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp){
            ListNode* t=temp->next;
            temp->next=prev;
            prev=temp;
            temp=t;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp){
            ListNode* kth=kthNode(temp,k);
            if(kth==nullptr){
                prev->next=temp;
                return head;
            }
            ListNode* nextNode=kth->next;
            kth->next=nullptr;
            reverse(temp);
            if(temp==head){
                head=kth;
            }
            else{
                prev->next=kth;
            }
            prev=temp;
            temp=nextNode;


        }
        return head;
    }
};