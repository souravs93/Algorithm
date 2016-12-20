#include<iostream>
using namespace std;

void merge(int arr[],int l,int m,int r){
    int n1,n2;
    n1 = m-l+1;
    n2 = r-m;
    
    int arr1[n1],arr2[n2];
    
    for(int i=0;i<n1;i++)
        arr1[i] = arr[l+i];
    for(int i=0;i<n2;i++)
        arr2[i] = arr[m+i+1];
    
    int i=0,j=0,w=l;
    
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr[w++] = arr1[i++];
        }
        else{
            arr[w++] = arr2[j++];
        }
    }
    
    while(i<n1)
        arr[w++] = arr1[i++];
    
    while(j<n2)
        arr[w++] = arr2[j++];
}

void mergesort(int arr[],int l,int r){
    if(l<r){
        int m = l+(r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        
        
        merge(arr,l,m,r);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        mergesort(arr,0,n-1);
        
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}
