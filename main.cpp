#include<iostream>
#include<cstdlib>
#include "BST.cpp"
using namespace std;
void init_code(){
	
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif	
}

int main(){
	init_code();
	int TreeKeys[16]={50,76,21,4,32,64,15,52,14,100,83,2,3,78,87,80};
	BST myTree;
	int input=0;

	cout<<"Print tree in order\n Before adding number\n";
	myTree.PrintinOrder();
	for(int i=0;i<16;i++){
		myTree.AddLeaf(TreeKeys[i]);
	}
	cout<<"Print tree in order\n After adding number\n";
	myTree.PrintinOrder();

	myTree.PrintChildren(myTree.ReturnRootKey());
	cout<<endl;
    

	for(int i=0;i<16;i++){
		myTree.PrintChildren(TreeKeys[i]);
		cout<<endl;
	}
    cout<<"The smallest value in tree is "<<myTree.FindSmallest()<<endl;


    cout<<"Enter the key to be deleted Stop =-1"<<endl;

    while(input!=-1){
    	cout<<"Delete node :";
    	cin>>input;
    	{
    		if(input!=-1){
    			cout<<endl;
    			myTree.RemoveNode(input);
    			myTree.PrintinOrder();
    			cout<<endl;
    		}
    	}

    }

    



	return 0;
}