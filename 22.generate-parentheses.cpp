/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start

/*
Notes:
Try adding '(', and if have enough L try adding R, and backtrack

*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string track = "";
        backtrack(n, res, track, 0, 0);
        return res;
    }

    void backtrack(int n, vector<string>& res, string& track, int countL, int countR) {
        if (countL == n && countR == n){
            res.push_back(track);
        }
        if (countL > n || countR > n){
            return;
        }

        // can put L whenever, or put R when there's enough L
        // try L first
        track.push_back('(');
        backtrack(n, res, track, countL + 1, countR);
        track.pop_back();

        // try R next
        if (countL > countR){
            track.push_back(')');
            backtrack(n, res, track, countL, countR + 1);
            track.pop_back();
        }
        // no valid solutions, just return
        return;
    }
};
// @lc code=end

