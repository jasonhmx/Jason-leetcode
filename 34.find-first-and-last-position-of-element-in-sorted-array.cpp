/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start

/*
Notes: 
Binary search.
Careful with edge cases, note when existing the while loop, where the left and right pointers end up.
There may be out-of-bounds access, which needs taken into account
*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()){
            return {-1, -1};
        }
        int left = 0, right = nums.size(); // left closed right open
        vector<int> result(2, 0);
        
        // search left bound
        while (left < right){
            int mid = left + (right - left)/2;
            if (nums[mid] == target){
                right = mid;
            } else if (nums[mid] > target){
                right = mid;
            } else if (nums[mid] < target){
                left = mid+1;
            }
        }
        if (left == nums.size()){ // check bounds
            result[0] = -1;
        }
        else if (nums[left] == target){
            result[0] = left;
        } else {
            result[0] = -1;
        }

        left = 0;
        right = nums.size();
        //search right bound
        while (left < right){
            int mid = left + (right - left)/2;
            if (nums[mid] == target){
                left = mid + 1;
            } else if (nums[mid] > target){
                right = mid;
            } else if (nums[mid] < target){
                left = mid+1;
            }
        }
        if (left == 0){ // check bounds
            result[1] = -1;
        }
         else if (nums[left - 1] == target){
            result[1] = left - 1;
        } else{
            result[1] = -1;
        }
        return result;
    }
};
// @lc code=end

