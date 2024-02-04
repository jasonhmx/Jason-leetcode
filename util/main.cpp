#include <iostream>
#include "sorting.h"

int main(){
    MergeSort ms;
    QuickSort qs;
    vector<int> test = {5,8,9,2,6,3,4,0,12,61};
    // ms.mergeSort(test);
    qs.quickSort(test);
    for (int i : test){
        cout << i << "\n";
    }
}