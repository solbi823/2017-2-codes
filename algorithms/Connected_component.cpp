

//2016026026_CHOI_SOLBI
//connected_component

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

using namespace std;

typedef struct vertex{
    
    int component;
    int visited;
    
} Vertex;

void DFS(Vertex* arr, int** linked, int vertex, int componentID, int vertexNum);

int main(){
    
    int vertexNum, v1, v2;
    cin>>vertexNum;
    
    Vertex *arr = (Vertex*)malloc(sizeof(Vertex)*(vertexNum+1));
    for(int i=1; i<=vertexNum; i++){
        arr[i].visited=FALSE;
    }
    
    /* double dimentioned array that shows which vertexes are connected. */
    
    int **linked =(int**)malloc(sizeof(int*)*(vertexNum+1));
    for(int i=1; i<=vertexNum; i++){
        linked[i]=(int*)malloc(sizeof(int)*(vertexNum+1));
        for(int j=1; j<=vertexNum; j++){
            linked[i][j]=FALSE;
        }
    }

    while (scanf("%d %d", &v1, &v2)!=EOF){
        linked[v1][v2]=TRUE;
        linked[v2][v1]=TRUE;
    }
    
    /* graph search step */
    
    int componentID=1;
    for(int i=1; i<=vertexNum; i++){
        if(arr[i].visited==FALSE){
            DFS(arr, linked, i, componentID, vertexNum);
            componentID++;
        }
    }
    
    componentID--;
    cout<<componentID<<endl;
    for(int i=1; i<=vertexNum; i++){
        printf("%d\n", arr[i].component);
    }
    
    return 0;
}


void DFS(Vertex* arr, int** linked, int vertex, int componentID, int vertexNum){
    
    arr[vertex].component=componentID;
    arr[vertex].visited=TRUE;
    
    for(int i=1; i<=vertexNum; i++){
        if(linked[vertex][i]==TRUE && arr[i].visited==FALSE){
            DFS(arr, linked, i, componentID, vertexNum);
        }
    }
}


