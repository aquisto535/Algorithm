#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree2.h"

BTreeNode * MakeBTreeNode(void)
{
    BTreeNode * nd = (BTreeNode*)malloc(sizeof(BTreeNode));

    if (nd == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    nd->left = NULL;
    nd->right = NULL;
    return nd;
}

BTData GetData(BTreeNode * bt)
{
    return bt->data;
}

void SetData(BTreeNode * bt, BTData data)
{
    bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt)
{
    return bt->left;
}

BTreeNode * GetRightSubTree(BTreeNode * bt)
{
    return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
    if(main->left != NULL)
        free(main->left);

    main->left = sub;
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
    if(main->right != NULL)
        free(main->right);

    main->right = sub;
}

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action) //전위 순회
{
    if(bt == NULL)
        return;

    action(bt->data);
    PreorderTraverse(bt->left, action);
    PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode* bt, VisitFuncPtr action) //중위 순회
{
    if(bt == NULL)
        return;

    InorderTraverse(bt->left, action);
    action(bt->data);
    InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action) //후위 순회
{
    //if(bt == NULL)
    //    return;

    if (bt == NULL)
        return;

    PostorderTraverse(bt->left, action);
    PostorderTraverse(bt->right, action);
    action(bt->data);
}

void DeleteTree(BTreeNode* node)
{
    if (node == NULL)
        return;

    printf("Enter Node Number: %d\n", node->data);

    if (node->left != NULL || node->right != NULL)
    {
        if (node->left != NULL)
        {
            DeleteTree(node->left);
        }

        if (node->right != NULL)
        {
            DeleteTree(node->right);
        }

        //DeleteSubTree(node);
        printf("free Node Number: %d\n", node->data);
        free(node);
        
    }
    else
    {
        printf("free Node Number: %d\n", node->data);
        free(node);
        return;
    }

}
