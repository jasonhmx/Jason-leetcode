/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    // comparison struct used for sorting, declares an object directly after definition
    struct ShorterEdge{
        bool operator() (vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        }
    } shorterEdge;

    class UF{
    private:
        int count;
        vector<int> parents;

    public:
        UF(int n) : parents(n, 0){
            for (int i = 0; i < n; i++){
                // initially all point to self
                parents[i] = i;
            }
            count = n;
        }

        void make_union(int p, int q_master) {
            int rootP = find_and_flatten(p);
            int rootQ = find_and_flatten(q_master);
            if (rootP != rootQ){
                parents[rootP] = rootQ;
            }
            count--;
        }

        bool connected(int p, int q) {
            return (find_and_flatten(p) == find_and_flatten(q));
        }

        int find_and_flatten(int x) {
            if (parents[x] == x){
                return x;
            }
            parents[x] = find_and_flatten(parents[x]);
            return parents[x];
        }

        int get_count() {
            return count;
        }
    };
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> graph;
        // iterate through points and add each edge to graph
        for (int i = 0; i < points.size(); i++){
            // second in the pair goes from i + 1 to end
            for (int j = i + 1; j < points.size(); j++){
                graph.push_back({i, j, cost(i, j, points)});
            }
        }

        // sort the edges so Kruskal's algo can be used
        sort(graph.begin(), graph.end(), shorterEdge);

        // Kruskal's algorithm:
            // Union find class implementation, initialise
            // iterate through sorted edges, check for connectedness
            // if not connected, connect
            // return at the end, count should be == 1 (if not the graph isn't connected)
            // increment the cost along the way
        UF unionFind(points.size());
        int res = 0;
        for (auto edge : graph){
            if (!unionFind.connected(edge[0], edge[1])){
                unionFind.make_union(edge[0], edge[1]);
                res += edge[2];
            }
        }
        return res;
    }

    int cost(int i, int j, vector<vector<int>>& points){
        return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
    }
};
// @lc code=end

