#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct Tree
{
	int num;
	struct Tree* left;
	struct Tree* right;
}Tree;

typedef struct Root
{
	Tree* root;
}Root;

void print_post(Tree* root);
void insert_node(Root* node, int num);
void search_node(Tree* node, int num);
void init_Root(Root* root);

void init_Root(Root* root)
{
	root->root = NULL;
}

void print_post(Tree* root)
{
	if (root->left)
		print_post(root->left);
	if (root->right)
		print_post(root->right);
	cout << root->num << '\n';
}

void insert_node(Root* root, int num)
{
	if (root->root == NULL)
	{
		Tree* node = (Tree*)malloc(sizeof(Tree));
		node->num = num;
		node->right = NULL;
		node->left = NULL;
		root->root = node;
	}
	else
		search_node(root->root, num);
}

void search_node(Tree* node, int num)
{
	if (node->num > num)
	{
		if (node->left == NULL)
		{
			Tree* temp = (Tree*)malloc(sizeof(Tree));
			temp->num = num;
			temp->left = NULL;
			temp->right = NULL;
			node->left = temp;
		}
		else
			search_node(node->left, num);
	}
	else
	{
		if (node->right == NULL)
		{
			Tree* temp = (Tree*)malloc(sizeof(Tree));
			temp->num = num;
			temp->left = NULL;
			temp->right = NULL;
			node->right = temp;
		}
		else
			search_node(node->right, num);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	Root root;
	init_Root(&root);

	while (cin >> N)
	{
		insert_node(&root, N);
	}
	print_post(root.root);
	return 0;
}