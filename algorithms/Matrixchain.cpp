//2016026026_최솔비_508
//Matrix Chain 구현

#include <iostream>
#include <stdio.h>
#include <limits.h>
#define MAX 100

using namespace std;

int p[MAX+1];
int m[MAX+1][MAX+1];
int s[MAX+1][MAX+1];

void printOptimalParens(int i, int j){
    if(i==j){
        printf("%d ", i);
    }
    else{
        printf("( ");
        printOptimalParens(i, s[i][j]);
        printOptimalParens(s[i][j]+1, j);
        printf(") ");
    }
}

int main(){
    
    int N;
    cin>>N;
    
    for(int i=0; i<=N; i++){
        scanf("%d", p+i);
    }
    
    for(int i=1; i<=N; i++){
        m[i][i]=0;
    }
    for(int l=2; l<=N; l++){
        for(int i=1; i<= N-l+1; i++){
            int j=i+l-1;
            m[i][j]=INT_MAX;
            for(int k=i; k<= j-1;k++){
                int q= m[i][k] +m[k+1][j]+ p[i-1]*p[k]*p[j];
                
                if(q<m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    
    
    printf("%d\n", m[1][N]);
    printOptimalParens(1, N);
    printf("\n");
    
    return 0;
}
