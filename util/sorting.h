#include <vector>
using namespace std;

class MergeSort{
private:
    vector<int> temp;

    void sort(vector<int>& nums, int lo, int hi){
        if (lo >= hi){
            return;
        }
        int mid = (lo + hi) / 2;
        // or int mid = lo + (hi-lo) / 2; if worried about addition overflow
        sort(nums, lo, mid);
        sort(nums, mid+1, hi);
        merge(nums, lo, mid, hi);
    }

    void merge(vector<int>& nums, int lo, int mid, int hi){
        if (lo >= hi){
            return;
        }
        // copy contents from nums to temp, then write merged result into nums
        temp = nums;
        // note that lower half goes from lo to mid, higher goes from mid + 1 to hi
        int i = lo; 
        int j = mid+1;
        for (int p = lo; p <= hi; p++){
            // if one of them out of bounds already, write the other one only
            if (i == mid+1){
                nums[p] = temp[j++];
            } else if (j == hi+1){
                nums[p] = temp[i++];
            } else if (temp[i] < temp[j]){ // if both in bounds, take smaller one
                nums[p] = temp[i++];
            } else {
                nums[p] = temp[j++];
            }
        }
    }

public:
    void mergeSort(vector<int>& nums){
        temp.resize(nums.size(), 0);
        sort(nums, 0, nums.size()-1);
    }
};


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
