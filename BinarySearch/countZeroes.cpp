#include <bits/stdc++.h>
using namespace std;

int countZeroes(int arr[],int n){
  if(n==1){
    return arr[0]==0?1:0;
  }
  else{
    int s=0;
    int e=n-1;
    int mid = s+(e-s)/2;
    while(s<=e){
      if(arr[mid]==0){
        e=mid-1;
      }
      else{
        s=mid+1;
      }
      mid = s+(e-s)/2;
    }
  return n-s;
  }
}

int main() {
  int arr[5] = {1,1,1,0,0};
  cout<<countZeroes(arr,5);
  return 0;
}