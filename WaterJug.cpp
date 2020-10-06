#include<iostream>
#include<unordered_set>
#include<string>
#include<cstring>
using namespace std;

int xinit=0, yinit=0, xf, yf, capX, capY;
unordered_set<string> done;

string to_string(int a, int b)
{
    string str="";
    str.push_back(char(a+'0'));
    str.push_back(' ');
    str.push_back(char(b+'0'));
    return str;
}

bool heuristics(int a, int b, int c, int d)
{
    if(a==-1){
        return true;
    }
    return (abs(capX-a)+abs(capY-b)) > (abs(capX-c)+abs(capY-d));
}

int main()
{
    //cout<<"Enter Jugs Capacity: \n";
    //cin>>capX>>capY;
    capX = 4,capY = 3;
    //cout<<"Enter Final State: \n";
    //cin>>xf>>yf;
    xf = 0;
    yf = 2;
    int steps=0;
    while(xf != xinit || yf != yinit){
        cout<<"\nStep: "<<++steps<<"\n";
        done.insert(to_string(xinit, yinit));

        int tx = -1, ty = -1;

        // Production rules

        // Rule 1 - Fill 4 L Jug
        if(xinit < capX){
            cout<<"Using Rule 1: Fill 1st Jug Full : "<<capX<<" "<<yinit<<"\n";
            if(done.count(to_string(capX, yinit))==0){
                tx = capX, ty = yinit;
            }
        }

        // Rule 2 - Fill 3 L Jug
        if(yinit < capY){
            cout<<"Using Rule 2: Fill 2nd Jug Full : "<<xinit<<" "<<capY<<"\n";
            if(done.count(to_string(xinit, capY))==0){
                if(heuristics(tx, ty, xinit, capY)){
                    tx = xinit;
                    ty = capY;
                }
            }
        }

        // Rule 5 - Empty 4 gallon jug to ground
        if(xinit > 0){
            cout<<"Using Rule 5: Empty 1st jug to ground : 0 "<<yinit<<"\n";
            if(done.count(to_string(0, yinit))==0){
                if(heuristics(tx, ty, 0, yinit)){
                    tx = 0;
                    ty = yinit;
                }
            }
        }

        // Rule 6 - Empty 3 gallon jug to ground
        if(yinit > 0){
            cout<<"Using Rule 6: Empty 2nd jug to ground : "<<xinit<<" 0\n";
            if(done.count(to_string(xinit, 0))==0){
                if(heuristics(tx, ty, xinit, 0)){
                    tx = xinit;
                    ty = 0;
                }
            }
        }

        // Rule 7 - pour water from 3 gallon jug to  4 gallon jug until 4 gallon jug is full
        if(yinit > 0 && (xinit + yinit) >= capX){
            cout<<"Using Rule 7: Pour water from 2nd jug to 1st jug until 1st jug is full : "<<capX<<" "<<yinit - (capX - xinit)<<"\n";
            if(done.count(to_string(capX, yinit - (capX - xinit)))==0){
                if(heuristics(tx, ty, capX, yinit - (capX - xinit))){
                    tx = capX;
                    ty = yinit - (capX - xinit);
                }
            }
        }

        // Rule 8 - pour water from 4 gallon jug to 3 gallon jug until 3 gallon jug is full
        if(xinit > 0 && (xinit+yinit) >= capY){
            cout<<"Using Rule 8: Pour water from 1st jug to 2nd jug until 2nd jug is full : "<<xinit - (capY - yinit)<<" "<<capY<<"\n";
            if(done.count(to_string(xinit - (capY - yinit), capY))==0){
                if(heuristics(tx, ty, xinit - (capY - yinit), capY)){
                    tx = xinit - (capY - yinit);
                    ty = capY;
                }
            }
        }

        // Rule 9 - pour all water from 3 gallon jug to 4 gallon jug
        if(yinit > 0 && (xinit+yinit) <= capX){
            cout<<"Using Rule 9: Pour all water from 2nd jug to 1st Jug : "<<xinit+yinit<<" "<<"0\n";
            if(done.count(to_string(xinit+yinit, 0))==0){
                if(heuristics(tx, ty, xinit+yinit, 0)){
                    tx = xinit+yinit;
                    ty = 0;
                }
            }
        }

        // Rule 10 - pour all water from 4 gallon jug to 3 gallon jug
        if(xinit > 0 && (xinit+yinit) <= capY){
            cout<<"Using Rule 10: Pour all water from 1st jug to 2nd Jug : 0 "<<xinit+yinit<<"\n";
            if(done.count(to_string(0, xinit+yinit))==0){
                if(heuristics(tx, ty, 0, xinit+yinit)){
                    tx = 0;
                    ty = xinit+yinit;
                }
            }
        }

        cout<<"Selected State: "<<tx<<" "<<ty<<"\n";
        xinit = tx;
        yinit = ty;
    }

    return 0;
}