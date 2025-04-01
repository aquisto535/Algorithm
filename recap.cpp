#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode
{
	TreeNode* RightSubTreeNode;
	TreeNode* LeftSubTreeNode;
	int data;

}TreeNode;

TreeNode* MakeTreeNode()
{
	TreeNode* Tree = (TreeNode*)malloc(sizeof(TreeNode));

	return Tree;
}

void SetTreeData(TreeNode* node, int nData)
{
	node->data = nData;
}

void FrontSearchTreeNode(TreeNode* node)
{
	printf("%d", node->data);
	SearchLeftSubTreeNode(node);
	SearchRightSubTreeNode(node);

}

void SearchLeftSubTreeNode(TreeNode* node)
{
	if (node == NULL)
		return;

	printf("%d", node->data);
	SearchLeftSubTreeNode(node->LeftSubTreeNode);

}

void SearchRightSubTreeNode(TreeNode* node)
{
	if (node == NULL)
		return;

	printf("%d", node->data);
	SearchRightSubTreeNode(node->RightSubTreeNode);

}

void main()
{
	TreeNode* TreeNode1 = MakeTreeNode();
	TreeNode* TreeNode2 = MakeTreeNode();
	TreeNode* TreeNode3 = MakeTreeNode();
	TreeNode* TreeNode4 = MakeTreeNode();
	TreeNode* TreeNode5 = MakeTreeNode();

	SetTreeData(TreeNode1, 1);
	SetTreeData(TreeNode2, 2);
	SetTreeData(TreeNode3, 3);
	SetTreeData(TreeNode4, 4);
	SetTreeData(TreeNode5, 5);







}