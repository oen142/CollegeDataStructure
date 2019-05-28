#include<stdio.h>
#include<malloc.h>
typedef char element;

typedef struct tree {

	element a;
	tree *lchild;
	tree *rchild;

}tree;


tree *createBt() {
	tree *newTree = (tree *)malloc(sizeof(tree));
	newTree->a = NULL;
	newTree->lchild = NULL;
	newTree->rchild = NULL;

	return  newTree;
}

int isEmpty(tree *p) {



}
void *makeBt( char c , tree *a , tree *b) {
	tree *newTree = (tree*)malloc(sizeof(tree));
	newTree ->a= c;
	newTree->lchild = a;
	newTree->rchild = b;


}

int main(void) {


	
	return 0;

}