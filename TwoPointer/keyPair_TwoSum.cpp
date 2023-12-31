#include <bits/stdc++.h>
using namespace std;

	bool twoPointerPairSum(int arr[], int n, int x) {	    
	    sort(arr,arr+n);
	    int s=0;
	    int e=n-1;
	    while(s<e){
	        if(arr[s]+arr[e]==x){
	            return true;
	        }
	        else if(arr[s]+arr[e]<x){
	            s+=1;
	        }
	        else{
	            e-=1;
	        }
	    }
	    return false;
	}


int main() {
  int arr[6] = {10,3,23,0,5,6};
  int ans = twoPointerPairSum(arr,6,26);
  if(ans==1){
    cout<<"Pair sum is present"<<endl;
  }
  else{
    cout<<"Pair sum is not present"<<endl;

  }
  return 0;
}