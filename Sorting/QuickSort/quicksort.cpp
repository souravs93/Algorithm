#include<iostream>
using namespace std;

void swap(int* a,int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[],int l,int r){
    int pivot = arr[r];
    int i = l-1;
    
    for(int j=l;j<=r-1;j++){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return (i+1);
}

void quicksort(int arr[],int l,int r){
    if(l<r){
        int pivot = partition(arr,l,r);
        quicksort(arr,l,pivot-1);
        quicksort(arr,pivot+1,r);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n=0;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
            
        quicksort(arr,0,n-1);
        
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}
