/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start

/*
Notes:
Main idea is to use what is called a 'hash-linkedList'; where a key is mapped in the hashmap
to a node in a doubly-linked list. The list retains time order and the hashmap retains constant
time access.

My commented implementation at the bottom does work in testing, but has integer unaligned error when submitting to leetcode.
The commented implementation contains a custom doubly-linked list.

A more C++ way of doing things, which the uncommented section successfully does,
is to use std::list, and have a hashmap that maps to the list iterator.
This would mean that the key would not only map to the key-value pair, but also to the
iterator within the list, which the list can use to perform erase operations without us
worrying about implementing it ourselves.

We can do this, thanks to the fact that list iterators in C++ aren't invalidated
when list changes internally.

This approach also avoids the need to use the `new` keyword and manual-allocate 
heap memory; and instead uses std containers to manage dynamic memory. 
*/
#include <unordered_map>
#include <list>
using namespace std;


class LRUCache{
private:
    struct Node{
        // here we don't need to worry about initialisation, or pointers
        // to prev and next values. The std::list will take care of this for you
        int key;
        int val;
    };
    list<Node> timeCache;
    unordered_map<int, list<Node>::iterator> keyCache;
    int cap;
    void moveToFront(list<Node>::iterator nodeIter) {
        // a function that moves a node to a front of the list

        // get the node pointed to by the iterator (dereference)
        Node toUpdate = *nodeIter;
        // remove the node from the timeCache
        timeCache.erase(nodeIter);
        // push the node to the front as the most-recently used
        timeCache.push_front(toUpdate);
    }
    void addToFrontAndUpdateKeyCache(int key, int val){
        Node toAdd = {key, val};
        timeCache.push_front(toAdd);
        keyCache[key] = timeCache.begin();
    }

public:
    LRUCache(int capacity) : cap{capacity} {} // initialiser list
    LRUCache() : cap{0} {} // everything else has default constructor

    int get(int key){
        // If key is in keyCache
            // move the key to the front, update keyCache with new position
        // else return -1
        if (keyCache.count(key)){
            // found the key
            // get the iterator
            list<Node>::iterator nodeIter = keyCache[key]; 
            moveToFront(nodeIter);
            // update the keyCache
            keyCache[key] = timeCache.begin();
            // return the value
            return keyCache[key] -> val;
        } else {
            return -1;
        }
    }

    void put(int key, int value){
        // if key is in keyCache
            // update timeCache, update keyCache on the iterator
            // update its value
        // if key isn't in keyCache
            // if capacity not reached (check using list.size())
                // create a new Node, push to front of timeCache
                // Add the mapping to keyCache
            // if capacity is reached
                // pop-off the least-recently used node
                // delete from keyCache
                // create a new Node, push to front of timeCache
        if (keyCache.count(key)) {
            // if found, move to front
            list<Node>::iterator nodeIter = keyCache[key];
            moveToFront(nodeIter);
            // update keyCache
            keyCache[key] = timeCache.begin();
            // update val
            keyCache[key] -> val = value;
        } else{
            if (timeCache.size() < cap){
                addToFrontAndUpdateKeyCache(key, value);
            } else { // timeCache.size() == cap
                int toDelete = timeCache.back().key;
                timeCache.pop_back();
                keyCache.erase(toDelete);
                addToFrontAndUpdateKeyCache(key, value);
            }
        }
    }

};


/*
#include <unordered_map>
#include <utility>
using namespace std;

class LRUCache {
private:
    // implement a hash-linkedlist data structure, that retains
    // both time order and O(1) access.#

    template<typename T>
    struct ListNode {
        public:
            ListNode<T>* next;
            ListNode<T>* prev;
            T key; // need key as well for deletion from cache hash
            T val;

            ListNode(){
                next = nullptr;
                prev = nullptr;
            }

            ListNode(T keyval, T value){
                key = keyval;
                val = value;
            }
    };

    // have an unordered map that maps key to list nodes
    unordered_map<int, ListNode<int>*> cacheHash;
    // a pointer that tracks which node is last used
    ListNode<int>* least_used;
    ListNode<int>* recent_used;
    int cap = 0;
    int count = 0;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(cacheHash.count(key)){
            // if key exists, return value and update order
            ListNode<int>* toUpdate = cacheHash[key];
            // if toUpdate is the most recently used node, don't do anything
            // otherwise update
            if (toUpdate != recent_used){ // update list
                if (toUpdate != least_used){
                    // take the toUpdate node out, put in front as recent_used
                    // update its neighbouring nodes
                    ListNode<int>* next = toUpdate->next;
                    ListNode<int>* prev = toUpdate->prev;
                    toUpdate->next = recent_used;
                    recent_used->prev = toUpdate;
                    toUpdate->prev = nullptr;
                    prev->next = next;
                    next->prev = prev;
                    recent_used = toUpdate;
                } else {
                    // take toUpdate node out, put in front
                    // update both recent_used and least_used
                    ListNode<int>* prev = toUpdate->prev;
                    prev->next = nullptr;
                    toUpdate->next = recent_used;
                    recent_used->prev = toUpdate;
                    toUpdate->prev = nullptr;
                    recent_used = toUpdate;
                    least_used = prev;
                }
            }
            return toUpdate->val;
        } else {
            return -1;
        }
        
    }
    
    void put(int key, int value) {
        if (get(key) != -1) { // if key exists
            // running get(key) updates the node structure for existing key pairs
            cacheHash[key]->val = value;
        } else { // key doesn't exist
            ListNode<int>* toAdd = new ListNode<int>(key, value);
            cacheHash[key] = toAdd;
            toAdd->next = recent_used;
            if (recent_used != nullptr){
                recent_used->prev = toAdd;
            } else {
                // recent_used == least_used == nullptr, need to initialise least_used
                least_used = toAdd;
            }
            toAdd->prev = nullptr;
            recent_used = toAdd;
            if (count == cap){
                ListNode<int>* prev = least_used->prev;
                if (prev != nullptr){
                    prev->next = nullptr;
                }
                // remember to erase from hash as well after deleting from list
                cacheHash.erase(least_used->key);
                delete least_used;
                least_used = prev;

            } else {
                count++;
            }
        }
    }
};
*/

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

