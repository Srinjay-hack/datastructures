#include<iostream>
#include<cstdlib>
#include "BST.h"
using namespace std;

BST::BST()
{
	root=NULL;
}
BST::node* BST::CreateLeaf(int key){

   node* n=new	node;
   n->key	=	key;
   n->left	=	NULL;
   n->right =	NULL;
   return n;



}
void BST::AddLeaf(int key)
{
	AddLeafPrivate(key,root);

}
void BST::AddLeafPrivate(int key,node* Ptr){
	if(root==NULL){

		root=CreateLeaf(key);
	}
	else if(key<Ptr->key){
		if(Ptr->left!=NULL)
		{
			AddLeafPrivate(key,Ptr->left);

		}
		else{
			Ptr->left 	=	CreateLeaf(key);
		}
	}
	else if(key>Ptr->key){
		if(Ptr->right!=NULL)
		{
			AddLeafPrivate(key,Ptr->right);

		}
		else{
			Ptr->right 	=	CreateLeaf(key);
		}
	}
	else{
		 cout<<"The key is"<<key<<" has already added "; 
	}  

}

void BST::PrintinOrder(){

    PrintinOrderPrivate(root);

}

void BST::PrintinOrderPrivate(node* Ptr){
	if(root!=NULL){
		if(Ptr->left!= NULL){
			PrintinOrderPrivate(Ptr->left);
		} 
		cout<<Ptr->key<<" ";
		if(Ptr->right!= NULL){
			PrintinOrderPrivate(Ptr->right);
		}


	}
	else{
		cout<<"The tree is empty"<<endl;
	}
}


BST::node* BST::ReturnNode(int key){


	return ReturnNodePrivate(key,root);
}
BST::node* BST::ReturnNodePrivate(int key,node* Ptr){

	if(Ptr!=NULL)
	{
		if(Ptr->key == key){
			return Ptr;
		} 
		else{

			if(key< Ptr->key){
				return ReturnNodePrivate(key,Ptr->left);
			}
			else{
				return ReturnNodePrivate(key,Ptr->right);
			}
		}
		
	}
	else{
			return NULL;
		}

}
int BST::ReturnRootKey(){
	if(root!=NULL){
		return root->key;
	}
	else{
		return -1000;
	}
}


void BST::PrintChildren(int key){

	node* Ptr=ReturnNode(key);
	if(Ptr!= NULL){
		cout<<"Parent Node ="<<Ptr->key<<endl;
		Ptr->left==NULL?
		cout<<"Left Child = NULL\n":
		cout<<"Left Child ="<<Ptr->left->key<<endl;
		Ptr->right==NULL?
		cout<<"Right Child = NULL\n":
		cout<<"Right Child ="<<Ptr->right->key<<endl;

	}
	else{
		cout<<"Key is not in tree";
	}
}
int BST::FindSmallest(){
	return FindSmallestPrivate(root);

}
int BST::FindSmallestPrivate(node* Ptr){

	if(root==NULL){
		cout<<"Tree is empty";
		return -1000;
	}
	else{
		if(Ptr->left!=NULL){
			return FindSmallestPrivate(Ptr->left);
		}
		else{
			return Ptr->key;
		}
	}


}
void BST::RemoveNode(int key){

	return RemoveNodePrivate( key,root);

}

void BST::RemoveNodePrivate(int key,node* parent)
{
	if(root!=NULL){

		if(root->key==key){
			RemoveRootMatch();
		}
		else{
			if(key < parent->key && parent->left!=NULL){
				parent->left->key == key?
				RemoveMatch(parent, parent->left, true):
				RemoveNodePrivate(key,parent->left);

			}
			else if(key>parent->key && parent->right!=NULL){
				parent->right->key  == key ?
				RemoveMatch(parent,parent->right,false):
				RemoveNodePrivate(key,parent->right);

			}
			else{
				cout<<"The Key was not found "<<endl;
			}

		}

	}
	else{
		cout<<"The tree is empty"<<endl;
	}

}

void BST::RemoveRootMatch(){

	if(root!=NULL){
		node* delPtr=root;
		int rootKey=root->key;
		int smallestInRightSubtree;

		// Case 0-0

		if(root->left==NULL && root->right==NULL){
			root=NULL;
			delete delPtr;

		}
		//Case 1-1 child
		else if(root->left==NULL && root->right!=NULL){
			root=root->right;
			delPtr->right=NULL;
			delete delPtr;
			cout<<"The root node is deleted "<<" new root "<<root->key<<endl;
		}

		else if(root->left!=NULL && root->right==NULL){
			root=root->left;
			delPtr->left=NULL;
			delete delPtr;
			cout<<"The root node is deleted "<<" new root "<<root->key<<endl;
		}
		//Case 2-2 Children
		else{
			smallestInRightSubtree=FindSmallestPrivate(root->right);
			RemoveNodePrivate(smallestInRightSubtree,root);
			root->key=smallestInRightSubtree;
			cout<<"The root key containing key "<<rootKey<<" was overwritten with "<<root->key<<endl;

		}

	}
	else{
		cout<<"Cannot remove root"<<endl;
	}
}


void BST::RemoveMatch(node* parent,node* match, bool left){
   
   if(root!=NULL){

   	node* delPtr;
   	int matchKey=match->key;
   	int smallestInRightSubtree;

   	//case 0-0 children
   	if (match->left == NULL && match->right == NULL){
   		delPtr=match;
   		left=true?parent->left=NULL:parent->right=NULL;
   		delete delPtr;
   		cout<<"The node containing key "<<matchKey<<" was removed \n";

   	}
   	//case  1-1 child

   	else if(match->left == NULL && match->right!=NULL){
   		left=true? parent->left = match->right 	:	parent->right=match->right;
   		match->right=NULL;
   		delPtr =match;
   		delete	delPtr;
   		cout<<"The node containing	Key "<<matchKey<<" was removed \n";

   	}
   	else if(match->left != NULL && match->right == NULL){
   		left=true? parent->left = match->left 	:	parent->right=match->left;
   		match->left=NULL;
   		delPtr = match;
   		delete	delPtr;
   		cout<<"The node containing	Key "<<matchKey<<" was removed \n";

   	}
   	//case 2-2 child
   	else{
   		smallestInRightSubtree=FindSmallestPrivate(match->right);
   		RemoveNodePrivate(smallestInRightSubtree,match);
   		match->key=smallestInRightSubtree;

   	}

   }
   else{
   	cout<<"Cannot remove match the tree is empty"<<endl;
   }

}