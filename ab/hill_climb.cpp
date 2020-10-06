#include <bits/stdc++.h>
using namespace std;

int previous=-1;
int currCost;

unordered_map<string,bool>vis;

void insertMap(int arr[3][3]){
    string temp="";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            temp+=to_string(arr[i][j]);
        }
    }
    vis[temp] = true;
}

bool checkMap(int arr[3][3]){
    string temp="";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            temp+=to_string(arr[i][j]);
        }
    }
    return vis[temp];
}

bool check(int start[3][3], int end[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(start[i][j]!=end[i][j]){
                return false;
            }
        }
        }
    return true;
}

int calculate(int start[3][3], int end[3][3]){
    int d=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(start[i][j]!=-1 && start[i][j]!=end[i][j]){
                d++;
            }
        }
        }
    return d;
}
void display(int start[3][3]){
    cout<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<start[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void next_iteration(int start[3][3], int end[3][3]){
  
    int di=-1,dj=-1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(start[i][j]==-1){
                di=i;dj=j;
                break;
            }
        }
        if(di!=-1) break;
    }
    int xi=-1,xj=-1,minCost=INT_MAX;
    if(di-1>=0){
        if(start[di-1][dj]!=previous){
            swap(start[di][dj],start[di-1][dj]);
            int cost = calculate(start,end);
            display(start);
            cout<<cost<<endl;
            swap(start[di][dj],start[di-1][dj]);
            if(cost<minCost){
                minCost=cost;
                xi=di-1;
                xj=dj;
            }
        }
    }
    
    if(minCost<currCost){
        previous=start[xi][xj];
        swap(start[di][dj],start[xi][xj]);
        currCost = minCost;
        cout<<"Minimum cost is = "<<minCost<<endl;
        return;
    }

    if(di+1<3){
        if(start[di-1][dj]!=previous){
            swap(start[di][dj],start[di+1][dj]);
            int cost = calculate(start,end);
            display(start);
            cout<<cost<<endl;
            swap(start[di][dj],start[di+1][dj]);
            if(cost<minCost){
                minCost=cost;
                xi=di+1;
                xj=dj;
            }
        }
    }

    if(minCost<currCost){
        previous=start[xi][xj];
        swap(start[di][dj],start[xi][xj]);
        currCost = minCost;
        cout<<"Minimum cost is = "<<minCost<<endl;
        return;
    }

    if(dj-1>=0){
        if(start[di][dj-1]!=previous){
            swap(start[di][dj],start[di][dj-1]);
            int cost = calculate(start,end);
            display(start);
            cout<<cost<<endl;
            swap(start[di][dj],start[di][dj-1]);
            if(cost<minCost){
                minCost=cost;
                xi=di;
                xj=dj-1;
            }
        }
    }

    if(minCost<currCost){
        previous=start[xi][xj];
        swap(start[di][dj],start[xi][xj]);
        currCost = minCost;
        cout<<"Minimum cost is = "<<minCost<<endl;
        return;
    }

    if(dj+1<3){
        if(start[di][dj+1]!=previous){
            swap(start[di][dj],start[di][dj+1]);
            int cost = calculate(start,end);
            display(start);
            cout<<cost<<endl;
            swap(start[di][dj],start[di][dj+1]);
            if(cost<minCost){
                minCost=cost;
                xi=di;
                xj=dj+1;
            }
        }
    }
    if(xi==-1){
        previous=-1;
        return;
    }

    if(minCost<currCost){
        previous=start[xi][xj];
        swap(start[di][dj],start[xi][xj]);
        currCost = minCost;
        cout<<"Minimum cost is = "<<minCost<<endl;
        return;
    }
    currCost = INT_MAX;

}

void pattern() {
    cout<<endl;
    cout<<"*****************************************\n";
    cout<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int start[3][3]= { {1,2,3},
                       {-1,4,6},
                       {7,5,8}};
    int end[3][3]= { {1,2,3},
                       {4,5,6},
                       {7,-1,8}};
    
    cout<<endl<<"Starting Matrix :"<<endl;
    display(start);

    cout<<endl<<"Ending Matrix :"<<endl;
    display(end);

    cout<<"Heuristic is "<<calculate(start,end)<<endl;

    currCost = calculate(start,end);

    pattern();

    int steps=0;
    while(1){
        bool flag = check(start,end);

        if(flag){
            break;
        }
        cout<<"After iteration "<<steps+1<<endl;
        next_iteration(start,end);

        if(currCost == INT_MAX){
            cout<<"No further state possible\n";
            cout<<"Exiting\n";
            return 0;
        }
        if(previous==-1){
            steps=-1;
            break;
        }
        
        steps++;

        cout<<endl;
        for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<start[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    pattern();

    }   
    if(previous==-1) cout<<"Not Possible\n";      
return 0;    
}

