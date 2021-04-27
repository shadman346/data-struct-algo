#include <bits/stdc++.h>
#define clockST clock_t time_req=clock();
#define clockUP time_req=clock();
#define shadman346 cout <<"Time taken:" << (clock() - time_req)/(CLOCKS_PER_SEC / (double) 1000000.0) << " μs" << endl;

using namespace std;

void print_arr(int *a, int n){
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}
void merge(int *arr, int sizeL, int sizeR){
    int L[sizeL],R[sizeR];
    for(int i=0; i<sizeL; i++)
        L[i]=arr[i];
    
    for(int i=0; i<sizeR; i++)
        R[i]=arr[sizeL+i];
    
    int i=0,j=0,k=0;
    while(i<sizeL && j<sizeR){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else if(L[i]>R[j]){
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<sizeL){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<sizeR){
        arr[k]=R[j];
        j++;
        k++;
    }
    
}

int mergeSort(int *arr,int size){
    if(size<2){ 
        return 1;
    }
    int m = (size/2);  // take note our mergeSort func taking size as parameter not indexes like left_most or right_most
    mergeSort(arr,m); //left
    mergeSort(arr+m,size-m); //right -passing refrence of array-index where i want to start my array and size of subarray will always bigger in odd size
    merge(arr,m,size-m);
return 0;
}

void mergeId(int *arr,int l,int r,int mid){
    int nl= mid-l +1;
    int nr= r-mid;
    int L[nl], R[nr];
    for(int i=0; i<nl; i++)
        L[i]=arr[l+i];
    
    for(int i=0; i<nr; i++)
        R[i]=arr[mid+1+i];
    
    int i=0,j=0,k=l;
    while(i<nl && j<nr){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }else if(R[j]<L[i]){
            arr[k]=R[j];
            j++;
        }
        k++;
    }

    while(i<nl){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<nr){
        arr[k]=R[j];
        j++;
        k++;
    }

}
int mergeSortId( int *arr, int l, int r){
    if(l>=r) return 1;
    int mid = (r-l)/2 + l;
    mergeSortId(arr,l,mid);
    mergeSortId(arr,mid+1,r);
    mergeId(arr,l,r,mid);
return 0;
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
    for (int i = size/2 -1; i >=0; i--)
    {
        maxheapify(arr,size,i);
    }
    for (int i = size-1; i >0; i--)
    {
        swap(arr[0],arr[i]);
        maxheapify(arr,i,0);
    }
    
}




int main(){
    srand(time(0));
    int run=10;
    while(run){
        int n = run*100;
        run--;
        int a[n],b[n];
        for(int i=0; i<n; i++)
            a[i]=b[i]=rand();
        cout<<"=>>>>array size:"<<n;

        cout<<endl<<"mergeSort ";
        clockST;
        mergeSort(a,n);
        shadman346;

        cout<<"heapSort ";
        clockUP;
        heapSort(a,n);
        shadman346;
        
        cout<<"quickSort ";
        clockUP;
        quickSort(b,0,n-1);
        shadman346;

        cout<<endl;
    }


return 0;
}