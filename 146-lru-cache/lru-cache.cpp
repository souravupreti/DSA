class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k,int v){
        key=k;
        val=v;
        prev=NULL;
        next=NULL;
    }
};

class LRUCache {
public:
    int capacity;
    Node * head1;
    Node * tail1;
    unordered_map<int ,Node *>mp;

    LRUCache(int capacity) {
        this->capacity=capacity;
        head1=new Node(-1,-1);
        tail1=new Node(-1,-1);
        head1->next=tail1;
        tail1->prev=head1;
    }

    void deleteNode (Node * temp){
        Node *temp1=temp->next;
        temp1->prev=temp->prev;
        temp->prev->next=temp1;
    }

    void addNode(Node * temp){
        Node * temp1=head1->next;

        head1->next=temp;
        temp->prev=head1;

        temp->next=temp1;
        temp1->prev=temp;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        Node * temp=mp[key];
        deleteNode(temp);
        addNode(temp);
        return temp->val;
    }
    
    void put(int key, int value) {

        if(mp.find(key)!=mp.end()){
            Node* node=mp[key];
            node->val = value;
            deleteNode(node);
            addNode(node);
            return;
        }

        if(capacity==mp.size()){
            Node* node=tail1->prev;
            deleteNode(node);
            mp.erase(node->key);
        }

        Node * temp=new Node(key,value);
        addNode(temp);
        mp[key]=temp;
    }
};