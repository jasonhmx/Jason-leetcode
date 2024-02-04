/*
 * @lc app=leetcode id=1631 lang=cpp
 *
 * [1631] Path With Minimum Effort
 */

// @lc code=start

/*
Notes:
build graph, use dijkstra to find min-path. The cost function for dijkstra is no longer
the minimum path, but the minimum effort, so be careful there
Also be careful it mentions the absolute difference, not direct difference
*/
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
using Graph = vector<vector<vector<int>>>;

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        Graph graph = buildGraph(heights);
        vector<int> result = dijkstra(graph);
        return result[graph.size() - 1];
    }

private:
    // constexpr here to indicate compile-time evaluation of a constant
    // int array
    static constexpr int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    vector<int> dijkstra(Graph& graph){
        vector<int> efforts(graph.size(), INT_MAX);
        vector<bool> visited(graph.size(), false);
        efforts[0] = 0; // we always start from the top left corner
        priority_queue<State, vector<State>, decltype(comp)> pq(comp);
        pq.emplace(0, 0);
        while(!pq.empty()){
            State current = pq.top();
            pq.pop();
            if (visited[current.node]){
                continue;
            }
            if (current.node == graph.size() - 1){
                // early return if we got the last node
                return efforts;
            }
            visited[current.node] = true;
            for (auto neighbor : graph[current.node]){
                int adjNode = neighbor[0];
                int new_effort = max(efforts[current.node], neighbor[1]); // we only care about max diff
                if(visited[adjNode] || new_effort > efforts[adjNode]){
                    continue;
                }
                efforts[adjNode] = new_effort;
                pq.emplace(adjNode, new_effort);
            }
        }
        return efforts;
    }
    
    Graph buildGraph(vector<vector<int>>& heights){
        int height = heights.size();
        int width = heights[0].size();
        // init graph with number of nodes equal to size of the grid
        Graph graph(height * width);
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                // add the neighbor of each node to the graph
                // structured binding in range-for loop
                for (auto &[horizontal, vertical] : directions){
                    int x = i + horizontal;
                    int y = j + vertical;
                    if (isValid(x, y, height, width)){
                        graph[getIdx(i, j, width)].push_back({getIdx(x, y, width), abs(heights[x][y] - heights[i][j])});
                    }
                }
            }
        }
        return graph;
    }

    bool isValid(int x, int y, int height, int width){
        return(x >= 0 && x < height && y >= 0 && y < width);
    }

    int getIdx(int x, int y, int width){
        return x * width + y;
    }

    struct State{
        int node;
        int effortFromStart;
        State(int n, int dist) : node(n), effortFromStart(dist) {}
    };

    // declare comparison struct
    struct {
        bool operator()(State& a, State& b){
            return a.effortFromStart > b.effortFromStart;
        }
    } comp;


};
// @lc code=end

