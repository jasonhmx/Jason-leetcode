/*
 * @lc app=leetcode id=870 lang=cpp
 *
 * [870] Advantage Shuffle
 */

// @lc code=start

/*
Notes:
Use priority queue for nums2 so as to not disturb nums2's ordering
priority queue constructor takes type name, container for the queue, and comparison function
use lambda function for defining the comparison

Pay attention to priority queue comparison ordering. a is the element to be pushed,
so a < b sorts elements in descending order. Think about this.
*/

#include <vector>
#include <queue>
#include <utility>
using namespace std;

auto cmp = [](const pair<int, int> &a, const pair<int,int> &b){
    return a.second < b.second;
}; // function type so use auto to avoid confusion

class Solution {
public:

    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        // construct priority queue for nums2
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> maxpq(cmp);
        for (int i = 0; i < nums2.size(); i++){
            maxpq.emplace(i, nums2[i]);
        }
        // sort nums1
        sort(nums1.begin(), nums1.end());
        vector<int> result(nums1.size(), 0);
        int left = 0, right = nums1.size()-1;
        while(!maxpq.empty()){
            auto [i, maxval] = maxpq.top();
            maxpq.pop();
            if(nums1[right] > maxval){
                result[i] = nums1[right];
                right--;
            } else {
                result[i] = nums1[left];
                left++;
            }
        }
        return result;
    }
};
// @lc code=end

