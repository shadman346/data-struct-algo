#include <bits/stdc++.h>
#define clockST clock_t time_req=clock();
#define clockUP time_req=clock();
#define shadman346 cout <<"Time taken:" << (clock() - time_req)/(CLOCKS_PER_SEC / (double) 1000.0) << " milliseconds" << endl;
using namespace std;

void print_arr(int *a, int n){
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int max_ele(int *arr, int n){
    int max=arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]>max)
            max=arr[i];
    }
    return max;
}

void countSort(int *arr, int n){

    int X=max_ele(arr,n);
    int count[X+1];

    for(int i=0; i<=X; i++)
        count[i]=0;
   
    for(int i = 0; i<n; i++)
        count[arr[i]]++;
    

    for(int i = 1; i<=X; i++)
        count[i]+=count[i-1];
    
    int A[n];
    for(int i=n-1; i>=0; i--)
        A[--count[arr[i]]]=arr[i];
    
    for(int i=0; i<n; i++)
        arr[i]=A[i];
        

}




void countSort_Redix(int *arr, int n, int exp){

    
    int count[10]={0};
   
    for(int i = 0; i<n; i++)
        count[(arr[i]/exp)%10]++;
    

    for(int i = 1; i<10; i++)
        count[i]+=count[i-1];
    
    int A[n];
    for(int i=n-1; i>=0; i--)
        A[--count[(arr[i]/exp)%10]]=arr[i];
    
    for(int i=0; i<n; i++)
        arr[i]=A[i];
    

}


void radixSort(int *arr, int n){

    int X=max_ele(arr,n);

    for(int exp=1; X/exp > 0; exp*=10)
        countSort_Redix(arr,n,exp);
}


void bucketSort(int *arr, int size) {

int min = *min_element(arr,arr+size);
int max = *max_element(arr,arr+size);
int range =  (max-min) /size || 1;

vector<int> bucket[size+1] ;
   
    for(int i = 0; i<size; i++)
        bucket[(arr[i]-min)/range].push_back(arr[i]);
        

    for(int i = 0; i<size+1; i++)
        sort(bucket[i].begin(), bucket[i].end());
        
    
    int index = 0;
    for (int i = 0; i < size+1; i++)
        for (int j = 0; j < bucket[i].size(); j++)
            arr[index++] = bucket[i][j];
}            
   
int main(){

    int forcount[]={7, 6, 3, 4, 16, 5, 7, 13, 8 ,12, 6, 6};
    int forbucket[]={71, 10, 31, 41, 16, 46, 51, 21, 13, 8};
    int forradix[]={171, 210, 131, 341, 316, 246, 351, 121, 113, 218, 324};
    int n= *(&forcount+1)-forcount;
    int x= *(&forradix+1)-forradix;
    int z= *(&forbucket+1)-forbucket;
    cout<<"given array:";
    print_arr(forcount,n);
    cout<<"countSort: ";
    countSort(forcount,n);
    print_arr(forcount,n);

    cout<<endl<<"given array:";
    print_arr(forradix,x);
    cout<<"radixSort: ";
    radixSort(forradix,x);
    print_arr(forradix,x);

    cout<<endl<<"given array:";
    print_arr(forbucket,z);
    cout<<"buckSort: ";
    bucketSort(forbucket,z);
    print_arr(forbucket,z);


return 0;
}






