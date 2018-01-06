

//2016026026_최솔비
//Dijkstra

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#define WEIGHT_MAX 1000000

using namespace std;

typedef pair<int, int> P;

int main(){
    
    int vertexNum;
    cin>>vertexNum;
    
    vector <vector<P> > edges(vertexNum+1);         //이중 vector. index는 depart vertex를 의미한다. 내부벡터의 first는 arrival vertex, second는 weight.
    priority_queue<P, vector<P>, greater<P> > Q;     //first에 distance, second에 vertex index를 저장하는 min Priority Queue.

    vector <int> distance(vertexNum+1);                            //결과 distance 를 저장하기 위한 vector. index는 vertexNumber.
    
    
    
    int depart, arrival, weight, edgeNum;
    
    for(int i=0; i<vertexNum; i++){
        scanf("%d %d ", &depart, &edgeNum);
        
        for(int j=0; j<edgeNum; j++){
            scanf("%d %d", &arrival, &weight);
            edges[depart].push_back(make_pair(arrival, weight));
        }
        distance[i+1]=WEIGHT_MAX;
    }
    
    distance[1]=0;
    P tmp=make_pair(distance[1], 1);
    
    Q.push(tmp);
    
    while(!Q.empty()){
        
        tmp=Q.top();
        Q.pop();
        int here=tmp.second;
        
        for(int i=0; i<edges[here].size(); i++){
            weight=edges[here][i].second;
            arrival=edges[here][i].first;
            
            if(distance[arrival]> distance[here]+ weight){
                distance[arrival]= distance[here]+ weight;
                
                tmp=make_pair(distance[arrival], arrival);
                Q.push(tmp);
            }
        }
        
    }
    
    int maxD=0;
    for(int i=1; i<=vertexNum; i++){
        if(maxD < distance[i]){
            maxD=distance[i];
        }
    }
    
    cout<<maxD<<endl;
    
    return 0;
}
