/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start

/*
Notes:
Tried using two unordered_sets, takes too long
Use the coloring approach
*/

#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        vector<bool> color(graph.size(), false);
        bool valid = true;
        for (int i = 0; i < graph.size(); i++){
            if(!visited[i]){
                dfs(graph, visited, color, i, valid);
                // bfs(graph, visited, color, i, valid);
            }
        }
        return valid;
    }

    void dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& color, int node, bool& valid){
        if (!valid){
            return;
        }
        
        visited[node] = true; // we have checked whether it has been visited in inner loops, so can safely set visited here
        for (auto k : graph[node]){
            if (!visited[k]){
                color[k] = !color[node];
                dfs(graph, visited, color, k, valid);
            } else {
                if (color[k] == color[node]){
                    valid = false;
                    return;
                }
            }
        }

    }

    void bfs(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& color, int node, bool& valid){
        if (!valid){
            return;
        }
        queue<int> q;
        visited[node] = true;
        q.push(node);
        while (!q.empty()){
            int sz = q.size();
            for (int i = 0; i < sz; i++){
                int curr = q.front();
                q.pop();
                // we mark visited inside inner loop, so don't have
                // to check for curr's visitedness
                for (auto k : graph[curr]){ // look at all curr's neighbors
                    if (!visited[k]){
                        visited[k] = true;
                        color[k] = !color[curr];
                        q.push(k);
                    } else {
                        if (color[k] == color[curr]){
                            valid = false;
                        }
                    }
                }
            }
        }
    }

};

// @lc code=end

/*         for (int i = 0; i < graph.size(); i++){
            if (left.count(i)){
                // if i already in left, all k needs to be in right
                for (auto k : graph[i]){
                    if (left.count(k)){
                        return false;
                    }
                    if (!right.count(k)){
                        right.insert(k);
                    }
                }
            }
            if (right.count(i)){
                // same for i already in right
                for (auto k : graph[i]){
                    if (right.count(k)){
                        return false;
                    }
                    if (!left.count(k)){
                        left.insert(k);
                    }
                }
            }

            // what if i isn't in either set? don't know
        } */
