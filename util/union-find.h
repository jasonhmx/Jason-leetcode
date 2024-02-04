#include <vector>
using namespace std;

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