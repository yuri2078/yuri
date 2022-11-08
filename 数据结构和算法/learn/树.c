#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int e;
	struct Tree* left;
	struct Tree* right;
}Tree;

void createTree(Tree* tree, int *array, int size)
{
	tree = (Tree*)malloc(sizeof(Tree));
	
	
}

int main(int argc, const char *argv[])
{
	Tree* tree;
	int array[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	createTree(tree, array, 9);
	
    return 0;
}


