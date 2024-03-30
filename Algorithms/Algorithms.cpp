#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <time.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

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

void print_current_level(struct node* node, int i)
{
	if (node == NULL)
		return;
	if (i == 1) {
		printf("%d ", node->data);
	}
	else {
		print_current_level(node->left, i - 1);
		print_current_level(node->right, i - 1);
	}
}

void print_level_order(struct node* root)
{
	int max_l = max_level(root);
	printf("max-level: %d\n", max_l);
	for (int i = 1; i <= max_l; ++i) {
		print_current_level(root, i);
		printf("\n");
	}

	printf("  \n");
}

struct node* new_node(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->left = NULL;
	node->right = NULL;
	node->data = data;
	return node;
}

#define MAX_QUEUE 50

struct queue {
	struct node* q[MAX_QUEUE];
	int tail;
	int front;
};

void enqueue(struct queue* Q, struct node* data)
{
	Q->q[Q->tail] = data;
	if (Q->tail == MAX_QUEUE - 1)
		Q->tail = 0;
	else
		++(Q->tail);
}

struct node* dequeue(struct queue* Q)
{
	struct node* data = Q->q[Q->front];
	if (Q->front == MAX_QUEUE - 1)
		Q->front = 0;
	else
		++(Q->front);
	return data;

}

struct node* top(struct queue* Q)
{
	return Q->q[Q->front];
}

void print_level_order_using_queue(struct node* node)
{
	struct queue my_queue;
	struct node* tmp = node;
	my_queue.front = 0; 
	my_queue.tail = 0;

	enqueue(&my_queue, node);
	while (my_queue.front != my_queue.tail) {
		printf("%d ", tmp->data);
		if (tmp->left)
			enqueue(&my_queue, tmp->left);
		if (tmp->right)
			enqueue(&my_queue, tmp->right);

		tmp = dequeue(&my_queue);
		printf("\n");
	}
	printf("\n");
}

int main(int argc, char** argv)
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

	print_level_order(root);
	print_level_order_using_queue(root);

	return 0;
}

