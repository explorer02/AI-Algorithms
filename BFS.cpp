#include<bits/stdc++.h>
using namespace std;

unordered_map<char, vector<pair<char, int>>>graph;
unordered_map<char, int>straight_dist;
char start, goal;
queue<char>path;
unordered_set<char>closed;
priority_queue<pair<int, char>>open;
bool found = false;

int distance(char a, char b){
    for(auto p: graph[a]){
        if(p.first==b){
            return p.second;
        }
    }
    return -1;
}

void optimalCost(int &ans, char currVertex, vector<char> &optimalPath, vector<char> &currPath, int currAns=0){
    if(currVertex==goal){
        if(currAns < ans){
            ans = currAns;
            optimalPath = currPath;
        }
        return;
    }
    for(auto p: graph[currVertex]){
        // if not repeated
        if(find(currPath.begin(), currPath.end(), p.first) == currPath.end()){
            currPath.push_back(p.first);
            optimalCost(ans, p.first, optimalPath, currPath, currAns + p.second);
            currPath.pop_back();
        }
    }
}

int main(){
    int n;
    cout<<"Enter Number of Vertices: \n";
    cin>>n;
    int e;
    cout<<"Enter Number of Edges: \n";
    cin>>e;
    for(int i=0; i<e; i++){
        char x, y;
        int z;
        cin>>x>>y>>z;
        graph[x].push_back({y, z});
        graph[y].push_back({x, z});
    }
    cout<<"Enter starting vertex: ";
    cin>>start;
    cout<<"Enter goal vertex: ";
    cin>>goal;
    cout<<"Enter Straight Line Distances to goal vertex: \n";
    for(int i=1; i<n; i++){
        int x;
        char ch;
        cin>>ch>>x;
        straight_dist[ch] = x;
    }
    straight_dist[goal] = 0;
    // Enter starting vertex into open state
    open.push({-1*straight_dist[start], start});

    while(!open.empty()){
        auto currVert = open.top();
        open.pop();
        closed.insert(currVert.second);
        path.push(currVert.second);

        // if goal state reached
        if(currVert.second == goal){
            found = true;
            break;
        }

        // Exploring its children/neighbors
        for(auto p: graph[currVert.second]){
                // If unvisited
            if(closed.count(p.first)==0){
                open.push({-1*straight_dist[p.first], p.first});
            }
        }
    }

    if(!found){
        cout<<"Path doesn't exist \n";
    }else{
        cout<<"\n\nPath Obtained: \n";
        char ch='$';
        int pathLength = 0;
        while(!path.empty()){
            cout<<path.front()<<" ";
            if(ch!='$'){
                pathLength += distance(ch, path.front());
            }
            ch = path.front();
            path.pop();
        }
        cout<<"\n";
        cout<<"Best First Search Cost: "<<pathLength<<"\n";
        int ans = INT_MAX;
        vector<char>optimalPath, currPath;
        currPath.push_back(start);
        optimalCost(ans, start, optimalPath, currPath);
        cout<<"Most Optimal Cost: "<<ans<<"\n";
        cout<<"Optimal Path: ";
        for(auto ch : optimalPath){
            cout<<ch<<" ";
        }
        cout<<"\n";
    }
    return 0;
}



8
10
a b 11
a d 7
a c 14
b e 15
c e 8
c f 10
d f 25
e h 9
f g 20
h g 10
a
g
a 40
b 32
c 25
d 35
e 19
f 17
h 10