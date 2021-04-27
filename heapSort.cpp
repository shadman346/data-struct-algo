#include <bits/stdc++.h>
#define clockST clock_t time_req=clock();
#define clockUP time_req=clock();
#define shadman346 cout <<"Time taken:" << (clock() - time_req)/(CLOCKS_PER_SEC / (double) 1000000.0) << " μs" << endl;

using namespace std;

void print_arr(int *a, int n){
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}


void swap(int *x, int *y){
    int t=*x;
    *x=*y;
    *y=t;
}

void maxheapify(int *arr, int size, int i){
    int max_index=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<size && arr[l]>arr[max_index])
        max_index=l;

    if(r<size && arr[r]>arr[max_index])
        max_index=r;

    if(max_index != i){
        swap(arr[i],arr[max_index]);

        maxheapify(arr,size,max_index);
    }
}
void heapSort(int *arr, int size){
    int j=1;
    cout<<"Rearrange complete binary tree to maxheap:-"<<endl;
    for (int i=(size/2)-1; i>=0; i--)
    {
        maxheapify(arr,size,i);
        cout<<"Pass"<<j++<<": ";
        print_arr(arr,size);
        cout<<endl;

    }
    cout<<endl<<"obtained rearranged array or maxheap==>>>"<<endl<<endl;
    cout<<"Sort the array using heapsort:-"<<endl;
    for (int i = size-1; i >0; i--)
    {
        swap(arr[0],arr[i]);
        cout<<"PassSwap___"<<size-i<<": ";
        print_arr(arr,i+1);
        cout<<endl;
        maxheapify(arr,i,0);
        cout<<"PassHeapify"<<size-i<<": ";
        print_arr(arr,i+1);
        cout<<" <<=out[index:"<<i<<"]"<<endl;
    }
    cout<<"              ^"<<endl;
    cout<<"           [index:0]"<<endl;

    
    
}

int main(){
    
    int a[]={71, 10, 31, 41, 16, 46, 51, 21, 13, 8};
    int n= *(&a+1) -a;
    cout<<endl<<"Given:";
    print_arr(a,n);
    cout<<endl<<endl;
    heapSort(a,n);
    cout<<endl<<"Sorted Array: ";
    print_arr(a,n);
    cout<<endl;


return 0;
}