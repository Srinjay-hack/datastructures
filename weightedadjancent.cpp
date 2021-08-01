#include<iostream>
#include<vector>
#define V 5
using namespace std;
void addEdge(vector<pair<int,int>>graph[5],int u,int v,int weight){
	graph[u].emplace_back(make_pair(v,weight));
}
void init_code(){
	
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif	
}
int main(){
	init_code();
	vector<pair<int,int>> graph[V];
	addEdge(graph,0,1,1);
	addEdge(graph,0,4,5);
	addEdge(graph,1,1,2);
	addEdge(graph,1,2,3);
	addEdge(graph,1,3,4);
	addEdge(graph,1,4,2);
	addEdge(graph,3,2,2);
	addEdge(graph,3,4,3);

	cout<<"Adjacency List"<<endl;
	for(int i=0;i<V;i++){
		cout<<i<<endl;
		for(int j=0; j < graph[i].size();j++){
			cout<<" -> "<<graph[i][j].first<<","<<graph[i][j].second<<endl;
		}
		cout<<endl;


	}



	return 0;
}