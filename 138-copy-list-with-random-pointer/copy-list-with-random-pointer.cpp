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
        Node* temp=head;
         while (temp) {
            Node* newn = new Node(temp->val);
            newn->next = temp->next;
            temp->next = newn;
            temp = newn->next;
        }
        temp = head;
        while (temp) {
            if (temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        Node* dummy = new Node(-1);
        Node* copyTail = dummy;
        temp = head;
        while (temp) {
            Node* copy = temp->next;
            copyTail->next = copy;
            copyTail = copy;

            temp->next = copy->next; // restore original list
            temp = temp->next;
        }

        return dummy->next;

    }
};