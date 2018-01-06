//2016026026_최솔비_508
//Priority Queue 구현


#include <iostream>
#include <stdio.h>
#define MAX 100000

using namespace std;

int heapArr[MAX+1]{-1,};
int saveMax[MAX+1]{-1,};
int size, saveSize;

void printOutput();
void insert(int insertNum);
void extractMax();
void substitute(int index, int newInteger);
void maxHeapify(int index);
void buildMaxHeap();

int main(){
    
    size=0;
    saveSize=0;
    
    int menu;
    
    while(1){
        
        cin>> menu;
        
        if(menu==0){
            printOutput();
            break;
        }
        else if(menu==1){
            int insertNum;
            cin>> insertNum;
            insert(insertNum);
        }
        else if(menu==2){
            extractMax();
        }
        else if(menu ==3){
            int index, newInteger;
            cin>>index>> newInteger;
            substitute(index, newInteger);
        }
    }
    
    return 0;
}

void printOutput(){
    for(int i=1; i<=saveSize; i++){
        printf("%d ", saveMax[i]);
    }
    printf("\n");
    for(int i=1; i<=size; i++){
        printf("%d ", heapArr[i]);
    }
    printf("\n");
}

void insert(int insertNum){
    size++;
    heapArr[size]=insertNum;
    int i= size;
    while( i>1 && heapArr[i/2]< heapArr[i]){
        int tmp= heapArr[i];
        heapArr[i]=heapArr[i/2];
        heapArr[i/2]=tmp;
        i/=2;
    }
}

void extractMax(){
    saveSize++;
    saveMax[saveSize]=heapArr[1];
    heapArr[1]=heapArr[size];
    heapArr[size]=-1;
    size--;
    maxHeapify(1);
}

void substitute(int index, int newInteger){
    heapArr[index]=newInteger;
    buildMaxHeap();
}

void maxHeapify(int index){
    int leftChild = index*2;
    int rightChild = index*2+1;
    int largest;
    if(leftChild<=size && heapArr[leftChild]> heapArr[index]){
        largest=leftChild;
    }
    else{
        largest=index;
    }
    if(rightChild<=size && heapArr[rightChild]>= heapArr[largest]){
        largest=rightChild;
    }
    if(largest!= index){
        int tmp=heapArr[index];
        heapArr[index]=heapArr[largest];
        heapArr[largest]=tmp;
        maxHeapify(largest);
    }
}

void buildMaxHeap(){
    for(int i=size/2; i!=0; i--){
        maxHeapify(i);
    }
}
