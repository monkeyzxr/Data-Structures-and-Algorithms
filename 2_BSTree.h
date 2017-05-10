#ifndef BSTREE_H
#define BSTREE_H

struct Node
	{
	int     Val;
	Node *  LChild;
	Node *  RChild;
	};

class BSTree
	{
	public:
		        BSTree       ();
			    ~BSTree      ();
		Node *  NewNode      (int);
		void    InOrder      (Node *);
		Node *  InsertNode   (Node *, int);
		Node *  MinValueNode (Node *);
		Node *  DeleteNode   (Node *, int);
	public:
		Node * root;
	};

BSTree::BSTree ()
	{
	root = NULL;
	}

BSTree::~BSTree ()
	{
	}

Node * BSTree::NewNode (int key)
	{
	Node * Tmp = new (Node);
	(*Tmp).Val = key;
	(*Tmp).LChild = (*Tmp).RChild = NULL;

	return Tmp;
	}

void BSTree::InOrder (Node * root)
	{
	if (root == NULL)
		return;
	InOrder ((*root).LChild);
	cout << (*root).Val << endl;
	InOrder ((*root).RChild);
	}

Node * BSTree::InsertNode (Node * node, int key)
	{
	if (node == NULL)
		return NewNode(key);
	else
		if (key < (*node).Val)
			(*node).LChild = InsertNode((*node).LChild, key);
		else
			if (key > (*node).Val)
				(*node).RChild = InsertNode((*node).RChild, key);
	return node;
	}

Node * BSTree::MinValueNode (Node * node)
	{
	Node * Tmp = node;
	while ((*Tmp).LChild != NULL)
		Tmp = (*Tmp).LChild;
	return Tmp;
	}

Node * BSTree::DeleteNode (Node * root, int key)
	{
	if (root == NULL)
		return root;
	if (key == (*root).Val)
		{
		if ((*root).LChild == NULL)
			{
			Node * Tmp = (*root).RChild;
			free (root);
			return Tmp;
			}
		else
			if ((*root).RChild == NULL)
				{
				Node * Tmp = (*root).LChild;
				free (root);
				return Tmp;
				}
		Node * Tmp =MinValueNode ((*root).RChild);  //get successor
		(*root).Val = (*Tmp).Val;
		(*root).RChild = DeleteNode ((*root).RChild, (*Tmp).Val);
		}
	else
		if (key < (*root).Val)
			(*root).LChild = DeleteNode ((*root).LChild, key);
		else
			if (key > (*root).Val)
				(*root).RChild =DeleteNode ((*root).RChild,key);
	return root;
	}



#endif
