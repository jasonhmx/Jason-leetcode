/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start

#include <unordered_map>
using namespace std;
class Solution {

// for each number k (k>1) as root, the number of trees in that config
// is numTrees(k-1) * numTrees(n-k). Essentially you have all the ways
// in the left subtree plus the right subtree

// make a memo for it
public:
    unordered_map<int, int> memo;
    int numTrees(int n) {
        if (memo[n] > 0){// result is already in memo
            return memo[n];
        }
        if (n == 1 || n == 0){ // nullptr and one node only has one config
            return 1;
        }
        int result = 0;
        for (int i = 1; i <= n; i++){
            result += numTrees(i-1) * numTrees(n-i);
        }
        memo[n] = result;
        return result;
    }
};
// @lc code=end

