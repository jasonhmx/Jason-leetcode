/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/*
Notes:
Think of NestedInteger as a multi-nary tree, traverse the nodes and add the leaves to vector
this is a bit too memory intensive
Do instead: flatten first list until we have an integer to pop off

*/
#include <list>
#include <vector>
#include <utility>
using namespace std;

class NestedIterator {
public:
    list<NestedInteger> nestList;
    NestedIterator(vector<NestedInteger> &nestedList) {
        list<NestedInteger> toMove(nestedList.begin(), nestedList.end());
        nestList = move(toMove);
    }
    
    int next() {
        int result = nestList.front().getInteger();
        nestList.pop_front();
        return result;
    }
    
    bool hasNext() {
        if (nestList.empty()){
            return false;
        } 
        while(!nestList.front().isInteger()){
            // flatten nestList[0] and add to front
            vector<NestedInteger> toAdd = nestList.front().getList();
            for (int i = toAdd.size()-1; i>=0; i--){
                nestList.push_front(toAdd[i]);
            }
        }
        return !nestList.empty();
    }
};

/*
Commented code block here expands the whole nest first, then iterate. Works but is very memory-intensive:

class NestedIterator {
public:
    vector<int> flattened;
    int index = 0;
    NestedIterator(vector<NestedInteger> &nestedList) {
        traverse(nestedList);
    }
    
    int next() {
        return flattened[index];
        index++;
    }
    
    bool hasNext() {
        return (index < flattened.size());
    }

    void traverse(vector<NestedInteger> &nestedList) {
        for (int i = 0; i < nestedList.size(); i++){  
            if (nestedList[i].isInteger()){
                flattened.push_back(nestedList[i].getInteger());
            }
            else {
                traverse(nestedList[i].getList());
            }
        }
    }
};
*/


/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

