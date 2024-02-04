/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start

/*
Notes:
Topological sort. Same traversal as previous question, but add postorder log, which when 
reversed gives you the correct sort.

There are two parts to this postorder logging we can dig into:
1. why does it give correct sort for a well connected graph with a start
2. The nodes aren't all connected. Some are left out on their own; and how do you make sure the postorder log works
    when you are adding those in as well; and more importantly, how do you make sure it works when it is traversing
    a different part of a connected graph, which contains another part that has already been traversed?

The first question is answered by formal mathematical proof which we won't go into
The second is answered by thinking about the visited list. If we have already traversed part of the graph, that means
we have traversed all parts of the graph that could be visited from the start we picked.
A new start, if still in the same connected graph, must have not been visited, hence has to point TO what we already
traversed, and not from those. Hence the postorder traversal of these would come after the previous ones. Which maintains
the validity.
*/
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<bool> onPath(numCourses, false);
        vector<bool> visited(numCourses, false);
        vector<int> postorder; // used to store the postorder traversal

        for (auto i : prerequisites){
            // i is a pair of classes, first being the class, second being the prerequisite
            // prerequisite points to class
            graph[i[1]].push_back(i[0]);
        }

        for (int i = 0; i < numCourses; i++){
            if (hasLoop(graph, i, onPath, visited, postorder)){
                return {};
            }
        }

        reverse(postorder.begin(), postorder.end());
        return postorder;
    }

    bool hasLoop(vector<vector<int>>& graph, int node, vector<bool>& onPath, vector<bool>& visited, vector<int>& postorder){
        if (onPath[node]){
            return true;
        }

        if (!visited[node]){
            visited[node] = true;
            onPath[node] = true;
            for (auto i : graph[node]){
                if (hasLoop(graph, i, onPath, visited, postorder)){
                    return true;
                }
            }
            postorder.push_back(node); // million-dollar line
            onPath[node] = false;
        }
        return false;
    }
};
// @lc code=end

