/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start

/*
Notes:
Sliding window method. Left inclusive and right exclusive.
*/
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0){
            return 0;
        }
        unordered_map<char, int> window;
        int left, right = 0;
        int len = 0;
        // increase window
        while(right < s.size()){
            char c = s[right];
            right++;
            window[c]++;
            // if repeating characters are met, shrink window
            while(window[c] > 1){ // shrink until the repeated character no longer repeats
                char d = s[left];
                left++;
                window[d]--;
            }
            len = max(len, right - left);
        }
        return len;
    }
};
// @lc code=end

