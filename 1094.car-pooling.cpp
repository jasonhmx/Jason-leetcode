/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> numPassengers(1001, 0);
        vector<int> difference(1001, 0);
        // create difference vector
        for(int i = 0; i < trips.size(); i++)
        {
            if (trips[i][0] > capacity){
                return false;
            }
            difference[trips[i][1]] += trips[i][0];
            difference[trips[i][2]] -= trips[i][0];
        }
        // calculate numPassengers from difference
        numPassengers[0] = difference[0];
        for(int i=1; i < 1001; i++)
        {
            numPassengers[i] = numPassengers[i-1] + difference[i];
            if (numPassengers[i] > capacity){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

