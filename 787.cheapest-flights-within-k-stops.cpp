/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
private:
    using Graph = vector<vector<vector<int>>>; 
    Graph graph;
    // graph[i] is a list of node i's neighbors, where
    // neighbor[0] is node, neighbor[1] is edgeweight
    Graph memo;
    // memo[src][dst][k] logs min dist from src to dst in at most k steps
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        buildGraph(flights, n, k);
        return dp(src, dst, k);
    }

    int dp(int src, int dst, int k){
        // min dist from src to dst in at most k is
        // min dist from src's neighbors to dist in at most k-1, + price from src to src neighbors
        
        // base case:
        if (src == dst){
            return 0; // reached destination, no cost
        }
        if (k < 0){
            return -1; // src != dst and we ran out of stops
        }
        if (memo[src][dst][k] != -2){
            return memo[src][dst][k];
        }
        int res = INT_MAX;
        for(auto& neighbor : graph[src]){
            int to = neighbor[0];
            int price = neighbor[1];
            int subprob = dp(to, dst, k-1);
            if(subprob == -1){
                continue;
            }
            res = min(res, subprob + price);
        }
        if (res == INT_MAX){
            return memo[src][dst][k] = -1;
        } else {
            return memo[src][dst][k] = res;
        }
    }

    void buildGraph(vector<vector<int>>& flights, int n, int k){
        graph.resize(n+1);
        for(auto& flight : flights){
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            graph[from].push_back({to, price});
        }

        memo.resize(n+1);
        for(auto& i : memo){
            i.resize(n+1);
            for(auto& j : i){
                j.resize(k+1, -2);
            }
        }
    }
};
// @lc code=end

