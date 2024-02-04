/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start

/*
monotonic stack approach
*/
#include <vector>
#include <stack>
#include <utility>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> s; // stack that tracks the temp and its idx
        vector<int> res(temperatures.size());
        for (int i = temperatures.size()-1; i>=0; i--){
            while (!s.empty() && s.top().first <= temperatures[i]){
                s.pop();
            }
            res[i] = s.empty() ? 0 : s.top().second - i;
            s.push({temperatures[i], i});
        }
        return res;
    }
};
// @lc code=end

