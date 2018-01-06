//2016026026_최솔비_508
//Merge Sort 구현

#include <iostream>
#include <stdio.h>
using namespace std;

void merge(int* arr, int first, int middle, int last);

void mergeSort(int* arr, int first, int last){
    if(first<last){
        int middle= (last+first)/2;
        mergeSort(arr, first, middle);
        mergeSort(arr, middle+1, last);
        merge(arr, first, middle, last);
    }
}

void merge(int* arr, int first, int middle, int last){
    int arrSize1= middle-first+1;
    int arrSize2= last-middle;
    
    int arr1[arrSize1+1];
    int arr2[arrSize2+1];
    for(int i=0; i<arrSize1; i++){
        arr1[i]=arr[first+i];
    }
    arr1[arrSize1]=-1;
    
    for(int i=0; i<arrSize2; i++){
        arr2[i]=arr[middle+1+i];
    }
    arr2[arrSize2]=-1;
    
    int i=0, j=0;
    for(int k=first; k<=last; k++){
        if(arr1[i]>arr2[j]){
            arr[k]=arr1[i];
            i++;
        }
        else{
            arr[k]=arr2[j];
            j++;
        }
    }
}


int main() {
    
    int keyNumber;
    cin>>keyNumber;
    
    int* arr= new int[keyNumber];
    
    for(int i=0; i<keyNumber; i++){
        scanf("%d", &arr[i]);
    }
    
    mergeSort(arr, 0, keyNumber-1);
    
    for(int i=0; i<keyNumber; i++){
        printf("%d\n", arr[i]);
    }
    
    return 0;
}
