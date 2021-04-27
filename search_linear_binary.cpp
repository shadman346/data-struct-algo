#include <bits/stdc++.h>
#define clockST clock_t time_req=clock();
#define clockUP time_req=clock();
#define shadman346 cout <<"Time taken:" << (clock() - time_req)/(CLOCKS_PER_SEC / (double) 1000.0) << " milliseconds" << endl;
using namespace std;

int binarySearch(int x, int *arr, int size)
{
    int m = size;
    while(m>0){
        m = size / 2;
        if(x==arr[m]){return 1;}
        else if(x<arr[m]){size=m;}
        else if(x>arr[m]){arr=arr+m+1; size=size-m-1;}
    }
    return -1;  
}
int linearSearch(int x, int *arr)
{
    for (int i = 0; i < 100000; i++){
        if (arr[i] == x)
            return 1;
    }
    return 0;
}

int main()
{
    int size = 100000;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = i + 1;

    int search_num[10] = {5000, 15000, 25000, 35000, 45000, 55000, 65000, 75000, 85000, 95000};

    for (int i = 0; i < 10; i++)
    {
        cout << search_num[i] << endl;

        clockST;
        linearSearch(search_num[i], arr);
        cout << "For linear search ";
        shadman346;

        clockUP;
        binarySearch(search_num[i], arr, size);
        cout << "For Binary search ";
        shadman346;

        cout << "----------------------------------" << endl;
    }

    return 1;
}
