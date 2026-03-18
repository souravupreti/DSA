class Node {
public:
    int key, value, freq;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        freq = 1;
        prev = next = NULL;
    }
};

class DLL{
    public:
    Node* head;
    Node* tail;
    DLL(){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node * temp){
        Node * temp1=head->next;
        head->next=temp;
        temp->prev=head;
        temp->next=temp1;
        temp1->prev=temp;
    }
    void removeNode(Node * temp){
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
    Node * removeLast(){
        Node * temp=tail->prev;
        temp->prev->next=tail;
        tail->prev=temp->prev;
        return temp;
    }
     bool isEmpty() {
        return head->next == tail;
    }
};


class LFUCache {
public:
    int capacity;
    int minFreq;
    unordered_map<int,Node *>mp;
    unordered_map<int ,DLL *>frequency;
    LFUCache(int capacity) {
        this->capacity=capacity;   
    }
    void updateFrequency(Node * t){
        int fre=t->freq;
        frequency[fre]->removeNode(t);
        if (frequency[fre]->isEmpty()) {
            if (minFreq == fre) minFreq++;
        }
        t->freq++;

        if (frequency.find(t->freq) == frequency.end()) {
            frequency[t->freq] = new DLL();
        }
        frequency[t->freq]->addNode(t);

    }
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        Node* node = mp[key];
        updateFrequency(node);
        return node->value; 
    }
    
    void put(int key, int value) {
        if(capacity==0) return ;
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            node->value = value;
            updateFrequency(node);
            return;
        }
        if (mp.size() == capacity) {
            DLL* list = frequency[minFreq];
            Node* nodeToRemove = list->removeLast();
            mp.erase(nodeToRemove->key);
        }
        Node* newNode = new Node(key, value);
        if (frequency.find(1) == frequency.end()) {
            frequency[1] = new DLL();
        }
        frequency[1]->addNode(newNode);
        mp[key] = newNode;
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */