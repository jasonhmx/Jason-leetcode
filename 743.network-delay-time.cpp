/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

// @lc code=start

/*
Notes:
Dijkstra. Min time for n nodes to receive signal is bound by the
min time for the farthest node to receive the signal
*/

#include <vector>
#include <queue>
#include <utility>
using namespace std;
class Solution {
public:
    typedef vector<vector<vector<int>>> Graph;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // construct an adjacency list for each indexed node
        // graph[i] contains all the adjacent nodes and edge weights from node [i]
        // index starts from 1, so need size of n+1, where graph[0] is empty
        Graph graph(n+1);
        // build the graph from edge list
        for (auto edge : times){
            graph[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<int> distances = dijkstra(graph, k);
        int res = 0;
        for (int i = 1; i < distances.size(); i++){
            if (distances[i] == INT_MAX){
                return -1;
            }
            if (res < distances[i]){
                res = distances[i];
            }
        }
        return res;
    }

    vector<int> dijkstra(Graph& graph, int start){
        // dijkstra that returns the min distance to every node
        vector<int> distances(graph.size(), INT_MAX);
        vector<bool> visited(graph.size(), false);
        distances[start] = 0;

        // priority queue of integer pairs of (node, dist_from_start)
        priority_queue<State, vector<State>, decltype(comp)> pq(comp);
        pq.emplace(start, 0);
        while (!pq.empty()){
            State curr = pq.top();
            pq.pop();
            if (visited[curr.node]){
                // if the min path has already been found, don't process further
                // but this do need to be after pop; otherwise the while loop never ends
                continue;
            }
            visited[curr.node] = true;
            for(auto neighbor : graph[curr.node]){
                int adj_node = neighbor[0];
                int weight = neighbor[1];
                int new_distance = distances[curr.node] + weight;
                // update the min distance from start for the neighbor
                // only if we haven't visited the node before, and the new_distance
                // is smaller
                if (!visited[adj_node] && distances[adj_node] > new_distance){
                    distances[adj_node] = new_distance;
                    pq.emplace(adj_node, new_distance);
                }
            }
        }
        return distances;
    }

private:
    struct State{
        int node;
        int dist_from_start;
        State(int n, int dist){
            node = n;
            dist_from_start = dist;
        }

        // no point implementing move assignments here, as
        // integers would just be copied over.
        // better use if there are dynamic memories to be moved
    };    
    
    struct { // make it anonymous for one-time use
        bool operator() (State& a, State& b){
            return a.dist_from_start > b.dist_from_start;
        }
    } comp;


};
// @lc code=end

