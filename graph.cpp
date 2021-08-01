
#include <bits/stdc++.h>
#include<unordered_map>
#include<map>

using namespace std;

void init_code(){
	
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif	
}



// Driver code
int main()
{
	init_code();

    int n,m;
    cin>>n>>m;
    // undirected weighted graph
    vector<pair<int,int>> adj[n+1];

    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        
        adj[u].push_back({v , wt});
        adj[v].push_back({u , wt});


    }
    /**for undirected graph
     * for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
     * **/
    
    
   




	return 0;
}

