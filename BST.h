class BST{
private:
	struct node{
		int key;
		node* left;
		node* right;


	};

	node* root;
	void AddLeafPrivate(int key,node* Ptr);
	void PrintinOrderPrivate(node* Ptr);
	node* ReturnNodePrivate(int key,node* Ptr);
    int FindSmallestPrivate(node* Ptr);
    void RemoveNodePrivate(int key,node* parent);
    void RemoveRootMatch();
    void RemoveMatch(node* parent,node* match, bool left);

public:
	BST();
	node* CreateLeaf(int key);

	void AddLeaf(int key);
	void PrintinOrder();
	node* ReturnNode(int key);
	int ReturnRootKey();
    void PrintChildren(int key);
    int FindSmallest();
    void RemoveNode(int key);

   



};