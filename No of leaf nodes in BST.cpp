#include<iostream>
#include<list>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;	
};

Node* insert(Node* root, int data)
{
	if(!root){
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
	{
		root->left=  insert(root->left, data);
	}
	else if(data > root->data)
	{	
		root->right = insert(root->right, data);
	}
	return root;
}

void inorder(Node* root)
{
	if(!root) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int Noleafnodes(Node* root)
{
	int total=0;
	struct Node* s;
	list<Node*> queue;
	queue.push_back(root);
	while(!queue.empty())
	{
		s = queue.front();
		queue.pop_front();
		if(s->left!=NULL){
			queue.push_back(s->left);
		}
		if(s->right!=NULL){
			queue.push_back(s->right);
		}
		if(s->right==NULL && s->left==NULL)
		total++;
	}
	return total;
}
int main()
{
	int Number_of_leafNodes;
	Node* root = NULL;
	root = insert(root,5); root = insert(root,10);
	root = insert(root,3); root = insert(root,4); 
	root = insert(root,1); root = insert(root,11);
	Number_of_leafNodes = Noleafnodes(root);
	cout<<"Number of leaf Nodes are: "<<Number_of_leafNodes;
	return 0;
}
