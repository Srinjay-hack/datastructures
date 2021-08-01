
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
    int t;
    cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;

        if(a>b)
            swap(a,b);
        if(a==b)
            cout<<"0 0\n";
        else{

            long long x=abs(a-b);
            long long y=a%x;
            y=min(y,x-y);

            cout<<x<<" "<<y<<endl;
        }

    }
   




	return 0;
}

