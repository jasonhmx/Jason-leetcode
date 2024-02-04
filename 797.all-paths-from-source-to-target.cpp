/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start

/*
Notes:
onPath here isn't necessary, as the problem stated there wouldn't be any loops
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> track;
        traverse(graph, 0, res, track);
        return res;
    }

    void traverse(vector<vector<int>>& graph, int node, vector<vector<int>>& res, vector<int>& track){
        track.push_back(node);
        if (node == graph.size()-1){
            res.push_back(track);
        } else {
            for (auto i : graph[node]){
                traverse(graph, i, res, track);
            }
        }
        track.pop_back();
    }

/*     void traverse(vector<vector<int>>& graph, int node, vector<vector<int>>& res, vector<int>& track, vector<bool>& onPath){
        if (node == graph.size() - 1){ // base case needs to be at node, not at null
            track.push_back(node);
            res.push_back(track);
            track.pop_back();
        }

        if (!onPath[node]){ // if hasn't been on the path before
            track.push_back(node);
            onPath[node] = true;
            for (auto i : graph[node]){
                traverse(graph, i, res, track, onPath); // here it won't enter target's children cus it doesn't have any
            }
            onPath[node] = false;
            track.pop_back();
        }
    } */
};
// @lc code=end

