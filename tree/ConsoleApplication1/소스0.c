#include <stdio.h>
#include <stdlib.h>


typedef struct treeNode {

	int number;
	struct treeNode *lchild;
	struct treeNode *rchild;

}treeNode;


treeNode *createNode( int number) {
	treeNode *p = (treeNode *)malloc(sizeof(treeNode));
	
	p->number = number;
	
	p->lchild = NULL;
	p->rchild = NULL;
	return p;

}
treeNode * searchNode(treeNode *root , int key) {

	if (root == NULL) {
		return NULL;
	}
	if (root->number < key) {

		root->rchild =  searchNode(root->rchild, key);

	}
	else if(root->number>key) {
		root ->lchild = searchNode(root->lchild, key);
	}
	else if (root->number == key) {
		printf("%d 를 찾았습니다.", key);
		return root;
	}


}
//treeNode * deleteNode() {
//
//}

treeNode *insertNode ( int key ,treeNode *insert ) {
	if (insert == NULL) {
		treeNode *newNode = createNode(key);
		return newNode;
	}
	if (key < insert->number) {
		insert->lchild = insertNode(key, insert->lchild);
	}
	else if (key > insert->number) {
		insert->rchild = insertNode(key, insert->rchild);
	}
	else if (key == insert->number) {
		printf("같은 값이 있습니다.");
	
	}


	return insert;

}

void printNode(treeNode *root) {
	treeNode *p = root;
	if (p) {
	
		printNode(p->lchild);
		printf("%d\n", p->number);
		printNode(p->rchild);
	}


}
int main(void) {

	treeNode *root = createNode(8);
	insertNode(3, root);
	insertNode(5, root);
	insertNode(6, root);
	insertNode(10, root);
	insertNode(12, root);
	insertNode(13, root);

//	printf("%d" , searchNode(root, 12));

	printNode(root);
	return 0;
}