class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<int> ihash;
    MyHashSet() {  
    }
        /** Returns true if this set contains the specified element */
    bool contains(int key) {
        vector<int>::iterator ite=find(ihash.begin(), ihash.end(), key);
        if(ite!=ihash.end()) return true;
        return false;
    }
    void add(int key) {
        if(find(ihash.begin(), ihash.end(), key)==ihash.end())
        ihash.push_back(key);
    }
    
    void remove(int key) {
        vector<int>::iterator ite=find(ihash.begin(), ihash.end(), key);
        if(ite!=ihash.end()) ihash.erase(ite);
    }
    

};