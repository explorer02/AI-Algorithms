#include <bits/stdc++.h>
using namespace std;

int previous=-1;

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
    previous=start[xi][xj];
    swap(start[di][dj],start[xi][xj]);
    
    cout<<"Minimum cost is = "<<minCost<<endl;

}

void pattern() {
    cout<<endl;
    cout<<"*****************************************\n";
    cout<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int start[3][3]= { {2,8,3},
                       {1,6,4},
                       {7,-1,5}};
    int end[3][3]= { {1,2,3},
                       {8,-1,4},
                       {7,6,5}};
    
    cout<<endl<<"Starting Matrix :"<<endl;
    display(start);

    cout<<endl<<"Ending Matrix :"<<endl;
    display(end);

    cout<<"Cost is "<<calculate(start,end)<<endl;

    pattern();

    int steps=0;
    while(1){
        bool flag = check(start,end);

        if(flag){
            break;
        }
        cout<<"After iteration "<<steps+1<<endl;
        next_iteration(start,end);
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

