/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

// @lc code=start

/*
More complicated than LRUCache, since it needs to keep track of
the minimum frequency used.
Requires a map from key to frequency and frequency to key. 
More specifically, using iterators in C++ and list structures:
map from frequency to lists of key-val-freq nodes
map from key to an iterator of a list of those nodes
int to keep track of minimum frequency
int to keep track of capacity

The implementation should be ok but has heap buffer overflow errors.
Not sure why
*/
#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
private:
    struct Node {
        int key;
        int val;
        int freq;
    };
    unordered_map<int, list<Node>::iterator> keyCache;
    unordered_map<int, list<Node>> freqCache;
    int cap;
    int minFreq;

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        // if key is in keyCache
            // update freqCache, since key has just been used
                // delete from old freq
                // update Node with new freq
                // push to new freq list
            // update minFreq if needed
            // update keyCache
        // if not, retrurn -1
        if (keyCache.count(key)) { //key is in
            // get iterator and the underlying struct
            list<Node>::iterator nodeIter = keyCache[key];
            Node toUpdate = *nodeIter;
            int prevFreq = toUpdate.freq;
            // update freqCache: delete struct from original list
            freqCache[prevFreq].erase(nodeIter);
            // update node with new freq
            toUpdate.freq++;
            // push to new freq list
            freqCache[prevFreq + 1].push_front(toUpdate);
            // update minFreq
            if (freqCache[prevFreq].empty()){ // we used the only minfreq element. increment minfreq
                minFreq++;
            }
            // update keyCache
            keyCache[key] = freqCache[prevFreq + 1].begin();
            return keyCache[key]->val;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        // if key is in keyCache
            // essentially do get, and update value
        if (get(key) != -1){
            keyCache[key] -> val = value;
        } else{ // if key isn't in key cache
            // if capacity hasn't been reached
                // create new node with new info
                // update freqCache:
                    // push new node to freqCache[1]
                    // update minFreq = 1
                    // add key to keyCache, point to iterator
            if (keyCache.size() < cap) {
                minFreq = 1;
                Node toAdd = {key, value, 1}; // new node with freq 1
                freqCache[1].push_front(toAdd);
                keyCache[key] = freqCache[1].begin();
            } else { // capacity reached
                // pop back the least frequently/recently used element
                // delete from keycache
                // update minFreq = 1
                // push new node to freqCache[1]
                // update keyCache
                Node toDelete = freqCache[minFreq].back();
                keyCache.erase(toDelete.key);
                freqCache[minFreq].pop_back();
                minFreq = 1;
                Node toAdd = {key, value, 1};
                freqCache[1].push_front(toAdd);
                keyCache[key] = freqCache[1].begin();
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

