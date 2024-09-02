class Node
{
public:
	int value;
	Node* left;
	Node* right;
	Node()
	{
		value = 0;
		left = right = NULL;
	}
	Node(int val, Node* l, Node* r)
	{
		value = val;
		left = l;
		right = r;
	}
};


class BST
{
	Node* root;
public:

	BST()
	{
		root = NULL;
	}

	void addValue(int value)
	{
		if (search(value))return;
		Node* n = new Node(value, NULL, NULL);
		if (root == NULL)
		{
			root = n;
			return;
		}
		Node* p = root;

		//getting last node

		while (true)
		{//p stands at the root
			if (value > p->value)
			{
				if (p->right == NULL)break;
				p = p->right;
			}
			else
			{
				if (p->left == NULL)break;
				p = p->left;
			}
		}
		//p stands at the last node 
		if (value > p->value)
		{
			p->right = n;
		}
		else
		{
			p->left = n;
		}
	}

	bool search(int value)
	{
		Node* p = root;
		while (p != NULL)
		{
			if (p->value == value)return true;
			if (value > p->value)
				p = p->right;
			else
				p = p->left;
		}
		return false;
	}

	void DFS(Node* n)   //to visit all tree elements from leafs
	{
		if (n == NULL)return;

		//print sub left tree
		DFS(n->left);

		//print root
		cout << n->value << " -> ";

		//print sub right tree
		DFS(n->right);
	}

	void print()
	{
		DFS(root);
	}

	void BFS()		    //to visit all tree elements from root
	{
		queue <Node*> myQueue;
		myQueue.push(root);
		while (myQueue.empty() == false){
			cout << myQueue.front()->value << endl;
			if (myQueue.front()->left != NULL){
				myQueue.push(myQueue.front()->left);
			}
			if (myQueue.front()->right != NULL){
				myQueue.push(myQueue.front()->right);
			}
			myQueue.pop();
		}
	}

	void deleteBST(int value)
	{
		Node* p = root;
		Node* parent = NULL;

		//to get the wanted value
		while (p != NULL) {
			if (p->value == value)break;
			parent = p;
			if (value > p->value)
				p = p->right;
			else
				p = p->left;
		}
		//case 1 : the node is not exesting to be deleted
		if (p == NULL)return;

		//case 2 : a node with no children
		if (p->left == NULL && p->right == NULL) {
			//to know if it is on the right or left from parent
			if (p->value > parent->value) {
				parent->right = NULL;
			}
			else {
				parent->left = NULL;
			}
			delete p;
			return;
		}

		// case 3 : a node with no left child
		if (p->left == NULL) {
			if (p->value > parent->value) {
				parent->right = p->right;
			}
			else {
				parent->left = p->right;
			}
			delete p;
			return;
		}

		// case 4 : a node with no right child
		if (p->right == NULL) {
			if (p->value > parent->value) {
				parent->right = p->left;
			}
			else {
				parent->left = p->left;
			}
			delete p;
			return;
		}

		//case 5 : the node is the root it's self or
		//case 6 : a node with two children

		//to get the nearest value of the deleted point
		//we will get the smalest one one it's right

		if (p->right != NULL && p->left != NULL) {
			Node* p1 = p->right;

			//getting smallest value on right
			if (p1->left == NULL) {
				parent = p1;
				p->value = p1->value;
				p->right = parent->right;
				delete p1;
			}
			else {
				while (p1->left != NULL) {
					parent = p1;
					p1 = p1->left;
				}
				p->value = p1->value;
				parent->left = nullptr;
				delete p1;

			}
		}

	}
};


int main()
{
	BST myTree;
	myTree.addValue(50);
	myTree.addValue(40);
	myTree.addValue(45);
	myTree.addValue(47);
	myTree.addValue(43);
	myTree.addValue(30);
	myTree.addValue(42);
	myTree.addValue(41);
	myTree.addValue(55);
	myTree.addValue(60);
	myTree.addValue(57);
	myTree.addValue(66);


	myTree.print();
	cout << "\n\n";

	//Delete Cases:

	//case 1: not exist
	//myTree.deleteBST(100);

	//case 2: no child
	//myTree.deleteBST(30);

	//case 3: no left child
	//myTree.deleteBST(45);

	//case 4: no right child
	//myTree.deleteBST(60);

	//case 5: the root
	//myTree.deleteBST(50);

	//case 6: with 2 childeren
	//myTree.deleteBST(40);


	myTree.print();
	cout << "\n\n";
	return 0;
}