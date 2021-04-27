#include<bits/stdc++.h>
using namespace std;

class NodeMinHeap {
    public:
    NodeMinHeap* left;
    NodeMinHeap* right;
    int freq;
    char data;
    NodeMinHeap(int f, char d) {
        left = NULL;
        right = NULL;
        freq = f;
        data = d;
    }
};

class Compare {
    public:
    bool operator()(NodeMinHeap* l, NodeMinHeap* r)
    {
        return (l->freq > r->freq);
    }
};

void printCodes(NodeMinHeap* top, string print) {
    if(!top) return;

    if(top->data != '$') {
        cout << top->data << " : " << print << endl;
        return;
    }
    printCodes(top->right, print + "1");
    printCodes(top->left, print + "0");
}


void huffmanCodes(char *a, int *f, int n) {
    priority_queue<NodeMinHeap*, vector<NodeMinHeap*>, Compare> minHeap;
    for(int i = 0 ; i < n; i++) {
        NodeMinHeap *node = new NodeMinHeap(f[i], a[i]);
        minHeap.push(node);
    }

    NodeMinHeap *left,*right, *top;
    while(minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        
        top = new NodeMinHeap(left->freq + right->freq, '$');
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    printCodes(minHeap.top(), "");
}

int main() {
    char arr[] = { 'm', 's', 'i', 'p'};
    int freq[] = { 1, 4, 4, 2};
 
    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<"1) mississippi"<<endl;
    huffmanCodes(arr, freq, size);
    cout<<endl<<endl;

    char arr1[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    int freq1[] = { 1, 1, 2, 3, 5, 8, 13, 21};
    size = sizeof(arr1) / sizeof(arr1[0]);
    cout<<"2)"<<endl;
    huffmanCodes(arr1, freq1, size);
    cout<<endl<<endl;

    char arr2[] = { 'g', 'o', ' ', 'p', 'h', 'e', 'r', 's'};
    int freq2[] = { 3, 3, 2, 1, 1, 1, 1, 1};
    size = sizeof(arr2) / sizeof(arr2[0]);
    cout<<"3) go go gophers"<<endl;
    huffmanCodes(arr2, freq2, size);
    cout<<endl<<endl;
    return 0;
}


