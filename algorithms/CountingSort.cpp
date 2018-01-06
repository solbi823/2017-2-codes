
//2016026026_CHOI_SOLBI
//topological sort

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

using namespace std;

int cycle;

void dfs(int i, int* top, int *stack, int *visited, int *finish, int **edge, int vertexNum){
    visited[i]=TRUE;
    for(int k=1; k<=vertexNum; k++){
        if(edge[i][k]==TRUE && visited[k]==FALSE){
            dfs(k, top, stack, visited, finish, edge, vertexNum);
        }
        else if(edge[i][k]==TRUE && finish[k]==FALSE){
            cycle=TRUE;
        }
    }
    
    finish[i]=TRUE;
    (*top)++;
    stack[*top]=i;
}

int main(){
    
    cycle=FALSE;
    int vertexNum, v1, v2;
    cin >>vertexNum;

    int *stack=(int*)malloc(sizeof(int)*(vertexNum+1));
    int *visited=(int*)malloc(sizeof(int)*(vertexNum+1));
    int *finish=(int*)malloc(sizeof(int)*(vertexNum+1));
    
    
    for(int i=1; i<=vertexNum; i++){
        visited[i]=FALSE;
    }
    for(int i=1; i<=vertexNum; i++){
        finish[i]=FALSE;
    }
    
    int **edge=(int**)malloc(sizeof(int*)*(vertexNum+1));
    for(int i=1; i<=vertexNum; i++){
        edge[i]=(int*)malloc(sizeof(int)*(vertexNum+1));
        for(int j=1; j<=vertexNum; j++){
            edge[i][j]=FALSE;
        }
    }
    
    while (scanf("%d %d", &v1, &v2)!=EOF){
        edge[v1][v2]=TRUE;
    }
    
    int top=0;
    
    for(int i=1; i<=vertexNum; i++){
        if(visited[i]==FALSE){
            dfs(i, &top, stack, visited, finish, edge, vertexNum);
        }
    }
    
    if(cycle==TRUE){
        cout<<"0"<<endl;
        return 0;
    }
    else{
        cout<<"1"<<endl;
    }
    
    for(int i=top; i!=0; i--){
        printf("%d ",stack[i]);
    }
    cout<<endl;
    
    return 0;
}
