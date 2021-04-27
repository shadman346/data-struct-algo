#include <bits/stdc++.h>
#define clockST clock_t time_req=clock();
#define clockUP time_req=clock();
#define shadman346 cout <<"Time taken:" << (clock() - time_req)/(CLOCKS_PER_SEC / (double) 1000.0) << " milliseconds" << endl;
using namespace std;


int disjoint_set_id[20];

void initialize(){  // will keep track of root parent for every subset.
    for (int i = 0; i < 20; i++)
        disjoint_set_id[i]=-1;

}

//keep track of nodes and their root parents

template <typename T>
class _pair{
    public:
    T x,y,weight;
    _pair(T x, T y, T weight){
        this->x=x;
        this->y=y;
        this->weight=weight;
    }
};

template <typename T>
void swap(T *a, T *b){
    T temp= *a;
    *a=*b;
    *b = temp;
}

void minheapify(_pair<int> *p ,int size,int i){
    int min_index = i;
    int l=2*i + 1;
    int r=2*i + 2;

    if(l<size && p[l].weight<p[min_index].weight)
        min_index = l;
    if(r<size && p[r].weight<p[min_index].weight)
        min_index = r;
    
    if(min_index!=i){
        swap<_pair<int>>(p[min_index],p[i]);

        minheapify(p,size,min_index);
    }
}

int root(int x){
    while(disjoint_set_id[x]!=-1){  
        
        // disjoint_set_id[x]= disjoint_set_id[disjoint_set_id[x]];
        x=disjoint_set_id[x];
    }
    return x;
}

void _union (int x , int y){
    int p= root(x);
    int q= root(y);
    cout<<"union p:"<<p<<" <-- q:"<<q<<endl;
    disjoint_set_id[p]=q;
}

int kruskal(_pair<int> *p,int edges, int vertices){
    int minimumCost=0;
    for(int i=edges/2 -1 ; i>=0; i--){ //rearrange edges in minHeap according to thier weight
        minheapify(p,edges,i);
    }

    int Mst_Edges = 0;
    for(int i=edges-1; i>=0 ; i--){
        int x = p[0].x;
        int y = p[0].y;
        int cost = p[0].weight;
        cout<<edges-i<<"=> from: "<<x<<" to: "<<y<<" weight: "<< cost<<endl;
        cout<<"from_rootParent: "<<root(x)<<" To_rootParent: "<<root(y)<<endl;
        if(root(x) != root(y)){
            _union(x,y);     // one of the root parent (either from X or Y set) will point towards the root parent of other set. 
            minimumCost+=cost;
            Mst_Edges++;
            cout<<"TotalEdges in spanning tree: ("<<Mst_Edges<<"/"<<vertices-1<<")"<<endl;
            if(Mst_Edges == (vertices-1) )
                return minimumCost;
        }else cout<<"Since it result in cycle, discard it!!"<<endl;
        
        swap<_pair<int>>(p[0],p[i]);
        minheapify(p, i , 0);
       cout<<endl;
    }
    return minimumCost;
}

int main()
{   
    int TotalVertices = 9;
    _pair<int> *p =new _pair<int>[14]{
        {0,1,4},{1,2,8},{2,3,7},
        {3,4,9},{4,5,10},{5,6,2},
        {6,7,1},{7,8,7},{7,0,8},
        {7,1,11},{2,8,2},{8,6,6},
        {2,5,4},{3,5,14} };

    initialize();
    
    int minimumCost = kruskal(p,14,TotalVertices);
    cout<<"Minimum spanning tree Cost: "<<minimumCost;

return 0;
}



