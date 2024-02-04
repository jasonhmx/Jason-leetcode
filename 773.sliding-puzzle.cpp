/*
 * @lc app=leetcode id=773 lang=cpp
 *
 * [773] Sliding Puzzle
 */

// @lc code=start

/*
Notes:
Puzzle/maze solving algorithm -- BFS
Trick is to serialise the board state so it's easier to store
*/
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    const vector<vector<int>> neighbors = { // neighbors[i] notes i's neighbors in the flattened string
        {1, 3},
        {0, 2, 4},
        {1, 5},
        {0, 4},
        {1, 3, 5},
        {2, 4}
    };

    int slidingPuzzle(vector<vector<int>>& board) {
        // first serialise the board
        string start = "";
        for (auto i : board){
            for (auto k : i){
                start+=to_string(k);
            }
        }
        string target = "123450";
        unordered_set<string> visited;
        return bfs(start, visited, target);
    }

    int bfs(string& start, unordered_set<string>& visited, string& target){
        queue<string> q;
        q.push(start);
        int step = 0;
        while (!q.empty()){
            int sz = q.size();
            for (int i = 0; i < sz; i++){
                string curr = q.front();
                q.pop();
                if (curr == target){
                    return step;
                }
                // see where 0 is in the string
                int index = curr.find("0");
                for (auto k : neighbors[index]){
                    // add every neighbor swap to the queue
                    string toAdd = curr; // copy current
                    toAdd[index] = curr[k];
                    toAdd[k] = curr[index];
                    if (!visited.count(toAdd)){
                        q.push(toAdd);
                        visited.insert(toAdd);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
// @lc code=end

