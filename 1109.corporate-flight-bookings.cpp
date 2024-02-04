/*
 * @lc app=leetcode id=1109 lang=cpp
 *
 * [1109] Corporate Flight Bookings
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> answer(n, 0);
        vector<int> difference(n, 0);
        for(int i = 0; i < bookings.size(); i++)
        {
            difference[bookings[i][0] - 1] += bookings[i][2];
            if(bookings[i][1] < n){
                difference[bookings[i][1]] -= bookings[i][2];
            }
        }
        answer[0] = difference[0];
        for(int i = 1; i < n; i++)
        {
            answer[i] = answer[i-1] + difference[i];
        }
        return answer;
    }
};
// @lc code=end

