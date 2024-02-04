/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1){
            return memo[n];
        } 
        for (int i = 2; i <= n; i++){
            if (i % 2 == 0){
                memo[0] = memo[0] + memo[1];
            } else {
                memo[1] = memo[0] + memo[1];
            }
        }
        return n % 2 == 0 ? memo[0] : memo[1];
    }

private:
    int memo[2] = {0, 1};
};
// @lc code=end

