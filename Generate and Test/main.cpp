#include <bits/stdc++.h>
using namespace std;
int calculateCost(vector<int>& v, vector<vector<int>>& dist) {
    int c = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        c += dist[i][i + 1];
    }
    c += dist[v[v.size() - 1]][v[0]];
    return c;
}
int fact(int n) { return n == 1 ? 1 : (fact(n - 1) * n); }
int main() {
    int n = 4;
    vector<vector<int>> dist = {
        {0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
    int test = n > 10 ? 1000 : min(fact(n), 1000);
    set<vector<int>> set;
    vector<int> res, cur;
    int cost = 1e7;
    for (int i = 0; i < n; i++) cur.push_back(i);
    while (test > 0) {
        int c = calculateCost(cur, dist);
        if (c < cost) {
            cost = c;
            res = cur;
        }
        set.insert(cur);
        test--;
        while (test && set.find(cur) != set.end())
            random_shuffle(cur.begin(), cur.end());
    }
    cout << "\n\nSolution found: \n";
    cout << "Cost: " << cost << endl << endl << "Path: ";
    for (int x : res) cout << x + 1 << " ";
    cout << res[0] + 1 << endl;
}