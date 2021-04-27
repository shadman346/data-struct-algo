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
void swap(int *x,int *y){
    int t = *x;
    *x=*y;
    *y=t;
}

void selectionSort(int *a , int n){
    for(int i=0; i<n-1; i++){
        int min_idx = i;
        for(int j=i+1; j<n; j++){
            if(a[j]<a[min_idx]){
                min_idx=j;
            }
        }
        swap(&a[i],&a[min_idx]); //swap after getting index that has min value.
    }
}

void bubbleSort(int *a, int n){
    for(int i=n-1; i>0; i--){
        int flag=0;
        for(int j=0; j<i; j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
                flag++;
            }
        }
        if(flag==0) break;
    }
}

void insertionSort(int *a, int n){
    for(int i=1; i<n; i++){
        int j = i-1, key=a[i];
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int main(){
    srand(time(0));
    int run=10;
    while(run){
        int n = run*100;
        run--;
        int a[n],b[n],c[n];
        for(int i=0; i<n; i++)
            a[i]=b[i]=c[i]=rand();
        cout<<"=>>>>array size:"<<n;
        cout<<endl<<"selection sort ";
        clockST;
        selectionSort(a,n);
        shadman346;
        
        cout<<"bubble sort ";
        clockUP;
        bubbleSort(b,n);
        shadman346;
        
        cout<<"insertion sort ";
        clockUP;
        insertionSort(c,n);
        shadman346;
        cout<<endl;
    }

return 0;
}