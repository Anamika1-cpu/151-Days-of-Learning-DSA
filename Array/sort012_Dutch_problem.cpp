#include <bits/stdc++.h>
using namespace std;


    void sort012(int a[], int n)
    {
        
        int z=0;
        int o=0;
        int t=0;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                z++;
            }
            else if(a[i]==1){
                o++;
            }
            else{
                t++;
            }
        }
        int i=0;
        while(z--){
            a[i++]=0;
        }
        while(o--){
            a[i++]=1;
        }
        while(t--){
            a[i++]=2;
        }
        
    };

int main() {
    
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
  int a[n]; 
  cout<<"Input elements of array"<<endl;
  for(int i=0;i<5;i++){
    cin>>a[i];
  }
  sort012(a,n);
  cout<<"Array after sorting:"<<endl;
  for(int i=0;i<5;i++){
    cout<<a[i]<<" ";
  }
  return 0;
}