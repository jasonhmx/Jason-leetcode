/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start

/*
Notes:
Sliding window

Pay attention to using need[c] and need.size() together. This is not OK because
indexing into an unordered map would create the key automatically, hence modifying
the value of need.size(). Use need.count(c) instead
*/
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        int left = 0, right = 0, valid = 0;
        // valid counts how many characters have met the needed number

        // populate need map with characters in s1
        for (int i = 0; i < s1.size(); i++)
        {
            char c = s1[i];
            need[c]++;
        }

        // increase right until the valid number of characters are in window
        while (right < s2.size()){
            char c = s2[right];
            right++;
            if (need.count(c)){
                window[c]++;
                if (window[c] == need[c]){
                    valid++;
                }
            }

            while(valid == need.size() && left < right){
                if ((right - left) == s1.size()){
                    return true;
                }
                char d = s2[left];
                left++;
                if(need.count(d)){
                    if(window[d] == need[d]){ // valid decreases if we just took out a char and the number of that char doesn't satisfy requirements anymore
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return false;
    }
};
// @lc code=end

