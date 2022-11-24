#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
	char val;
	struct Tree* left;
	struct Tree* right;
} Tree;

void createTree(Tree** tree)
{
	char ch = getchar(); 
	getchar(); 
	if (ch == '#') {
		*tree = NULL; 
		return;
	} else {
		*tree = (Tree*)calloc(1, sizeof(Tree));
		(*tree)->val = ch; 
		createTree(&(*tree)->left); 
	}
	
	createTree(&(*tree)->right);
}

void lecel(Tree *tree)
{
    Tree *queue[100];
    int front = 0, back = 0, size = 1;
    if(tree == NULL){
        return;
    }
    queue[back++] = tree;
    while(size){
        int k = size;
        for (int i = 0; i < k; i++){
            Tree *node = queue[front++];
            size--;
            printf("%c", node->val);

            if(node->left){
                queue[back++] = node->left;
                size++;
            }

            if(node->right){
                queue[back++] = node->right;
                size++;
            }
        }
    }
}

int main()
{
    Tree *tree;
    createTree(&tree);
    lecel(tree);
}
