#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
	char val;
	int weight;
	struct Tree* left;
	struct Tree* right;
} Tree;

int myComp(const void* x, const void* y){
	return ((Tree *)x)->weight < ((Tree*)y)->weight;
}


Tree* createHff(Tree* tree, int n)
{
	if (n == 1) {
		return tree;
	}
	while (n >= 2) {
		qsort(tree, n, sizeof(Tree), myComp);
		Tree node;
		node.val = 0;
		node.weight = tree[n - 1].weight + tree[n - 2].weight;
		node.left = &tree[n - 1];
		node.right = &tree[n - 2];
		tree[n - 2].val = node.val;
		tree[n - 2].left = node.left;
		tree[n - 2].right = node.right;
		n--;
    }
	return tree;
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

int main(void)
{
	int n;
	scanf("%d", &n);
	getchar();
	Tree tree[n];
	for (int i = 0; i < n; i++) {
		scanf("%c,%d", &tree[i].val, &tree[i].weight);
		getchar();
	}

	createHff(tree, n);
	// lecel(tree);
	putchar('\n');
    return 0;
}