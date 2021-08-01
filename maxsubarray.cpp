#include<iostream>
#include<vector>
#define V 5
using namespace std;
void addEdge(vector<int>graph[5],int u,int v){
	graph[u].emplace_back(v);
}
void init_code(){
	
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif	
}
int maxxor(vector<int> a,int m,int k){
	int n=a.size();
	if(k>=n-m)
		return -1;
	for(int i=0;i<64;i++)
	{
		if(m & (1<<i)){
			m-=(1<<i);


			for(int j=0;j<n-1;j++){
				a[j]=a[j] xor a[j+(1<<i)];
			}
		}
	}
	return a[k];
}

int main(){
	init_code();
	vector<int> a ={1,4, 5,6 ,7};
	int m=1,k=2;
	int ans=maxxor(a,m,k);
	cout<<ans<<endl;




	return 0;
}
//O(nlog(m))