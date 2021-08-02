class Node{
public:
    int key, value;
    Node *next, *prev;
    
    Node(int k, int v){
        key = k;
        value = v;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList{
    Node *head, *tail;
    
    bool isEmpty(){
        return head == NULL;
    }
public:
    DoublyLinkedList(){
        head = NULL;
        tail = head;
    }
    
    Node* addFirst(int key, int value){
        Node* curr = new Node(key, value);
        if(head == NULL){
            head = tail = NULL;
        }
        else{
            curr->next = head;
            head->prev = curr;
            head = curr;
        }
        return head;
    }
    
    void moveToHead(Node* curr){
           
        if(curr == head){
            return;
        }    
        else if(curr == tail){
            tail = curr->prev;
            tail->next = NULL;
        }
        
        curr->next = head;
        curr->prev = NULL;
        head->prev = curr;
        head = curr;
    }
    
    void removeLast(){
        if(isEmpty())return;
        
        if(head == tail){
            delete(head);
            head = tail = NULL;
        }
        else{
            Node* temp = tail;
            tail =  tail->prev;
            tail->next = NULL;
            delete(temp);
        }
    }
    
    Node* getTail(){
        return tail;
    }
};


class LRUCache {
    
    int capacity, size;
  DoublyLinkedList *pageList;
  map<int, Node*> pageMap;

  public:
    LRUCache(int capacity) {
      this->capacity = capacity;
      size = 0;
        pageList = new DoublyLinkedList();
        pageMap = map<int, Node*>();
    }

    int get(int key) {
        if(pageMap.find(key)==pageMap.end()) {
          return -1;
        }
        int val = pageMap[key]->value;

        // move the page to front
        pageList->moveToHead(pageMap[key]);
        return val;
    }

    void put(int key, int value) {
      if(pageMap.find(key)!=pageMap.end()) {
          // if key already present, update value and move page to head
          pageMap[key]->value = value;
          pageList->moveToHead(pageMap[key]);
          return;
      }

        if(size == capacity) {
          // remove rear page
          int k = pageList->getTail()->key;
          pageMap.erase(k);
          pageList->removeLast();
          size--;
        }

        // add new page to head to Queue
        Node *page = pageList->addFirst(key, value);
        size++;
        pageMap[key] = page;
    }

    ~LRUCache() {
      map<int, Node*>::iterator i1;
      for(i1=pageMap.begin();i1!=pageMap.end();i1++) {
          delete i1->second;
      }
      delete pageList;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
