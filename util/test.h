#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> memo;
    bool PredictTheWinner(vector<int>& nums) {
        memo.resize(nums.size());
        for(auto& i : memo){
            i.resize(nums.size(), -1);
        }
        int p1 = maxScore(nums, 0, nums.size()-1);
        int p2 = max(maxScore(nums, 1, nums.size()-1), maxScore(nums, 0, nums.size()-2));
        return p1>p2;
    }

    int maxScore(vector<int>& nums, int low, int high){
        // returns the max score you can get when it is your turn
        // and the array is bound between low and high
        if (low == high){
            return nums[low];
        }
        if (low > high){
            return 0;
        }
        if(memo[low][high] != -1){
            return memo[low][high];
        }
        int res = 0;
        // it is the max score of picking low vs picking high
        // 4 scenarios: 1 l 2 l, 1 l 2 r, 1 r 2 l, 1 r 2 r
        int p1lp2l = nums[low] + maxScore(nums, low+2, high);
        int p1lp2r = nums[low] + maxScore(nums, low+1, high-1);
        int minLeft = min(p1lp2l, p1lp2r); // p2 has the choice of making this worse for p1
        int p1rp2l = nums[high] + maxScore(nums, low+1, high-1);
        int p1rp2r = nums[high] + maxScore(nums, low, high-2);
        int minRight = min(p1rp2l, p1rp2r); // same here
        res = max(minLeft, minRight);
        memo[low][high] = res;
        return res;
    }
};