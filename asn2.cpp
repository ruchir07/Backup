#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

//Node structure
struct Node{
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(char c,int f){
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct Compare{
    bool operator()(Node* a,Node* b){
        return a->freq > b->freq;
    }
};

void printHuffman(Node* node,string code){
    if(node == NULL){
        return;
    }

    if(node->left == NULL && node->right == NULL){
        cout<<node->ch<<" : "<<code<<endl;
        return;
    }
    
    printHuffman(node->left,code + '0');
    printHuffman(node->right,code + '1');

}

void huffman(vector<char> &chars,vector<int> freq,int n){

    priority_queue<Node*,vector<Node*>,Compare> pq; //Min heap
    for(int i=0;i<n;i++){
        pq.push(new Node(chars[i],freq[i]));
    }

    while(pq.size() > 1){
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* newNode = new Node('$',left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    cout<<"Huffman Encoding Code for each Character:"<<endl;
    printHuffman(pq.top(),"");

}

int main() {

    int n;
    cout<<"\nEnter total no. of Nodes:";
    cin>>n;

    vector<char> chars(n);
    vector<int> freq(n);
    cout<<"\nEnter the character followed by its Frequency:";
    for(int i=0;i<n;i++){
        cin>>chars[i]>>freq[i];
    }

    huffman(chars,freq,n);


    return 0;
}