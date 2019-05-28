#include <stdio.h>
#include <stdlib.h>


typedef struct treeNode {

	int number;
	struct treeNode *lchild;
	struct treeNode *rchild;

}treeNode;


treeNode *createNode(int size, treeNode *lNode, treeNode *rNode) {
	treeNode *p = (treeNode *)malloc(sizeof(treeNode));
	p->number = size;

	p->lchild = lNode;

	p->rchild = rNode;
	return p;

}

int afterSum(treeNode *root) {
	treeNode *p = root;
	if (p != NULL) {
		return p->number + afterSum(p->lchild) + afterSum(p->rchild);
	}
	else if (p == NULL) {
		return 0;
	}


}
int main(void) {

	treeNode *n7 = createNode(120, NULL, NULL);
	treeNode *n6 = createNode(30, n7, NULL);
	treeNode *n5 = createNode(50, NULL, NULL);
	treeNode *n4 = createNode(70, NULL, NULL);
	treeNode *n3 = createNode(55, NULL, n6);
	treeNode *n2 = createNode(80, n4, n5);
	treeNode *n1 = createNode(120, n2, n3);

	printf("%d", afterSum(n1));
	return 0;
}