//2016026026_최솔비_508
//Longest Common Subsequence 구현.


#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 500

using namespace std;

int table[MAX+1][MAX+1];

int max(int a, int b){
    if(a>b) return a;
    else    return b;
}

int main(){
    
    char line1[MAX+1]{'\0',};
    char line2[MAX+1]{'\0',};
    
    fgets(line1, MAX+1, stdin);
    fgets(line2, MAX+1, stdin);
    
    int xlength, ylength;
    char xStr[MAX+1]{'\0',};
    char yStr[MAX+1]{'\0',};
    
    if(strcmp(line1, line2)<0){
        xlength=(int)strlen(line2)-1;
        ylength=(int)strlen(line1)-1;
        strcpy(xStr, line2);
        strcpy(yStr, line1);
    }
    else{
        xlength=(int)strlen(line1)-1;
        ylength=(int)strlen(line2)-1;
        strcpy(xStr, line1);
        strcpy(yStr, line2);
    }
    
    for(int i=0; i<=xlength; i++){
        table[i][0]=0;
    }
    for(int i=1; i<=ylength; i++){
        table[0][i]=0;
    }
    
    for(int i=1; i<=xlength; i++){
        for(int j=1; j<=ylength; j++){
            if(xStr[i-1]==yStr[j-1]){
                table[i][j]=table[i-1][j-1]+1;
            }
            else{
                table[i][j]=max(table[i][j-1], table[i-1][j]);
            }
        }
    }
    
    int i=xlength, j=ylength;
    int charIndex=table[xlength][ylength]-1;
    
    char LCS[charIndex+1];
    
    while(charIndex>=0){
        if(table[i][j]==table[i-1][j]){
            i--;
        }
        else if(table[i][j]==table[i][j-1]){
            j--;
        }
        else{
            LCS[charIndex]=xStr[i-1];
            i--; j--;
            charIndex--;
        }
    }
    
    for(int i=0; i<=xlength; i++){
        for(int j=0; j<=ylength; j++){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<LCS<<endl;
    return 0;
    
}
