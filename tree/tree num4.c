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
void addHnode(NODE *tree) {
	NODE *Left = NULL, *Right = NULL;
	getNode(&Left); getNode(&Right);
	int l, m, r;
	scanf("%d %d %d", &m, &l, &r);
	tree->num = m;
	Left->num = l;
	Right->num = r;
	tree->left = Left;
	tree->right = Right;
}
void find(NODE *p,int m,NODE **Find) {
	if (p != NULL) {
		if (p->num == m) {
			*Find = p;
			return;
		}
		find(p->left, m, &(*Find));
		find(p->right, m, &(*Find));
	}
}
void addnode(NODE *p) {
	NODE *Left = NULL, *Right = NULL, *Find = NULL;
	getNode(&Left); getNode(&Right);
	int l, m, r;
	scanf("%d %d %d", &m, &l, &r);
	find(p, m,&Find);
	if (l != 0) {
		Left->num = l;
		Find->left = Left;
	}
	if (r != 0) {
		Right->num = r;
		Find->right = Right;
	}
}
int main() {
	NODE *tree = NULL,*p; getNode(&tree);
	int n, i, j;
	char str[101] = "";
	scanf("%d", &n);
	for (i = 0;i < n;i++) {
		if (i == 0)
			addHnode(tree);
		else
			addnode(tree);
	}
	scanf("%d", &n);
	for (i = 0;i < n;i++) {
		getchar();
		scanf("%s", str);
		printf(" %d", tree->num);
		p = tree;
		for (j = 0;j < strlen(str);j++) {
			if (str[j] == 'R') {
				p = p->right;
				printf(" %d", p->num);
			}
			else if (str[j] == 'L') {
				p = p->left;
				printf(" %d", p->num);
			}
		}
		printf("\n");
	}
	return 0;
}
