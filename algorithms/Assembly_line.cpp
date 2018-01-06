
//2016026026_최솔비_508
//Assembly line

#include <iostream>
#include <algorithm>
#include <stdio.h>
#define MAX 100

using namespace std;

int main(){
    
    int line1[MAX+1];
    int line2[MAX+1];
    int time1[MAX+1];
    int time2[MAX+1];
    int save1[MAX+1];
    int save2[MAX+1];
    int way[MAX+1];
    
    int staNum;
    
    cin>>staNum;
    cin>>time1[0]>>time2[0];
    cin>>time1[staNum]>>time2[staNum];
    
    for(int i=1; i<=staNum; i++){
        scanf("%d", line1+i);
    }
    for(int i=1; i<=staNum; i++){
        scanf("%d", line2+i);
    }
    for(int i=1; i<staNum; i++){
        scanf("%d", time1+i);
    }
    for(int i=1; i<staNum; i++){
        scanf("%d", time2+i);
    }
    
    int min1=time1[0]+line1[1];
    int min2=time2[0]+line2[1];
    
    for(int i=2;i<=staNum; i++){
        
        int tmp=min1;
        
        if(min1+line1[i]< min2+time2[i-1]+line1[i]){
            save1[i]=1;
            min1=min1+line1[i];
        }
        else{
            save1[i]=2;
            min1=min2+time2[i-1]+line1[i];
        }
        
        if(min2+line2[i]< tmp+time1[i-1]+line2[i]){
            save2[i]=2;
            min2=min2+line2[i];
        }
        else{
            save2[i]=1;
            min2=tmp+time1[i-1]+line2[i];
        }
    }
    
    min1+=time1[staNum];
    min2+=time2[staNum];
    
    int result;
    
    if(min1<min2){
        result=min1;
        way[staNum]=1;
    }
    else{
        result=min2;
        way[staNum]=2;
    }
    
    cout<<result<<endl;
    
    for(int i=staNum-1; i!=0; i--){
        if(way[i+1]==1){
            way[i]=save1[i+1];
        }
        else{
            way[i]=save2[i+1];
        }
    }
    
    for(int i=1; i<=staNum; i++){
        printf("%d %d\n", way[i], i);
    }
    
    
    return 0;
}
