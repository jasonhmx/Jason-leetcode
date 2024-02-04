/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

// @lc code=start

/*
Notes:
First thoughts: BFS, put all valid moves in queue, avoiding deadends
traverse that level, put more in queue, increment step after for loop
if found target, return
Keep a visited set, don't revisit

Conclusion:
As the above; remember to handle base-case carefully. Treat starting position
the same in principle as other nodes in the queue. I.e. to check for validity,
early return, and put the start to visited.
*/
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        unordered_set<string> visited;
        int step = 0;
        for (string item : deadends){ // mark the deadends as visited so we don't visit them
            visited.insert(item); 
        }
        if (visited.count("0000")){
            return -1;
        }
        q.push("0000");
        // remember to insert 0000 to visited too
        visited.insert("0000");
        while(!q.empty()){
            int sz = q.size();
            for (int i = 0; i < sz; i++){
                string current = q.front();
                q.pop();
                // check if found
                if (current == target){
                    return step;
                }
                // there are 8 choices of next turns
                for (int k = 0; k < 4; k++){
                    string up = plus1(current, k);
                    string down = min1(current, k);
                    if(!visited.count(up)){
                        q.push(up);
                        visited.insert(up);
                    }
                    if(!visited.count(down)){
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            step++;
        }
        return -1;
    }

    // conversion functions for generating next step strings
    string min1(string& s, int j){
        string res = s;
        if(res[j] == '0'){
            res[j] = '9';
        } else {
            res[j]--;
        }
        return res;
    }

    string plus1(string& s, int j){
        string res = s;
        if(res[j] == '9'){
            res[j] = '0';
        } else {
            res[j]++;
        }
        return res;
    }
};
// @lc code=end

