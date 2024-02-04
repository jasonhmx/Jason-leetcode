/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start
/*
Notes:
Divide the nums into k buckets, there are two ways of thinking:
1. Look at each number in nums with index, try to put that indexed number into each bucket
2. Look at each number in the bucket, and see which numbers the bucket can take

The commented-out code below works but is too slow (exceeds time-limit). It uses the first approach.
The actual code is still too slow, uses the second approach, but should be much faster than the first approach.
*/
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    struct greater{
        template <typename T>
        bool operator()(T& a, T& b) {return a > b;}
    };

    bool backtrack(vector<int>& nums, int16_t used, int start, int k, int bucket, int target, unordered_map<int, bool> memo){
        if (k == 0){ // filled all buckets
            return true;
        }
        
        if (bucket == target){
            if(memo.count(used)){
                return memo[used];
            }
            bool res = backtrack(nums, used, 0, k-1, 0, target, memo);
            memo[used] = res; // memoise when filled a bucket
            return res;
        }

        for (int i = start; i < nums.size(); i++){
            if ((used >> i) & 1 == 1){
                continue;
            }

            if (bucket + nums[i] > target){
                continue;
            }

            used |= 1 << i; // set ith to 1
            bucket += nums[i];
            if (backtrack(nums, used, start + 1, k, bucket, target, memo)){
                return true;
            }
            bucket -= nums[i];
            used ^= 1 << i; // set ith to zero
        }
        return false; // no number works for current bucket

    }

    bool canPartitionKSubsets(vector<int>& nums, int k){
        if (k > nums.size()) return false;
        int sum = 0;
        for (auto i : nums) sum += i;
        if (sum % k != 0) {
            return false;
        }
        // sort(nums.begin(), nums.end(), greater());
        int used = 0;
        int target = sum / k;
        unordered_map<int, bool> memo;
        return backtrack(nums, used, 0, k, 0, target, memo);
    }
};
// @lc code=end
/*
public:
    struct greater{
        template <typename T>
        bool operator()(T& a, T& b) {return a > b;}
    };

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k > nums.size()){
            return false;
        }
        int sum = 0;
        for (auto i : nums) 
            {sum += i;}
        if (sum % k != 0){
            return false;
        }
        int target = sum / k;
        sort(nums.begin(), nums.end(), greater());
        vector<int> bucket(k, 0);
        return backtrack(nums, target, bucket, 0);
        
    }

    bool backtrack(vector<int>& nums, int target, vector<int>& bucket, int index){
        if (index == nums.size()){ // check for buckets at the end of loop
            for (int i = 0; i < bucket.size(); i++) {
                if (bucket[i] != target){
                    return false;
                }
                // successfully partitioned.
                return true;
            }
        }

        for (int i = 0; i < bucket.size(); i++){ // for the number at index, choose to put it into bucket[i]
            if (bucket[i] + nums[index] > target){
                continue; // can't put in i, try next bucket
            }

            bucket[i] += nums[index];
            if (backtrack(nums, target, bucket, index+1)) { // we checked that after traversing, partition is great
                return true;
            }
            bucket[i] -= nums[index];
        }

        // ends up here if number can't be put into any bucket
        