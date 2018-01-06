//2016026026_최솔비_508
//Heap Sort 구현

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


int arr[100001];

void heapify(int* arr, int size, int keyIndex);
void heapSort(int* arr, int size);

int main(){
    
    int size, k;
    
    scanf("%d %d",&size, &k);
    
    int N=size;
    
    for(int i=1; i<=size; i++){
        scanf("%d", arr+i);
    }
    
    heapSort(arr, size);

    for(int i=0; i<k; i++){
        printf("%d " ,arr[1]);
        arr[1]=arr[N];
        N--;
        heapify(arr, N, 1);
    }
    printf("\n");
    
    for(int i=1; i<= size-k; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

void heapify(int* arr, int size, int keyIndex){
    int largest;
    int currentIndex=keyIndex;
    
    int leftChild=currentIndex*2;
    int rightChild=currentIndex*2+1;
    
    if(arr[leftChild]>arr[currentIndex] && leftChild<=size){
        largest=leftChild;
    }
    else{
        largest=currentIndex;
    }
    if(arr[rightChild]>arr[largest] && rightChild<=size){
        largest=rightChild;
    }
    
    if(largest!=currentIndex){
        int tmp=arr[largest];
        arr[largest]=arr[currentIndex];
        arr[currentIndex]=tmp;
        
        heapify(arr, size, largest);
    }
}

void heapSort(int* arr, int size){
    for(int i=size/2; i!=0; i--){
        heapify(arr, size, i);
    }
}
