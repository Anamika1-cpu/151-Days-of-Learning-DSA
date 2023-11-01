#include<bits/stdc++.h>
using namespace std;

//Here, we are using the concept of Binary Search
// for finding the square root. Here we are creating
// a search spce space for finding the square root
//between 0 and the given number.
int sqrt(int x){
    int s=0;
    int e=x;
    int ans =-1;
    int mid = s+(e-s)/2;

    while(s<=e){
        if(mid*mid==x){
            return mid;
        }
        else if(mid*mid<x){
            //we will go to the right side
            s=mid+1;
            ans = mid;
        }
        else{
            //we will go to the left side
            e=mid-1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}
int main(){
    int n;
    cout<<"Give the input for finding square root"<<endl;
    cin>>n;
    cout<<"The square root of "<<n<<" is ";
    cout<<sqrt(n)<<endl;
    return 0;
}
