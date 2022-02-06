#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node {
	struct node *left;
	struct node *right;
	int num;
};
typedef struct node NODE;
void getNode(NODE **p) {
	(*p) = (NODE *)malloc(sizeof(NODE));
	(*p)->left = NULL;
	(*p)->right = NULL;
}
void preorder(NODE *p) {
	if (p != NULL) {
		printf(" %d", p->num);
		preorder(p->left);
		preorder(p->right);
	}
}
void inorder(NODE *p) {
	if (p != NULL) {
		inorder(p->left);
		printf(" %d", p->num);
		inorder(p->right);
	}
}
void postorder(NODE *p) {
	if (p != NULL) {
		postorder(p->left);
		postorder(p->right);
		printf(" %d", p->num);
	}
}
int main() {
	NODE **tree = NULL;
	tree = (NODE *)malloc(sizeof(NODE *) * 8);
	int i, n;
	for (i = 0;i < 8;i++) {
		getNode(&tree[i]);
		if (i == 0)
			tree[i]->num = 20;
		else if (i == 1)
			tree[i]->num = 30;
		else if (i == 2)
			tree[i]->num = 50;
		else if (i == 3)
			tree[i]->num = 70;
		else if (i == 4)
			tree[i]->num = 90;
		else if (i == 5)
			tree[i]->num = 120;
		else if (i == 6)
			tree[i]->num = 130;
		else if (i == 7)
			tree[i]->num = 80;
	}
	tree[0]->left = tree[1]; tree[0]->right = tree[2];
	tree[1]->left = tree[3]; tree[1]->right = tree[4];
	tree[2]->right = tree[5];
	tree[5]->left = tree[6];tree[5]->right = tree[7];
	scanf("%d %d", &n,&i);
	if (i >= 1 && i <= 8) {
		if (n == 1)
			preorder(tree[i - 1]);
		else if (n == 2)
			inorder(tree[i - 1]);
		else
			postorder(tree[i - 1]);
	}
	else
		printf("-1\n");
	return 0;
}
