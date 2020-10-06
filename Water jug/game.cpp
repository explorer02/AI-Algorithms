#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

#define vec vector<vector<char>>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

string mat_to_string(vec &mat) {
    string r = "";
    for (auto q : mat)
        for (auto c : q) r += c;
    return r;
}

int cost(vec &v1, vec &v2) {
    int c = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (v1[i][j] != v2[i][j] && v1[i][j] != '_') c++;
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
    vec init(3, vector<char>(3, 0));
    vec final(3, vector<char>(3, 0));
    cout << "Enter Initial State" << endl;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) cin >> init[i][j];
    cout << "\nEnter Final State" << endl;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) cin >> final[i][j];
    cout << endl;

    int i, j, moves = 0;
    for (int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++)
            if (init[x][y] == '_') i = x, j = y;

    if (cost(init, final) == 0) {
        cout << "Already in final state";
        return 0;
    }
    system("CLS");
    auto init_cpy = init;

    while (1) {
        vector<int> level_cst;
        int x = i, y = j;
        int cst = 1000;
        string move;
        int cc = cost(init, final);

        cout << "Initial State\t\tFinal State\n\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) cout << init_cpy[i][j] << " ";
            cout << "\t\t\t";
            for (int j = 0; j < 3; j++) cout << final[i][j] << " ";
            cout << "\n";
        }
        cout << endl;
        cout << "Total Moves: " << moves++ << endl << endl;

        cout << "Current State: \n\n";
        print_mat(init);

        if (cc == 0) {
            cout << "Final State Reached";
            return 0;
        }
        if (x > 0) {
            auto r = init;
            swap(r[x][y], r[x - 1][y]);
            int q = cost(r, final);
            if (q < cst) cst = q, move = "UP";
        }
        if (y > 0) {
            auto r = init;
            swap(r[x][y], r[x][y - 1]);
            int q = cost(r, final);
            if (q < cst) cst = q, move = "LEFT";
        }

        if (x < 2) {
            auto r = init;
            swap(r[x][y], r[x + 1][y]);
            int q = cost(r, final);
            if (q < cst) cst = q, move = "DOWN";
        }
        if (y < 2) {
            auto r = init;
            swap(r[x][y], r[x][y + 1]);
            int q = cost(r, final);
            if (q < cst) cst = q, move = "RIGHT";
        }

        cout << "\nCurrent Cost: " << cc << endl;
        cout << "Optimal Move: " << move << endl;

        cout << "Press any arrow key to move tile: ";
    input_key:
        while (!kbhit())
            ;
        char c = getch();
        bool flag = false;

        switch (c) {
            case KEY_UP:
                i--;
                break;
            case KEY_DOWN:
                i++;
                break;
            case KEY_LEFT:
                j--;
                break;
            case KEY_RIGHT:
                j++;
                break;
            default:
                flag = true;
                break;
        }
        if (flag || i < 0 || i > 2 || j < 0 || j > 2) {
            cout << "Invalid Move.... Try Again...\n";
            i = x, y = j;
            goto input_key;
        }
        swap(init[x][y], init[i][j]);
        system("CLS");
    }

    return 0;
}

// 2 8 3 1 6 4 7 _ 5
// 1 2 3 8 _ 4 7 6 5