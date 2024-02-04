class Solution {
public:
    vector<vector<int>> memo;
    bool isMatch(string s, string p) {
        memo.resize(s.size());
        for(auto& i : memo){
            i.resize(p.size(), -1);
        }
        return dp(s, p, 0, 0);
    }

    bool dp(string& s, string& p, int i, int j){
        // i and j indexes into s and p
        // if both at end, return true
        if(i == s.size() && j == p.size()){
            return true;
        }
        if(j == p.size() && i < s.size()){
            return false;
        }
        if(i == s.size() && j < p.size()){
            // what's left of p can still match empty string
            if ((p.size() - j) % 2 != 0){
                return false;
            }
            int remain = j+1;
            while (remain < p.size()){
                if(p[remain] != '*'){
                    return false;
                }
                remain += 2;
            }
            return true;
        }
        if (memo[i][j] != -1){
            return memo[i][j];
        }

        if (s[i] == p[j] || p[j] == '.'){
            // can match current letter
            if (j < p.size()-1 && p[j+1] == '*'){
                // keep matching current, or don't match at all
                return memo[i][j] = dp(s, p, i+1, j) || dp(s, p, i, j+2);
            } else {
                return memo[i][j] = dp(s, p, i+1, j+1);
            }
        } else {
            if (j < p.size()-1 && p[j+1] == '*'){
                // don't match current
                return memo[i][j] = dp(s, p, i, j+2);
            } else {
                return memo[i][j] = false;
            }
        }
    }
};