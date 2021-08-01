class MyHashMap {
    private:
    vector<vector<pair<int,int>>> data;
    
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        data.resize(10000);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int newKey = key % data.size();
        
        for(auto &i : data[newKey]){
            if(i.first == key){
                i.second = value;
                return;
            }
        }
        data[newKey].push_back({key,value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int newKey = key % data.size();
        
        for(auto &i : data[newKey]){
            if(i.first == key){
                return i.second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int newKey = key % data.size();
        int count = 0;
        for(auto &i : data[newKey]){
            if(i.first == key){
                data[newKey].erase(data[newKey].begin()+count);
                return;
            }
            count++;
        }
    }
};
