#include <bits/stdc++.h>

using namespace std;

void print_arr(int *a, int n){
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}

void swap(int *x, int *y){
    int t=*x;
    *x=*y;
    *y=t;
}

int partition(int *arr, int start, int end){
    int pindex=start;   //a[end] as pivot
    for(int i=start; i<end; i++){
        if(arr[i]<=arr[end]){
            swap(arr[i],arr[pindex]);
            pindex++;
        }   
    }
    swap(arr[pindex],arr[end]);
return pindex;
}

int quickSort(int *arr,int start, int end){
    if(start>=end) return 0;

    int pindex = partition(arr,start,end); //taking end el as pivot for convenience

    quickSort(arr,start,pindex-1);
    quickSort(arr,pindex+1,end);

return 0;
}

int main() {

    int a[]= {38, 81, 22, 48, 13, 69, 93, 14, 45, 58, 79, 72};
    int n= *(&a+1) -a;
    cout<<endl<<"Given:";
    print_arr(a,n);
    cout<<endl;
    quickSort(a,0,n-1);
    cout<<"Sorted Array: ";
    print_arr(a,n);
    cout<<endl;


return 0;
 }



