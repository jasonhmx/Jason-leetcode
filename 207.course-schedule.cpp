/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start

/*
Notes:
Construct a directed graph, check for loop
Can use a adjacency matrix (faster) or adjacency list (easier to implement)
vector of vectors or list of lists?
*/
#include <vector>
#include <list>
#include <unordered_set> // can use this or a simple vector
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // construct a vector of vectors for the adjacency list
        // graph[i] contains the accessible neighbors from class i
        vector<vector<int>> graph(numCourses);
        vector<bool> onPath(numCourses, false);
        vector<bool> visited(numCourses, false);
        for (auto i : prerequisites){
            // i is a pair of classes, first being the class, second being the prerequisite
            // prerequisite points to class
            graph[i[1]].push_back(i[0]);
        }

        for (int i = 0; i < numCourses; i++){
            if (hasLoop(graph, i, onPath, visited)){
                return false;
            }
        }
        return true;
    }

    bool hasLoop(vector<vector<int>>& graph, int node, vector<bool>& onPath, vector<bool>& visited){
        if (onPath[node]){
            return true;
        }

        if (!visited[node]){// make sure to visit nodes previously unvisited
            // log to path
            onPath[node] = true;
            visited[node] = true;
            for (auto i : graph[node]){
                if (hasLoop(graph, i, onPath, visited)){
                    return true;
                }
            }
            onPath[node] = false;
        }
        return false;
    }

};
// @lc code=end

