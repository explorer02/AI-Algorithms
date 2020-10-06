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

int main() {
    int n = 4;
    vector<vector<int>> dist = {
        {0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};

    vector<int> res;
    int cost = 1e7;

    for (int i = 0; i < n; i++) {
        vector<int> cur = {i};
        set<int> s;
        s.insert(i);
        while (cur.size() != n) {
            int le = cur[cur.size() - 1];
            int minD = 1000;
            int ind = 0;
            for (int w = 0; w < n; w++) {
                if (s.find(w) == s.end()) {
                    if (dist[le][w] < minD) {
                        minD = dist[le][w];
                        ind = w;
                    }
                }
            }
            cur.push_back(ind);
            s.insert(ind);
        }
        int c = calculateCost(cur, dist);
        if (c < cost) {
            cost = c;
            res = cur;
        }
    }
    cout << "\n\nSolution found: \n";
    cout << "Cost: " << cost << endl << endl << "Path: ";
    for (int x : res) cout << x + 1 << " ";
    cout << res[0] + 1 << endl;
}