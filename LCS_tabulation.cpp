
#include<bits/stdc++.h>
using namespace std;



int t[12+1][12+1];


void initialize(int m, int n){
    for (int i=0; i<m+1; i++)
        for(int j=0; j<n+1; j++)
        {
            if(j==0)
                t[i][j]=0;
            if(i==0)               
                t[i][j]=0;
        }
    
   
}

void print(int m, int n){
for (int i = 0; i < m+1; i++){
        cout<<endl;
        for(int j = 0; j< n+1; j++)
            {
              cout<<t[i][j]<<"  ";
            }
    }
    cout<<endl;
}


int LCS(string x, string y, int m, int n){
    for(int i=1; i<m+1; i++)
        for(int j=1; j<n+1; j++){
            if(m==0 || n==0)
                return 0;
            
            if(x[i-1]==y[j-1]){
            t[i][j]= 1+ t[i-1][j-1];
            }
            else{
            t[i][j]= 0;
            }
        }
    
return t[m][n];
}

int main(){
string X = "PQRSTPQRS";
string Y = "PRATPBRQRPS";
int m = X.size();
int n = Y.size();

    initialize(m,n);
    cout<<"string X: "<<X<<" and string Y: "<<Y<<endl;
    cout<<"Longest Common Subsequence: "<<LCS(X,Y,m,n);
    cout<<endl;
    print(m,n);
    

cout<<endl<<endl;

X = "BACDB";
Y = "BDCB";
m = X.size();
n = Y.size();

    initialize(m,n);
    cout<<"string X: "<<X<<" and string Y: "<<Y<<endl;
    cout<<"Longest Common Subsequence: "<<LCS(X,Y,m,n);
    cout<<endl;
    print(m,n);


cout<<endl<<endl;

X = "abbcdgf";
Y = "bbadcgf";
m = X.size();
n = Y.size();

    initialize(m,n);
    cout<<"string X: "<<X<<" and string Y: "<<Y<<endl;
    cout<<"Longest Common Subsequence: "<<LCS(X,Y,m,n);
    cout<<endl;
    print(m,n);

return 0;
}
