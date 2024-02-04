#include <vector>
using namespace std;

/* given a vector of vectors of books, where 1st is weight 2nd value,
    and a capacity, return maximum value (and preferably the weights)
    of books that can be put in the knapsack

    can choose repetedly
*/

class KnapsackTD{
private:
    vector<vector<int>> memo;

public:
    int maxValue(vector<vector<int>>& books, int capacity){
        memo.resize(books.size());
        for(auto& i : memo){
            i.resize(capacity+1, -1);
        }
        // return dpBucket(books, 0, capacity);
        return dpBall(books, 0, capacity);
    }

    int dpBucket(vector<vector<int>>& books, int start, int capacity){
        // returns the max value at that capacity
        // value = max of (each book + capacity for rest of books)
        if (memo[start][capacity] != -1){
            return memo[start][capacity];
        }
        int maxVal = 0;
        for (int i = start; i < books.size(); i++){
            int weight = books[i][0];
            if (weight > capacity){
                continue;
            }
            int value = books[i][1];
            maxVal = max(maxVal, value + dpBucket(books, i, capacity-weight));
        }
        memo[start][capacity] = maxVal;
        // will be 0 if no book can fit in
        return maxVal;
    }

    int dpBall(vector<vector<int>>& books, int start, int capacity){
        // max is the bigger between choose this and not choose this
        if (start >= books.size()){ // ran out of books to choose from
            return 0;
        }
        if (memo[start][capacity] != -1){
            return memo[start][capacity];
        }
        int res = 0;
        int choose = 0;
        if(capacity >= books[start][0]){ // can choose
            choose = books[start][1] + dpBall(books, start, capacity-books[start][0]);
        }
        int dontChoose = dpBall(books, start+1, capacity);
        res = max(choose, dontChoose);
        memo[start][capacity] = res;
        return res;
    }
};


