
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
    /**map<char, int>M;
    unordered_map<char, int>N;
    string s="Srinjay"
    for(char c:s)M[c]++;//nlogn
    for(char c:s)N[c]++;//n^2**/
    int n;
    long long S;
    cin>>n;
    vector<int> A(n,0);
    for(int i=0;i<n;i++) cin>>A[i] , S+=A[i];

    if(S & 1){
    	cout<<"NO";
    	return 0;
    } 	

    map<int,int>first,second;
    first[A[0]]=1;
    for (int i=1;i<n;i++) second[A[i]]++;
    int sdash=0;

    for(int i=0;i<n;i++){
    	sdash=A[i];//first i numbers
    	if(sdash == S/2){
    		cout<<"YES\n";
    		return 0;

    	}
    	if(sdash<S/2){
    		long long x=S/2-sdash;
    		if(second[x]>0){
    			cout<<"YES\n";
    		}

    	}
    	else{
    		long long y=sdash-S/2;
    		if(first[y]>0){
    			cout<<"YES\n";
    			return 0;
    		}
    	}
    	first[A[i+1]]++;
    	second[A[i+1]]--;

    }	
    cout<<"NO\n";





	return 0;
}

