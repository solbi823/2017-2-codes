// 2016026026_최솔비_508
// Insertion Sort 구현


#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int keyNumber;
    cin>>keyNumber;
    int* arr= new int[keyNumber];
    
    for(int i=0; i<keyNumber; i++){
        scanf("%d", &arr[i]);
    }
    
    for(int i=1; i<keyNumber; i++){
        int keyValue=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]<keyValue){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=keyValue;
    }
    
    for(int i=0; i<keyNumber; i++){
        printf("%d\n", arr[i]);
    }
    
    delete []arr;
    return 0;
}
