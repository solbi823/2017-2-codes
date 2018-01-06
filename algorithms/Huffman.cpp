//2016026026_최솔비_508
//HuffmanCode

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <math.h>

#define MAX 30000

using namespace std;

typedef struct node{
    
    char alphaKey;
    long long freq;
    int depth;
    
    node* leftChild;
    node* rightChild;
    
} node;

typedef node* Node;

Node heapArr[MAX+1];
int heapSize;

void makeNode();
void minHeapify(int index);
void buildMinHeap();
Node extractMin();
void depthPlus(Node tmp);
Node huffman();
void insert(Node tmp);

long long fixedNumber(long long a){
    double b= log(a)/log(2);
    return (floor(b)+1);
}

long long huffNumber(Node tmp){
    
    long long sum=0;
    
    if(tmp==NULL)
        return 0;
    
    else if(tmp->rightChild==NULL && tmp->leftChild==NULL){
        return (tmp->depth) * (tmp->freq);
    }
    
    sum+= huffNumber(tmp->rightChild) + huffNumber(tmp->leftChild);

    return sum;
}

void print(){
    for(int i=1; i<=heapSize; i++){
        cout<<heapArr[i]->alphaKey<<" "<<heapArr[i]->freq<<endl;
    }
}

int main(){
    
    int charNum;
    cin>>charNum;
    
    heapSize=0;
    
    for(int i=1; i<=charNum; i++){
        makeNode();
    }
    
    long long totalNum;
    cin>>totalNum;

    /* input의 heapify */
    
    buildMinHeap();
    
    /* huffman tree 작성. */
    
    Node root =huffman();
    
    cout<< fixedNumber(charNum) * totalNum<< endl;
    cout <<huffNumber(root)<<endl;

    
    
    return 0;
}

void makeNode(){
    
    Node temp=(node*)malloc(sizeof(node));
    
    char tmpChar[5]; long long tmpInt;
    scanf("%s", tmpChar);
    scanf("%lld", &tmpInt);
    
    temp->alphaKey =tmpChar[0];     //string의 첫 캐릭터만 저장하도록한다.
    temp->freq =tmpInt;
    temp->depth=0;
    temp->leftChild=NULL;
    temp->rightChild=NULL;

    heapSize++;
    heapArr[heapSize]=temp;
}

void minHeapify(int index){
    
    int left=index*2;
    int right=index*2+1;
    int smallest;
    
    if(left<=heapSize && heapArr[left]->freq < heapArr[index]->freq){
        smallest=left;
    }
    else{
        smallest=index;
    }
    
    if(right<=heapSize && heapArr[right]->freq < heapArr[smallest]->freq){
        smallest=right;
    }
    if(smallest!=index){
        Node tmp=(node*)malloc(sizeof(node));
        tmp=heapArr[index];
        heapArr[index]=heapArr[smallest];
        heapArr[smallest]=tmp;
        minHeapify(smallest);
    }
}

void buildMinHeap(){
    for(int i=heapSize/2; i!=0; i--){
        minHeapify(i);
    }
}

Node extractMin(){
    Node temp=(node*)malloc(sizeof(node));
    temp =heapArr[1];
    heapArr[1]=heapArr[heapSize];
    heapSize--;
    minHeapify(1);
    
    return temp;
}

void depthPlus(Node tmp){
    
    if(tmp == NULL)  return;
    
    else {
        tmp->depth++;
        depthPlus(tmp->leftChild);
        depthPlus(tmp->rightChild);
    }
}

Node huffman(){
    
    int loop=heapSize;
    for(int i=1; i<loop; i++){
        
        Node newNode=(node*)malloc(sizeof(node));
        
        Node x=extractMin();
        Node y=extractMin();
        depthPlus(x); depthPlus(y);
        
        newNode->leftChild=x;
        newNode->rightChild=y;
        newNode->freq= x->freq + y->freq;

        insert(newNode);
    }
    
    return extractMin();
}

void insert(Node tmp){
    
    heapSize++;
    heapArr[heapSize]=tmp;
    
    int i =heapSize;
    while(i>1 && heapArr[i/2]->freq > heapArr[i]->freq){
        Node tempo=(node*)malloc(sizeof(node));
        tempo= heapArr[i];
        heapArr[i]=heapArr[i/2];
        heapArr[i/2]=tempo;
        i/=2;
    }
}



