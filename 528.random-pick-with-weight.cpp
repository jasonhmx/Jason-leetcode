/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */

// @lc code=start

/*
Notes:
Use presum array to turn weighted random into uniform random
use binary search to find the desired index
*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> presum;
    vector<int> weights;

    Solution(vector<int>& w) {
        // construct presum vector
        weights = w;
        presum = vector<int>(weights.size()+1, 0);
        for (int i = 1; i < presum.size(); i++){
            presum[i] = presum[i-1] + weights[i-1];
        }
    }
    
    int pickIndex() {
        // generate random number within range of presum
        // find the closest presum element using binary search (right bound)
        // get corresponding index
        int upperbound = presum.back();
        int target = rand() % upperbound; // generates between 0 and upperbound - 1
        int left = 0, right = presum.size();
        while(left < right){
            int mid = left + (right - left) / 2;
            if (presum[mid] == target){
                left = mid + 1;
            } else if (presum[mid] < target){
                left = mid + 1;
            } else if (presum[mid] > target){
                right = mid;
            }
        }
        // eventually left and right would move to the right side of target
        // target is always within presum bounds, left and right will never be out of bounds
        // therefore left is the presum_index we want
        return left - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

