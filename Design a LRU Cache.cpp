class Node{
public:
    int key, value;
    Node* prev, *next;
    
    Node(int k, int v){
        key = k;
        value = v;
        prev = NULL;
        next = NULL;
    }
};


class LRUCache {
    
    Node* head, *tail;
    int capacity, size;
    unordered_map<int, Node*> m;
    
    void removeNode(Node* curr){
        if(curr->prev!=NULL){
            curr->prev->next = curr->next;
        }
        else{
            head = curr->next;
        }
        if(curr->next != NULL){
            curr->next->prev = curr->prev;
            
        }
        else{
            tail = curr->prev;
        }
        curr->prev=NULL;
        curr->next=NULL;
    }
    
    void addFirst(Node* curr){
        if (head == NULL)
        {
            head = tail = curr;
        }
        else{
        head->prev = curr;
        curr->next = head;
        head = curr;
        }
    }  
    
public:
    LRUCache(int capacity) {
        head = NULL;
        tail = head;
        this->capacity = capacity;
        size = 0;
    }
    
    int get(int key) {
        if (m.find(key)==m.end())
            return -1;
        Node *curr=m[key];
        removeNode(curr);
        addFirst(curr);
        //insert the node at first
        
        return curr->value;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            m[key]->value = value;
            removeNode(m[key]);
            addFirst(m[key]);
        }
        else{
            Node* curr = new Node(key, value);
            if(size == capacity){
                int key = tail->key;
                m.erase(key);
                size--;
                removeNode(tail);
            }
            addFirst(curr);
            m[key] = curr;
            size++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
