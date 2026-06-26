class LFUCache {
    int cap;
    int minFreq;
    
    unordered_map<int, pair<int, int>> keyNode; 
    unordered_map<int, list<int>> freqList; 
    unordered_map<int, list<int>::iterator> keyIter; 

    void updateFreq(int key) {
        int currentFreq = keyNode[key].second;
        
        freqList[currentFreq].erase(keyIter[key]);
        
        if (freqList[currentFreq].empty() && currentFreq == minFreq) {
            minFreq++;
        }
        
        keyNode[key].second++;
        int newFreq = keyNode[key].second;
        
        freqList[newFreq].push_back(key);
        keyIter[key] = --freqList[newFreq].end();
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) {
            return -1;
        }
        
        updateFreq(key);
        return keyNode[key].first;
    }
    
    void put(int key, int value) {
        if (cap == 0) return;

        if (keyNode.find(key) != keyNode.end()) {
            keyNode[key].first = value;
            updateFreq(key);
            return;
        }

        if (keyNode.size() == cap) {
            int evictKey = freqList[minFreq].front();
            
            freqList[minFreq].pop_front();
            keyNode.erase(evictKey);
            keyIter.erase(evictKey);
        }

        keyNode[key] = {value, 1};
        freqList[1].push_back(key);
        keyIter[key] = --freqList[1].end();
        
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
