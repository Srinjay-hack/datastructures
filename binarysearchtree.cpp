#include<iostream>
#include<cstdlib>
using namespace std;
void init_code(){
	
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif	
}
struct Node{
	int data;
	Node  *left, *right;
	Node(int val){

		data=val;
		left=NULL;
		right=NULL;

	}

};

//INSERT
Node* insertBST(Node *root, int val){
	if(root == NULL){

		return new Node(val);
	}
	if(val < root->data){
		root->left=insertBST(root->left,val);

	}
	else{
		root->right=insertBST(root->right,val);
	}
	return root;

}
//SEARCH

Node* searchInBST(Node* root,int key){
    if(root == NULL){
    	return root;
    }

	if(root->data == key){
		return root;

	}
	if(root->data > key){
		return searchInBST(root->left,key);
	}
	return searchInBST(root->right ,key);
 
}

bool isBST(Node* root, Node* min=NULL, Node* max=NULL){
	if(root == NULL)
	{
		return true;
	}


	if(min!=NULL && root->data <= min->data){
		return false;

	}
	if(max!=NULL && root->data >= max->data){
		return false;
	}
	bool leftValid = isBST(root->left , min,root);
	bool rightValid = isBST(root->right,root,max);
	return leftValid and rightValid;
}


//PRINT INORDER

void inorder(Node *root){
	if(root == NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data <<" ";
	inorder(root->right);
}

Node* inorderSucc(Node* root){
	Node* curr = root;
	while(curr && curr->left != NULL){
		curr =curr->left;
	}
	return curr;
}
//DELETE
Node* deleteInBST(Node *root, int key){

	if(key < root->data){
		root->left=deleteInBST(root->left,key);
	}
	else if(key > root->data){
		root->right = deleteInBST(root->right,key);
	}
	else{
		if(root->left == NULL){
			Node* temp= root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL){

			Node* temp = root->left;
			free(root);
			return temp;
		}
		//case  3
		Node* temp = inorderSucc(root->right);
		root->data = temp->data;
		root->right = deleteInBST(root->right, temp->data );


	}
	return root;


}


int main(){


	init_code();
	Node* root =NULL;
	root=insertBST(root,5);
	insertBST(root,1);
	insertBST(root,3);
	insertBST(root,4);
	insertBST(root,2);
	insertBST(root,7);
	insertBST(root,9);

	//print in order

	inorder(root);
	cout<<endl;
	//search
	if(searchInBST(root,10) == NULL){
		cout<<"key doesnt exist"<<endl;
	}
	else{
		cout<<"key exists"<<endl;
	}

	root= deleteInBST(root,3);
	inorder(root);


	if(isBST(root,NULL,NULL)){
		cout<<"Valid"<<endl;

	}
	else{
		cout<<"INvalid BST";
	}
	return 0;
}