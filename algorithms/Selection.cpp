//2016026026_최솔비_508
//Selection Sort 구현

#include <iostream>
#include <stdio.h>
#include <limits.h>
using namespace std;

void swap(int* a, int* b){
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

int main() {
    
    int inputNumber, sortStep;
    
    cin>>inputNumber>>sortStep;
    
    int* arr= new int[inputNumber];
    
    for(int i=0; i<inputNumber ;i++){
        scanf("%d", &arr[i]);
    }
    
    for(int i=0; i<sortStep; i++){
        int min=INT_MAX;
        int minIndex=-1;
        for(int j=i; j<inputNumber; j++){
            if(arr[j]<min){
                min=arr[j];
                minIndex=j;
            }
        }
        swap(&arr[minIndex], &arr[i]);
    }
    
    for(int i=0; i<inputNumber; i++){
        printf("%d\n", arr[i]);
    }
    
    delete[] arr;
    
    return 0;
}
