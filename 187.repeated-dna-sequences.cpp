/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */

// @lc code=start

/*
Notes: sliding window + hash; basis of Robin-Karp
*/
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // first, create a vector of integers and convert each char into 0, 1, 2 or 3
        vector<int> nums(s.size());
        // create an unordered set to store the hashed integers
        unordered_set<int> seen;
        // create an unordered set of strings to store the result
        unordered_set<string> result;
        for(int i = 0; i < s.size(); i++){
            switch(s[i]){
                case 'A':
                    nums[i] = 0;
                    break;
                case 'C' :
                    nums[i] = 1;
                    break;
                case 'G':
                    nums[i] = 2;
                    break;
                case 'T':
                    nums[i] = 3;
                    break;
            }
        }
        
        // define the parameters used in hashing the substring into an integer
        int R = 4; // quaternary system
        int L = 10; // length of substring of interest
        int RL = pow(R, L - 1);

        // adding digit to tail: num * R + dig
        // removing digit from head: num - dig * RL
        int left = 0, right = 0;
        int num = 0;
        while(right < s.size()){
            num = num * R + nums[right];
            right++;
            if (right - left == L){
                if(seen.count(num)){
                    // if repeat, extract the substring and insert into result
                    result.insert(s.substr(left, right - left));
                }
                else {
                    seen.insert(num);
                }
                // shrink window here
                num = num - nums[left] * RL;
                left++;
            }
        }
        return vector<string>(result.begin(), result.end());
    }
};
// @lc code=end

