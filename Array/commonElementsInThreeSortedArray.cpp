#include<bits/stdc++.h>
using namespace std;


vector<int> common_Elements(int A[],int n1,int B[],int n2,int C[],int n3){
    int i=0;int j=0;int k=0;
    set<int>s;
    while(i<n1 && j<n2 && k<n3){
        if(A[i]==B[j] && B[j]==C[k]){
            s.insert(A[i]);
            i++;j++;k++;
        }
        else if(A[i]<B[j]){
            i++;
        }
        else if(B[j]<C[k]){
            j++;
        }
        else{
            k++;
            //this means C[K]<B[j] && C[k]<A[i]
        }
        
    }
    vector<int>ans;
        for(auto i:s){
        ans.push_back(i);
        }
        return ans;
}

int main()
{
    int A[] = {1,2,3,4,5};
    int B[] = {3,3,4,5};
    int C[] = {1,2,2,3,4,5};
    
    vector<int>a = common_Elements(A,5,B,4,C,6);
    cout<<"Common elements in given 3 arrays are:"<<endl;
    for(auto i:a){
        cout<<i<<" ";
    }
    return 0;
}
