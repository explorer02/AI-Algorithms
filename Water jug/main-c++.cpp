#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

#define vec vector<vector<char>>

string mat_to_string(vec &mat) {
    string r = "";
    for (auto q : mat)
        for (auto c : q) r += c;
    return r;
}
int cost(string s1, string s2) {
    int c = 0;
    for (int i = 0; i < 9; i++)
        if (s1[i] != s2[i] && s1[i] != '_') c++;
    return c;
}
void print_mat(vec &mat) {
    for (auto r : mat) {
        for (auto c : r) {
            cout << c << " ";
        }
        cout << endl;
    }
}
int main(int argc, char const *argv[]) {
    // vector<vector<char>> init = {{'2', '8', '3'}, {'1', '6', '4'}, {'7', '_',
    // '5'}}; auto init_cpy = init; vector<vector<char>> final = {{'1', '2',
    // '3'}, {'8', '_', '4'}, {'7', '6', '5'}};

    vec init(3, vector<char>(3, 0));
    vec final(3, vector<char>(3, 0));
    cout << "Enter Initial State" << endl;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) cin >> init[i][j];
    cout << "\nEnter Final State" << endl;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) cin >> final[i][j];
    cout << endl;
    auto init_cpy = init;
    unordered_set<string> visited;
    auto cur_str = mat_to_string(init);
    visited.insert(cur_str);
    auto final_str = mat_to_string(final);
    int steps = 0, lvl = 1, i = cur_str.find('_') / 3,
        j = cur_str.find('_') % 3;
    if (cur_str == final_str) {
        cout << "Already in final state";
        return 0;
    }
    cout << "Initial State: \n";
    print_mat(init_cpy);
    cout << "\nFinal State: \n";
    print_mat(final);
    cout << endl;

    while (cur_str != final_str) {
        cout << "Level: " << lvl++ << endl << endl;
        vector<vector<vector<char>>> level_mats;
        vector<int> level_cst;
        int currentCost = cost(cur_str, final_str);

        int x = i, y = j;
        int cst = 1000;
        if (x > 0) {
            swap(init[x][y], init[x - 1][y]);
            auto p = mat_to_string(init);
            if (visited.find(p) == visited.end()) {
                int c = cost(p, final_str);
                level_mats.push_back(init);
                level_cst.push_back(c);
                if (c < cst) {
                    i = x - 1, j = y, cst = c;
                }
            }
            swap(init[x][y], init[x - 1][y]);
            visited.insert(p);
        }
        if (y > 0) {
            swap(init[x][y], init[x][y - 1]);
            auto p = mat_to_string(init);
            if (visited.find(p) == visited.end()) {
                int c = cost(p, final_str);
                level_mats.push_back(init);
                level_cst.push_back(c);
                if (c < cst) {
                    i = x, j = y - 1, cst = c;
                }
            }
            swap(init[x][y], init[x][y - 1]);
            visited.insert(p);
        }
        if (x < 2) {
            swap(init[x][y], init[x + 1][y]);
            auto p = mat_to_string(init);
            if (visited.find(p) == visited.end()) {
                int c = cost(p, final_str);
                level_mats.push_back(init);
                level_cst.push_back(c);
                if (c < cst) {
                    i = x + 1, j = y, cst = c;
                }
            }
            swap(init[x][y], init[x + 1][y]);
            visited.insert(p);
        }
        if (y < 2) {
            swap(init[x][y], init[x][y + 1]);
            auto p = mat_to_string(init);
            if (visited.find(p) == visited.end()) {
                int c = cost(p, final_str);
                level_mats.push_back(init);
                level_cst.push_back(c);
                if (c < cst) {
                    i = x, j = y + 1, cst = c;
                }
            }
            swap(init[x][y], init[x][y + 1]);
            visited.insert(p);
        }
        if (i == x && j == y) {
            cout << "Same state reached!! No Solution!!";
            break;
        }
        if (lvl > 1000) {
            cout << "Can't be solved!!";
            break;
        }
        for (int i = 0; i < 3; i++) {
            for (int k = 0; k < level_mats.size(); k++) {
                for (int j = 0; j < 3; j++) {
                    cout << level_mats[k][i][j] << " ";
                }
                cout << "\t\t";
            }
            cout << endl;
        }
        cout << endl;
        for (int c : level_cst) cout << "Cost: " << c << "\t\t";
        cout << endl << endl;
        swap(init[x][y], init[i][j]);
        if (cst == currentCost) {
            cout << "Algorithm Stuck...!!";
            return 0;
        }
        cout << "Selected matrix: \n\n";
        print_mat(init);
        cout << "\nCost: " << cst << endl << endl;
        cout << "***************************************\n";
        cur_str = mat_to_string(init);
        if (cst == 0) {
            cout << "Final State Reached";
            return 0;
        }
    }

    return 0;
}

// 2 8 3 1 6 4 7 _ 5
// 2 _ 3 1 8 4 7 6 5
// 1 2 3 8 _ 4 7 6 5