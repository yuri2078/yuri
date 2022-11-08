#include <stdlib.h>
#include <stdio.h>

typedef struct {
	char e;
	struct Tree* left;
	struct Tree* right;
	
}Tree;

void initTree(Tree* tree)
{
	tree = (Tree*)malloc(sizeof(Tree));
	tree->e = 'A';
	
}

int main(int argc, const char *argv[])
{
    Tree *tree;
    return 0;
}


