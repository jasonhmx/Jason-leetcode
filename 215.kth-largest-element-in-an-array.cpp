/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
/*
Notes:
Can do a straightforward sort, or use a priority queue
But can also do something like a binary search. Use what we did with partition in quicksort
Compare partition result with k, we then know where the element is.
*/
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int ascendingIdx = nums.size() - k;
        int lo = 0;
        int hi = nums.size() - 1;
        int res = 0;
        while (lo < hi){
            int mid = partition(nums, lo, hi);
            if (mid < ascendingIdx){ // we need to find in the upper half
                lo = mid + 1;
            } else if (mid > ascendingIdx){
                hi = mid - 1;
            } else {
                return nums[ascendingIdx];
            }
        }
        return nums[lo];
    }

    int partition(vector<int>& nums, int lo, int hi){
        // partition only called in sort(), which will have taken care of lo >= hi
        int pivot = nums[lo];
        int i = lo + 1;
        int j = hi;
        while(i <= j){
            while(i <= hi && nums[i] <= pivot){
                i++;
            }
            while(j >= lo && nums[j] > pivot){
                j--;
            }
            // now we should have nums[i] > pivot, nums[j] <= pivot
            if (i <= j){ // make sure i is still on the left
                swap(nums, i, j);
            }
        }
        // swap lo with j since j here definitely points to a number smaller than or equal to pivot
        swap(nums, lo, j);
        return j;
        // ensures lo to j are <= pivot, j+1 to hi are > pivot
    }

    void swap(vector<int>& nums, int left, int right){
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
    }

};
// @lc code=end

