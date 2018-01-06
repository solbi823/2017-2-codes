//2016026026_최솔비_508
//FindingSameKeys

#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int N, M;
    
    scanf("%d %d",&N, &M);
    
    int* arrN=new int[N];
    int max=0;
    
    for(int i=0; i<N; i++){
        scanf("%d", arrN+i);
        if(arrN[i]>max){
            max=arrN[i];
        }
    }
    
    int* countArrN=new int[max+1];
    for(int i=0; i<=max; i++){
        countArrN[i]=0;
    }
    
    for(int i=0; i<N; i++){
        countArrN[arrN[i]]=1;
    }
    
    int count=0;
    for(int i=0; i<M;i++){
        int tmp;
        scanf("%d", &tmp);
        if(countArrN[tmp]==1){
            count++;
        }
    }
    
    cout<<count<<endl;
    
    delete[] arrN;
    delete[] countArrN;
    
    return 0;
}
