#include<iostream> 
#include<cstdio> 
using namespace std; 
int Heuristics(int arr[],int N)
{ 
 int c=0; 
 for(int i=0;i<N;i++)
 { 
    for(int j=i+1;j<N;j++) 
        {
            if(arr[j]<arr[i]) 
            c++; 
        }
 }
 return c; 
} 

int main()
{ 
 int N = 10; 
 int arr[100];
 for(int i=0;i<N;i++) 
 {
    arr[i] = rand() % 100;
 }
 int bestCost=Heuristics(arr,N),newCost,swaps=0; 
 while(bestCost>0)
 { 
  for(int i=0;i<N-1;i++)
  { 
    swap(arr[i],arr[i+1]); 
    newCost=Heuristics(arr,N); 
    cout<<"Cost "<<newCost;
    cout<<endl;
    if(bestCost>newCost)
    { 
        cout<<"After swap : "<<++swaps<<endl; 
        for(int i=0;i<N;i++) 
            cout<<arr[i]<<" "; 
        cout<<endl; 
        bestCost=newCost; 
   } 
   else 
        swap(arr[i],arr[i+1]); 
  } 
 } 
 cout<<"Final Ans ";
 return 0; 
}