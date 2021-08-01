#include <cstdio>
#include <cmath>
#include <cstring>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <array>
#define ll long long int
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void init_code(){
	fastio
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif	
}
int main(){
	init_code();
	int a,b,c;
	string s;
	cin>>a;
	cin>>b>>c;
	cin>>s;
	cout<<a+b+c<<" "<<s;
	cout<<endl;

	return 0;
	   

}