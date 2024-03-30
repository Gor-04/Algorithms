#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* new_node(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->left = NULL;
	node->right = NULL;
	node->data = data;
	return node;
}
void Inorder(struct node* node)
{
	if (node == NULL)return;

	Inorder(node->left);
	printf("%d ", node->data);
	Inorder(node->right);
}

void Preorder(struct node* node)
{
	if (node == NULL)return;
	printf("%d ", node->data);
	Preorder(node->left);
	Preorder(node->right);
}

void Postorder(struct node* node)
{
	if (node == NULL)return;
	Postorder(node->left);
	Postorder(node->right);
	printf("%d ", node->data);
}
int max_level(struct node* n)
{
	if (n == NULL)
		return 0;
	int left = max_level(n->left);
	int right = max_level(n->right);
	if (left > right)
		return left + 1;
	else
		return right + 1;
}
void current_level(struct node* node, int i)
{
	if (node == NULL)
		return;
	if (i == 1) {
		printf("%d ", node->data);
	}
	else {
		current_level(node->left, i - 1);
		current_level(node->right, i - 1);
	}
}

void Levelorder(struct node* root)
{
	int max_l = max_level(root);
	printf("max-level: %d\n", max_l);
	for (int i = 1; i <= max_l; ++i) {
		current_level(root, i);
		printf("\n");
	}

	printf("  \n");
}
int main()
{

	struct node* root = new_node(1);
	struct node* r_l = new_node(2);
	struct node* r_r = new_node(3);
	struct node* r_l_r = new_node(5);
	struct node* r_r_l = new_node(6);
	struct node* r_r_l_l = new_node(9);
	struct node* r_r_r = new_node(7);

	root->left = r_l;
	root->right = r_r;
	r_l->right = r_l_r;
	r_r->left = r_r_l;
	r_r->right = r_r_r;
	r_r_l->left = r_r_l_l;
	printf(" Inorder is : ");
	Inorder(root);
	printf("\n Preorder is : ");
	Preorder(root);
	printf("\n Postorder is : ");
	Postorder(root);
	printf("\n Levelorder is : ");
	Levelorder(root);
}
