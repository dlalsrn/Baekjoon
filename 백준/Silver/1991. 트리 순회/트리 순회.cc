#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <stdlib.h>
using namespace std;

typedef struct BAEK_1991_tree
{
	struct BAEK_1991_tree* left;
	char alpha;
	struct BAEK_1991_tree* right;
}Tree;

void Print_tree_pre(Tree*head)
{
	cout << head->alpha;
	if (head->left != NULL)
		Print_tree_pre(head->left);
	if (head->right != NULL)
		Print_tree_pre(head->right);
}

void Print_tree_in(Tree*head)
{
	if (head->left != NULL)
		Print_tree_in(head->left);
	cout << head->alpha;
	if (head->right != NULL)
		Print_tree_in(head->right);
}

void Print_tree_post(Tree*head)
{
	if (head->left != NULL)
		Print_tree_post(head->left);
	if (head->right != NULL)
		Print_tree_post(head->right);
	cout << head->alpha;
}
Tree* Add_Node(char a)
{
	Tree*temp = (Tree*)malloc(sizeof(Tree));
	temp->alpha = a;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void Node(Tree*head, char a, char b, char c)
{
	if (head->alpha == a)
	{
		if (b != '.')
			head->left = Add_Node(b);
		if (c != '.')
			head->right = Add_Node(c);
	}
	else
	{
		if (head->left != NULL)
			Node(head->left, a, b, c);
		if (head->right != NULL)
			Node(head->right, a, b, c);
	}
}

int main(void)
{
	int N;
	Tree * head = (Tree*)malloc(sizeof(Tree));
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char a, b, c;
		cin >> a >> b >> c;
		if (i == 0)
		{
			head->alpha = a;
			if (b != '.')
				head->left = Add_Node(b);
			if (c != '.')
				head->right = Add_Node(c);
		}
		else
			Node(head, a, b, c);
	}
	Print_tree_pre(head);
	cout << "\n";
	Print_tree_in(head);
	cout << "\n";
	Print_tree_post(head);
    return 0;
}