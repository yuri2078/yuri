#include <stdio.h>
#include "stack.h"
void createTree(Tree** tree)
{
    char ch = getchar(); // 获取数据
    getchar(); // 吃掉多余的回车
    if (ch == '#') {
        *tree = NULL; // 当他为# 则将自己变成null
        return; // 直接返回不用申请空间
    } else {
        *tree = (Tree*)calloc(1, sizeof(Tree)); // 不是# 就要存储，需要申请空间
        (*tree)->val = ch; // 存储数据
        createTree(&(*tree)->left); // 继续存储左节点
    }
    createTree(&(*tree)->right); // 当左节点处理完毕，处理右节点
}


// 二叉树前序遍历
// 遍历顺序 中 左 右
// 入栈顺序 右 左 中
void preorderTraversal(Tree* tree)
{
    SqStack stack;
	initSqStack(&stack);
    pushSqStack(&stack, tree);// 先存入根节点
    while (!isEmpty(&stack)) {
        tree = popSqStack(&stack); // 先获取栈顶数据
        if (tree) { // 如果不为null，说明还没到需要处理的地方
            // 弹出数据，重新入栈

            // 插入右节点
            if (tree->right) {
                pushSqStack(&stack, tree->right);
            }

            // 插入左节点
            if (tree->left) {
                pushSqStack(&stack, tree->left);
            }

           pushSqStack(&stack, tree); // 插入根节点
           pushSqStack(&stack, NULL); // 插入需要处理标识符 null

        } else {
            // 如果获取到了 就说明遇到需要处理的节点了
			tree = popSqStack(&stack); // 获取null前面需要处理的数据
			printf("%c", tree->val); // 存储数据
        }
    }
    printf("\n");
}

// 二叉树中序遍历
// 遍历顺序 左 中 右
// 入栈顺序 右 中 左
void inorderTraversal(Tree* tree)
{
    SqStack stack;
	initSqStack(&stack);
    pushSqStack(&stack, tree);// 先存入根节点
    while (!isEmpty(&stack)) {
        tree = popSqStack(&stack); // 先获取栈顶数据
        if (tree) { // 如果不为null，说明还没到需要处理的地方
            // 弹出数据，重新入栈

            // 插入右节点
            if (tree->right) {
                pushSqStack(&stack, tree->right);
			}

			pushSqStack(&stack, tree); // 插入根节点
            pushSqStack(&stack, NULL); // 插入需要处理标识符 null

            // 插入左节点
            if (tree->left) {
                pushSqStack(&stack, tree->left);
            }
        } else {
            // 如果获取到了 就说明遇到需要处理的节点了
			tree = popSqStack(&stack); // 获取null前面需要处理的数据
			printf("%c", tree->val); // 存储数据
        }
    }
    printf("\n");
}

// 二叉树后序遍历
// 遍历顺序 左 右 中
// 入栈顺序 中 右 左
void postorderTraversal(Tree* tree)
{
    SqStack stack;
	initSqStack(&stack);
    pushSqStack(&stack, tree);// 先存入根节点
    while (!isEmpty(&stack)) {
        tree = popSqStack(&stack); // 先获取栈顶数据
        if (tree) { // 如果不为null，说明还没到需要处理的地方

			pushSqStack(&stack, tree); // 插入根节点
            pushSqStack(&stack, NULL); // 插入需要处理标识符 null

            // 插入右节点
            if (tree->right) {
                pushSqStack(&stack, tree->right);
            }

            // 插入左节点
            if (tree->left) {
                pushSqStack(&stack, tree->left);
            }

        } else {
            // 如果获取到了 就说明遇到需要处理的节点了
			tree = popSqStack(&stack); // 获取null前面需要处理的数据
			printf("%c", tree->val); // 存储数据
        }
    }
    printf("\n");
}



int main()
{
	Tree *tree;
	createTree(&tree);
	preorderTraversal(tree);
	inorderTraversal(tree);
	postorderTraversal(tree);
    return 0;
}
