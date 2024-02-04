/*
 * @lc app=leetcode id=887 lang=cpp
 *
 * [887] Super Egg Drop
 */

// @lc code=start

/*
Notes:
kind of a binary search with attempts. If land on right, we lose egg;
if land on left, we are safe and can retain egg

What we do is, we drop egg in the middle. If egg doesn't break, we have k eggs
to figure out f in the right half of n. If egg breaks, we have k-1 eggs to figure
out f in the left half of n.

BUT this also doesn't give you the optimal solution. Forget binary search. just try
throwing egg on every floor and get the minimum solution

BUT we can do binary search on the result to only search in the smaller region
I don't quite understand how the binary search step works though....
*/
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> memo;
public:
    int superEggDrop(int k, int n) {
        memo.resize(k+1);
        for(auto& i : memo){
            i.resize(n+1, -1);
        }
        // when k == 1, all n would take n tries
        for(int i = 0; i <= n; i++){ // n could be zero, in which case we need 0 tries
            memo[1][i] = i;
        }

        // when n == 1, all we need is 1 move
        for(int i = 0; i <= k; i++){
            memo[i][1] = 1;
        }

        return dp(k, n);
    }

    int dp(int k, int n){
        if (k == 1){
            return n;
        }
        if (n == 1 || n == 0){
            return n;
        }
        if (memo[k][n] != -1){ // k == 1 cases return here
            return memo[k][n];
        }
        int res = 99999;
        int temp = res;
        int l = 1, h = n; // left right both closed
        int mid;
        while(l <= h){ // binary search
            mid = (l+h)/2;
            int left = dp(k-1, mid-1);
            int right = dp(k, n - mid); 
            // here, k ad k-1 doesn't change, only mid-1 and n-mid changes
            // we know that left is increasing with mid; right is decreasing with mid.
            // need to find when left == right. Therefore if right is greater, we move more to the right
            temp = 1 + max(left, right);

            // l and h has to be updated to be different from mid otherwise loop doesn't exit
            if (left < right){
                l = mid+1;
            } else{
                h = mid-1;
            }
            res = min(res, temp);
        }
        
        memo[k][n] = res;
        return res;
    }
};
// @lc code=end

