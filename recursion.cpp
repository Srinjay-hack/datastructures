#include<iostream>
#include<cstdlib>
using namespace std;
void init_code(){
	
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif	
}

void recurr(int n){

	if (n==1){
		cout<<n<<" ";
		return ;
	}
	//cout<<n<<" "; Reverse loop

	recurr(n-1);
	cout<<n<<" ";
	
}


int main(){
	init_code();


	int n;
	n=7;
	recurr(n);



	return 0;
}