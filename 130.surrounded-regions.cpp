/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start

/*
Notes:
DFS, similar to island problem
or, can use union-find. 
*/
#include <vector>
using namespace std;


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int m = board.size();
        int n = board[0].size();

        UF uf(m*n + 1);
        int dummy = m*n;

        for (int i = 0; i < m; i++){
            if(board[i][0] == 'O'){
                uf.make_union(i*n, dummy);
            }
            if (board[i][n-1] == 'O'){
                uf.make_union(i*n+n-1, dummy);
            }
        }

        for (int j = 0; j < n; j++) {
        if (board[0][j] == 'O') {
            uf.make_union(j, dummy);
        }
        if (board[m - 1][j] == 'O') {
            uf.make_union(n * (m - 1) + j, dummy);
        }
        }

        int directions[4][2] = {{1,0}, {0,1}, {0,-1}, {-1,0}};
        for (int i = 1; i < m-1; i++){
            for (int j = 1; j < n-1; j++){
                if(board[i][j] == 'O'){
                    for (auto k : directions){
                        int row = i+k[0];
                        int col = j+k[1];
                        if (board[row][col] == 'O'){
                            uf.make_union(i*n+j, row*n+col);
                        }
                    }
                }
            } 
        }

        for (int i = 1; i < m-1; i++){
            for (int j = 1; j < n-1; j++){
                if(!uf.connected((i*n + j), dummy)){
                    board[i][j] = 'X';
                }       
            }
        }
    }
    
    class UF{
    private:
        int count;
        vector<int> parents;

    public:
        UF(int n) : parents(n, 0){
            for (int i = 0; i < n; i++){
                // initially all point to self
                parents[i] = i;
            }
            count = n;
        }

        void make_union(int p, int q_master) {
            int rootP = find_and_flatten(p);
            int rootQ = find_and_flatten(q_master);
            if (rootP != rootQ){
                parents[rootP] = rootQ;
            }
            count--;
        }

        bool connected(int p, int q) {
            return (find_and_flatten(p) == find_and_flatten(q));
        }

        int find_and_flatten(int x) {
            if (parents[x] == x){
                return x;
            }
            parents[x] = find_and_flatten(parents[x]);
            return parents[x];
        }

        int get_count() {
            return count;
        }
    };
};
// @lc code=end

