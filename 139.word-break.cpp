/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> memo;
    bool wordBreak(string s, vector<string>& wordDict) {
        memo.resize(s.size(), -1);
        return dp(s, wordDict, 0);
    }

    bool dp(string& s, vector<string>& wordDict, int i){
        // base case first
        if (i >= s.size()){ // found all
            return true;
        }
        if (memo[i] != -1){
            return memo[i];
        }

        for (string& word : wordDict){
            int wordLen = word.size();
            if ((s.size() - i) < wordLen){ // if remaining chars in s is shorter than current word in dict
                continue;
            }
            string curr = s.substr(i, wordLen);
            if (curr != word){
                continue;
            }
            // use word or use different word
            if (dp(s, wordDict, i+wordLen)){
                memo[i] = true;
                return true;
            }
        }
        memo[i] = false;
        return false;
    }

};
// @lc code=end

