#include <bits/stdc++.h>
using namespace std;

int cx = 5, cy = 3, targetx = 5;
void applyRule(int x, int y, int& fx, int& fy, int num) {
    switch (num) {
        case 1:
            if (x < cx) fx = cx, fy = y;
            return;
        case 2:
            if (y < cy) fx = x, fy = cy;
            return;
        case 3:
            fx = x, fy = y;
            return;
        case 4:
            fx = x, fy = y;
            return;
        case 5:
            if (x > 0) fx = 0, fy = y;
            return;
        case 6:
            if (y > 0) fx = x, fy = 0;
            return;
        case 7:
            if (x < cx && y >= (cx - x)) fx = cx, fy = y - (cx - x);
            return;
        case 8:
            if (y < cy && x >= (cy - y)) fx = x - (cy - y), fy = cy;
            return;
        case 9:
            if (x < cx && y <= (cx - x)) fx = x + y, fy = 0;
            return;
        case 10:
            if (y < cy && x <= (cy - y)) fx = 0, fy = x + y;
            return;
    }
}
int main() {
    auto hue = [&](int x) { return abs(x - targetx); };

    cout << "Enter capacity of both jugs: ";
    cin >> cx >> cy;
    cout << "Enter target capacity in first jug: ";
    cin >> targetx;

    vector<string> rules = {
        "Fill the " + to_string(cx) + " gallon jug",
        "Fill the " + to_string(cy) + " gallon jug",
        "",
        "",
        "Empty the " + to_string(cx) + " gallon jug on the ground",
        "Empty the " + to_string(cy) + " gallon jug on the ground",
        "Pour water from " + to_string(cy) + " gallon jug into " +
            to_string(cx) + " gallon jug until " + to_string(cx) +
            " gallon jug is "
            "full",
        "Pour water from " + to_string(cx) + " gallon jug into " +
            to_string(cy) + " gallon jug until " + to_string(cy) +
            " gallon jug is "
            "full",
        "Pour all the water from " + to_string(cy) + " gallon jug into " +
            to_string(cx) + " gallon jug ",
        "Pour all the water from " + to_string(cx) + " gallon jug into " +
            to_string(cy) + " gallon jug "};
    int currentx = 0, currenty = 0;
    bool flag = true;
    while (1) {
        int cost = flag ? 1000 : hue(currentx);
        flag = false;
        int oldCost = cost, minCost = 1000;
        for (int i = 0; i < rules.size(); i++) {
            int nx, ny;
            applyRule(currentx, currenty, nx, ny, i + 1);
            int nc = hue(nx);
            minCost = min(minCost, nc);
            if (nc < cost) {
                cout << "Rule " << i + 1 << ": " << rules[i] << endl;
                printf("(%d, %d) -> (%d, %d)\n", currentx, currenty, nx, ny);
                printf("Old Cost: %d\t\tNew Cost: %d\n", cost, nc);
                cost = nc;
                currentx = nx, currenty = ny;
                break;
            };
        }
        if (currentx == targetx) {
            cout << "\n\nSolution Reached!!";
            break;
        }
        if (oldCost == cost) {
            cout << "\n\nAlgorithm Stuck...";
            break;
        }
    }
}

// 7 4 4
