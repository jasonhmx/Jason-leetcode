class Solution {
public:
    vector<vector<int>> memo;
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0){
            return false;
        }
        int target = sum/2;
        memo.resize(nums.size());
        for (auto& i:memo){
            i.resize(target, -1);
        }
        return dp(nums, 0, 0, target);
    }

    bool dp(vector<int>& nums, int i, int sum, int& target){
        if (sum == target){
            return true;
        }
        if (sum > target){
            return false;
        }
        if (i >= nums.size()){
            return false;
        }
        if (memo[i][sum] != -1){
            return memo[i][sum];
        }

        bool res = dp(nums, i+1, sum+nums[i], target) || dp(nums, i+1, sum, target);
        memo[i][sum] = res;
        return res;
    }
};