#include <bits/stdc++.h>
using namespace std;

int capacity_x, capacity_y, target_x, target_y;

struct state {
    int x, y;
    bool operator < (const state& that) const {
        if (x != that.x) return x < that.x;
        return y < that.y;
    }
};


void bfs(state start, stack <pair <state, int> >& path)   {
    queue <state> q;
    state goal = (state) {-1, -1};
    map <state, pair <state, int> > parentOf;

    q.push(start);
    parentOf[start] = make_pair(start, 0);

    while(!q.empty()){
        state top = q.front();
        q.pop();
        if (top.x == target_x && top.y == target_y) {
            goal = top;
            break;
        }

        if (top.x < capacity_x)  {
            state child = (state) {capacity_x, top.y};
            if (parentOf.find(child) == parentOf.end()) {
                q.push(child);
                parentOf[child] = make_pair(top, 1);
            }
        }
        if (top.y < capacity_y)  {
            state child = (state) {top.x, capacity_y};
            if (parentOf.find(child) == parentOf.end()) {
                q.push(child);
                parentOf[child] = make_pair(top, 2);
            }
        }
        if (top.x > 0)  {
            state child = (state) {0, top.y};
            if (parentOf.find(child) == parentOf.end()) {
                q.push(child);
                parentOf[child] = make_pair(top, 3);
            }
        }
        if (top.y > 0)  {
            state child = (state) {top.x, 0};
            if (parentOf.find(child) == parentOf.end()) {
                q.push(child);
                parentOf[child] = make_pair(top, 4);
            }
        }

        if (top.y > 0)  {
            state child = (state) {min(top.x + top.y, capacity_x), max(0, top.x + top.y - capacity_x)};
            if (parentOf.find(child) == parentOf.end()) {
                q.push(child);
                parentOf[child] = make_pair(top, 5);
            }
        }
        if (top.x > 0)  {
            state child = (state) {max(0, top.x + top.y - capacity_y), min(top.x + top.y, capacity_y)};
            if (parentOf.find(child) == parentOf.end()) {
                q.push(child);
                parentOf[child] = make_pair(top, 6);
            }
        }
    }

    if (goal.x == -1 || goal.y == -1)
        return;

    path.push(make_pair(goal, 0));

    while (parentOf[path.top().first].second != 0)
        path.push(parentOf[path.top().first]);
}

int main()  {
    stack <pair <state, int> > path;

    cout<<"Enter the capacities of the two jugs : ";
    cin>>capacity_x>>capacity_y;
    cout<<"Enter the target amount : ";
    cin>>target_x>>target_y;

    bfs((state) {0, 0}, path);
    if (path.empty()){
        cout<<"\nTarget cannot be reached.\n";
    }
    else{
        cout<<"\nNumber of moves to reach the target : "<<path.size()<<"\nOne path to the target is as follows :\n";
        while(!path.empty()){
            state top = path.top().first;
            int rule = path.top().second;
            path.pop();

            switch (rule){
                case 0: printf("State : (%d, %d)\n#\n", top.x, top.y);
                        break;
                case 1: printf("State : (%d, %d)\nProduction Rule %d : Fill the first jug\n", top.x, top.y,rule);
                        break;
                case 2: printf("State : (%d, %d)\nProduction Rule %d : Fill the second jug\n", top.x, top.y,rule);
                        break;
                case 3: printf("State : (%d, %d)\nProduction Rule %d : Empty the first jug\n", top.x, top.y,rule);
                        break;
                case 4: printf("State : (%d, %d)\nProduction Rule %d : Empty the second jug\n", top.x, top.y,rule);
                        break;
                case 5: printf("State : (%d, %d)\nProduction Rule %d : Pour from second jug into first jug\n", top.x, top.y,rule);
                        break;
                case 6: printf("State : (%d, %d)\nProduction Rule %d : Pour from first jug into second jug\n", top.x, top.y,rule);
                        break;
            }
        }
    }

    return 0;
}
