/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start

/*
Notes:
Pay attention to the order of && and ||, so that out of bounds conditions
aren't evaluated

Two pointers, from middle towards out
*/
#include <string>
using namespace std;

class Solution {
public:
    string palindrome(string s, int l, int r){
        while(l>=0 && r<s.length() && s[l] == s[r]){
            l--;
            r++;
        }
        return s.substr(l+1, r-l-1);
    }

    string longestPalindrome(string s){
        string result = "";
        int len = s.length();
        for(int i = 0; i<len; i++){
            string pal1 = palindrome(s, i, i);
            string pal2 = palindrome(s, i, i+1);
            if(result.length() < pal1.length()){
                result = pal1;
            }
            if(result.length() < pal2.length()){
                result = pal2;
            }
        }
        return result;
    }
};
// @lc code=end

