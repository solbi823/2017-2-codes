//2016026026_최솔비_508
//counting sort 구현.

#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    
    int inputNum, range, queryNum;
    
    scanf("%d %d %d",&inputNum,&range,&queryNum);
    
    int *arrA;
    arrA= new int[inputNum];
    
    int *rangeA, *rangeB;
    rangeA= new int[queryNum];
    rangeB =new int[queryNum];
    
    int *countArr= new int[range];
    
    for(int i=0; i<queryNum; i++){
        scanf("%d %d",rangeA+i, rangeB+i);
    }
    
    for(int i=0; i<inputNum; i++){
        scanf("%d", arrA+i);
    }
    
    
    for(int i=0; i<range; i++){
        countArr[i]=0;
    }
    
    for(int j=0; j<inputNum; j++){
        countArr[arrA[j]]++;
    }
    
    for(int i=1; i<range; i++){
        countArr[i]=countArr[i-1]+countArr[i];
    }
    
    for(int i=0; i<queryNum; i++){
        printf("%d\n", countArr[rangeB[i]]-countArr[rangeA[i]-1]);
    }
    
    delete []arrA;
    delete []rangeA;
    delete []rangeB;
    delete []countArr;

    return 0;
}
