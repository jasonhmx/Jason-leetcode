/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        auto rng = default_random_engine{};
        std::shuffle(nums.begin(), nums.end(), rng);
        QuickSort qs;
        qs.quickSort(nums);
        return(std::move(nums));
    }
    class QuickSort {
    public:
        void quickSort(vector<int>& nums){
            sort(nums, 0, nums.size()-1);
        }

    private:
        void sort(vector<int>& nums, int lo, int hi){
            if(lo >= hi){
                return;
            }
            int mid = partition(nums, lo, hi);
            sort(nums, lo, mid-1);
            sort(nums, mid+1, hi);
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
};
// @lc code=end

