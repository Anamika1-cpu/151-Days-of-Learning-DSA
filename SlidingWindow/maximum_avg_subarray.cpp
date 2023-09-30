#include<bits/stdc++.h>
using namespace std;


double brute_force(vector<int>&arr,int k){
    int i=0;
    int j=k-1;
    int maxSum=INT_MIN;
    while(j<arr.size()){
        int sum=0;
        for(int y=i;y<=j;y++){
            sum+=arr[y];
        }
        maxSum = max(sum,maxSum);
        i++;
        j++;
    }
    double avgSum=maxSum/(double)k;
    return avgSum;
}

double sliding_Window(vector<int>&arr,int k){
    int i=0;int j=k-1;
    int sum=0;
    for(int y=i;y<=j;y++){
        sum+=arr[y];
    }
    int maxSum = sum;
    j++;
    while(j<arr.size()){
        sum-=arr[i++];
        sum+=arr[j++];
        maxSum = max(sum,maxSum);
    }
    double avgSum = maxSum/(double)k;
    return avgSum;
}
int main(){
       vector<int>v = {1,12,-5,-6,50,3};
    cout<<"Maximum avg subarray is "<<endl;
    cout<<brute_force(v,2)<<endl;
    cout<<sliding_Window(v,2);

    return 0;
}