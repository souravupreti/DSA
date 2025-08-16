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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1=l1;
        ListNode* t2=l2;
        int carry=0;
        ListNode* n=new ListNode(-1);
        ListNode* h=n;
        while(t1&&t2){
            int sum=t1->val+t2->val+carry;
            h->next=new ListNode(sum%10);
            carry= sum/10;
            t1=t1->next;
            t2=t2->next;
            h=h->next;
        }
        if(t1){
            while(t1){
                int sum=t1->val+carry;
                h->next=new ListNode(sum%10);
                carry= sum/10;
                t1=t1->next;
                h=h->next;
            }
        }
        else{
            while(t2){
                int sum=t2->val+carry;
                h->next=new ListNode(sum%10);
                carry= sum/10;
                t2=t2->next;
                h=h->next;
            }
        }
        if(carry){
            h->next=new ListNode(carry%10);
        }
        return n->next;
    }
};