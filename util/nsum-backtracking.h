#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void nsum(vector<int>& nums, int target, int n, int start, unordered_map<int, vector<int>>& int2index, unordered_set<int>& visited, vector<vector<int>>& res, vector<int>& track){
    // needs to return all combinations, no repititions. Use a hashmap to store number to a vector of indices
    // only use the index if the previous index has been used
    
    // base case:
/*         if (n == 1){
        // find target's index in the unordered map
        if(int2index.count(target)){
            for (auto i : int2index[target]){
                if (!visited.count(i)){
                    track.push_back(target);
                    res.push_back(track);
                    track.pop_back();
                }
            }
        }
        return;
    } */

    if (n == 0){
        if (target == 0){
            res.push_back(track);
        }
        return;
    }
    
    for (int i = start; i < nums.size(); i++){
        if (visited.count(i)){ // if already used
            continue;
        }
        
        // check if the duplicate number prior to current one has been used
        if (duplicateCombo(i, nums, int2index, visited)){
            continue;
        }

        // now we can actually use the number:
        visited.insert(i);
        track.push_back(nums[i]);
        nsum(nums, target - nums[i], n-1, i, int2index, visited, res, track);
        visited.erase(i);
        track.pop_back();
    }
}

bool duplicateCombo(int index, vector<int>& nums, unordered_map<int, vector<int>>& int2index, unordered_set<int>& visited){
    if (int2index.count(nums[index])){ // see if this number is in the map
        // make sure previous indices has been used
        for (int k : int2index[nums[index]]){
            if (k == index){ // exit the loop once it reaches i
                break;
            }
            if (!visited.count(k)){
                return true;
            }
        }
    }
    return false;
}